#include<iostream>
#include<climits>
using namespace std;
//matrix chain multiplication find the minum multiplication
int mchain(int arr[],int i , int j)
{
    if(i+1 == j) return 0;
    int res  = INT_MAX;
    for(int k = i+1 ; k < j ; k++)
    {
        res = min(res, mchain(arr,i,k) + mchain(arr,k,j)+arr[i]*arr[k]*arr[j]);
    }
    return res;
}
int mChainDynamic(int arr[],int n)
{
    int dp[n][n];
    for(int i = 0 ; i < n-1; i++)
    dp[i][i+1] = 0;
    for(int gap =2; gap < n; gap++)
     {
         for(int i = 0 ; i+gap < n; i++)
         {
             int j = i+gap;
             dp[i][j] = INT_MAX;
             for(int k = i+1 ; k < j; k++)
             {
                 dp[i][j] = min(dp[i][j],dp[i][k] + dp[j][k] + arr[i]*arr[k]*arr[j]);
             }
         }
     }
     return dp[0][n-1];
}
int main()
{
    int arr[]= {20,10,30,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<mChainDynamic(arr,n);
    return 0;
}