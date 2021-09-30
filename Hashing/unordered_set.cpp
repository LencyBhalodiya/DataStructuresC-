#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
    // in unordered set if can onlyy add unique elements not include duplicates bcoz it will ignore the duplicates
    unordered_set<int> s;
    s.insert(4);
    s.insert(42);
    s.insert(46);
    s.insert(46);//this will get ignored

    for(auto it = s.begin(); it!= s.end();it++)
    cout<<(*it)<<" ";
    cout<<endl;
    cout<<s.size()<<endl;
    // s.clear();
    s.size();
    cout<<s.size()<<endl;
    
    // finding an element
    if(s.find(4) == s.end())
    cout<<"not found"<<endl;
    else 
     cout<<"found"<<endl;

    // erase an element
    s.erase(42);
    cout<<s.size()<<endl;
    auto i = s.find(4);
    s.erase(i);
    cout<<s.size()<<endl;
}