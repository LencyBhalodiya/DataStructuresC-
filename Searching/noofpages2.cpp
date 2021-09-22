#include<iostream>
using namespace std;
// https://www.canva.com/design/DAEpEq_FLVo/share/preview?token=D0e6x3qDDcQDVXWMt13Cew&role=EDITOR&utm_content=DAEpEq_FLVo&utm_campaign=designshare&utm_medium=link&utm_source=sharebutton
bool isFeasible(int arr[],int n,int k,int ans)
{
    int stud=1,sum = 0;
    for(int i=0;i<n;i++)
    {
        if(sum+arr[i]>ans)
        {
            stud++;
            sum =sum =arr[i];
        }else
        sum+=arr[i];
    }
    return (stud<=k);
}
int pages(int arr[],int n,int k)
{
    int sum=0,mx=0;
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
        mx = max(mx,arr[i]);
    }
    int low=mx;
    int high = sum;
    int res = 0;
    
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(isFeasible(arr,n,k,mid))
        {
            res =mid;
            high = mid-1;
        }else 
        low = mid+1;
    }
    return res;
}
int main()
{
  int k=2;
  int arr[]={2,3,1,7,2};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<pages(arr,n,k);
}