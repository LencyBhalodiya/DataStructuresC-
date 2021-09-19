#include<iostream>
using namespace std;

int maxSumSubarray(int arr[],int n)
{  //Niave Solution
    int res = 0;
    for(int i=0;i<n;i++)
    {
        int curr = 0;
        for(int j=i;j<n;j++)
        {
            curr = curr + arr[j];
            res = max(curr,res);
        }
    }
    return res;
}
int maxSumSubarrayE(int arr[],int n)
{  
    // effective method
     int res = arr[0];
     int maxEnding = arr[0];
     for(int i=1;i<n;i++)
     {
         maxEnding = max(maxEnding+arr[i],arr[i]);
         res = max(res,maxEnding);

     }
     return res;
}
int main()
{
  int arr[]={5,-9,-2,2,1};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<maxSumSubarrayE(arr,n);
}