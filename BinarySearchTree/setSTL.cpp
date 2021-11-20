#include<bits/stdc++.h>
using namespace std;
//  set using red black tree
 int main()
 {
     set<int> s; //defining the set used to store sorted  data
     set<int,greater<int>> t; //used to store element in decreasing order
     s.insert(10);
     s.insert(40);
     s.insert(1);
     s.insert(11);
     s.insert(11); // set ignores the duplicate value
     s.erase(1); // erase the  element in the set

    // traverse the set 
    // for(int x: s)
    // cout<<x<<" ";

    // another way of traversal
    for(auto it = s.begin(); it!=s.end(); it++)
    cout<<(*it)<<" "; 
    cout<<endl;

    //  find the element
    auto it = s.find(110);
    if(it == s.end())
     cout<<"Not found "<<endl;
     else
     cout<<"Found"<<endl;

    // lower and upper bound
    auto itt = s.lower_bound(10);
    if(itt != s.end())
    cout<<(*itt)<<" ";
    else 
    cout<<"given element is greater than the largest";
     return 0;
 }