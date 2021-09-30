#include<iostream>
#include<unordered_set>
using namespace std;
// find the interestion of 2 array or no of element which is same is both array
int  intersection(int arr[],int arr2[],int n,int m)
{
  int res =0;
  for(int i=0;i<n;i++)
  {
      bool flag = false;
      for(int j=0;j<i-1;j++)
       if(arr[j] == arr[i])
       {
           flag = true;
           break;
       }
       if(flag == true)
       {
           continue;
       }
       for(int j=0;j<n;j++)
       {
           if(arr[i]==arr2[j])
           {
               res++;
               break;
           }
       }
  }
  return res;
}
int intersectionset(int arr[],int arr2[],int n,int m)
{
    unordered_set<int> s;
    for(int i=0;i<n;i++)
        s.insert(arr[i]);
    int res = 0;
    for(int j=0;j<n;j++)
    {
        if(s.find(arr2[j])!=s.end())
        {
            res++;
            s.erase(arr2[j]);
        }
    }
    return res;
}
int main()
{
  int arr[]=  {10,23,5,10,7};
  int arr2[]={23,3,5,66,10,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  int m = sizeof(arr2)/sizeof(arr2[0]);
  cout<<intersectionset(arr,arr2,n,m);
   return 0;
}