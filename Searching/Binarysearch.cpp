#include<iostream>
using namespace std;
 
 int binarySearch(int arr[],int n,int x)
 {
     int low = 0;
     int high = n-1;
     while(low<=high)
     {
     int mid = (low+high)/2;

         if(arr[mid]==x)
         {
           return mid;
         }
         else if(arr[mid]>x)
         {
          high = mid-1;
         }else{
             low=mid+1;
         }
     }
     return -1;
 }
 int recursivebinary(int arr[],int low,int high,int x)
 {
     
         int mid = (low+high)/2;
         if(arr[mid]==x)
         {
             return mid;
         }
         else if (arr[mid]>x)
         {
             return recursivebinary(arr,low,mid-1,x);
         }else{
             return recursivebinary(arr,mid+1,high,x);
         }
     
 }
 int main()
 {
     int arr[]={1,2,3,4,65,77};
     int x=2;
     int n = sizeof(arr)/sizeof(arr[0]);
     cout<<binarySearch(arr,n,x);
 }