#pragma once
class CEvent;
class CHuntingEventScript : public CEvent
{
public:
	CHuntingEventScript() { m_iKillCount = 0; m_iLevelLimit = 0; };
	
public:
	int m_iKillCount;
	int m_iLevelLimit;
	//int m_bitRewardFlag;
public:
	virtual bool ParsingScript();

	// CEvent을(를) 통해 상속됨
	virtual void KillMonsterProcess();
};

