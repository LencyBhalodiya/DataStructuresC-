#include<iostream>
using namespace std;
// find the number 1 occurence in an array
int FirstiterativeSolution(int arr[],int n,int x)
 {
    //  fist occurence element
    int low = 0,high = n-1;
     while(low<=high)
     {
       int mid = (low+high)/2;
         if(arr[mid]>x)
         {
          high = mid-1;
         }else if(arr[mid]<x){
             low=mid+1;
         }
         else{
             if(mid==0||arr[mid-1]!=arr[mid])
             return mid;
             else
           high = mid-1; 
             }
     }
     return -1;
 }
int count1s(int arr[],int n,int x)
{
    int first = FirstiterativeSolution(arr,n,x);
    
    if(first == -1)
    {
        return 0;
    }
    return (n-first);
}
 int main()
{
    int arr[]={0,0,1,1,1,1,1};
     int x=1;
     int n = sizeof(arr)/sizeof(arr[0]);
     cout<<count1s(arr,n,x);
}