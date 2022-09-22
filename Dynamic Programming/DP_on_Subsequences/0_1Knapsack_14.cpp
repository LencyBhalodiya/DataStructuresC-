#include<bits/stdc++.h>
using namespace std;
//find the maximum value you can get or fit in mybag with max weight of x

int solve(vector<int> W , vector<int> value , int mybag , int index,vector<vector<int>> &dp)
{
    if(index == 0)
    {
        if(W[index] <= mybag)
         return value[index];
         else
         return 0;
    }
    if(dp[index][mybag] != -1)
     return dp[index][mybag];

    int notTake = solve(W,value,mybag,index-1,dp) + 0;
    int take = INT_MIN;
    if(W[index] <= mybag)
    take = solve(W,value,mybag - W[index],index - 1,dp) + value[index];

    return dp[index][mybag] = max(take,notTake);
}
int main()
{
    vector<int> weight = {2,3,5};
    vector<int> value = {10,20,60};
    int mybag = 8;
    int n = weight.size();
    vector<vector<int>> dp(n,vector<int>(mybag,-1));
    cout<<solve(weight,value,mybag,n-1,dp);

    return 0;
}