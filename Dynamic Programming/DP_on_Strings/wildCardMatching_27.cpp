#include<bits/stdc++.h>
using namespace std;
// find if is matching or not ? denotes it can match if any single character of s2
// * denotes it can match any sequence with length more than 0;
int solve(string &s1, string &s2, int i , int j)
{
   if(i < 0 && j < 0) return true;
   if(i < 0 && j >= 0) return false;
   if(i > 0 && j < 0){
    for(int j = 0 ; j <= i ; i++){
     if(s1[i] != '*')
      return false;
    }
    return false;
   }

   if(s1[i] == s2[j] || s1[i] == '?')
     return solve(s1,s2,i-1,j-1);
   else{
        if(s1[i] == '*')
        return solve(s1,s2,i-1,j) || solve(s1,s2,i,j-1);
        else
        return false;
   }
}
bool isAllStars(string & S1, int i) {

  // S1 is taken in 1-based indexing
  for (int j = 1; j <= i; j++) {
    if (S1[j - 1] != '*')
      return false;
  }
  return true;
}
bool tabulation(string & S1, string & S2) {

  int n = S1.size();
  int m = S2.size();

  vector < vector < bool >> dp(n + 1, vector < bool > (m, false));

  dp[0][0] = true;

  for (int j = 1; j <= m; j++) {
    dp[0][j] = false;
  }
  for (int i = 1; i <= n; i++) {
    dp[i][0] = isAllStars(S1, i);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {

      if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
        dp[i][j] = dp[i - 1][j - 1];

      else {
        if (S1[i - 1] == '*')
          dp[i][j] = dp[i - 1][j] || dp[i][j - 1];

        else dp[i][j] = false;
      }
    }
  }

  return dp[n][m];

}
int main()
{
    string s1 = "ab*cd";
    string s2 = "abecd";
    int n = s1.size();
    int m = s2.size();

    cout<< solve(s1,s2,n-1,m-1)<<endl;
    cout<<tabulation(s1,s2);
    return 0;
}