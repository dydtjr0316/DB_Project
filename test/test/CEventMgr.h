#pragma once
class CEventMgr
{
private:
	vector<pair<Event::ID, CEvent*>> m_vEventLst;

public:
	vector<pair<Event::ID, CEvent*>> GetEventLst() { return m_vEventLst; }
	/*const 확인하고 추가하기 */
public:
	void AddEvent(const Event::ID& eventID, CEvent* pEvent);

	bool IsExistEvent(const Event::ID& eventID);

	void PrintErr(const string& err);
};

