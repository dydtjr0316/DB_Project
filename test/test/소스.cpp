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
#define SQL_INSERT_RECORD "INSERT INTO playerinfo VALUES \
(NULL, % s, % d); " //"
int main()
{
	if (ParsingEventData() == false)
		return 0;

	CDataBase* db = new CDataBase;

	db->ConnectDB();

	//db->SetQuery("select * from logdb");
	int testint = 9999;
	char name[20] = "\"testname\"";
	int testeventno = 10000;
	char t[200] = "insert into logdb(m_id, charctor_name, event_no, var_1, var_2, var_3, var_4, var_5) values (%d, %s, % d, % d, % d, % d, % d, % d)";
	char tt[500];
	sprintf_s(tt, t, testint, name, testeventno, 1, 2, 3, 4, 5);
	db->SetQuery(tt);

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
