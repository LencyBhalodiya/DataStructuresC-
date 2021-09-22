#include<iostream>
using namespace std;
// find the element in infinite or long array 
int binarySearch(int arr[],int low,int high,int x)
 {
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
int infinteSearch(int arr[],int x)
{
  if(arr[0]==x) return 0;
  int i=1;
  while(arr[i]<x){
   i=i*2; 
   }
  if(arr[i]==x)
       return i;
        else
        return binarySearch(arr,i/2+1,i-1,x);
  

}
int main(){
  int arr[]={1,3,3,3,65,77,80,87,89,98,122,333,554,567,678};
  int x=80;
  int n = sizeof(arr)/sizeof(arr[0]);  
  cout<<infinteSearch(arr,x);
  }