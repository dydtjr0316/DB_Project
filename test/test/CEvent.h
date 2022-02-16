#pragma once
class CEvent
{
public:
	virtual bool ParsingScript() = 0;
	virtual void KillMonsterProcess() = 0;
	virtual void UpdateDB_Flag(const bool flag);

	virtual const bool GetIsUpdate() { return m_isUpdate; }

protected:
	bool m_isUpdate;
};

