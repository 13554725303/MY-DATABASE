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
    //�����ڵ����ݿ���
public:
    TableHandler(const string& data_base_handler_name);
    //��ͷ�ļ��Ͷ������ļ�����ͬһ��Ŀ¼�У���һ��list����Ԫ���ݵ�����
    void create(const string& table_directory,const string& table_name_,list<string> columns,DBMeta &data_base_meta);
    //����open����һ��TableRow����ʵ�ֶԶ������ļ��Ĳ���
    TableRow open(const string& table_name);
    //�Ա�ͷ�ļ��Ͷ������ļ�����ɾ��
    void drop(const string& table_name);
};
#endif
/*
{
  "table_name1": {
	"table_name1": "����",
	"directory": "file_path",
	"column_num": "int",
	"column_list": {
	  "column1_name": "name1",
	  "column2_name": "name2"
	}
  },
  "table_name2": {
	"table_name2": "����",
	"directory": "file_path",
	"column_num": "int",
	"column_list": {
	  "column1_name": "name1",
	  "column2_name": "name2"
	}
  }
}
*/