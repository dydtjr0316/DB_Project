#include "stdafx.h"
#include "CEvent.h"

#ifdef HUNTING_EVENT_SCRIPT_0427
#include "CHuntingEventScript.h"
#endif // HUNTING_EVENT_SCRIPT_0427

#ifdef HUNTING_EVENT_0216
#	ifdef HUNTING_EVENT_SCRIPT_0427
bool CHuntingEventScript::ParsingScript()
{
	// event 정보 파일 입출력
	std::ifstream ifs("../Script//Event//HuntingEvent.txt");

	if (ifs.fail())
	{
		//std::cerr << "Error!" << std::endl;
		return false;
	}

	while (!ifs.eof()) {
		string token;
		string subToken;
		ifs >> token;	// 

		if (token.find("[KillCount]") != string::npos)
		{
			ifs >> subToken;
			m_iKillCount = stoi(subToken);
			subToken = "";
			token = "";
		}
		if (token.find("[LevelLimit]") != string::npos)
		{
			ifs >> subToken;
			m_iLevelLimit = stoi(subToken);
			subToken = "";
			token = "";
		}
	}

	return true;
}
#	endif // HUNTING_EVENT_SCRIPT_0427
void CHuntingEventScript::KillMonsterProcess()
{
}


#endif // HUNTING_EVENT_0216
