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
public:
	void WriteLogDB(const int& id, string& name, const int& eventNo, 
		const int& var1, const int& var2, const int& var3, const int& var4, const int& var5);
};

