#include<iostream>
using namespace std;
// in bubble sort every iteration gives the largeest element and gets place in last position.
void bubblesort(int arr[],int n)
{
   int i,j;
   for(i=0;i<n-1;i++)
   {
       for(j=0;j<n-i-1;j++)
       {
           if(arr[j]>arr[j+1])
           swap(arr[j],arr[j+1]);
       }
   }
}
void bubblesortOptimize(int arr[],int n)
{
   int i,j;
   bool sorted;
   for(i=0;i<n-1;i++)
   {   
       sorted = false;
       for(j=0;j<n-i-1;j++)
       {
           if(arr[j]>arr[j+1])
           {
             swap(arr[j],arr[j+1]);
             sorted =true;
           }
   
       }
       if(sorted == false)
       break;
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
    bubblesort(arr,n);
    printarray(arr,n);
    
    // 2,6,5,3,1,4
    // 1st iteration 2,5,3,1,4,6
    // 2nd iteration 2,3,1,4,5,6
}