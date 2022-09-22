#include<bits/stdc++.h>
using namespace std;
//find the total path if you can't cross obstacles

int solve(vector<vector<int>>maze,int row , int col,vector<vector<int>> &dp)
{
    if( row == 0 && col == 0)
     return 1;
    if( row < 0 || col < 0 || maze[row][col] == -1)
     return 0;
     if(dp[row][col]!= -1) return dp[row][col];
    int up = solve(maze, row-1,col,dp);
    int left = solve(maze,row,col-1,dp);
    return dp[row][col] = left + up;
}
int tabulation(vector<vector<int>>maze,int row , int col,vector<vector<int>> &dp)
{
   for(int i = 0 ; i < row ; i++)
   {
    for(int j = 0 ; j < col ; j++)
    {
        if(i>0 && j>0 && maze[i][j]==-1){
            dp[i][j]=0;
            continue;
          }
         if(i==0 && j==0){
              dp[i][j]=1;
              continue;
          }
            int left = 0, up = 0;
            if(j > 0)
             left = dp[i][j-1];
             if(i > 0)
             up = dp[i-1][j];
             dp[i][j] = up  + left;
    }
   }
   return dp[row-1][col-1];
}
int main()
{
     vector<vector<int> > maze{{0,0,0},
                            {0,-1,0},
                            {0,0,0}};
    int row = maze.size();
    int col = maze[0].size();
    vector<vector<int>> dp(row,vector<int>(col,-1));
    cout<<solve(maze, row -1, col-1,dp)<<endl;
    cout<<tabulation(maze, row , col,dp);

    return 0;
}