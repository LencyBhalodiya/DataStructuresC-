#include<bits/stdc++.h>
using namespace std;
//find the min cost path to reach till bottom right

int solve(vector<vector<int>> &arr, int row , int col)
{
    if(row == 0 && col == 0)
        return arr[0][0];

    if(row < 0 || col < 0) 
     return  1e9;

    int up = arr[row][col] + solve(arr, row-1,col);
    int left = arr[row][col] + solve(arr,row,col-1);

    return min(up,left);
}
int minSumPathUtil(int row, int col,vector<vector<int>> &arr,vector<vector<int>> &dp)
{
   for(int i = 0 ; i <= row ; i++)
   {
     for(int j = 0 ; j <= col ; j++)
     {
       if(i == 0 && j == 0)
        dp[i][j] = arr[i][j];
        else{
            int left = arr[i][j];
            if(j > 0)
            left += dp[i][j-1];
            else
            left+=1e9;
            int  up = arr[i][j];
            if( i > 0)
            up  += dp[i-1][j] ;
            else
            up += 1e9;
            dp[i][j] = min(left,up);
        }
     }
   } 
   return dp[row][col];
}
int main()
{
    vector<vector<int> > maze{{1,3,3},
                            {4,1,5},
                            {5,8,7}};
    int row = maze.size();
    int col = maze[0].size();
    vector<vector<int>> dp(row,vector<int>(col,-1));
    cout<<solve(maze, row-1, col-1)<<endl;
    cout<<minSumPathUtil(row-1,col-1,maze,dp);
   
    return 0;
}