#pragma once
class CEvent
{
public:
	virtual void KillMonsterProcess();
	virtual void UpdateDB_Flag(const bool flag);

	virtual const bool GetIsUpdate() { return m_isUpdate; }

protected:
	bool m_isUpdate;
};

