#include<iostream>
using namespace std;
// given a fix array and multiple queries of following types on the array, how to efficiently program
bool isEquilibrium(int arr[],int n)
{
    int sum =0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    int lsum=0;
    for(int i=0;i<n;i++)
    {
        if(lsum == sum-arr[i]){
        return true;
        }
        lsum = lsum + arr[i];
        sum= sum - arr[i];
    }
    return false;
}

// find the equilibrium point
int main()
{
  int arr[]={1,4,3,5,9,7};
  int n = sizeof(arr)/sizeof(arr[0]);
  isEquilibrium(arr,n);
}