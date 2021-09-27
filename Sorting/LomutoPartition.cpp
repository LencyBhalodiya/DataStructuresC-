#include<iostream>
using namespace std;


int LomutoPartition(int arr[],int l,int h)
{
    // this only works when pivot is n-1 element but if the pivot is another index just swap that pivot with n-1 element.
  int pivot = arr[h];  
  int i = l-1;
  for(int j=l;j<=h-1;j++)
  {
      if(arr[j]<pivot)
      {
          i++;
          swap(arr[i],arr[j]);
      }
  }
  swap(arr[i+1],arr[h]);
  return (i+1);
}

void printarray(int arr[],int n){
    for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
}
int main()
{
    int arr[]={8,5,6,9,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<LomutoPartition(arr,0,n-1);
    printarray(arr,n);
}