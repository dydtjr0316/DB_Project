#include<iostream>
#include<my_global.h>
#include<mysql.h>
#include "stdafx.h"
#include "CHuntingEvent.h"
#include "CDataBase.h"
using namespace std;

#pragma comment(lib,"libmysql.lib")
vector<CEvent*> g_Event;
#ifdef PARSING_EVENT_DATA_0215
bool ParsingEventData();
#endif // PARSING_EVENT_DATA_0215
int main()
{
	if (ParsingEventData() == false)
		return 0;

	CDataBase* db = new CDataBase;

	db->ConnectDB();

	//db->SetQuery("select * from logdb");

	//db->PrintResult();



	return 0;
}

#ifdef PARSING_EVENT_DATA_0215
bool ParsingEventData() // 이부분은 app 쪽 기능으로 빼기 
{
	// event 정보 파일 입출력
	std::ifstream ifs("../Script//Event//EventingScript.txt");
	if (ifs.fail())
	{
		std::cerr << "Error!" << std::endl;
		return false;
	}

	while (!ifs.eof()) {
		string str;
		ifs >> str;
		if (str.find("//") != string::npos)
			continue;
		int eventID = stoi(str);

		switch ((Event::ID)eventID)
		{
		case Event::ID::eHungtingEvent:
		{
			CEvent* parsingEvent = new CHuntingEvent;
			g_Event.push_back(parsingEvent);
		}
		break;

		default:
			break;
		}
	}

	for (auto& ev : g_Event)
	{
		// parsing event 구현
		ev->ParsingScript();
	}

	return true;
}
#endif // PARSING_EVENT_DATA_0215
