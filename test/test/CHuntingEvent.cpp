#include "stdafx.h"
#include "CHuntingEvent.h"

#ifdef HUNTING_EVENT_0216
void CHuntingEvent::KillMonsterProcess()
{
}

bool CHuntingEvent::ParsingScript()
{
	m_pScript->ParsingScript();
	return false;
}

#endif // HUNTING_EVENT_0216
