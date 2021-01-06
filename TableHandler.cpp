#include "TableHandler.h"
TableHandler::TableHandler(const string& data_base_handler_name_)
{
	data_base_handler_name = data_base_handler_name_;
}
void TableHandler::create(const string& table_directory, const string& table_name_, list<string> columns)
{
	//在DBMeta中记录对应的增加的表
	tables[table_name_]["table_name"] = table_name_;
	tables[table_name_]["directory"] = table_directory;
	tables[table_name_]["columns_num"] = columns.size();
	for (list<string>::iterator it = columns.begin(); it != columns.end(); it++)
	{
		json columns_name = *it;
		tables[table_name_]["columnlist"].push_back(columns_name);
	}
	//元数据文件的路径
	string table_meta_path = table_directory + table_name_ + ".json";
	TableMeta table_meta(tables, table_meta_path);
	table_meta.save();
	//二进制文件的路径
	string table_data_path = table_directory + table_name_ + ".dat";
	DataFileHandler table_data(table_data_path);
	table_data.SetData_list_num(columns.size());
	table_data.open();
}


string TableHandler::open(const string& table_name)
{
	string table_data_path = tables[table_name]["directory"];
	table_data_path = table_data_path + table_name + ".dat";
	return table_data_path;
}

void TableHandler::drop(const string& table_name)
{
	string table_path = tables[table_name]["directory"] + ".json";
	string table_data_path = tables[table_name]["directory"] + ".dat";
	const char* Table_drop = table_path.c_str();
	const char* Data_drop = table_data_path.c_str();
	remove(Table_drop);
	remove(Data_drop);
}
int TableHandler::Get_columns_num(const string& table_name_)
{
	return tables[table_name_]["columns_num"];
}