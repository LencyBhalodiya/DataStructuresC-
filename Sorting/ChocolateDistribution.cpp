#include<iostream>
#include<algorithm>
using namespace std;
// given students who should get one chocolate each and different between them should be minimum.

int Chocolate(int arr[],int n,int m)
{
    if(m > n)
    return -1;
    sort(arr,arr+n);
    int res = arr[m-1] - arr[0];
    for(int i=1;i+m-1<n;i++)
    res = min(res,(arr[i+m-1]-arr[i]));

    return res;

}

void printarray(int arr[],int n){
    for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
}
int main()
{
    int arr[]={5,4,2,9,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<Chocolate(arr,n,3);
    // printarray(arr,n);
}