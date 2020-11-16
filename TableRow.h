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
	//��off_set+1�п�ʼ������ȡline_number�У�����json����
	json read(uint64_t off_set, uint64_t line_number);
	//��json����д���ļ���
	int write(const json& row_information);
};
#endif

