#include <iostream>
#include<string>
#include<fstream>//��д�ļ���
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
        cout<<"�ļ���ȡʧ��"<<endl;
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
    //ifstream ofstream ����������
    //ifstream ָ��д��/�򿪵��ļ�
    //��ȡһ���ļ�
    ifstream myStream("myFile.txt");
    int a;
    myStream >> a;//���ļ��ж�ȡ����
    //���ļ�
    ifstream mys;
    mys.open("myFile.txt");
    //��ʾ�ļ��򲻴�ÿ�
    ifstream input("myFile.txt");
    if(!input.is_open())
        cerr<< "���ܴ�myFile.txt�ļ�"<<endl;//cerr����cout������ר�����ڱ������
        //ofstream
    ofstream mystream("myFlie.txt");//����ļ������ھ�ofstream���Զ�����һ���������һ���Ѿ����ڵĻḲд��ԭ������������
    cout<<setw(10)<<777<<endl;//setw ����<iomanip>,�������ÿհ׼��
    cout<< '['<< left << setw(10) << "hello" << ']'<<endl;//[hello     ]
    cout<< '['<< right << setw(10) << "hello" << ']'<<endl;//[     hello]
    cout<<setfill('-')<<setw(10)<<"hhh"<<endl;//-------hhh setfill('ĳ���ַ�')��ĳ��ָ��ed�ַ���ռλ
    //�ж������Ƿ���ȷ
    int b;
    cin >> b;
    if(cin.fail())
    {
        cout<<"��������ȷ������"<<endl;
    }*/
    PrintTableHead();
    PrintTableBody();
    return 0;
}
