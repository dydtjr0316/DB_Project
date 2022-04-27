#pragma once
class CEvent
{
public:
	CEvent() { m_isUpdate = false; }
	~CEvent() {}
public:
	virtual bool ParsingScript() { return false; }
	virtual void KillMonsterProcess();
	virtual void UpdateDB_Flag(const bool flag);

	virtual const bool GetIsUpdate() { return m_isUpdate; }

protected:
	bool m_isUpdate;
};

