#pragma once
#include "CEvent.h"
#ifdef HUNTING_EVENT_0216
class CHuntingEvent : public CEvent
{
public:
	CHuntingEvent() {};
public:
	// CEvent��(��) ���� ��ӵ�
	virtual void KillMonsterProcess() override;
	virtual bool ParsingScript() override;

};
#endif // HUNTING_EVENT_0216

