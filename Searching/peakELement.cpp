#include<iostream>
using namespace std;
// find the peak element in an array means elements whose neighbours are smaller than the element previous and next element should be smaller than the element himself
int naivepeak(int arr[],int n)
{
    for(int i=1;i<n-1;i++)
    {
        if(arr[0]>arr[1]) return arr[0];
        if(arr[n-1]>arr[n-2]) return arr[n-1];
        if((arr[i]>arr[i-1])&&(arr[i]>arr[i+1]))
        {
            return arr[i];
        }
    }
}
     int getPeak(int arr[],int n) {
 
       int start = 0;
       int end = n - 1;
 
       while (start <= end) {      
 
            int mid = (start + end) / 2;
       
            if ((mid == 0 || arr[mid - 1] <= arr[mid]) 
               && (mid == n - 1 || arr[mid] >= arr[mid + 1])) {
               return arr[mid];
 
            } else if (mid > 0 && arr[mid - 1] > arr[mid]) {
              end = mid - 1;
 
            } else {
              start = mid + 1;
            }
       }
 
     return -1;
   }
int main()
{
     int arr[]={1,2,5,6,8,2};
     int n = sizeof(arr)/sizeof(arr[0]);
     cout<<getPeak(arr,n);
}