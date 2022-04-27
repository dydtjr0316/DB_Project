#include "stdafx.h"
#include "CHuntingEvent.h"
#include "CMainApp.h"


#ifdef PARSING_EVENT_DATA_0215

void CMainApp::GameLogic()
{
}

bool CMainApp::ParsingEvent()
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
void CMainApp::HuntingEventTest()
{
	cout << "Hunting Event Test" << endl;
	while (true)
	{

	}
}
#endif // PARSING_EVENT_DATA_0215

