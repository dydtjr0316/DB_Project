#include "stdafx.h"
#include "CEventMgr.h"

void CEventMgr::AddEvent(const Event::ID& eventID, CEvent* pEvent)
{
	if (IsExistEvent(eventID))
		m_vEventLst.push_back(make_pair((Event::ID)eventID, pEvent));
	else
		PrintErr("AddEvent");
}

bool CEventMgr::IsExistEvent(const Event::ID& eventID)
{
	if (eventID > Event::ID::eStart && eventID < Event::ID::eEnd)
		return true;
	else 
		return false;
}

void CEventMgr::PrintErr(const string& err)
{
	cout << "==========Error==========" << endl;
	printf("EventMgr class의 함수 %s - %d줄 Error!\n", __FUNCTION__, __LINE__);
	cout << "=========================" << endl;
}
