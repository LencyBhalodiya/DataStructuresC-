#include<bits/stdc++.h>
using namespace std;
// minimum coins for change if coins are infinte supply

int solve(vector<int> &arr, int index , int target,vector<vector<int>> &dp)
{
    if(target == 0) return 0;
    if(target < 0 || index < 0)
        return 1e9;

    if(dp[index][target] != -1)
     return dp[index][target];

    int notTake = 0 + solve(arr,index-1,target,dp);
     int take = 1 + solve(arr, index , target - arr[index],dp);

    dp[index][target] =  min(take,notTake);
    return dp[index][target];
}
int tabulation(vector<int> arr, int target)
{
   int n = arr.size();
   vector<vector<int>> dp(n+1,vector<int>(target + 1 , -1));

        for(int i=0;i<=n;++i)
        {
            for(int j=0;j<=target;++j)
            {
                if(j==0)
                    dp[i][j] = 0;
                else if(i==0)
                    dp[i][j] = 1e5;
                else if(arr[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = min(1 + dp[i][j-arr[i-1]], dp[i-1][j]);
            }
        }
        return dp[n][target]>1e4 ? -1:dp[n][target];
}
int main()
{
    vector<int> arr = {2,3,5,6};
    int n = arr.size();
    int target = 10;
     vector<vector<int>> dp(n,vector<int>(target + 1 , -1));
    cout<<solve(arr,n-1,target,dp)<<endl;
    cout<<tabulation(arr,target);
    return 0;
}