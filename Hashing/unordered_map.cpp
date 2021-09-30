#include<iostream>
#include<unordered_map>
using namespace std;

 int main()
 {
     unordered_map<string,int> m;
     m["gfg"] = 20;
     m.insert({"courses",15});
    //  for(auto x:m)
    //    cout<<x.first<<endl;
    // search
    if(m.find("gfg")!= m.end())
    cout<<"found"<<endl;
    else
    cout<<"not found";
    for(auto i = m.begin();i!=m.end();i++)
    {
      cout<<i->first<<" "<<i->second<<" ";
    }
    // search another method
    if(m.count("gfg")>0)
    cout<<"found";
    else 
    cout<<"not found";
    return 0;
 }