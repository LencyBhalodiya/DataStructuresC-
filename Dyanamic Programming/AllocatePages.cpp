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
int allocatePagesDynamic(int arr[],int n ,int k){
    int dp[k+1][n+1];
    for(int i = 1; i <=n ; i++)
     dp[1][i]  = sum(arr,0,i-1);
     for(int i = 1 ; i<=k ; i++)
      dp[i][1] = arr[0];

      for(int i = 2 ; i<=k ; i++)
      {
          for(int j = 2 ; j <= n ; j++)
          {
              int res = INT_MAX;
              for(int p =1 ; p < j ; p++)
              {
                  res = min(res,max(dp[i-1][p],sum(arr,p,j-1)));
              }
              dp[i][j] = res;
          }
      }
      return dp[k][n];
}

int main()
{
    int k=2;
  int arr[]={5,3,5,7,2};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<pages(arr,n,k);
}