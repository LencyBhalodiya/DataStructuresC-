#include<iostream>
using namespace std;
// stable algo and follow divide and conquer rules
// takes nlogn and n aux space
// well suited for linked list works of 0{1} aux space

void mergeArray(int a[],int low,int mid,int high)
{
  int n1 = mid-low+1;
  int n2=high-mid;
  int left[n1],right[n2];
  for(int i=0;i<n1;i++)
  {
      left[i] = a[low+i];
  }
  for(int i=0;i<n2;i++)
  {
      right[i] = a[n1+i];
  }
  int i=0,j=0,k=0;
  while(i<n1 && j<n2)
  {
      if(left[i]<= right[j]){
          a[k] = left[i];
          i++;
          k++;
      }else{
          a[k]=right[j];
          k++;
          j++;
      }
  }
  while(i<n1)
  {
      a[k]= left[i];
      i++;
      k++;
  }
    while(j<n2)
  {
      a[k]= right[i];
      j++;
      k++;
  }
  
}
void printarray(int arr[],int n){
    for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
}
int main()
{
    int arr[]={10,15,20,11,30};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeArray(arr,0,2,4);
    cout<<"Sorted aray: "<<endl;
    printarray(arr,n);
    return 0;
}