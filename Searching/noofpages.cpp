#include<iostream>
using namespace std;
#include<limits.h>
// find the no of pages a student can read which should be minimum and should read every book int an given array in an contious manner
int sum(int arr[],int b,int e)
{
    int summ=0;
    for(int i=b;i<=e;i++)
    {
        summ+=arr[i];
    }
    return summ;
}
int pages(int arr[],int n,int k)
{
  if(k==1)
  return sum(arr,0,n-1);
  if(n==1)
  return arr[0];
  
  int res=INT_MAX;
  for(int i=1;i<n;i++)
  {
    res = min(res,max(pages(arr,i,k-1),sum(arr,i,n-1)));
  }
  return res;
}

int main()
{
    int k=2;
  int arr[]={5,3,5,7,2};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<pages(arr,n,k);
}