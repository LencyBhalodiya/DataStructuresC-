#include<iostream>
using namespace std;
//  find the sum of two element which is same as given number x

int twoelementsum(int arr[],int n,int x)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j]==x){
                return true;
            }
        }
    }
    return false;
}
int twoPointerApproach(int arr[],int n,int x)
{
    int low=0,high=n-1;
    while(low<=high)
    {
        int sum = 0;
         sum = arr[low]+arr[high];
        if(sum==x)return true;
        if(sum>x)
        {
            if(arr[low]<arr[high])
            high--;
            else
            low++;
        }
        if(sum<x)
        {
            if(arr[low]<arr[high])
            low++;
            else
            high--;
        }

    }
    return false;
}
 int main()
 {
     int arr[]={11,2,5,6,8,2};
     int n = sizeof(arr)/sizeof(arr[0]);
     cout<<twoPointerApproach(arr,n,15);
 }