#include<iostream>
using namespace std;
//find out the longest Increasing subsequence in the given array

int lis(int arr[],int n)
{
    //time complexity of this is n2
  int lis[n];
  lis[0] = 1;
  for(int i = 1 ; i < n; i++)
  {
      lis[i] = 1;
      for(int j = 0 ; j < i; j++)
      {
          if(arr[j]<arr[i])
          lis[i] = max(lis[i],lis[j]+1);
      }   
  }
  int res = lis[0];
  for(int i = 0 ; i < n ; i++)
   res = max(res,lis[i]);

   return res;
}
int ceilIndex(int tail[],int l , int r, int x)
{
    //helper function to return the index of the ceiling number
    while( r > l)
    {
        int m = l + (r-l)/2;
        if(tail[m] >= x)
         r = m;
         else
         l = m+1;
    }
    return r;
}
int lisEffective(int arr[],int n)
{
    int tail[n] , len = 1;
    tail[0] = arr[0];

    for(int i = 1 ; i < n ; i++)
    {
        if(arr[i] > tail[len-1])
        {
            tail[len] = arr[i];
            len++;
        }else{
            int c = ceilIndex(tail,0,len-1,arr[i]);
            tail[c] = arr[i];
        }
    }
    return len;
}
int main()
{
    int arr[] = {3,10,20,4,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<lisEffective(arr,n);
    return 0;
}