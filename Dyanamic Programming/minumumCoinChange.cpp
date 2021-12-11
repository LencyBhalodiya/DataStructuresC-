#include<bits/stdc++.h>
using namespace std;
//find the minimum coins to give the change
int getMin(int coins[],int n , int val)
{
    if(val == 0) return 0;
    int res = INT_MAX;
    for(int i =0 ; i < n ; i++)
    {
        int subres;
        if(coins[i] <= val)
         subres = getMin(coins,n,val-coins[i]);
        if(subres!=INT_MAX)
        res = min(res,subres+1);
    }
    return res;
}
int getMinDynamic(int arr[],int n , int val)
{
  int dp[val+1];
  dp[0] = 0;

//  for(int i = 0 ; i<=val ; i++)
//     dp[i] = INT_MAX;

  for(int i = 1 ; i<=val ; i++)
  {
      for(int j =0; j < n ; j++)
      {
          if(arr[j] <= i){
           int subres = dp[i-arr[j]];
           if(subres != INT_MAX)
           dp[i] = min(dp[i],subres+1);
          }
      }
  }
  return dp[val];
}
int main()
{
    int arr[] = {15,10,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<getMinDynamic(arr,n,25);
    return 0;
}