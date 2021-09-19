#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[],int low,int high){
    // reverse the number 
    
    while(low<high){
        int temp = arr[low];
        arr[low]= arr[high];
        arr[high]=temp;
        low++;
        high--; 
    }
    
}
// check if the array is sorted or not
bool sorted(int arr[],int n)
{
  for(int i=1;i<n;i++){
      if(arr[i]<arr[i-1]){
          return false;
      }
  }
     return true;

}

int main(){
    int arr[]={30,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
      reverse(arr,0,n-1);
      for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}