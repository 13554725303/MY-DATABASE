#include "TableRow.h"
TableRow::TableRow(const string& table_data_path_)
{
	table_data_path = table_data_path_;
}
json TableRow::read(uint64_t off_set, uint64_t line_number)
{
	DataFileHandler datahandler(table_data_path);
	datahandler.open();
	string result = "";
	json result_to_json=json::array();
	for (int i = off_set+1; i <= line_number; i++)
	{
		char* temp=datahandler.read_line(i);
		result = result + temp;
		json result_temp = json::parse(result);
		result_to_json.push_back(result_temp);
	}
	return result_to_json;
}
int TableRow::write(const json& row_information)
{
	int length = row_information.size();
	DataFileHandler datahandler(table_data_path);
	datahandler.open();
	for (int i = 0; i < length; i++)
	{
		datahandler.append(row_information[i].dump());
	}
}
	
