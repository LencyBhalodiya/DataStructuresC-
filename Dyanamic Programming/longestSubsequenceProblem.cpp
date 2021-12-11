#include<bits/stdc++.h>
using namespace std;
// find the longest subseequence problem using top dowm approach or memoization
const int maximum = 16;

int lcs(string str1,string str2,int m,int n,int memo[][maximum])
{
   if(memo[m][n] != -1)
    return memo[m][n];

    if(m==0 || n == 0)
      memo[m][n] = 0;
  else{
    if(str1[m-1] == str2[n-1])
     memo[m][n] = 1 + lcs(str1,str2,m-1,n-1,memo);
     else
     memo[m][n] = max(lcs(str1,str2,m-1,n,memo),lcs(str1,str2,m,n-1,memo));
  }
   return memo[m][n];
}
//method 2 solving based on the tabular method
int lcsTabular(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    int dp[m+1][n+1];

    for(int i = 0 ; i <= m ; i++)
     dp[i][0] = 0;
    for(int j = 0 ; j<=n ; j++)
     dp[0][j] = 0;
     
     for(int i = 1 ; i<=m ; i++)
     {
         for(int j = 1 ; j<=n ; j++)
         {
             if(s1[i-1] == s2[j-1])
              dp[i][j] = 1+dp[i-1][j-1];
              else
              dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
         }
     }
     return dp[m][n];
}

int main()
{
    string a = "abcde";
    string b = "badaa";
    int m = a.length();
    int n = b.length();
    int memo[m+1][maximum]; //define 2d array of size m+1,n+1 and initialize to -1
    memset(memo,-1,sizeof(memo));
 
    cout<<lcsTabular(a,b);
    
    return 0;
}