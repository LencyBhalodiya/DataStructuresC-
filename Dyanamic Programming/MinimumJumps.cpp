#include<bits/stdc++.h>
using namespace std;
//find the minimum jumps to reach the end of the array
int minJumps(int arr[],int n)
{
    if(n==1) return 0;
    int res = INT_MAX;
    for(int i = 0 ; i <= n-2; i++)
    {
        if(i + arr[i] >= n-1)
        {
            int subres = minJumps(arr,i+1);
            if(subres != INT_MAX)
             res = min(res,subres+1);
        }
    }
    return res;
}
int minJumpsDynamic(int arr[],int n)
{
    int dp[n];
    dp[0] = 0;
    for(int i =1 ; i<n ;i++)
     dp[i] = INT_MAX;

     for(int i = 1 ; i<n ;i++ )
     {
         for(int j = 0 ; j<i ;j++)
         {
             if(arr[j]+j >= i){
                 if(dp[j]!= INT_MAX)
                  dp[i] = min(dp[i],dp[j]+1);
             }
         }
     }
     return dp[n-1];
}
int main()
{
    int arr[] = {3,5,2,1,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<minJumpsDynamic(arr,n);
}
