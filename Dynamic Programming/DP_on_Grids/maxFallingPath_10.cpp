#include<bits/stdc++.h>
using namespace std;
// find max path from start to bottom of matrix if you can move down , and diagonally
int solve(vector<vector<int>> arr, int row , int col,int colsize)
{
    if(row == 0)
     return arr[0][col]; //if reached top then return 0th row and specific col
    
     if(col<0 || col >= colsize)
        return -1e9;

     int up = solve(arr,row-1,col,colsize) + arr[row][col];
     int leftD = solve(arr,row-1,col-1,colsize)+ arr[row][col]; // moving left diagonal
     int rightD = solve(arr,row-1,col+1,colsize) + arr[row][col];

     return max(up,max(leftD,rightD));
}
int tabulation(vector<vector<int>> arr, int row , int col, vector<vector<int>> dp)
{
    for(int i = 0 ; i < col ; i++)
     dp[0][i] = arr[0][i]; 

     for(int i = 1 ; i < row ; i++)
     {
        for(int j = 0 ; j < col ; j++)
        {
            int up = arr[i][j] + dp[i-1][j];
            int left = arr[i][j], right = arr[i][j];
            if(j-1 >=0)
             left += dp[i-1][j-1];
             else
             left += -1e9;
            if(j+1 < col)
            right += dp[i-1][j+1];
            else
            right+= -1e9;

            dp[i][j] = max(up,max(left,right));
        }
     }
     int maxi = 0;
     for(int j = 0 ; j < col ; j++)
      maxi = max(maxi,dp[row-1][j]);

      return maxi;
}
int main()
{
    vector<vector<int>> matrix{{1,2,10,4},
                              {10,3,2,1},
                              {1,1,20,2},
                              {1,2,2,1}};
    int row = matrix.size();
    int col = matrix[0].size();
    int maxi = 0;
    vector<vector<int>> dp(row,vector<int>(col,-1));
    for(int j = 0 ; j < col; j++)
    {
        int ans = solve(matrix,row-1,j,col);
        maxi = max(maxi,ans);
    }
    cout<<maxi<<endl;

    cout<<tabulation(matrix,row,col,dp);
    return 0;
}