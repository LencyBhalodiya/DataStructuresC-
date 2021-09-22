#include<iostream>
#include <limits.h>
using namespace std;

double getMedian(int arr[],int arr2[],int n,int m)
{
    int begin = 0,end = n;
    while(begin<=end)
    {
        int i1 = (begin + end)/2;
        int i2 = (n+m+1)/2-i1;
        int min1 = (i1 ==n)?INT_MAX:arr[i1];
        int max1 = (i1 ==0)?INT_MIN:arr[i1-1];
        int min2 = (i2 ==m)?INT_MAX:arr[i2];
        int max2 = (i2 ==0)?INT_MIN:arr[i2-1];
        if(max1<=min2 && max2 <=min1)
        {
            if((n+m)%2==0)
            return ((double)max(max1,max2) + min(min1,min2))/2;
            else
            return (double)max(max1,max2);
        }else if(max1>min2) end =i1-1;
        else begin = i1+1;

    }
}
 int main()
 {
  int arr[]={10,11,12,14,15};
  int arr2[]={1,2,3,4,5,6,7};
  int n = sizeof(arr)/sizeof(arr[0]);
  int m =sizeof(arr2)/sizeof(arr[0]);
  cout<<getMedian(arr,arr2,n,m);
 }