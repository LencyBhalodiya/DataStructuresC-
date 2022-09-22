#include<bits/stdc++.h>
using namespace std;
//find the subset with minimum difference of their sum

int solve(vector<int> arr,int n)
{
     int sum = 0;
    for(auto i: arr) // find the array total sum
     sum+= i;

    vector<vector<int>> dp(n,vector<int>(sum,0));
 
    for(int i=0; i<n; i++){ // if target is 0 then return true  acc. to base case
        dp[i][0] = true;
    }
    if(arr[0]<= sum && arr[0] < n)
        dp[0][arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<= sum; target++){
            
            bool notTaken = dp[ind-1][target];
    
            bool taken = false;
                if(arr[ind]<=target)
                    taken = dp[ind-1][target-arr[ind]];
        
            dp[ind][target]= notTaken||taken;
        }
    }    
    int mini = 1e9;
    for(int i = 0 ; i <= sum/2 ; i++)
    {
       if(dp[n-1][i] == true)
       {
         mini = min(mini, (sum - i)- i);
       }
    }
    return mini;
}

int main()
{
    vector<int> arr = {1,6,10,18};
    int n = arr.size();
    cout<<solve(arr,n-1);
   
}