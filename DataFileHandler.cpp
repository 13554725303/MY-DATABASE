#include "DataFileHandler.h"

DataFileHandler::DataFileHandler(const string& file_path_)
{
	file_path = file_path_;
}

void DataFileHandler::open()
{
	datafile.open(file_path, ios::in | ios::out | ios::binary|ios::app);
}

void DataFileHandler::append(const string& new_data)
{
	datafile.write(new_data.c_str(), new_data.size());
}

char* DataFileHandler::read_line(int n)
{
	//计算字节数利用seekg指针读取
	datafile.seekg(sizeof(int)*(n-1)*data_list_num, ios::beg);
	char* result_line = new char[data_list_num];
	datafile.get(result_line, data_list_num);
	return result_line;
}

DataFileHandler::~DataFileHandler()
{
	datafile.close();
}

void DataFileHandler::SetDatafile(const string& file_path_)
{
	file_path = file_path_;
}

const string& DataFileHandler::GetDatapath()
{
	return file_path;
}
void DataFileHandler::SetData_list_num(int num)
{
	data_list_num = num;
}