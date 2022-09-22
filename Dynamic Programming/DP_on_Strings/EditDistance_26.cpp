#include<bits/stdc++.h>
using namespace std;
//use insert delete and replace operation and find min operation to convert s1 into s2

int solve(string s1, string s2, int i , int j,vector<vector<int>> &dp)
{
    if(i < 0) return j + 1; // if string 1 gets finish then insert j+1 element
    if(j < 0) return i + 1; //if string 2 get finish then delete s1 remaing elements
    if(dp[i][j] != -1)
     return dp[i][j];
     
   if(s1[i] == s2[j])
    return solve(s1,s2,i-1,j-1,dp);
   
    int del = 1 + solve(s1,s2, i-1,j,dp); // delete
    int insert = 1 + solve(s1,s2,i,j-1,dp); // insert
    int replace = 1 + solve(s1,s2,i-1,j-1,dp); // replace
    
    return dp[i][j] = min(del,min(insert,replace));
}
int tabulation(string& S1, string& S2){
    
    int n = S1.size();
    int m = S2.size();
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int i=0;i<=n;i++){
        dp[i][0] = i;
    }
    for(int j=0;j<=m;j++){
        dp[0][j] = j;
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(S1[i-1]==S2[j-1])
                dp[i][j] = 0+dp[i-1][j-1];
            
            else dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
        }
    }
    
    return dp[n][m];
    
}
int main()
{
    string s1 = "whgtdwhgtdg";
    string s2 = "aswcfg";
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n,vector<int> (m,-1));
    cout<<solve(s1,s2,n-1,m-1,dp)<<endl;
    cout<<tabulation(s1,s2);
    return 0;
}