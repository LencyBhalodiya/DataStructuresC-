#include<bits/stdc++.h>
using namespace std;
// find the max price to sell after cutting rod rodlength times 

int solve(vector<int> &arr , int index , int N, vector<vector<int>> &dp)
{
    if(index == 0)
     return N*arr[0];

    if(dp[index][N] != -1)
     return dp[index][N];

    int notTake = 0 + solve(arr,index - 1, N,dp);
    int take = INT_MIN;
    int rodlength = index + 1;

    if(rodlength <= N)
    take = solve(arr, index , N - rodlength,dp) + arr[index];

    return dp[index][N] = max(take,notTake);
}
int tabulation(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    
    for(int i = 0 ; i <= n ; i++)
     dp[0][i] = i*arr[0];

     for(int ind = 1 ; ind < n ; ind++){
        for(int N = 0 ; N <= n ; N++){
           int notTake = 0 + dp[ind-1][N];
            int take = INT_MIN;
            int rodlength = ind + 1;

            if(rodlength <= N)
            take = dp[ind][N - rodlength] + arr[ind];

             dp[ind][N] = max(take,notTake);
        }
     }
     return dp[n-1][n];
}
int main()
{
    vector<int> arr = {2,5,7,8,10};
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    cout<<solve(arr,n-1,n,dp)<<endl;
    cout<<tabulation(arr);
    return 0;
}