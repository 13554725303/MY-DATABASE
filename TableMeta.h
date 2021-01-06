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
	//两种构造函数，第一种是传入元数据的路径，调用load函数对json进行赋值，第二种是直接传入json和路径直接赋值
	TableMeta(const string& table_path_);
	TableMeta(json& table_,const string &table_path_);
	//将json保存在文件中
	void save();
	//从文件中导入json
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
