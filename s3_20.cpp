#include <iostream>
#include<string>
#include<fstream>//读写文件流
#include<iomanip>
#include<string>
#include<sstream>//用stringstream
using namespace std;
const int COLUMN_WIDTH = 20;
const int NUM_LINES = 3;
const int NUM_COLUMNS = 3;
void PrintTableHead();
void PrintTableBody();
void ReadByLine();
string Getline();
int GetInteger();
void PrintTableBody()
{
    ifstream input("test-table.txt");
    if(!input.is_open())
    {
        cout<<"文件读取失败"<<endl;
    }
    int row_number = 0;
    string name;
    int id;
    while(input>>name>>id)
    {    if(input.fail())
        { cout<<"输入数据错误";
          continue;
        }//为什么不能实现跳过不正确的数据？
        cout<<setw(COLUMN_WIDTH)<<row_number+1<<"|";
        cout<<setw(COLUMN_WIDTH)<<name<<"|";
        cout<<setw(COLUMN_WIDTH)<<id<<endl;
        row_number++;
    }

}
void PrintTableHead()
{
    for(int c = 0; c<NUM_COLUMNS-1;++c)
        cout<<setfill('-')<<setw(COLUMN_WIDTH)<<""<<"+";
    cout<<setw(COLUMN_WIDTH)<<""<<setfill(' ')<<endl;
}
void ReadByLine()//一行一行的读取文件
{
    ifstream readline("read-test.txt");
    if(!readline.is_open())
    {
        cerr << "不能读取该文件！"<<endl;

    }
    string line;
    while(getline(readline,line))
    {
        if(readline.fail()) break;
        cout<<line<<endl;
    }
}
string GetLine()
{
    string result;
    getline(cin,result);
    return result;
}
//确保输入的是整数
int GetInteger()
{   cout<<"请输入一个整数"<<endl;
    while(true){
        stringstream converter;
        converter << GetLine();
        int result;
        if(converter >> result){
            char remaining;
            if(converter >> remaining)
                cout <<"不应该输入的字符 :" << remaining << endl;
            else
                return result;

        } else
            cout <<"请输入一个整数！"<<endl;
        cout << "重试！"<<endl;

    }

}
int main()
{   /*
    //ifstream ofstream 是两个类型
    //ifstream 表示输入文件流  以读的模式打开
    //ofstream 表示输出文件流用于创建文件并写入信息 以写的模式打开
    //读取一个文件
    ifstream myStream("myFile.txt");
    int a;
    myStream >> a;//从文件中读取数据
    //以读的模式打开文件
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
    }
    //关闭刷新所有流并关闭打开的文件
    close();
    //cin是不够安全的如下  cin一次读取一个数据（以空格或换行分隔的）
    string password;
    cout << "Enter administrator password: ";
    cin >> password;
    if(password == "password") {
        cout << "Do you want to erase your hard drive (Y or N)? ";
        char yesOrNo;
        cin >> yesOrNo;
            if(yesOrNo == 'y')
                EraseHardDrive();
 }//如果输入密码password y 会直接执行下一步
    //可以用getline  getline直到遇到新的一行才读取
    string mys;
    getline(cin,mys);
    //但是getline也有不足  且getline返回的是字符串
    int dummyInt;
    string dummyString;
    cin >> dummyInt;
    getline(cin, dummyString);//会返回空值因为getline 不会跳过在CIN流中仍保留的空白上。因此，一旦调用 getline，它就会找到上一个 CIN 语句中剩余的换行符，假设用户已按 Return 键，并且返回空字符串
    //stringstream   你既可以将数据插入字符串流以将数据转换为字符串，也可以从字符串流中提取数据以将字符串数据转换为其他格式
    //类型转换
     stringstream my;
     int myint;
     double mydouble;
     string mystring;
     myint = 777;
     my << myint;//将int类型的值放入输入流
     my >> mystring;//将输入流中前面的值再赋给string类型的变量
     cout<<mystring;
     stringstream ss;
    ss << "312 hello 3.1415926";//将一个字符串给了ss
    ss >> myint >> mystring >> mydouble;//将字符串中空格分隔的分给三个变量并且转化为相应的类型
    cout << myint+7 << mystring <<mydouble*2<<endl;
    //字符串拼接,不同类型的也可以拼接
    stringstream sa;
    int score=100;
    sa << "myscore" << score <<" is good";
    cout << "拼接后"<<sa.str()<<endl;

    */
    PrintTableHead();
    PrintTableBody();
    ReadByLine();
   GetInteger();


    return 0;
}
