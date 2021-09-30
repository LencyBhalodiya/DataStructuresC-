#include<iostream>
#include<unordered_set>
using namespace std;
// find the number of element which is formed by the union of the two array
int  unionset(int arr[],int arr2[],int n,int m)
{
  int c[m+n];
  for(int i=0;i<m;i++)
    c[i]=arr[i];
  for(int i=0;i<n;i++)
   c[m+i] = arr2[i];
    
   int res =0;
   for(int i=0;i<m+n;i++)
   {
     bool flag = false;
     for(int j=0;j<i;j++)
     {
         if(c[i]==c[j])
         {
             flag = true;
             break;
         }
     }
     
       if(flag == false)
        res++;
   }
   return res;
}
int findUnion(int arr[],int arr2[],int n,int m)
{
    unordered_set<int> s;
    for(int i=0;i<n;i++)
    s.insert(arr[i]);
    for(int i=0;i<m;i++)
    s.insert(arr2[i]);
    return s.size();


}
int main()
{
  int arr[]=  {10,10};
  int arr2[]={10,2,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  int m = sizeof(arr2)/sizeof(arr2[0]);
  cout<<unionset(arr,arr2,n,m);
   return 0;
}