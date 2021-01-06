#include "DataFileHandler.h"
DataFileHandler::DataFileHandler(const string& file_path_)
{
    file_path = file_path_;
}
void DataFileHandler::open()
{
    datafile.open(file_path, ios::in | ios::out | ios::binary | ios::app);
}
void DataFileHandler::append(vector<int> new_data)
{
    for (int i = 0; i < new_data.size(); i++)
    {
        datafile.write((char*)&new_data[i], sizeof(int));
    }
}

json DataFileHandler::read_line(int num, int columns_num)
{
	//num:对应行数
	ifstream i(file_path);
	json j;
	if (num < 1)
	{
		cout << "Fail to read" << endl;
		return 0;
	}
	i.seekg(sizeof(int) * columns_num * (num - 1), ios::cur);
	for (int k = 0; k < columns_num; k++)
	{
		int n;
		i.read((char*)&n, sizeof(int));
		j.push_back(n);
	}
	i.close();
	return j;
}
DataFileHandler::~DataFileHandler()
{
    datafile.close();
}

int DataFileHandler::Get_File_Size()
{
	ifstream file(file_path);
	file.seekg(0, ios::end);
	int file_size = file.tellg();
	return file_size;
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