#include<iostream>
using namespace std;

int stock(int arr[],int n){
  // Effective solution
   int profit =0;
   for(int i=1;i<n;i++)
   {
     if(arr[i]>arr[i-1]){
       
      profit = profit +=(arr[i]-arr[i-1]);
     }
   }
      return profit;
 }
 int main()
 {
   int arr[]={1,2,3,4};
   int n = sizeof(arr)/sizeof(arr[0]);
   cout<<stock(arr,n);
 }