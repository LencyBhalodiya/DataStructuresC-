#include<iostream>
using namespace std;
// find the number or count of an element occuring in the element
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
  int LastiterativeSolution(int arr[],int n,int x)
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
int CountOccurence(int arr[],int n,int x)
{
    int first= FirstiterativeSolution(arr,n,x);
    if(first == -1)
    return 0;
    else return (LastiterativeSolution(arr,n,x)-first+1);
}
int main()
{
    int arr[]={1,3,3,3,65,65,77};
     int x=3;
     int n = sizeof(arr)/sizeof(arr[0]);
     cout<<CountOccurence(arr,n,x);
}