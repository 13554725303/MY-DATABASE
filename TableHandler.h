#ifndef MYDATABASE1_TABLEHANDLER_H
#define MYDATABASE1_TABLEHANDLER_H
#include <fstream>
#include <string>
#include <cstdio>
#include <nlohmann/json.hpp>
#include "TableMeta.h"
#include "DataFileHandler.h"
#include "DBMeta.h"
#include "TableRow.h"
using namespace std;
using json = nlohmann::json;

class TableHandler {
private:
    json tables;
    string data_base_handler_name;
    //表所在的数据库名
public:
    TableHandler(const string& data_base_handler_name);
    //表头文件和二进制文件放入同一个目录中，用一个list传入元数据的列名
    void create(const string& table_directory,const string& table_name_,list<string> columns,DBMeta &data_base_meta);
    //调用open返回一个TableRow对象，实现对二进制文件的操作
    TableRow open(const string& table_name);
    //对表头文件和二进制文件进行删除
    void drop(const string& table_name);
};
#endif
/*
{
  "table_name1": {
	"table_name1": "表名",
	"directory": "file_path",
	"column_num": "int",
	"column_list": {
	  "column1_name": "name1",
	  "column2_name": "name2"
	}
  },
  "table_name2": {
	"table_name2": "表名",
	"directory": "file_path",
	"column_num": "int",
	"column_list": {
	  "column1_name": "name1",
	  "column2_name": "name2"
	}
  }
}
*/