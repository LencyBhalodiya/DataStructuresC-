#include<bits/stdc++.h>
using namespace std;
//find the total number of unique path to reach 0,0 matrix if started from rigth bottom
int solve(int row, int col,vector<vector<int>> dp)
{
    if(row == 0 && col == 0)
     return 1;
    if(row < 0 || col < 0)
     return 0;
    if(dp[row][col]!= -1)
     return dp[row][col];

    int up = solve(row -1, col,dp);
    int left = solve(row,col-1,dp);

    return dp[row][col] = up + left;
}
int tabulation(int row ,int col , vector<vector<int>> dp)
{
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            if(i == 0 && j == 0)
             dp[i][j] = 1;
             else{
                int left = 0 , up = 0;
                if(i > 0)
                 up= dp[i-1][j];
                 if(j> 0)
                 left = dp[i][j-1];
                 dp[i][j] = up + left;
             }
        }
    }
    return dp[row-1][col-1] ;
}
int main()
{
    int row = 3;
    int col = 3;
    vector<vector<int>> dp(row,vector<int> (col,-1));
    cout<<solve(row-1,col-1,dp)<<endl;
    cout<<tabulation(row,col,dp);
    return 0;
}