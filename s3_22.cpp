#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int Num = 5;
//size_t�Ǹ�����
//��һ��ʵ�֣�ͨ���ӵ�һ����ʼ���������Сֵ������Сֵ������ǰ��
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
//�ڶ���ʵ�� ������ʱ�͵���˳���λ��
size_t InsertionIndex(vector<string>& v ,string toInsert)
{
    for(size_t i = 0; i < v.size();++i)
        if(toInsert < v[i])
            return i;
        return v.size();

}
int main()
{   //vector ���Դ洢һϵ������(�ṹ��Ҳ����)����������ͬ������
    vector<int> values;//����int����
    cout<<"��һ��" <<"\n"<< "��������";
    for(int i = 0; i < Num;++i)
    {
        int val;
        cin >> val;
        values.push_back(val);//push_back����������ݵ�vectorĩβ

    }
    SelectionSort(values);
    PrintList(values);
    vector<string> valuess;
    cout<< "�ڶ���" << "�������ַ���";
    for(int i = 0; i < Num;++i)
    {   string vals;
        cin>>vals;
        valuess.insert(valuess.begin() + InsertionIndex(valuess,vals),vals);
    }
    PrintList(valuess);
    return 0;
}
