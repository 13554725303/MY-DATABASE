#ifndef MYDATABASE1_DBHANDLER_H
#define MYDATABASE1_DBHANDLER_H
#include <fstream>
#include <cstdio>
#include <string>
#include <nlohmann/json.hpp>
#include "DBMeta.h"
#include "TableHandler.h"
using namespace std;
using json = nlohmann::json;
class DBHandler
{
private:
	//���ԱΪDBMetaʵ��
	DBMeta data_base_meta;

public:
	//�������ݿ�ĵ�ַʵ�������Ա
	DBHandler(const string& data_base_path);
	//�½�һ�����ݿ�
	void createDataBase(const string& data_base_name_);
	//�����ݿ⣬����TableHandler����ʼ�Ա���в���
	TableHandler open(const string& database_name_);
	void drop();
	void Add_data_base(const string& data_base_name);
	DBMeta& getDBMeta();
	void Add_data_base_table(const string& database_name, const string& table_name, const string& table_path);
};
#endif

