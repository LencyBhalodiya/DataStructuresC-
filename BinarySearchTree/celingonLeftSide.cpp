#include<bits/stdc++.h>
using namespace std;
// traverse the array from left and find the nearest highest
void printCeiling(int arr[],int n)
{
    cout<<"-1 ";
    set<int> s;
    s.insert(arr[0]);
    for(int i =1 ; i<n ; i++)
    {
     auto it = s.lower_bound(arr[i]);
     if(it != s.end())
     cout<<(*it)<<" ";
     else 
     cout<<"-1 ";
     s.insert(arr[i]);
    }
}
int main()
{
    int arr[]= {2,8,30,15,25,12,3,66};
    int n =  sizeof(arr)/sizeof(arr[0]);
    printCeiling(arr,n);
    return 0;
}