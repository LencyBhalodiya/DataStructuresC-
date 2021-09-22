#include<iostream>
using namespace std;
// find the first occurence of the elemnt in the array
int recursiveLastOccurence(int arr[],int low,int high,int x,int n)
 {
        if(low>high) 
        return -1;
         int mid = (low+high)/2;
         if(arr[mid]>x)
         return recursiveLastOccurence(arr,0,mid-1,x,n);
         else if(arr[mid]<x)
         return recursiveLastOccurence(arr,mid+1,high,x,n);
         else{
             if(mid==n-1||arr[mid]!=arr[mid+1])
             return mid;
             else
            return recursiveLastOccurence(arr,mid+1,high,x,n);
         }
 }
 int iterativeSolution(int arr[],int n,int x)
 {
     int low = 0;
     int high = n-1;
     if(low>high) return -1;
     while(low<=high)
     {
        int mid = (low+high)/2;
         if(arr[mid]>x)
          high = mid-1;
         else if(arr[mid]<x)
         low = mid+1;
         else{
             if(mid==n-1||arr[mid]!=arr[mid+1])
             return mid;
             else
            low = mid+1;
         }  
     }
 }
int main()
{
    int arr[]={1,3,3,3,65,77};
     int x=4;
     int n = sizeof(arr)/sizeof(arr[0]);
     cout<<recursiveLastOccurence(arr,0,n-1,3,n);
}