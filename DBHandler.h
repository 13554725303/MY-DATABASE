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
	//类成员为DBMeta实例
	DBMeta data_base_meta;
public:
	//传入数据库的地址实例化类成员
	DBHandler(const string& data_base_path);
	//新建一个数据库
	void createDataBase(const string& data_base_name_);
	//打开数据库，返回TableHandler对象开始对表进行操作
	TableHandler open(const string& database_name_);
	void drop();
	void Add_data_base(const string& data_base_name);
};
#endif

