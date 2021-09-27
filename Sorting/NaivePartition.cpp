#include<iostream>
using namespace std;


void Partition(int arr[],int l,int h,int p)
{
  int temp[h-l+1];
  int index =0;
  for(int i=l;i<=h;i++)
  {
      if(arr[i]<=arr[p])
      {
          temp[index] = arr[i];
          index++;
      }
  }
  for(int i=l;i<=h;i++)
  {
      if(arr[i]>arr[p])
      {
          temp[index] = arr[i];
          index++;
      }
  }
  for(int i=l;i<=h;i++)
  {
      arr[i]=temp[i-l];
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
    Partition(arr,0,n-1,7);
    printarray(arr,n);
}