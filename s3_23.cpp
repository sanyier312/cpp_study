#include<iostream>
#include<vector>
#include<cstdlib>//rand srand
#include<time.h>
#include<set>
#include<string>
using namespace std;
const size_t NumInterations = 10000;//定义实验次数
//掷骰子实验求掷出两个一样的概率
//模拟骰子
int DieRoll()
{
    return (rand() % 6) + 1;
}
//模拟一次实验
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
    generated.push_back(NextValue);//如果不相同就加入容器
    }

}
//用set实现  set内的元素没有顺序，在添加元素时只有insert这一种方式，不能判断元素的位置但是可以用count判断元素是否存在
//set 元素不允许重复 元素不能是结构体
//删除元素用erase  所有的删除用clear 元素个数用size
//set可以copy另一个set set<int> otherset = aset
//set<int> cpset(orset.begin(),orset.end());//copy另一个set中的
size_t setRunProcess()
{

    set<int> generated;
    while(true)
    {
    int NextValue = DieRoll();
        if(generated.count(NextValue)) return generated.size()+1;
    generated.insert(NextValue);//如果不相同就加入容器
    }

}
int main()
{   srand(static_cast<unsigned>(time(NULL)));
    size_t total1=0;//总的次数
    size_t total2=0;
    for(int k = 0; k <  NumInterations;++k)
        {   total1 += RunProcess();
            total2 += setRunProcess();
        }
    cout<<"掷到相同的点数需要的平均次数是："<<endl<<double(total1)/NumInterations<<endl<<double(total2)/NumInterations<<endl;
    //iterator
    vector<int> testVector(10,7);
    for(vector<int>::iterator itr = testVector.begin();itr != testVector.end();++itr)
        cout<< *itr << "\t";
    cout<<endl;
    //set 用iterator
    set<int> randomnum;
    for(size_t k = 0; k<10;++k )
        randomnum.insert(rand());
    for(set<int>::iterator itr = randomnum.begin();itr != randomnum.end();++itr)
        cout << *itr << "\t";
    cout<<endl;
    //用iterator来写入元素
    vector<string> svector(10);
    for(vector<string>::iterator itr = svector.begin();itr != svector.end();++itr)
        *itr = "hhh";
    for(vector<string>::iterator itr = svector.begin();itr != svector.end();++itr)
        cout<<*itr<<'('<<itr->length()<<')'<<"\t";//用itr->length来表示字符串的长度
    cout << endl;
    //通过操作容器类的迭代器，可以编写对任何容器类的数据进行操作的函数。这些函数称为 STL 算法
    //set iterator中的upper_bound和lower_bound  [lower, upper]
    set<int>::iterator first = randomnum.lower_bound(5000);
    set<int>::iterator last = randomnum.upper_bound(20000);
    for(set<int>::iterator itr = first;itr != last;++itr)
        cout<<*itr<<"\t";
    cout<<endl;
    return 0;
}
