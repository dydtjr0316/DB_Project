#include<iostream>
#include<my_global.h>
#include<mysql.h>
#include "stdafx.h"
#include "CHuntingEvent.h"
#include "CDataBase.h"
using namespace std;
CEventMgr* g_Event_Mgr = new CEventMgr;
#pragma comment(lib,"libmysql.lib")

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

	string strTemp = "\"testC\"";

	db->WriteLogDB(9999, strTemp, 10000, 6, 7, 8, 9, 10);



	return 0;
}

// 이부분은 app 쪽 기능으로 빼기 
#ifdef PARSING_EVENT_DATA_0215
bool ParsingEventData() 
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

		//g_Event_Mgr->IsEventing(...) 함수 추가하기


		CEvent* parsingEvent = nullptr;
		switch ((Event::ID)eventID)
		{
		case Event::ID::eHungtingEvent:
		{
			parsingEvent = new CHuntingEvent;
		}
		break;

		default:
			break;
		}
		g_Event_Mgr->AddEvent((Event::ID)eventID, parsingEvent);
	}

	for (auto& ev : g_Event_Mgr->GetEventLst())
	{
		// parsing event 구현
		ev.second->ParsingScript();
	}

	return true;
}
#endif // PARSING_EVENT_DATA_0215
