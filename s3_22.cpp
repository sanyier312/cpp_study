#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int Num = 5;
//size_t非负整数
//第一种实现：通过从第一个开始往后的找最小值，将最小值排列在前面
void PrintList(vector<int>& v)
{
    for(size_t i = 0; i < v.size();++i)
    {
        cout<<v[i]<<endl;
    }
}
void PrintList(vector<string>& v)
{
    for(size_t i = 0; i < v.size();++i)
    {
        cout<<v[i]<<endl;
    }
}

size_t GetSmallestIndex(vector<int>& v ,size_t startIndex)
{
    size_t bestIndex = startIndex;
    for(size_t i = startIndex; i<v.size();++i)
    {
        if(v[i]<v[bestIndex])
            bestIndex = i;
    }
    return bestIndex;
}
void  SelectionSort(vector<int>& v)
{
    for(size_t i = 0; i<v.size();++i)
    {
         size_t smallestIndex = GetSmallestIndex(v,i);
         swap( v[i],v[smallestIndex]);
    }



}
//第二种实现 在输入时就到按顺序的位置
size_t InsertionIndex(vector<string>& v ,string toInsert)
{
    for(size_t i = 0; i < v.size();++i)
        if(toInsert < v[i])
            return i;
        return v.size();

}
int main()
{   //vector 可以存储一系列数据(结构体也可以)，但必须是同种类型
    vector<int> values;//储存int类型
    cout<<"第一种" <<"\n"<< "请输入数";
    for(int i = 0; i < Num;++i)
    {
        int val;
        cin >> val;
        values.push_back(val);//push_back函数添加数据到vector末尾

    }
    SelectionSort(values);
    PrintList(values);
    vector<string> valuess;
    cout<< "第二种" << "请输入字符串";
    for(int i = 0; i < Num;++i)
    {   string vals;
        cin>>vals;
        valuess.insert(valuess.begin() + InsertionIndex(valuess,vals),vals);
    }
    PrintList(valuess);
    return 0;
}
