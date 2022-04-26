#pragma once
class CEvent;
class CEventMgr
{
private:
	vector<pair<Event::ID, CEvent*>> m_vEventLst;
	
	unordered_map<Event::ID, CEvent*> m_umapEventLst; // �ٲٴ� �۾� �ϱ�

public:
	vector<pair<Event::ID, CEvent*>> GetEventLst() { return m_vEventLst; }
	
	/*const Ȯ���ϰ� �߰��ϱ� */
public:
	void AddEvent(const Event::ID& eventID, CEvent* pEvent);

	bool IsExistEvent(const Event::ID& eventID);

	void PrintErr(const string& err);
};

