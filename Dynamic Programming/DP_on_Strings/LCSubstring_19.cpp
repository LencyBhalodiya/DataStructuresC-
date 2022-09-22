#include<bits/stdc++.h>
using namespace std;
//find the largest common substring
int tabulation(string s1 ,string s2)
{
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n+1,vector<int>(m+1, -1));
   
    for(int i = 0 ; i <= n ; i++)
     dp[0][i]  = 0;
     for(int i = 0 ; i <= m ; i++)
     dp[i][0]  = 0;
     
     int ans = 0;

    for(int ind1 = 1 ; ind1 <= n ; ind1++){
        for(int ind2 = 1 ; ind2 <= m ; ind2++)
        {
            if(s1[ind1-1] == s2[ind2-1]){
             dp[ind1][ind2] = 1 + dp[ind1-1][ind2 -1];
             ans = max(ans,dp[ind1][ind2]);
            }
            else
             dp[ind1][ind2] = 0 ;
        }
    }
    return ans;
}
int main()
{
     string s1 = "abcde";
    string s2 =  "aecde";
    int n  = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n , vector<int> (m,-1));
    cout<<tabulation(s1,s2);
    return 0;
}