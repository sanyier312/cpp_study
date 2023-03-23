#include<iostream>
#include<string>
#include<cctype>//使用 tolower大写转换为小写字母
#include<sstream>
using namespace std;
void ConvertToLowerCase(string input);//实现将字符串中的大写转化为小写
void ConvertToUpperCase(string input);//转化为大写
string IntegerToString(int input);//将整数转换为字符串
string DoubleToString(double input);//将double转化为字符串
void ConvertToLowerCase(string input)
{
    for(int i=0;i < input.size();++i)
    {
        input[i] = tolower(input[i]);
    }
    cout<<input<<endl;
}
void ConvertToUpperCase(string input)
{
     for(int i=0;i < input.size();++i)
    {
        input[i] = toupper(input[i]);
    }
    cout<<input<<endl;
}
string IntegerToString(int input)
{
    stringstream converter;
    string result;
    converter << input;
    converter >> result;
     return result;
}
string DoubleToString(double input)
{
    stringstream converter;
    string result;
    converter << input;
    converter >> result;
    return result;
}
int main()
{
    string a = "THIS IS A STRING";
    ConvertToLowerCase(a);
    string b = "this is a string";
    ConvertToUpperCase(b);
    int inte = 777;
    string c = IntegerToString(inte);
    double str = 3.1415926;
    string d = DoubleToString(str);
    stringstream con;
    con << c << d;
    cout << con.str() <<endl;
    //如何组织一个多个文件的项目
    return 0;
}

