#include<iostream>
using namespace std;
//find the subset of the given array whose sum is equal to the given sum
int countSUM(int arr[],int n , int sum)
{
    if(n == 0) 
    return (sum == 0)?1:0;
    return countSUM(arr,n-1,sum) + countSUM(arr,n-1,sum-arr[n-1]);
}
int countSUMDynamic(int arr[],int n ,int sum)
{
    int dp[n+1][sum+1];
    for(int i = 0 ; i <= n ; i++)
     dp[i][0] = 1;
     for(int j = 1 ; j <= sum ; j++)
     dp[0][j] = 0;

     for(int i = 1; i<=n ; i++)
     {
         for(int j = 1 ; j <= sum ; j++)
         {
             if(j < arr[i-1])
              dp[i][j] = dp[i-1][j];
              else
              dp[i][j] = dp[i-1][j] + dp[i][j-arr[i-1]];
         }
     }
     return dp[n][sum];
}
int main()
{
    int arr[]= {2,3,4,6,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<countSUMDynamic(arr,n,5);
    return 0;
}