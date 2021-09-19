#include<iostream>
using namespace std;

int getwater(int arr[],int n)
{
    int res =0;
    for(int i=1;i<n-1;i++)
    {
        int lmax =arr[i];
        for(int j=0;j<i;j++)
        lmax = max(lmax,arr[j]);

        int rmax = arr[i];
        for(int j=i+1;j<n;j++)
        rmax = max(rmax,arr[j]);

        res =res+(min(lmax,rmax)-arr[i]);
    }
    return res;
}
int getwaterE(int arr[],int n)
{
    int storage =0;
    int leftmax[n],rightmax[n];
    leftmax[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        leftmax[i] = max(arr[i],leftmax[i-1]);
    }
     rightmax[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        rightmax[i]=max(arr[i],rightmax[i+1]);
    }
    for(int i=1;i<n-1;i++)
    {
        storage = storage + (min(leftmax[i],rightmax[i])-arr[i]);
    }
    return storage;
}
int main(){
  int arr[]={3,0,1,2,5};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<getwater(arr,n);

}