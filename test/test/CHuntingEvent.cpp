#include "stdafx.h"
#include "CHuntingEvent.h"

#ifdef HUNTING_EVENT_0216
void CHuntingEvent::KillMonsterProcess()
{
}

bool CHuntingEvent::ParsingScript()
{
	// event ���� ���� �����
	std::ifstream ifs("../Script//Event//HuntingEvent.txt");

	if (ifs.fail())
	{
		//std::cerr << "Error!" << std::endl;
		return false;
	}

	while (!ifs.eof()) {
		string str;
		ifs >> str;
		if (str.find("//") != string::npos)
			continue;
		int eventID = stoi(str);

		// token �� ��ũ��Ʈ �д� �κ�
	}

	for (auto& ev : g_Event_Mgr->GetEventLst())
	{
		// parsing event ����
	}

	return true;
}
#endif // HUNTING_EVENT_0216
