#include "DBMeta.h"
DBMeta::DBMeta(const string& data_base_path_)
{
	Data_Base_meta_path = data_base_path_;
	load();
}
DBMeta::DBMeta(json& data_base_, const string& data_base_path_)
{
	Data_Base_meta = data_base_;
	Data_Base_meta_path = data_base_path_;
}
void DBMeta::load()
{
	fstream filetemp;
	filetemp.open(Data_Base_meta_path, ios::in);
	filetemp >> Data_Base_meta;
	filetemp.close();
}
void DBMeta::save()
{
	fstream filetemp;
	filetemp.open(Data_Base_meta_path, ios::out);
	filetemp << Data_Base_meta;
	filetemp.close();
}
const string& DBMeta::GetDB_meta_path()
{
	return Data_Base_meta_path;
}
void DBMeta::addTable(const string& database_name, const string& table_name, const string& table_path)
{
	Data_Base_meta[database_name][table_name] = table_path;
}
void DBMeta::addDataBase(const string& database_name)
{
	Data_Base_meta[database_name] = json::object();
}
//在数据库元数据中加入一个名为database_name的json