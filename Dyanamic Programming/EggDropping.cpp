#include<bits/stdc++.h>
using namespace std;

int eggPlant(int e , int f)
{
    if(f==0 || f == 1)
    return f;
    if(e==1) 
     return f;
     int minV = INT_MAX;

     for(int i = 1; i <= f ;i++ )
     {
        int temp = 1 + max(eggPlant(e-1,i-1),eggPlant(e,f-i));
        minV = min(minV,temp);
     }
     return minV;
}
int eggDropDynamic(int e,int f)
{
  int dp[f+1][e+1];
  for(int i =1 ; i<=e ; i++)
  {
      dp[1][i] = 1;
      dp[0][i] = 0;
  }
  for(int j =1 ; j<=f ; j++)
  {
      dp[j][1] = j;
  }
  for(int i =2 ; i<=f ; i++)
  {
      for(int j = 2 ; j<=e ; j++)
      {
          dp[i][j] = INT_MAX;
          for(int x = 1 ; x <= i ; x++)
           dp[i][j] = min(dp[i][j], 1 + max(dp[x-1][j-1],dp[i-x][j]));
      }
  }
  return dp[f][e];
}
int main()
{
    cout<<eggPlant(2,5);
    return 0;
}