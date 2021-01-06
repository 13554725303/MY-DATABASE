#ifndef MYDATABASE1_TABLEMETA_H
#define MYDATABASE1_TABLEMETA_H
#include <iostream>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
#include "DataFileHandler.h"
using namespace std;
using json = nlohmann::json;

class TableMeta
{
private:
	json table;
	string table_path;
	int table_list_num;
public:
	//���ֹ��캯������һ���Ǵ���Ԫ���ݵ�·��������load������json���и�ֵ���ڶ�����ֱ�Ӵ���json��·��ֱ�Ӹ�ֵ
	TableMeta(const string& table_path_);
	TableMeta(json& table_,const string &table_path_);
	//��json�������ļ���
	void save();
	//���ļ��е���json
	void load();
	void SetTable(json& table_);
	void SetTable_path(const string& table_path);
	void SetTable_list_num(int num);
	int GetTable_list_num();
	const string& GetTable_path();
	const string& GetTable_data_path();
	const string& GetTable_name();
};
#endif // !MYDATABASE1_TABLEMETA_H
