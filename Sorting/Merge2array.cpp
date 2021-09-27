#include<iostream>
using namespace std;
// stable algo and follow divide and conquer rules
// takes nlogn and n aux space
// well suited for linked list works of 0{1} aux space

void mergeTwoArray(int a[],int b[],int n,int m)
{
    int i=0,j=0;
    while(i<m && j<n)
    {
        if(a[i]<=b[j]){
        cout<<a[i]<<" ";
          i++;
        }else{
            cout<<b[j]<<" ";
            j++;
        }
    }
    while(i<n){
        cout<<a[i]<<" ";
        i++;
    }
    while(j<m){
        cout<<a[j]<<" ";
        j++;
    }
    
}
void printarray(int arr[],int n){
    for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
}
int main()
{
    int a[]={2,23,45,46,67};
    int b[]={13,23,34,48,88};
    int n = sizeof(a)/sizeof(a[0]);
    int m = sizeof(b)/sizeof(b[0]);
    mergeTwoArray(a,b,n,m);
    
    
    
}