/*
�Զ����ɵĴ��룺
*/
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
/*
�ڴ˴�include����Ҫ�õ���libs
*/



using namespace std;

// ��������һ���õ���nlohmann/json����ôʹ������ľ��ӣ�����ע�͵���
using json = nlohmann::json;

void run()
{
    /*
    �����Լ������˼·���ڽ������ļ����д���һ�����ݿ⣺
    */
    DBHandler test("D:/QQQ/test_code");
    test.createDataBase("student_data_base");

    /*
    �����Լ������˼·���ڽ������ļ����д���һ�������������ݿ�ı�
    ��������е���Ϣ��
    ��һ�б�ʾѧ�ţ�int order
    �ڶ��б�ʾ�༶��int class
    �����б�ʾ������int score
    */
    TableHandler table_test = test.open("student_data_base");
    list<string> columns_test;
    columns_test.push_back("order");
    columns_test.push_back("class");
    columns_test.push_back("score");
    table_test.create("D:/QQQ/test_code/student/", "student_data_base_list", columns_test, test.getDBMeta());

    /*
    �����Լ������˼·���ڽ������ļ����д���һ��TableRow���ĸ�ʵ��row1��row2��row3��row4��
    */
    TableRow row1 = table_test.open("student_data_base_list");
    TableRow row2 = table_test.open("student_data_base_list");
    TableRow row3 = table_test.open("student_data_base_list");
    TableRow row4 = table_test.open("student_data_base_list");
    // ��ȡJSON

    // Ҳ���������·���е����ң���ô�������������ĸ�json���ڵ��ļ���
    string path = "D:/QQQ/JsonFile/";
    ifstream i(path + "test_data_100.json");
    json j_100;
    i >> j_100;
    i.close();
   /* ifstream i(path + "test_data_1000.json");
    json j_1000;
    i >> j_1000;
    i.close();

    ifstream i(path + "test_data_10000.json");
    json j_10000;
    i >> j_10000;
    i.close();

    ifstream i(path + "test_data_100000.json");
    json j_100000;
    i >> j_100000;
    i.close();
    */
    // rows
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

    cout << (&row1.read(4, 10)) << endl;
    cout << (&row1.read(100, 56)) << endl;
  /*  cout << (&row1.read(9999999, 1)) << endl; // ���ܳ���Ĳ���
    delete row1;
    delete j_100;
    //Ҳ����Ӧ��ͣһͣ
    system("pause");

    row2.write(j_1000);
    row2.write(j_1000);
    row2.write(j_1000);
    row2.write(j_1000);
    row2.write(j_1000);
    row2.write(j_1000);
    row2.write(j_1000);
    row2.write(j_1000);
    row2.write(j_1000);
    row2.write(j_1000);

    cout << (&row1.read(4, 10)) << endl;
    cout << (&row1.read(100, 56)) << endl;
    cout << (&row1.read(9999999, 1)) << endl; // ���ܳ���Ĳ���
    delete row2;
    delete j_1000;
    //Ҳ����Ӧ��ͣһͣ
    system("pause");

    row3.write(j_10000);
    row3.write(j_10000);
    row3.write(j_10000);
    row3.write(j_10000);
    row3.write(j_10000);

    cout << (&row1.read(4, 10)) << endl;
    cout << (&row1.read(100, 56)) << endl;
    cout << (&row1.read(9999999, 1)) << endl; // ���ܳ���Ĳ���
    delete row3;
    delete j_10000;
    //Ҳ����Ӧ��ͣһͣ
    system("pause");

    row4.write(j_100000);

    cout << (&row1.read(4, 10)) << endl;
    cout << (&row1.read(100, 56)) << endl;
    cout << (&row1.read(9999999, 1)) << endl; // ���ܳ���Ĳ���
    delete row4;
    delete j_100000;
    //Ҳ����Ӧ��ͣһͣ
    system("pause");

    */

}

int main()
{
    run();
    return 0;
}
