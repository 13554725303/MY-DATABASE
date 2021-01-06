#include "TableRow.h"
TableRow::TableRow(const string& table_data_path_, int columns_num_)
{
    table_data_path = table_data_path_;
    columns_num = columns_num_;
}
json TableRow::read(int off_set, int line_number)
{
	DataFileHandler datahandler(table_data_path);
	datahandler.open();
	json result_to_json;
	ifstream i(table_data_path);
	json j;
	int s = 1;
	int k = off_set;
	for (s, k; s <= line_number; k++, s++)
	{
		j = datahandler.read_line(k, columns_num);
		result_to_json.push_back(j);
	}
	return result_to_json;
}
void TableRow::write(const json& row_information)
{
	int length = row_information.size();
	vector<int> new_data;
	DataFileHandler datahandler(table_data_path);
	datahandler.open();
	for (int i = 0; i < length; i++)
	{
		int length2 = row_information[i].size();
		//int* new_data = new int[length2];
		new_data.clear();
		for (int j = 0; j < length2; j++)
		{
			new_data.push_back(row_information[i][j]);
		}
		datahandler.append(new_data);
	}
	data_size = datahandler.Get_File_Size();
}
	
