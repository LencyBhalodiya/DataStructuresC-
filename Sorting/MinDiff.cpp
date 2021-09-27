#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

int minDiff(int arr[],int n)
{
    // Naive solution
    int res = INT_MAX;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        res = min(res,abs(arr[i]-arr[j]));
    }
    return res;
}
int minDifference(int arr[],int n)
{
  int res = INT_MAX;
  sort(arr,arr+n);
  for(int i=1;i<n;i++)
  {
     res = min(res,abs(arr[i]-arr[i-1]));
    //  cout<<res<<" ";
  }
  return res;
}

void printarray(int arr[],int n){
    for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
}
int main()
{
    int arr[]={23,15,2,9,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<minDifference(arr,n);
    // printarray(arr,n);
}