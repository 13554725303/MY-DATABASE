#ifndef MYDATABASE1_DATAFILEHANDLER_H_
#define MYDATABASE1_DATAFILEHANDLER_H_
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;
class DataFileHandler {
private:
	fstream datafile;
	string file_path;
	int data_list_num;
public:
	//传进文件路径
	DataFileHandler(const string& file_path_);
	//打开文件
	void open();
	//在文件末尾添加一串信息
	void append(vector<int> new_data);
	//读取文件中第n行信息
	json read_line(int num, int columns_num);
	//用析构函数关闭文件
	~DataFileHandler();
	int Get_File_Size();
	void SetDatafile(const string& file_path_);
	const string& GetDatapath();
	void SetData_list_num(int num);
};
#endif // !MYDATABASE1_DATAFILEHANDLER_H_

