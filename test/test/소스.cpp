#include<iostream>
#include<my_global.h>
#include<mysql.h>
#include "stdafx.h"
#include "CDataBase.h"
using namespace std;

#pragma comment(lib,"libmysql.lib")
vector<CEvent*> g_Event;
#ifdef PARSING_EVENT_DATA_0215
void ParsingEventData();
#endif // PARSING_EVENT_DATA_0215

int main()
{
	CDataBase* db = new CDataBase;

	db->ConnectDB();

	db->SetQuery("select * from logdb");

	db->PrintResult();



	return 0;
}

#ifdef PARSING_EVENT_DATA_0215
void ParsingEventData()
{
	// event 정보 파일 입출력
}
#endif // PARSING_EVENT_DATA_0215
