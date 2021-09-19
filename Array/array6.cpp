#include<iostream>
using namespace std;

int maximumDiff(int arr[],int n)
{
    // int res=arr[1]-arr[0];
    int res = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            res = max(res,arr[j]-arr[i]);
        }
    }
    return res;
}
int EMaximumDiff(int arr[],int n)
{
    int res =0;
    int minV = arr[0];
    for(int i=1;i<n;i++)
    {
        res = max(res,arr[i]-minV);
        minV = min(minV,arr[i]);
    }
    return res;
}
void Frequency(int arr[],int n)
{
    int freq=1,i=1;
     while(i<n)
    {
      while(i<n && arr[i-1]==arr[i]){
          i++;
          freq++;
      }
      cout<<arr[i-1]<<" is repeated: "<<freq<<" times"<<endl;
      i++;
      freq=1;
    }
    if(n==1 || arr[n-1]!=arr[n-2])
    {
        cout<<arr[n-1]<<" is repeated: "<<"1 times";
    }
}


int main(){
    int arr[]={10,10,50,70,70,80};
    int n = sizeof(arr)/sizeof(arr[0]);
   fre(arr,n);
    return 0;
}