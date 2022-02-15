#include<iostream>
#include<my_global.h>
#include<mysql.h>
using namespace std;

#pragma comment(lib,"libmysql.lib")

int main()
{
	cout << mysql_get_client_info() << endl;
	return 0;
}