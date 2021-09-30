#include<iostream>
#include<unordered_set>
using namespace std;
// find the subarray whose sum is equal to given sum

bool subarraysum(int arr[],int n,int sum)
{
    unordered_set<int> s;
     int preSum = 0;
     for(int i=0;i<n;i++)
      {
           preSum += arr[i];
          if(preSum == sum)
          return true;
         
         if(s.find(preSum-sum)!= s.end())
          return true;

          s.insert(preSum);
      }
      return false;
}
int main()
{
  int arr[]=  {5,1,-6,3,1,5,12};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<subarraysum(arr,n,18);
   return 0;
}