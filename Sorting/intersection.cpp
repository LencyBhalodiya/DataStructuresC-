#include<iostream>
using namespace std;
// stable algo and follow divide and conquer rules
// takes nlogn and n aux space
// well suited for linked list works of 0{1} aux space

void intersection(int a[],int b[],int n,int m)
{
    // naive solution which takes n2 time complexity
  for(int i=0;i<n;i++)
  {
      if(i>0 && a[i] == a[i-1])
      continue;
      for(int j=0;j<m;j++)
      {
          if(a[i]==b[j])
          {
              cout<<a[i]<<" ";
              break;
          }
      }
  }
}
void intersection2(int a[],int b[],int n,int m)
{
    int i=0,j=0;
    while(i<m && j<n)
    {
        if(i>0 && a[i]==a[i-1])
        {
            i++;
            continue;
        }
        if(a[i]<b[j])
        i++;
        else if(a[i] > b[j])
        j++;
        else{
            cout<<a[i]<<" ";
            i++;
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
    int a[]={2,23,45,46,67};
    int b[]={2,23,34,46,67};
    int n = sizeof(a)/sizeof(a[0]);
    int m = sizeof(b)/sizeof(b[0]);
    intersection2(a,b,n,m);
    
    
    
}