#include<iostream>
#include<string>
#include<vector>
using namespace std;
//size_t�Ǹ�����
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
{   //vector ���Դ洢һϵ������(�ṹ��Ҳ����)����������ͬ������
    vector<int> values;//����int����
    for(int i = 0; i < 10;++i)
    {
        cout << "��������";
        int val;
        cin >> val;
        values.push_back(val);//push_back����������ݵ�vectorĩβ

    }
    SelectionSort(values);
    for(size_t i = 0;i<10;++i)
    {
        cout<< values[i]<<endl;
    }

    return 0;
}
