#include <iostream>
#include<string>
#include<fstream>//��д�ļ���
#include<iomanip>
#include<string>
#include<sstream>//��stringstream
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
        cout<<"�ļ���ȡʧ��"<<endl;
    }
    int row_number = 0;
    string name;
    int id;
    while(input>>name>>id)
    {    if(input.fail())
        { cout<<"�������ݴ���";
          continue;
        }//Ϊʲô����ʵ����������ȷ�����ݣ�
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
void ReadByLine()//һ��һ�еĶ�ȡ�ļ�
{
    ifstream readline("read-test.txt");
    if(!readline.is_open())
    {
        cerr << "���ܶ�ȡ���ļ���"<<endl;

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
//ȷ�������������
int GetInteger()
{   cout<<"������һ������"<<endl;
    while(true){
        stringstream converter;
        converter << GetLine();
        int result;
        if(converter >> result){
            char remaining;
            if(converter >> remaining)
                cout <<"��Ӧ��������ַ� :" << remaining << endl;
            else
                return result;

        } else
            cout <<"������һ��������"<<endl;
        cout << "���ԣ�"<<endl;

    }

}
int main()
{   /*
    //ifstream ofstream ����������
    //ifstream ��ʾ�����ļ���  �Զ���ģʽ��
    //ofstream ��ʾ����ļ������ڴ����ļ���д����Ϣ ��д��ģʽ��
    //��ȡһ���ļ�
    ifstream myStream("myFile.txt");
    int a;
    myStream >> a;//���ļ��ж�ȡ����
    //�Զ���ģʽ���ļ�
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
    }
    //�ر�ˢ�����������رմ򿪵��ļ�
    close();
    //cin�ǲ�����ȫ������  cinһ�ζ�ȡһ�����ݣ��Կո���зָ��ģ�
    string password;
    cout << "Enter administrator password: ";
    cin >> password;
    if(password == "password") {
        cout << "Do you want to erase your hard drive (Y or N)? ";
        char yesOrNo;
        cin >> yesOrNo;
            if(yesOrNo == 'y')
                EraseHardDrive();
 }//�����������password y ��ֱ��ִ����һ��
    //������getline  getlineֱ�������µ�һ�вŶ�ȡ
    string mys;
    getline(cin,mys);
    //����getlineҲ�в���  ��getline���ص����ַ���
    int dummyInt;
    string dummyString;
    cin >> dummyInt;
    getline(cin, dummyString);//�᷵�ؿ�ֵ��Ϊgetline ����������CIN�����Ա����Ŀհ��ϡ���ˣ�һ������ getline�����ͻ��ҵ���һ�� CIN �����ʣ��Ļ��з��������û��Ѱ� Return �������ҷ��ؿ��ַ���
    //stringstream   ��ȿ��Խ����ݲ����ַ������Խ�����ת��Ϊ�ַ�����Ҳ���Դ��ַ���������ȡ�����Խ��ַ�������ת��Ϊ������ʽ
    //����ת��
     stringstream my;
     int myint;
     double mydouble;
     string mystring;
     myint = 777;
     my << myint;//��int���͵�ֵ����������
     my >> mystring;//����������ǰ���ֵ�ٸ���string���͵ı���
     cout<<mystring;
     stringstream ss;
    ss << "312 hello 3.1415926";//��һ���ַ�������ss
    ss >> myint >> mystring >> mydouble;//���ַ����пո�ָ��ķָ�������������ת��Ϊ��Ӧ������
    cout << myint+7 << mystring <<mydouble*2<<endl;
    //�ַ���ƴ��,��ͬ���͵�Ҳ����ƴ��
    stringstream sa;
    int score=100;
    sa << "myscore" << score <<" is good";
    cout << "ƴ�Ӻ�"<<sa.str()<<endl;

    */
    PrintTableHead();
    PrintTableBody();
    ReadByLine();
   GetInteger();


    return 0;
}
