#ifndef MYDATABASE1_DATAFILEHANDLER_H_
#define MYDATABASE1_DATAFILEHANDLER_H_
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
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
	void append(const string& new_data);
	//��ȡ�ļ��е�n����Ϣ
	char* read_line(int n);
	//�����������ر��ļ�
	~DataFileHandler();
	void SetDatafile(const string& file_path_);
	const string& GetDatapath();
	void SetData_list_num(int num);
};
#endif // !MYDATABASE1_DATAFILEHANDLER_H_

