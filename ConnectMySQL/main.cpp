#include <mysql.h>
#include <iostream>

using namespace std;
int qstate;


int main()
{
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);


	conn = mysql_real_connect(conn, "localhost", "root", "1@2b3!4?5#C", "projetohenrique", 3306, NULL, 0);


	if (conn)
	{
		puts("Successful connection to database! ");
		string query = "SELECT * FROM comclien";
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);
			while (row = mysql_fetch_row(res))
			{
				printf("Numero do cliente: %s \nCodigo do Cliente: %s \nNome: %s \nRazao Social: %s \nData de Nascimento: %s \nCPF\\CNPJ: %s\nTelefone\\Cell: %s \nCidade: %s \nEstado: %s\n", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8], row[9]);
				cout << "_____________________________\n";
			}

		}
		else
		{
			cout << "Query failed: " << mysql_error(conn) << endl;
		}

	}
	else
	{
		puts("Connection to Database has failed!");
	}

	system("pause");
	return 0;
}