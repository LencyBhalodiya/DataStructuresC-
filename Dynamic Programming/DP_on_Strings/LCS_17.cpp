#include<bits/stdc++.h>
using namespace std;
//find the longest common subsequence from two strings

int solve(string s1, string s2, int ind1 , int ind2, vector<vector<int>> &dp)
{
    if(ind1 < 0 || ind2 < 0)
     return 0;

 if(dp[ind1][ind2] != -1)
  return dp[ind1][ind2];

  if(s1[ind1] == s2[ind2])
   return dp[ind1][ind2] = 1 + solve(s1,s2,ind1-1, ind2-1,dp);

   return dp[ind1][ind2] =  0 + max(solve(s1,s2,ind1-1,ind2,dp),solve(s1,s2,ind1,ind2-1,dp));
}
int tabulation(string s1 ,string s2)
{
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n+1,vector<int>(m+1, -1));
   
    for(int i = 0 ; i <= n ; i++)
     dp[i][0]  = 0;
     for(int i = 0 ; i <= m ; i++)
     dp[0][i]  = 0;

    for(int ind1 = 1 ; ind1 <= n ; ind1++){
        for(int ind2 = 1 ; ind2 <= m ; ind2++)
        {
            if(s1[ind1-1] == s2[ind2-1])
             dp[ind1][ind2] = 1 + dp[ind1-1][ind2 -1];
            else
             dp[ind1][ind2] = 0 + max(dp[ind1][ind2-1],dp[ind1-1][ind2]);
        }
    }
    return dp[n][m];
}
int main()
{
    string s1 = "abcde";
    string s2 =  "abede";
    int n  = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n , vector<int> (m,-1));
    cout<<solve(s1,s2,n-1,m-1,dp)<<endl;
    cout<<tabulation(s1,s2);
    return 0;
}