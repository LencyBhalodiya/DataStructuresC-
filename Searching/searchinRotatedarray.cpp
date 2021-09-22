#include<iostream>
using namespace std;
// find the element in array which is sorted and then rotateda
int SearchinRotated(int arr[],int n ,int x)
{
    int low =0;
    int high = n-1;
   while(low<=high)
     {
     int mid = (low+high)/2;
      if(arr[mid]==x) return mid;
         if(arr[mid]>arr[low] ){
             if(x>=arr[low] && x<arr[mid])
             {
                 high = mid-1;
             }else
               low = mid+1;
         }else{
             if(x<= arr[high] && x>arr[mid])
             {
                 low = mid+1;
             }else
              high = mid-1;
         }   
    }
     return -1;

}
 int main()
 {
     int arr[]={3,4,5,6,1,2};
     int x=1 ;
     int n = sizeof(arr)/sizeof(arr[0]);
     cout<<SearchinRotated(arr,n,x);
 }