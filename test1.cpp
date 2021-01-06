#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string>
#include<nlohmann/json.hpp>
#include"DataFileHandler.h"
#include"TableMeta.h"
#include"TableHandler.h"
#include"DBMeta.h"
#include"DBHandler.h"
#include"TableRow.h"

using namespace std;
using json = nlohmann::json;
int main()
{
	DBHandler dbtest("D:/QQQ/mytest/db_test3.json");
	dbtest.createDataBase("student3_data_base3");
	TableHandler table_test1 = dbtest.open("student3_data_base3");
	list<string> columns_test;
	columns_test.push_back("order");
	columns_test.push_back("class");
	columns_test.push_back("score");
	string testtable = "test126.json";
	string tablepath = "D:/QQQ/mytest/";
	table_test1.create(tablepath, "student_data3", columns_test);
	dbtest.Add_data_base_table("student3_data_base3", "student_data3", table_test1.open("student_data3"));
	json test_data = { {100, 100, 100},{90, 90, 90},{80, 80, 80},{70, 70, 70},{60, 60, 60} };
	string path = "D:/QQQ/mytest/test_all/";
	ifstream i(path + "test_data_100.json");
	json j_100;
	i >> j_100;
	i.close();
	TableRow row1(table_test1.open("student_data3"), table_test1.Get_columns_num("student_data3"));
	row1.write(j_100);
	row1.write(j_100);
	row1.write(j_100);
	row1.write(j_100);
	row1.write(j_100);
	row1.write(j_100);
	row1.write(j_100);
	row1.write(j_100);
	row1.write(j_100);
	row1.write(j_100);
	row1.write(j_100);
	row1.write(j_100);
	row1.write(j_100);
	row1.write(j_100);
	row1.write(j_100);
	row1.write(j_100);
	row1.write(j_100);
	row1.write(j_100);
	row1.write(j_100);
	row1.write(j_100);
	row1.write(j_100);
	row1.write(j_100);
	row1.write(j_100);
	row1.write(j_100);
	row1.write(j_100);

	cout << (row1.read(1, 10)) << endl;
}