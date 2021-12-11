#include<bits/stdc++.h>
using namespace std;
//find the max sum from the array where you cannot take the consecutive numbers while suming
int maxSum(int arr[],int n)
{
    if(n == 1) 
    return arr[0];
    else if(n == 2) 
     return max(arr[0],arr[1]);
     else
     return max(maxSum(arr,n-1),maxSum(arr,n-2)+arr[n-1]);
}
int maxSumDynamic(int arr[],int n)
{
    int dp[n];
    if(n == 1) return 0;
    dp[1] = arr[0];
    dp[2] = max(arr[0],arr[1]);

    for(int i =3 ; i<= n ; i++)
     dp[i] = max(dp[i-1],dp[i-2]+dp[i-1]);
     return dp[n];
}
int maxSumOptimizeDynamic(int arr[],int n)
{
    if(n ==1 ) return arr[0];
    int prev_prev = arr[0];
    int prev = max(arr[0],arr[1]);
    int res = prev;
    for(int i = 3 ; i <=n ; i++)
    {
        res = max(prev,prev_prev+arr[i-1]);
        prev_prev = prev;
        prev = res;
    }
    return res;
}
int main()
{
    int arr[] = {0,5,15,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxSumOptimizeDynamic(arr,n);
    return 0;
}