#include "stdafx.h"
#include "CDataBase.h"

void CDataBase::ConnectDB()
{
	mysql_init(&Conn);

	ConnHandle = mysql_real_connect(&Conn, "localhost", "root", "sp1121210!", "gamedb", 3306, (char*)NULL, 0);
	if (ConnHandle == nullptr)
	{
		fprintf(stderr, "MYsql Connention err : %s\n", mysql_error(&Conn));
	}
}

void CDataBase::DisConnectDB()
{
	// db 연결 해제
	mysql_close(ConnHandle);
}

void CDataBase::SetQuery(const char* query)
{
	dbStat = mysql_query(ConnHandle, query);
	if (dbStat != 0)
	{
		fprintf(stderr, "MYsql Query err : %s\n", mysql_error(&Conn));
	}
}

void CDataBase::PrintResult()
{
	int i = 0;
	Result = mysql_store_result(ConnHandle);
	while ((ResultRow = mysql_fetch_row(Result)) != NULL)
	{
		cout <<i<<"번 row : "<< ResultRow[0] <<", "<< ResultRow[1] << ", " << ResultRow[2] << ", " << ResultRow[3] << ", " << ResultRow[4] << ", " << ResultRow[5] << endl;
	}
	mysql_free_result(Result);
}
