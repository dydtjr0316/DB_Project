#pragma once
#include "CEvent.h"
#include "CHuntingEventScript.h"

#ifdef HUNTING_EVENT_0216
class CHuntingEventScript;
class CHuntingEvent : public CEvent
{
public:
	CHuntingEvent() { m_pScript = new CHuntingEventScript; };

public:
	CHuntingEventScript* m_pScript;
public:
	// CEvent을(를) 통해 상속됨
	virtual void KillMonsterProcess() override;
	virtual bool ParsingScript();

};
#endif // HUNTING_EVENT_0216

