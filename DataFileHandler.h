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
	//�����ļ�·��
	DataFileHandler(const string& file_path_);
	//���ļ�
	void open();
	//���ļ�ĩβ���һ����Ϣ
	void append(vector<int> new_data);
	//��ȡ�ļ��е�n����Ϣ
	json read_line(int num, int columns_num);
	//�����������ر��ļ�
	~DataFileHandler();
	int Get_File_Size();
	void SetDatafile(const string& file_path_);
	const string& GetDatapath();
	void SetData_list_num(int num);
};
#endif // !MYDATABASE1_DATAFILEHANDLER_H_

