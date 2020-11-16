#include "TableMeta.h"

TableMeta::TableMeta(const string& table_path_)
{
	table_path = table_path_;
	load();
}

TableMeta::TableMeta(json& table_, const string& table_path_)
{
	table = table_;
	table_path = table_path_;
}

void TableMeta::save()
{
	fstream filetemp;
	filetemp.open(table_path,ios::out);
	filetemp << table;
	filetemp.close();
}
void TableMeta::load()
{
	fstream filetemp;
	filetemp.open(table_path, ios::in);
	filetemp >> table;
	filetemp.close();
}
void TableMeta::SetTable(json& table_)
{
	table = table_;
}
void TableMeta::SetTable_path(const string& table_path_)
{
	table_path = table_path_;
}
int TableMeta::GetTable_list_num()
{
	return table_list_num;
}
const string& TableMeta::GetTable_path()
{
	return table_path;
}
const string& TableMeta::GetTable_data_path()
{
	return table["directory_path"];

}
const string& TableMeta::GetTable_name()
{
	return table["table_name"];
}
void TableMeta::SetTable_list_num(int num)
{
	table_list_num = num;
}
