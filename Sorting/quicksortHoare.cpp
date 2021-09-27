#include<iostream>
using namespace std;


int hoarePartition(int arr[],int l,int h)
{
  int pivot = arr[l];
  int i=l-1;
  int j= h+1;
  while(true)
  {
      do{
          i++;
      }while(arr[i] < pivot);

      do{
          j--;
      }while(arr[j] > pivot);

        if(i>=j) 
        return j;

       swap(arr[i],arr[j]);
  }
}

void quickSort(int arr[],int l,int h)
{
    if(l<h)
    {
        int p = hoarePartition(arr,l,h);
        quickSort(arr,l,p);
        quickSort(arr,p+1,h);
    }
}

void printarray(int arr[],int n){
    for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
}
int main()
{
    int arr[]={56,23,111,90,99,34,67};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);
    printarray(arr,n);
}