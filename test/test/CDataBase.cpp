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

void CDataBase::WriteLogDB(const int& id, string& name, const int& eventNo, const int& var1, const int& var2, const int& var3, const int& var4, const int& var5)
{
	char logBase[250] =
		"insert into logdb (m_id, charctor_name, event_no, var_1, var_2, var_3, var_4, var_5) "
		"values (%d, %s, % d, % d, % d, % d, % d, % d) "
		"on duplicate key update "
		"charctor_name = %s,"
		"event_no = %d,"
		"var_1 = %d,"
		"var_2 = %d,"
		"var_3 = %d,"
		"var_4 = %d,"
		"var_5 = %d";

	char query[350];

	sprintf_s(query, logBase, 
		id, name.c_str(), eventNo, var1, var2, var3, var4, var5,	// insert
		name.c_str(), eventNo, var1, var2, var3, var4, var5			// update
	);

	SetQuery(query);
}
