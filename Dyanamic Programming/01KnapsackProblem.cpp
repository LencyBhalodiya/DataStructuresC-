#include<bits/stdc++.h>
using namespace std;
//find the maximum profit by putting the item in W weight container with their respective profit
int knapsack(int W , int wt[],int profit[],int n)
{
  if(n == 0 || W == 0)
  return 0;
  
  if(wt[n-1] > W)
   return knapsack(W,wt,profit,n-1);
   else
    return max(knapsack(W,wt,profit,n-1),profit[n-1]+knapsack(W-wt[n-1],wt,profit,n-1));
}
int knapsackDynamic(int W , int wt[],int p[],int n)
{
  int dp[n+1][W+1];
  for(int i = 0 ; i <=W ; i++)
   dp[0][i] = 0;
   for(int i = 0 ; i <=n ; i++)
   dp[i][0] = 0;
   
   for(int i = 1 ; i<=n ; i++)
   {
       for(int j =1 ; j <=W ; j++)
       {
           if(wt[i-1] > j)
           dp[i][j] = dp[i-1][j];
           else
           dp[i][j] = max(p[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
       }
   }
  return dp[n][W];
}

int main()
{
    int profit[] = {10,40,30,50};
    int weight[] = {5,4,6,3};
    int n = sizeof(weight)/sizeof(weight[0]);
    int WTotal = 10;
    cout<<knapsackDynamic(WTotal,weight,profit,n);
    return 0 ;
}