#include<iostream>
#include<utility>
#include<map>
#include<string>
#include<fstream>
#include<set>
#include<cctype>//ispunct
#include<sstream>
using namespace std;
string Getline()
{

    string result;
    getline(cin,result);
    return result;

}
void OpenUserFile(ifstream& input)
{   while(true){
        cout<<"请输入要读取的文件名:";
        string filename = Getline();
        input.open(filename.c_str());
        if(input.is_open())  return;
        cout << "没有找到该文件" << endl;
        input.clear();
    }


}
string GetFileContents(ifstream& input){
    string result;
    string line;
    while(getline(input,line))
        result  += line + "\n";
    return result;
}
set<string> LoadKeyWords(){
    ifstream input("keywords.txt");
    set<string> result;
    string keyword;
    while(input >> keyword)
        result.insert(keyword);
    return result;
}
void Preprocessing(string& text)
{
    for(size_t i = 0; i<text.size();++i)
        if(ispunct(text[i]) && text[i] != '_')//ispunct函数判断是否是标点符号
            text[i] = ' ';
}
map<string,size_t> GenerateKeywordReport(string fileContents){
    set<string> keyword = LoadKeyWords();
    Preprocessing(fileContents);
    stringstream tokenizer;
    tokenizer << fileContents;
    map<string,size_t> result;
    string word;
    while(tokenizer >> word)
        if(keyword.count(word))
            ++ result[word];
    return result;
}
int main()
{    //pair
    pair<string,int> myPair = make_pair("林夕",312);
    cout<<myPair.first<<"\t"<<myPair.second<<endl;
    //map
    //map中的数据以键值对的形式存储，并且是无序的
    map<string, int> myMap;
    myMap["zero"] = 0;
    myMap["one"] = 1;
    myMap["two"] = 2;
    cout <<myMap["hhh"] <<endl;//如果不存在但是直接用回自动创建一个并赋0值
    //判断是否存在某个键
    map<string,int>::iterator itr = myMap.find("hhh");
    if(itr == myMap.end())
        cout << "该key不存在" <<endl;
    else
        cout << itr->first <<":"<<itr->second<<endl;
    myMap.erase("hhh");//删除该键值对  删除所有clear
    //map的键值唯一  map.size()  if(mymap.empty()) 迭代器中lower_bound upper_bound
    //map<int, string> myOtherMap = myMap;拷贝一个map
    //map<int,string> cpmap(mymap.begin(),mymap.end());
    //insert函数  mymap.insert(make_pair("hhh",312));
    ifstream input;
    OpenUserFile(input);
    map<string,size_t> report = GenerateKeywordReport(GetFileContents(input));
    for (map<string,size_t>::iterator itr = report.begin();itr != report.end();++itr )
        cout << "关键字"<<itr->first<<"出现了"<<itr->second << "次"<<endl;
    return 0;
}
