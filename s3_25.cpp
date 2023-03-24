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

    //accumulate  包含三部分 迭代器的开始结束以及求和的起始值
    cout << accumulate(values.begin(),values.end(),0.0) / values.size() <<endl;
    //accumulate可以计算任何类型包括vector multiset deque 也可以计算一个迭代器的范围
    accumulate(values.lower_bound(10),values.upper_bound(50),0);
    //count  统计出现的次数
    vector<int> vec;
    cout << count(vec.begin(),vec.end(),7)<<endl;
    //_if _count_if
    cout << count_if(vec.begin(),vec.end(),IsEven) << endl;
    //_n  运行某一个n次
    deque<int> myDeque;
    fill_n(myDeque.begin(),10,0);//将deque中的前十项设置为0
    //迭代器
    //random-access iterator itr += distance; tr + distance itr1 < itr2;  itr[myIndex];
    //Bidirectional Iterators   --itr;
    //Forward Iterators
    //Input Iterators val = *itr;  ++itr;
    //Output Iterators *itr = val; ++itr;
    //重新排序算法
    //sort  前两个参数就是迭代器的范围，第三个参数是用来说明比较的方式，用一个bool类型的函数来说明
    vector<string> myString(5);
    for(vector<string>::iterator itr = myString.begin();itr != myString.end();++itr)
        cin >> *itr;
    sort(myString.begin(),myString.end(),CompareStringLength);//根据字符串的长度来排序
    for(vector<string>::iterator itr = myString.begin();itr != myString.end();++itr)
        cout<<*itr<<"\t";
    cout << endl;
    //random_shuffle  随机打乱顺序  用srand来给其提供种子
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
