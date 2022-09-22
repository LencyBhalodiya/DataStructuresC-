#include<bits/stdc++.h>
using namespace std;
// find the minimum insertion to be done to make whole string palindromic
int tabulation(string s ,string s1)
{
  int n = s.length();
  vector<vector<int>> dp(n+1,vector<int> (n+1 , -1));
    
  for(int i = 0 ; i <= n ; i++){
      dp[0][i] = 0;
      dp[i][0] = 0;
   }
    
  for(int i = 1 ; i <= n ; i++)
  {
     for(int j = 1; j <= n ; j++)
     {
        if(s[i-1] == s1[j-1]) // since startting from 1 index
         dp[i][j] = 1 + dp[i-1][j-1];
       else 
         dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
     }  
   }
    return dp[n][n];    
}
int solve(string s)
{
    int n = s.length();
    string s2 = s;
    reverse(s2.begin(),s2.end());
    int ans = tabulation(s,s2);

    return n - ans;
}
int main()
{
    string s = "Codingninjas";
    cout<<solve(s);
    return 0;
}