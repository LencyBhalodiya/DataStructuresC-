#include<bits/stdc++.h>
using namespace std;

int main()
{
    // follow the read black tree
    map<int,int> m;
    map<string,greater<int>> t; // decrease order
    m.insert({10,200});
    m[5] = 100; // another way of insertion 
    m.insert({3,300});
    m.insert({3,340}); //ignore the repeated key
    m[10] = 134; // value of 10 is been updated
    m.at(10) = 134; // does same  has previous throws exception if key isn't present
    for(auto &it : m)
    cout<<it.first<<" "<<it.second<<endl;

    // findning the element
    if(m.count(3) == 0)
    cout<<"Not found";
    else 
     cout<<"found";
    return 0;
}