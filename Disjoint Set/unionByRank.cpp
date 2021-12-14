#include<bits/stdc++.h>
using namespace std;
// find the union of the disjoint set by rank
const int n =5;
int parent[n],rankk[n];
void initialize()
{
    for(int i = 0 ; i < n ;i++){
     parent[i] = i;
     rankk[i] = 0;
    }
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
     if(rankk[x_rep] < rankk[y_rep]){
         parent[x_rep] = y_rep;
     }else if(rankk[x_rep] > rankk[y_rep]){
         parent[y_rep] = x_rep;
     }else{
         parent[y_rep] = x_rep;
         rankk[x_rep]++;
     }
     
}
int main()
{
    initialize();
    unionn(1,2);
    unionn(2,4);
    cout<<find(4);
     return 0;
}