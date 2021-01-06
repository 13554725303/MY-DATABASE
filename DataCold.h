#ifndef MYDATABASE_DATA_COLD_H
#define MYDATABASE_DATA_COLD_H
#include "TableRow.h"
#include <fstream>
#include <vector>
#include <cstdio>
#include <string>
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;
struct Index {
	int first_primary_key;
	int offset;
};
class DataCold {
private:
	vector<Index> index_list;
	string cold_data_path;
	int column_num;
	long int data_offset;
	TableRow data_tools;
	long int data_size;
	long int List_num;
public:
	DataCold(string cold_data_path_, int column_num_) :data_tools(cold_data_path_, column_num_)
	{
		cold_data_path = cold_data_path_;
		column_num = column_num_;
		data_offset = 0;
	}
	void Create_Index_List()//����������
	{
		data_size = data_tools.Get_data_size();
		int temp_primarykey;
		if ((data_size / (column_num * 4)) % 128 == 0)
		{
			List_num = (data_size / (column_num * 4)) / 128;
		}
		else
		{
			List_num = ((data_size / (column_num * 4)) / 128) + 1;
		}
		index_list.clear();
		int current_offset = 1;
		int current_list_num = 1;
		while (current_list_num <= List_num)
		{
			temp_primarykey = (data_tools.read(current_offset, 1))[0][0];//�����1ָ����primarykey���ڵ�����
			Index temp;
			temp.first_primary_key = temp_primarykey;
			temp.offset = current_offset;
			index_list.push_back(temp);
			current_offset = current_offset + 128;
			current_list_num++;
		}
	}
	void insert(const json& row_information)
	{
		data_tools.write(row_information);
		//data_offset = data_offset + row_information.size();
		data_size = data_tools.Get_data_size();
	}
	void Find(int primary_key)
	{
		long int low, mid, high;//�������������ö��ֲ���
		low = 0;
		high = List_num - 1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (primary_key == index_list[mid].first_primary_key)
				break;
			else if ((primary_key > index_list[mid].first_primary_key))
			{
				if (mid + 1 <= List_num - 1)
				{
					if (primary_key < index_list[mid + 1].first_primary_key)
						break;
				}
			}
			if (primary_key < index_list[mid].first_primary_key)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		//�ҵ��������������ж�Ӧλ��mid
		//��˳�����
		long int current_offset = (mid - 1) * 128 + 1;
		int tag = 0;
		while (1)
		{
			int current_primarykey = (data_tools.read(current_offset, 1))[0][0];
			if (current_primarykey == primary_key)
			{
				tag = 1;
				cout << "��ѯ�ɹ�" << endl;
				cout << "primary key is " << primary_key << endl;
				cout << "�������ڵ�" << current_offset << "��" << endl;
				break;
			}
			current_offset++;
		}
		if (tag == 0)
		{
			cout << "��ѯʧ��" << endl;
		}
	}
};
#endif 

