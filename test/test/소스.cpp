#include<iostream>
#include<my_global.h>
#include<mysql.h>
#include "CDataBase.h"
using namespace std;

#pragma comment(lib,"libmysql.lib")

int main()
{
	CDataBase* db = new CDataBase;

	db->ConnectDB();

	db->SetQuery("select * from logdb");

	db->PrintResult();



	// db ���� ����
	//mysql_close(ConnHandle);

	return 0;
}