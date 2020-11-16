#include "DBHandler.h"

DBHandler::DBHandler(const string& data_base_path_):data_base_meta(data_base_path_){}

void DBHandler::createDataBase(const string& data_base_name_)
{
	data_base_meta.addDataBase(data_base_name_);
	data_base_meta.save();
}
//通过addDataBase新建一个库

TableHandler DBHandler::open(const string& database_name_)
{
	return TableHandler(database_name_);
}
//打开一个数据库，开始操作库中的表

void DBHandler::drop()
{
	const char* DB_drop = (data_base_meta.GetDB_meta_path()).c_str();
	remove(DB_drop);
}
//删除库所在的文件

void DBHandler::Add_data_base(const string& data_base_name_)
{
	data_base_meta.addDataBase(data_base_name_);
	data_base_meta.save();
}
