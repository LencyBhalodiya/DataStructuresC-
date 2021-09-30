#include<iostream>
#include<unordered_map>
using namespace std;
// find the longest subarray whose sum is equal to the givensum
int longestsubarray(int arr[],int n,int sum)
{ 
    int res=0;
    for(int i=0;i<n;i++)
    {
         int currSum = 0;
        for(int j=i;j<n;j++)
        {
            currSum+=arr[j];
            if(currSum == sum)
            {
                res = max(res,j-i);
            }
        }
    }
  return res+1;
}
int maxlength(int arr[],int n,int sum)
{
  unordered_map<int,int> m;
  int preSum = 0;
  int res = 0;
  for(int i=0;i<n;i++)
  {
      preSum += arr[i];
      if(preSum == sum){
          res = i+1;
      }
      if(m.find(preSum) == m.end())
      {
          m.insert({preSum,i});
      }
      if(m.find(preSum-sum)!= m.end())
       res = max(res,i-m[preSum-sum]);
  }
  return res;
}

int main()
{
  int arr[]=  {2,3,4,5,5,-2,3,-3};
  int n = sizeof(arr)/sizeof(arr[0]);
   cout<<maxlength(arr,n,0);
   return 0;
}