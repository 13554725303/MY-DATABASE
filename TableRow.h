#ifndef MYDATABASE1_TABLEROW_H
#define MYDATABASE1_TABLEROW_H
#include "DataFileHandler.h"
#include <fstream>
#include <cstdio>
#include <string>
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;
class TableRow
{
	string table_data_path;
public:
	TableRow(const string& table_data_path_);
	//从off_set+1行开始读，读取line_number行，返回json对象
	json read(uint64_t off_set, uint64_t line_number);
	//将json对象写入文件中
	int write(const json& row_information);
};
#endif

