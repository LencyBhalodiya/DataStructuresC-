#include<iostream>
#include<algorithm>
using namespace std;
// find the kth largest element in the array given
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
int kth(int arr[],int n,int k)
{
    sort(arr,arr+n);
    return(k-1);
}
void printarray(int arr[],int n){
    for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
}
int ksmallest(int arr[],int n,int k)
{
    int l=0,r=n-1;
    while(l<=r)
    {
        int p = LomutoPartition(arr,l,r);
        if(p == k-1)
        return p;
        else if(p>k-1)
        r= p-1;
        else
        l=p+1;
    }
    return -1;
}
int main()
{
  int arr[]={56,23,111,90,99,34,67};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<ksmallest(arr,n,3);
//  printarray(arr,n);
}