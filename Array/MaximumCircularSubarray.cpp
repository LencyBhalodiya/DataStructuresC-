#include<iostream>
using namespace std;
// Find the max sum of a circular subarray
int CircularSubArray(int arr[],int n)
{
    int res= arr[0];
    for(int i=0;i<n;i++)
    {
        int currSum =arr[i];
        int currMax = arr[i];
        for(int j=1;j<n;j++)
        {
            int index = (i+j)%n;
            currSum+=arr[index];
            currMax = max(currMax,currSum);
        }
        res = max(res,currMax);
    }
    return res;
}
int main()
{
  int arr[]={1,-2,2,2};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<CircularSubArray(arr,n);
}