#include<bits/stdc++.h>
using namespace std;
//find the subsequence or subset which has target k if yes return true

bool solve(vector<int> arr, int n , int target,vector<vector<int>> dp)
{
    if(target == 0)
     return true;
     if(n == 0){
        if(target == arr[0])
        return true;
        else return false;
     }
     
     if(dp[n][target]!= -1)
      return dp[n][target];

    int notTake = solve(arr,n-1,target,dp); // move index and not add target 
    int take = false;
    if(arr[n] <= target)
     take = solve(arr,n-1,target - arr[n],dp); // add sum and move index

     return dp[n][target] = take||notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr){
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    
    return solve(arr,n-1,k,dp);
}
bool tabulation(vector<int> arr, int n , int k)
{
   vector<vector<bool>> dp(n,vector<bool>(k+1,false));
      for(int i=0; i<n; i++){ // if target is 0 then return true  acc. to base case
        dp[i][0] = true;
    }
    
    if(arr[0]<=k && arr[0] < n)
        dp[0][arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            
            bool notTaken = dp[ind-1][target];
    
            bool taken = false;
                if(arr[ind]<=target)
                    taken = dp[ind-1][target-arr[ind]];
        
            dp[ind][target]= notTaken||taken;
        }
    }
    
    return dp[n-1][k];
}
int main()
{
    vector<int> arr = {1,2,1,4,5};
    int target = 111;
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    if(subsetSumToK(n,target,arr) == true)
     cout<<"it has target subsequences"<<endl;
     else
     cout<<"it has no value which has target"<<endl;
    cout<<tabulation(arr,n,target);
    return 0;
}