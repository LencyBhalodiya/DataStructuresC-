#include<bits/stdc++.h>
using namespace std;
// sort the array where the element can move up to i+k to i-k range

void klargest(int arr[],int k,int n)
{
  priority_queue<int,vector<int>,greater<int>> p;
  for(int i=0;i<k;i++)
  {
      p.push(arr[i]);
  }
  for(int i = k ; i<n ; i++)
  {
      if(arr[i] > p.top()){
        p.pop();
        p.push(arr[i]);
      }
  }
  while(p.empty() == false)
   {
       cout<<p.top()<<" ";
       p.pop();
   }
}
int main()
{
    int arr[]= {5,15,10,20,8,25,18};
    int n = sizeof(arr)/sizeof(arr[0]);
    klargest(arr,3,n);
  
    return 0;
}