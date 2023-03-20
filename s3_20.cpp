#include <iostream>
#include<string>
#include<fstream>//读写文件流
#include<iomanip>
#include<string>
using namespace std;
const int COLUMN_WIDTH = 20;
const int NUM_LINES = 3;
const int NUM_COLUMNS = 3;
void PrintTableHead();
void PrintTableBody();
void PrintTableBody()
{
    ifstream input("test-table.txt");
    if(!input.is_open())
    {
        cout<<"文件读取失败"<<endl;
    }
    for(int i=0;i < NUM_LINES;++i)
    {
        string name,id;
        input>>name>>id;
        cout<<setw(COLUMN_WIDTH)<<i+1<<"|";
        cout<<setw(COLUMN_WIDTH)<<name<<"|";
        cout<<setw(COLUMN_WIDTH)<<id<<endl;
    }
}
void PrintTableHead()
{
    for(int c = 0; c<NUM_COLUMNS-1;++c)
        cout<<setfill('-')<<setw(COLUMN_WIDTH)<<""<<"+";
    cout<<setw(COLUMN_WIDTH)<<""<<setfill(' ')<<endl;
}
int main()
{   /*
    //ifstream ofstream 是两个类型
    //ifstream 指定写入/打开的文件
    //读取一个文件
    ifstream myStream("myFile.txt");
    int a;
    myStream >> a;//从文件中读取数据
    //打开文件
    ifstream mys;
    mys.open("myFile.txt");
    //提示文件打不打得开
    ifstream input("myFile.txt");
    if(!input.is_open())
        cerr<< "不能打开myFile.txt文件"<<endl;//cerr类似cout但是是专门用于报错输出
        //ofstream
    ofstream mystream("myFlie.txt");//如果文件不存在就ofstream会自动创建一个，如果打开一个已经存在的会覆写掉原来的数据内容
    cout<<setw(10)<<777<<endl;//setw 来自<iomanip>,用于设置空白间距
    cout<< '['<< left << setw(10) << "hello" << ']'<<endl;//[hello     ]
    cout<< '['<< right << setw(10) << "hello" << ']'<<endl;//[     hello]
    cout<<setfill('-')<<setw(10)<<"hhh"<<endl;//-------hhh setfill('某个字符')用某个指定ed字符来占位
    //判断输入是否正确
    int b;
    cin >> b;
    if(cin.fail())
    {
        cout<<"请输入正确的数据"<<endl;
    }*/
    PrintTableHead();
    PrintTableBody();
    return 0;
}
