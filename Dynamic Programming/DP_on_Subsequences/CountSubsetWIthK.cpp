#include<bits/stdc++.h>
using namespace std;
//count total no of subset which is equal to sum k
int solve(vector<int> arr, int n, int k,vector<vector<int>> &dp)
{
    if(k == 0) return 1;
    if(n == 0){
        if(k == arr[0] )
        return 1;
        else 
        return 0;
    }
    if(dp[n][k] != -1)
     return dp[n][k];
    int notTake  = solve(arr,n-1,k,dp);
    int take = 0;
    if(arr[n] <= k)
     take = solve(arr,n-1,k - arr[n],dp);

     return dp[n][k] = take + notTake;
}
int tabulation(vector<int> arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int> (k+1,0));

    for(int i = 0 ; i < n ; i++)
     dp[i][0] = 1;
    if(arr[0] <= k)
     dp[0][arr[0]]= 1;

     for(int ind = 1; ind < n ; ind++)
     {
        for(int sum = 0; sum <= k ; sum++)
        {
            int notTake = dp[ind-1][sum];
            int take = 0;
            if(arr[ind] <= sum)
             take = dp[ind-1][sum - arr[ind]];

          dp[ind][sum]  = take + notTake;
        }
     }
       return dp[n-1][k];
}
int main()
{
    vector<int> arr = {1,2,3,2};
    int k = 4;
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int> (k+1,-1));
    cout<<solve(arr,n-1,k, dp)<<endl;
    cout<<tabulation(arr,k)<<endl;
    return 0;
}