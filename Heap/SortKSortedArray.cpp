#include<bits/stdc++.h>
using namespace std;
// sort the array where the element can move up to i+k to i-k range

void sortK(int arr[],int k,int n)
{
    priority_queue<int,vector<int>,greater<int>> p;

    for(int i = 0 ; i<= k ; i++)
     p.push(arr[i]);

     int index = 0;
     for(int i=k+1 ; i<n ; i++)
     {
         arr[index++] = p.top();
         p.pop();
         p.push(arr[i]);
     }
     while(p.empty() == false)
     {
         arr[index++] = p.top();
         p.pop();
     }
    //  time complexity 0(n)
}
int main()
{
    int arr[]= {9,8,7,18,19,17};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortK(arr,2,n);
  for(int i =0 ;i<n ; i++)
  cout<<arr[i]<<" ";
    return 0;
}