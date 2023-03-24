#include<iostream>
#include<set>
#include<fstream>
#include<numeric>
#include<algorithm>
#include<vector>
#include<deque>
#include<string>
using namespace std;
bool IsEven(int value)
{
    return value % 2 == 0;
}
bool CompareStringLength(string a,string b)
{
        return a.length() > b.length();

}
int main()
{  //
    ifstream input("data.txt");
    multiset<int> values;

    int currValue;
    while(input >> currValue)
        values.insert(currValue);

    //accumulate  ���������� �������Ŀ�ʼ�����Լ���͵���ʼֵ
    cout << accumulate(values.begin(),values.end(),0.0) / values.size() <<endl;
    //accumulate���Լ����κ����Ͱ���vector multiset deque Ҳ���Լ���һ���������ķ�Χ
    accumulate(values.lower_bound(10),values.upper_bound(50),0);
    //count  ͳ�Ƴ��ֵĴ���
    vector<int> vec;
    cout << count(vec.begin(),vec.end(),7)<<endl;
    //_if _count_if
    cout << count_if(vec.begin(),vec.end(),IsEven) << endl;
    //_n  ����ĳһ��n��
    deque<int> myDeque;
    fill_n(myDeque.begin(),10,0);//��deque�е�ǰʮ������Ϊ0
    //������
    //random-access iterator itr += distance; tr + distance itr1 < itr2;  itr[myIndex];
    //Bidirectional Iterators   --itr;
    //Forward Iterators
    //Input Iterators val = *itr;  ++itr;
    //Output Iterators *itr = val; ++itr;
    //���������㷨
    //sort  ǰ�����������ǵ������ķ�Χ������������������˵���Ƚϵķ�ʽ����һ��bool���͵ĺ�����˵��
    vector<string> myString(5);
    for(vector<string>::iterator itr = myString.begin();itr != myString.end();++itr)
        cin >> *itr;
    sort(myString.begin(),myString.end(),CompareStringLength);//�����ַ����ĳ���������
    for(vector<string>::iterator itr = myString.begin();itr != myString.end();++itr)
        cout<<*itr<<"\t";
    cout << endl;
    //random_shuffle  �������˳��  ��srand�������ṩ����
    random_shuffle(myString.begin(),myString.end());
     for(vector<string>::iterator itr = myString.begin();itr != myString.end();++itr)
        cout<<*itr<<"\t";
    cout << endl;
    //rotate
    vector<int> test;
    for(vector<int>::iterator itr = test.begin();itr != test.end();++itr)
        cin >> *itr;
    rotate(test.begin(),test.end() + 3,test.end());
    for(vector<int>::iterator itr = test.begin(); itr != test.end();++itr)
        cout << *itr <<"\t";
    cout<<endl;
    return 0;

}
