#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

void maxHeapify(int arr[],int n,int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && arr[left]>arr[largest])
    largest = left;
    if(right<n && arr[right]>arr[largest])
    largest = right;

    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        maxHeapify(arr,n,largest);
    }
}
void buildHeap(int arr[],int n)
{
    for(int i=(n-2)/2;i>=0;i--)
     maxHeapify(arr,n,i);
}
void HeapSort(int arr[],int n)
{
    buildHeap(arr,n);
    for(int i=n-1;i>=1;i--)
    {
        swap(arr[0],arr[i]);
       maxHeapify(arr,i,0);
    }
}
void printarray(int arr[],int n){
    for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
}
int main()
{
    int arr[]={5,3,17,6,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    HeapSort(arr,n);
    printarray(arr,n);
}