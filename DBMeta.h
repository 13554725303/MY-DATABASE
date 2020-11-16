#ifndef MYDATABASE1_DBMETA_H
#define MYDATABASE1_DBMETA_H
#include <fstream>
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;
class DBMeta{
private:
	json Data_Base_meta;
	string Data_Base_meta_path;
public:
	//构造函数同样有两种，一种是传入数据库路径调用load，另一种是直接传入json和路径
	DBMeta(const string& data_base_path_);
	DBMeta(json& data_base_, const string& data_base_path_);
	void save();
	void load();
	const string& GetDB_meta_path();
	//在数据库中添加表
	void addTable(const string& database_name, const string& table_name, const string& table_path);
	//在数据库中添加数据库
	void addDataBase(const string& database_name);
};
/*
Data_Base_meta格式如下：可放多个数据库，每个数据库可放多个表，每个表的value值对应的是表的路径
{
  "database_name1": {
	"table_name1": "table_path"
  },
  "database_name2": {
	"table_name1": "table_path"
  }
}
*/
#endif // !MYDATABASE1_DBMETA_H