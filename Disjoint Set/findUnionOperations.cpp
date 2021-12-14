#include<bits/stdc++.h>
using namespace std;
// find the union of the disjoint set
const int n =5;
int parent[n];
void initialize()
{
    for(int i = 0 ; i < n ;i++)
     parent[i] = i;
}
int find(int x)
{
    if(parent[x] == x)
     return x;
     else 
      return find(parent[x]);
}
void unionn(int x , int y)
{
    int x_rep = find(x);
    int y_rep = find(y);
    if(x_rep == y_rep)
     return;
     parent[y_rep] = x_rep;
}
int main()
{
    initialize();
    unionn(1,2);
    cout<<find(2);
     return 0;
}