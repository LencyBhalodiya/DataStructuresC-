#include<iostream>
#include<algorithm>
using namespace std;
// stable algo and follow divide and conquer rules
// takes nlogn and n aux space
// well suited for linked list works of 0{1} aux space

void Union(int a[],int b[],int m,int n)
{
    int c[m+n];
    for(int i=0;i<n;i++)
        c[i]=a[i];
    for(int i=0;i<m;i++)
      c[n+i]=b[i];
      sort(c,c+m+n);
      for(int i=0;i<m+n;i++)
      {
          if(i==0 || c[i]!=c[i-1])
          cout<<c[i]<<" ";
      }  
}
void Union2(int a[],int b[],int m,int n)
{
      int i=0,j=0;
    while(i<m && j<n)
    {
        if(i>0 && a[i]==a[i-1])
        {
            i++;
            continue;
        }
         if(j>0 && a[j]==a[j-1])
        {
            j++;
            continue;
        }
        if(a[i]<b[j]){
        cout<<a[i]<<" ";
        i++;
        }
        else if(a[i] > b[j])
        {
          cout<<b[j]<<" ";
          j++;
        }
        else if(a[i] == b[j]){
            cout<<a[i]<<" ";
            i++;
            j++;
        }
    }
    while(i<n){
        if(i>0 && a[i]!= a[i-1])
        {
            cout<<a[i]<<" ";
            i++;
        }
    }
    while(i<m){
        if(j>0 && a[j]!= a[j-1])
        {
            cout<<a[j]<<" ";
            j++;
        }
    }
}

void printarray(int arr[],int n){
    for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
}
int main()
{
    int a[]={2,23,23,45,46,67};
    int b[]={2,23,34,46,67};
    int n = sizeof(a)/sizeof(a[0]);
    int m = sizeof(b)/sizeof(b[0]);
    Union2(a,b,n,m);
    
    
    
}