#include<iostream>
#include<my_global.h>
#include<mysql.h>
#include "stdafx.h"
#include "CHuntingEvent.h"
#include "CDataBase.h"
#include "CMainApp.h"
#pragma comment(lib,"libmysql.lib")
using namespace std;
CEventMgr* g_Event_Mgr = new CEventMgr;
CMainApp* g_MainApp = new CMainApp;

int main()
{
	CDataBase* db = new CDataBase;
	db->ConnectDB();

	if (g_MainApp->ParsingEvent() == false)
		return 0;

	string strTemp = "\"testC\"";

	db->WriteLogDB(9999, strTemp, 10000, 6, 7, 8, 9, 10);

	return 0;
}

