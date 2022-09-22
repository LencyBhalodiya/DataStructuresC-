#include<bits/stdc++.h>
using namespace std;
// find the longest increasing subsequence

int solve(vector<int> &arr, int n , int curr , int prev)
{
    if(curr == n)
     return 0;

    //include
    int pick = INT_MIN;
    if(prev == -1 || arr[curr] > arr[prev])
     pick = 1 + solve(arr,n,curr + 1, curr);

     int notpick = solve(arr, n , curr + 1, prev);

     return max(pick, notpick);
}
int main()
{
    vector<int> arr = {1,0,1,0,3,2,3};
    int n = arr.size();
    int curr = 0 , prev = -1;

    cout<<solve(arr,n,curr,prev);
    return 0;
}