#include<bits/stdc++.h>
using namespace std;
// find the no of insertion and deletion to make to convert string 1 into string 2

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
    string s1 = "lency";
    string s2 = "yonc";
    int n  = s1.size();
    int m = s2.size();
    int k = tabulation(s1,s2);
    int ans = (n-k) + (m-k);
    cout<<ans;
    return 0;
}