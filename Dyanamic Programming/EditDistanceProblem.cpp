#include<bits/stdc++.h>
using namespace std;
//find the number of changes to make in the two string to make them same
int distance(string s1, string s2, int m , int n)
{
    if(m == 0) return n;
    if(n == 0) return m;
    if(s1[m-1] == s2[n-1])
     return distance(s1,s2,m-1,n-1);
     else{
         return 1 + min({distance(s1,s2,m,n-1),distance(s1,s2,m-1,n),distance(s1,s2,m-1,n-1)});
         //c-1 insert the last chararcter
         //c-2 delete the m last chararcter
         //c-3 replace the character
     }   
}
int dynamicMethod(string s1, string s2, int m , int n)
{
    int dp[m+1][n+1];
    
    for(int i = 0 ; i <= m ; i++)
     dp[i][0] = i;
     for(int i = 0 ; i <= n ; i++)
     dp[0][i] = i;

     for(int i = 1 ; i <=m ; i++)
     {
         for(int j = 1; j<=n ; j++ )
         {
             if(s1[i-1] == s2[j-1])
              dp[i][j] = dp[i-1][j-1];
              else
              dp[i][j] = 1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
         }
     }
     return dp[m][n];
}
int main()
{
    string a = "geeks";
    string b = "geks";
    int m = a.length();
    int n = b.length();
     cout<<dynamicMethod(a,b,m,n);
    return 0;
}