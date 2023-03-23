#include<iostream>
#include<vector>
#include<cstdlib>//rand srand
#include<time.h>
#include<set>
#include<string>
using namespace std;
const size_t NumInterations = 10000;//����ʵ�����
//������ʵ������������һ���ĸ���
//ģ������
int DieRoll()
{
    return (rand() % 6) + 1;
}
//ģ��һ��ʵ��
size_t RunProcess()
{

    vector<int> generated;
    while(true)
    {
    int NextValue = DieRoll();
    for(size_t i = 0; i<generated.size();++i){
        if(generated[i] == NextValue)
            return generated.size()+1;
    }
    generated.push_back(NextValue);//�������ͬ�ͼ�������
    }

}
//��setʵ��  set�ڵ�Ԫ��û��˳�������Ԫ��ʱֻ��insert��һ�ַ�ʽ�������ж�Ԫ�ص�λ�õ��ǿ�����count�ж�Ԫ���Ƿ����
//set Ԫ�ز������ظ� Ԫ�ز����ǽṹ��
//ɾ��Ԫ����erase  ���е�ɾ����clear Ԫ�ظ�����size
//set����copy��һ��set set<int> otherset = aset
//set<int> cpset(orset.begin(),orset.end());//copy��һ��set�е�
size_t setRunProcess()
{

    set<int> generated;
    while(true)
    {
    int NextValue = DieRoll();
        if(generated.count(NextValue)) return generated.size()+1;
    generated.insert(NextValue);//�������ͬ�ͼ�������
    }

}
int main()
{   srand(static_cast<unsigned>(time(NULL)));
    size_t total1=0;//�ܵĴ���
    size_t total2=0;
    for(int k = 0; k <  NumInterations;++k)
        {   total1 += RunProcess();
            total2 += setRunProcess();
        }
    cout<<"������ͬ�ĵ�����Ҫ��ƽ�������ǣ�"<<endl<<double(total1)/NumInterations<<endl<<double(total2)/NumInterations<<endl;
    //iterator
    vector<int> testVector(10,7);
    for(vector<int>::iterator itr = testVector.begin();itr != testVector.end();++itr)
        cout<< *itr << "\t";
    cout<<endl;
    //set ��iterator
    set<int> randomnum;
    for(size_t k = 0; k<10;++k )
        randomnum.insert(rand());
    for(set<int>::iterator itr = randomnum.begin();itr != randomnum.end();++itr)
        cout << *itr << "\t";
    cout<<endl;
    //��iterator��д��Ԫ��
    vector<string> svector(10);
    for(vector<string>::iterator itr = svector.begin();itr != svector.end();++itr)
        *itr = "hhh";
    for(vector<string>::iterator itr = svector.begin();itr != svector.end();++itr)
        cout<<*itr<<'('<<itr->length()<<')'<<"\t";//��itr->length����ʾ�ַ����ĳ���
    cout << endl;
    //ͨ������������ĵ����������Ա�д���κ�����������ݽ��в����ĺ�������Щ������Ϊ STL �㷨
    //set iterator�е�upper_bound��lower_bound  [lower, upper]
    set<int>::iterator first = randomnum.lower_bound(5000);
    set<int>::iterator last = randomnum.upper_bound(20000);
    for(set<int>::iterator itr = first;itr != last;++itr)
        cout<<*itr<<"\t";
    cout<<endl;
    return 0;
}
