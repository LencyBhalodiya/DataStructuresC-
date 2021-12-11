#include<bits/stdc++.h>
using namespace std;
//find the number of possible ways in which change can be given 
int getCountRec(int coins[] , int n , int sum)
{
    if(sum == 0) return 1;
    if(n == 0) return 0;

    int res = getCountRec(coins,n-1,sum);
    if(coins[n-1] <= sum)
     res = res+getCountRec(coins,n,sum-coins[n-1]);

     return res;
}

int getCount(int index,int coin[] , int n , int sum,int dp[100][100])
{
   if(sum == 0) return 1;
   if(index >= n || sum < 0) return 0;
   if(dp[index][sum]!= -1)
    return dp[index][sum];
   int left = getCount(index,coin,n,sum-coin[index],dp);
   int right = getCount(index+1,coin,n,sum,dp);
   return dp[index][sum] = left + right;
}
int main()
{
    int arr[] = {2,3,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
     int dp[100][100]; 
    memset(dp,-1,sizeof(dp));
    cout<<getCount(0,arr,n,10,dp)<<endl;
    cout<<getCountRec(arr,n,10);
  return 0;
  }