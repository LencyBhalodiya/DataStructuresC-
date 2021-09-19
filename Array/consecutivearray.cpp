#include<iostream>
using namespace std;
// find maximum Consecutive 1 in and bool array
int consecutiveArray(bool arr[],int n)
{
    // naive solution
    int res =0;
    for(int i=0;i<n;i++)
    {
        int curr = 0;
        for(int j=i;j<n;j++)
        {
           if(arr[j]==1)
           {
               curr++;
           }else{
               break;
           }
        }
        res =  max(curr,res);
    }
    return res;
}
// find maximum Consecutive 1 in and bool array

int maxConsecutive(bool arr[],int n)
{
     int res=0,curr;
     for(int i=0;i<n;i++)
     {
         if(arr[i]==0)
         {
             curr=0;
         }
         else{
             curr++;
             res =max(res,curr);

         }
     }
     return res;
}
int main()
{
  bool arr[]={0,1,1,0,1,1};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<maxConsecutive(arr,n);
}