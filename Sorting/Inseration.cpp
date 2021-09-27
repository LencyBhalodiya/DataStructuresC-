#include<iostream>
using namespace std;
// it is in place and stable algo sort
// used in practice for small array sizes

void inserationsort(int arr[],int n)
{
  for(int i=1;i<n;i++)
  {
      int key = arr[i];
      int j =i-1;
      while(j>=0 && arr[j]>key)
      {
          arr[j+1] = arr[j];
          j--;
      } 
      arr[j+1] = key;
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
    inserationsort(arr,n);
    printarray(arr,n);
    
}