#include<iostream>
#include<unordered_set>
using namespace std;
// find the pair whose sum is equal to the given number
bool pairsum(int arr[],int n,int sum)
{
    for(int i=0;i<n;i++)
     for(int j=i+1;j<n;j++)
      if(arr[i]+arr[j]==sum)
        return true;

  return false;
}
bool isPair(int arr[],int n,int sum)
{
    unordered_set<int> s;
    for(int i=0;i<n;i++)
    {
        if(s.find(sum-arr[i])!= s.end())
         return true;
         
         s.insert(arr[i]);
    }
    return false;
}
int main()
{
  int arr[]=  {10,10,2,5,6,4,3,12};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<isPair(arr,n,27);

   return 0;
}