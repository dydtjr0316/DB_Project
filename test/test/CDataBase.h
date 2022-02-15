#pragma once
class CDataBase
{
private:
	MYSQL Conn;
	MYSQL* ConnHandle = nullptr;
	MYSQL_RES* Result;
	MYSQL_ROW ResultRow;
	int dbStat;
public:
	void ConnectDB();
	void DisConnectDB();
	void SetQuery(const char* sql);
	void PrintResult();
};

