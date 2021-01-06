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
	int columns_num;
	long int data_size;
public:
	TableRow(const string& table_data_path_, int columns_num_);
	//��off_set+1�п�ʼ������ȡline_number�У�����json����
	json read(int off_set, int line_number);
	//��json����д���ļ���
	void write(const json& row_information);
	long int Get_data_size()
	{
		return data_size;
	}
};
#endif

