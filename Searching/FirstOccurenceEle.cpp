#include<iostream>
using namespace std;
// find the first occurence of the elemnt in the array
int recursiveFirstOccurence(int arr[],int low,int high,int x)
 {
     
        if(low>high) 
        return -1;
         int mid = (low+high)/2;
         if(arr[mid]>x)
         return recursiveFirstOccurence(arr,0,mid-1,x);
         else if(arr[mid]<x)
         return recursiveFirstOccurence(arr,mid+1,high,x);
         else{
             if(mid==0||arr[mid]!=arr[mid-1])
             return mid;
             else
            return recursiveFirstOccurence(arr,0,mid-1,x);
         }
 }
 int iterativeSolution(int arr[],int n,int x)
 {
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
 
int main()
{
    int arr[]={1,3,3,3,3,77};
     int x=4;
     int n = sizeof(arr)/sizeof(arr[0]);
     cout<<iterativeSolution(arr,n,3);
}