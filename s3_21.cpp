#include<iostream>
#include<string>
#include<cctype>//ʹ�� tolower��дת��ΪСд��ĸ
#include<sstream>
using namespace std;
void ConvertToLowerCase(string input);//ʵ�ֽ��ַ����еĴ�дת��ΪСд
void ConvertToUpperCase(string input);//ת��Ϊ��д
string IntegerToString(int input);//������ת��Ϊ�ַ���
string DoubleToString(double input);//��doubleת��Ϊ�ַ���
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
    //�����֯һ������ļ�����Ŀ
    return 0;
}

