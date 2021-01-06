/*
自动生成的代码：
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
在此处include你需要用到的libs
*/



using namespace std;

// 如果你和我一样用的是nlohmann/json，那么使用下面的句子，否则注释掉他
using json = nlohmann::json;

void run()
{
    /*
    以你自己的设计思路，在接下来的几行中创建一个数据库：
    */
    DBHandler test("D:/QQQ/test_code");
    test.createDataBase("student_data_base");

    /*
    以你自己的设计思路，在接下来的几行中创建一个属于上述数据库的表：
    表包含三列的信息：
    第一列表示学号：int order
    第二列表示班级：int class
    第三列表示分数：int score
    */
    TableHandler table_test = test.open("student_data_base");
    list<string> columns_test;
    columns_test.push_back("order");
    columns_test.push_back("class");
    columns_test.push_back("score");
    table_test.create("D:/QQQ/test_code/student/", "student_data_base_list", columns_test, test.getDBMeta());

    /*
    以你自己的设计思路，在接下来的几行中创建一个TableRow的四个实例row1，row2，row3，row4：
    */
    TableRow row1 = table_test.open("student_data_base_list");
    TableRow row2 = table_test.open("student_data_base_list");
    TableRow row3 = table_test.open("student_data_base_list");
    TableRow row4 = table_test.open("student_data_base_list");
    // 读取JSON

    // 也许你会对相对路径感到混乱，那么请在这里填上四个json所在的文件夹
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
  /*  cout << (&row1.read(9999999, 1)) << endl; // 可能出错的操作
    delete row1;
    delete j_100;
    //也许你应该停一停
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
    cout << (&row1.read(9999999, 1)) << endl; // 可能出错的操作
    delete row2;
    delete j_1000;
    //也许你应该停一停
    system("pause");

    row3.write(j_10000);
    row3.write(j_10000);
    row3.write(j_10000);
    row3.write(j_10000);
    row3.write(j_10000);

    cout << (&row1.read(4, 10)) << endl;
    cout << (&row1.read(100, 56)) << endl;
    cout << (&row1.read(9999999, 1)) << endl; // 可能出错的操作
    delete row3;
    delete j_10000;
    //也许你应该停一停
    system("pause");

    row4.write(j_100000);

    cout << (&row1.read(4, 10)) << endl;
    cout << (&row1.read(100, 56)) << endl;
    cout << (&row1.read(9999999, 1)) << endl; // 可能出错的操作
    delete row4;
    delete j_100000;
    //也许你应该停一停
    system("pause");

    */

}

int main()
{
    run();
    return 0;
}
