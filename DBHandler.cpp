#include "DBHandler.h"

DBHandler::DBHandler(const string& data_base_path_):data_base_meta(data_base_path_){}

void DBHandler::createDataBase(const string& data_base_name_)
{
	data_base_meta.addDataBase(data_base_name_);
	data_base_meta.save();
}
//ͨ��addDataBase�½�һ����

TableHandler DBHandler::open(const string& database_name_)
{
	return TableHandler(database_name_);
}
//��һ�����ݿ⣬��ʼ�������еı�

void DBHandler::drop()
{
	const char* DB_drop = (data_base_meta.GetDB_meta_path()).c_str();
	remove(DB_drop);
}
//ɾ�������ڵ��ļ�

void DBHandler::Add_data_base(const string& data_base_name_)
{
	data_base_meta.addDataBase(data_base_name_);
	data_base_meta.save();
}
