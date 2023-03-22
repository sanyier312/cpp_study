#include<iostream>
#include<string>
#include<vector>
using namespace std;
//size_t非负整数
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
int main()
{   //vector 可以存储一系列数据(结构体也可以)，但必须是同种类型
    vector<int> values;//储存int类型
    for(int i = 0; i < 10;++i)
    {
        cout << "请输入数";
        int val;
        cin >> val;
        values.push_back(val);//push_back函数添加数据到vector末尾

    }
    SelectionSort(values);
    for(size_t i = 0;i<10;++i)
    {
        cout<< values[i]<<endl;
    }

    return 0;
}
