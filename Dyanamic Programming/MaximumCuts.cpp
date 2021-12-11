#include<bits/stdc++.h>
using namespace std;

//find out the maximum cuts that can be made out of rope length n

int maxCuts(int n ,int a,int b,int c)
{
    if(n < 0) return -1;
    if(n == 0) return 0;
    int res = max({maxCuts(n-a,a,b,c),maxCuts(n-b,a,b,c),maxCuts(n-c,a,b,c)});
    if(res == -1)
    return res;
    else
     return res+1;

}
int maxCutsDynamic(int n ,int a,int b,int c)
{
  int dp[n+1];
  dp[0] = 0;
  
  for(int i =1; i<=n ; i++)
  {
      dp[i] = -1;
      if(i-a >= 0) 
      dp[i] = max(dp[i],dp[i-a]);
      if(i-b >= 0) 
      dp[i] = max(dp[i],dp[i-b]);
      if(i-c >= 0) 
      dp[i] = max(dp[i],dp[i-c]);
      if(dp[i]!= -1)
      dp[i]++;
  }
 return dp[n];
}
int main()
{
    int ropeLength = 5;
    int a = 3,b = 5, c= 2;
    cout<<maxCutsDynamic(ropeLength,a,b,c);
    return 0;
}