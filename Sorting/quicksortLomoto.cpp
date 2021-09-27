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
void quickSort(int arr[],int l,int h)
{
    if(l<h)
    {
        int p = LomutoPartition(arr,l,h);
        quickSort(arr,l,p-1);
        quickSort(arr,p+1,h);
    }
}

void printarray(int arr[],int n){
    for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
}
int main()
{
    int arr[]={2,23,42,111,90,99,34,67};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);
    printarray(arr,n);
}