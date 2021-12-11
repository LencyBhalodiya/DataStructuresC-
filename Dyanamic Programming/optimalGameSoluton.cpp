#include<bits/stdc++.h>
using namespace std;
//find the maximum number you can take when you have choice of picking corner number and then after picking your number the oppenent will pick his optimize or max number from remaining corner
// assume always you the first choice
int sol(int arr[],int i , int j)
{
    //both function code no working 
    if(i+1 == j)
    return max(arr[i],arr[j]);
    
    return max({arr[i] + min(sol(arr,i+2,j),sol(arr,i+1,j-1)),arr[i] + min(sol(arr,i+1,j),sol(arr,i,j-2))});
}
int solDynamic(int arr[], int n)
{
    int dp[n][n];
    for(int i = 0 ; i <n-1 ; i++)
     dp[i][i+1] = max(arr[i],arr[i+1]);
    for(int gap = 3 ; gap<n ; gap = gap+2)
    {
        for(int i = 0 ; i <n-gap; i++)
        {
            int j = i + gap;
            dp[i][j] = max(arr[i] + min(dp[i+2][j],dp[i+1][j-1]),arr[j] + min(dp[i+1][j-1],dp[i][j-2]));
        }
    }
}
int main()
{
    int arr[]= {20,5,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<solDynamic(arr,n);
    return 0;
}