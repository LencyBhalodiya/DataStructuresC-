#include<iostream>
using namespace std;
// this sorting does less memory writes
// its is not stable sorting
// in every iteration we get the smallest number
void selectionsort(int arr[],int n)
{
  for(int i=0;i<n;i++)
  {
      int minIndex =i;
      for(int j=i+1;j<n;j++)
      {
        if(arr[j]<arr[minIndex])
        minIndex=j;
      }
      swap(arr[minIndex],arr[i]);
  }
}

void printarray(int arr[],int n){
    for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
}
int main()
{
    int arr[]={2,4,2,1,9,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionsort(arr,n);
    printarray(arr,n);
    
}