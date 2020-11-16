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
	//���캯��ͬ�������֣�һ���Ǵ������ݿ�·������load����һ����ֱ�Ӵ���json��·��
	DBMeta(const string& data_base_path_);
	DBMeta(json& data_base_, const string& data_base_path_);
	void save();
	void load();
	const string& GetDB_meta_path();
	//�����ݿ�����ӱ�
	void addTable(const string& database_name, const string& table_name, const string& table_path);
	//�����ݿ���������ݿ�
	void addDataBase(const string& database_name);
};
/*
Data_Base_meta��ʽ���£��ɷŶ�����ݿ⣬ÿ�����ݿ�ɷŶ����ÿ�����valueֵ��Ӧ���Ǳ��·��
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