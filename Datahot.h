#ifndef MYDATABASE_DATA_HOT_H
#define MYDATABASE_DATA_HOT_H
#include <iomanip>
#include <iostream>
#include <vector>
#include "AVLTree.h"
#include "TableRow.h"
using namespace std;
#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )
class DataHot {
private:
    AVLTree<int>* tree;
    string log_file_path;
    int columns_num;
    long int CurrentOffset;
    TableRow log_tools;//处理log文件
public:
    DataHot(string path,int num):log_file_path(path),columns_num(num),CurrentOffset(1),log_tools(path,num)
    {
        tree = new AVLTree<int>();
    }
    void load()//从log文件中载入热数据
    {
        long int file_size = log_tools.Get_data_size();
        long int file_row_num = file_size / (sizeof(int) * columns_num);
        for (CurrentOffset = 1; CurrentOffset <= file_row_num; CurrentOffset++)
        {
            int Current_key = log_tools.read(CurrentOffset, 1)[0][0];
            tree->insert(Current_key, CurrentOffset);
        }
    }
    void insert(int primary_key,const json& rowinformation)//规定一行一行地写-----那么规定json的格式必须是[[]]才不会失配
    {
        log_tools.write(rowinformation);
        tree->insert(primary_key,CurrentOffset);
        CurrentOffset++;
    }
    void find(int primary_key)
    {
        cout << "primary key is " << primary_key << endl;
        cout << "the data is :";
        long int result_offset = tree->search(primary_key)->offset;
        cout<<log_tools.read(result_offset, 1)<<endl;
    }
    ~DataHot()
    {
        tree->destroy();
    }
};
#endif // !MYDATABASE_DATA_HOT_H

