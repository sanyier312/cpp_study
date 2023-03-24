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
        cout<<"������Ҫ��ȡ���ļ���:";
        string filename = Getline();
        input.open(filename.c_str());
        if(input.is_open())  return;
        cout << "û���ҵ����ļ�" << endl;
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
        if(ispunct(text[i]) && text[i] != '_')//ispunct�����ж��Ƿ��Ǳ�����
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
    pair<string,int> myPair = make_pair("��Ϧ",312);
    cout<<myPair.first<<"\t"<<myPair.second<<endl;
    //map
    //map�е������Լ�ֵ�Ե���ʽ�洢�������������
    map<string, int> myMap;
    myMap["zero"] = 0;
    myMap["one"] = 1;
    myMap["two"] = 2;
    cout <<myMap["hhh"] <<endl;//��������ڵ���ֱ���û��Զ�����һ������0ֵ
    //�ж��Ƿ����ĳ����
    map<string,int>::iterator itr = myMap.find("hhh");
    if(itr == myMap.end())
        cout << "��key������" <<endl;
    else
        cout << itr->first <<":"<<itr->second<<endl;
    myMap.erase("hhh");//ɾ���ü�ֵ��  ɾ������clear
    //map�ļ�ֵΨһ  map.size()  if(mymap.empty()) ��������lower_bound upper_bound
    //map<int, string> myOtherMap = myMap;����һ��map
    //map<int,string> cpmap(mymap.begin(),mymap.end());
    //insert����  mymap.insert(make_pair("hhh",312));
    ifstream input;
    OpenUserFile(input);
    map<string,size_t> report = GenerateKeywordReport(GetFileContents(input));
    for (map<string,size_t>::iterator itr = report.begin();itr != report.end();++itr )
        cout << "�ؼ���"<<itr->first<<"������"<<itr->second << "��"<<endl;
    return 0;
}
