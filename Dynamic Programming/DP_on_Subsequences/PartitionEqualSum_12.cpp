#include<bits/stdc++.h>
using namespace std;
//check whether the array can be partition in such a way that each side contains same sum
bool solve(vector<int> arr, int n,int target,vector<vector<int>> &dp)
{
  if(target == 0) return true;
  if( n == 0)
   return target == arr[0];
   
   if(dp[n][target]!= -1)
    return dp[n][target];

  int notTake = solve(arr,n-1,target,dp);
  int take = false;
  if(arr[n] <= target)
   take = solve(arr,n-1,target- arr[n],dp);
  
  int ans = take||notTake;

  return dp[n][target]=ans;
}
bool check(vector<int> arr)
{
     int sum = 0;
    for(auto i: arr) // find the array total sum
     sum+= i;
    int n = arr.size();

    if(sum % 2 != 0) return false ;// if sum is odd then equal partition isn't possible
    vector<vector<int>> dp(n,vector<int>((sum/2)+1,-1));
    return solve(arr,n-1,sum/2,dp);
}
int main()
{
    vector<int> arr = {1,2,3,2,2,2};
 
   if(check(arr))
    cout<<"yes";
    else
    cout<<"No";
    return 0;
}