#include<iostream>
#include<limits.h>
using namespace std;

int Window(int arr[],int n,int k)
{
    // niave solution using brute force technique
    // Time complexity 0(n2)
    int maxSum = 0;
    for(int i=0;i<n-k+1;i++)
    {
        int Sum = 0;
        for(int j=i;j<i+k;j++)
        {
            Sum+= arr[j];
        }
          maxSum = max(Sum,maxSum);

    }
    return maxSum;
}
int WindowE(int arr[],int n,int k)
{
    // Effective method using o(n)time
    int sum =0;
    for(int i=0;i<k;i++)
    {
        sum+=arr[i];        
    }
    int maxSum = sum;
    for(int i=k;i<n;i++)
    {
        sum+=(arr[i]-arr[i-k]);
        maxSum = max(maxSum,sum);
    }
    return maxSum;
}
// given a unsorted array of non negative integers. find if there is a subarray with given sum
bool SubSum(int arr[],int n,int sum)
{
    // not work of negative number
    int currSum = arr[0],s=0;
    for(int i=1;i<n;i++)
    {
        // clean the previous window
       while(currSum>sum && s<i-1)
       {
           currSum = currSum - arr[s];
           s++;
       }
       if(currSum == sum)
       return true;
       if(i<n)
       currSum+=arr[i];
    }
       return (currSum==sum);

}
int main()
{
  int arr[]={1,4,8,-3,9,1};
  int n = sizeof(arr)/sizeof(arr[0]);
  
  cout<<Window(arr,n,2);
}