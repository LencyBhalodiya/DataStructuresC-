#include<iostream>
using namespace std;
// find the triplet sum of an given sorted array whose sum is equal to given element n
int twoPointerApproach(int arr[],int low,int high,int x,int n)
{
     low=0,high=n-1;
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
int tripletnaive(int arr[],int n,int x)
{
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
               if(arr[i]+arr[j]+arr[k]==x)
               {
                   return true;
               }
            }
        }
    }
    return false;
}
int triplePointer(int arr[],int n,int x)
{
  for(int i=0;i<n;i++)
  {
      if(twoPointerApproach(arr,i+1,n-1,x-arr[i],n)){
          return true;
      }
  }    
  return false;
}
int main()
{
  int arr[]={11,2,5,6,8,2};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<triplePointer(arr,n,15);
}
