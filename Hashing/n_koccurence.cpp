#include<iostream>
#include<unordered_map>
#include <algorithm>
using namespace std;
// find the elements in array which occurs more than n/k times
void printnk(int arr[],int n,int k)
{
    sort(arr,arr+n);
    int i = 1;
    int count = 1;
    while(i<n)
    {
        while( arr[i]=arr[i-1])
        {
            count++;
            i++;
        }
        if(count >n/k)
         cout<<arr[i-1]<<" ";
         count  =1;
         i++;
    }
}
void printnbyk(int arr[],int n,int k)
{
    unordered_map<int,int> m ;
    for(int i=0;i<n;i++)
      m[arr[i]]++;
      for(auto e: m)
      {
          if(e.second > n/k)
          cout<<e.first<<" ";
      }
}
int main()
{
  int  arr[]=  {1,2,3,1,2,3,4,5,6,1,2};
  int n = sizeof(arr)/sizeof(arr[0]);
  printnbyk(arr,n,4);
   return 0;
}