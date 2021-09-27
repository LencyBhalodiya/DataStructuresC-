#include<iostream>
#include<algorithm>
using namespace std;
// sort the two array of different types

void Sort(int arr[],int n)
{
    int  temp[n],i=0;
    for(int j=0;j<n;j++)
    {
        if(arr[j]==0)
        {
            temp[i] = arr[j];
            i++;
        }
    }
    for(int j=0;j<n;j++)
    {
        if(arr[j]==1)
        {
            temp[i] = arr[j];
            i++;
        }
    }
    for(int j=0;j<n;j++)
    {
        if(arr[j]==2)
        {
            temp[i] = arr[j];
            i++;
        }
    }
    for(int j=0;j<n;j++)
    arr[j] = temp[j];
}

void sortingThree(int arr[],int n)
{
    // dutch national flag algorithm
    int low=0,high = n-1, mid =0;
    while(mid<=high)
    {
        if(arr[mid] == 0)
        {
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }else if(arr[mid] == 1)
           mid++;
        else {
            swap(arr[mid],arr[high]);
             high--;
        }
    }
}
void printarray(int arr[],int n){
    for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
}
int main()
{
    int arr[]={0,0,1,0,1,2,1,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortingThree(arr,n);
    printarray(arr,n);
}