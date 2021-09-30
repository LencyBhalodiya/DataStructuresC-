#include<iostream>
#include<unordered_map>
using namespace std;
// find the longest subarray with equal no of 0s and 1s
int longestsub(bool arr[],int n)
{
    int res = 0;
     for(int i=0;i<n;i++)
     {
         int co =0;
         int c1 = 0;
         for(int j=i;j<n;j++)
         {
             if(arr[j]==0)
             co++;
             else
              c1++;
              if(co == c1)
              res = max(res,j-i+1);
         }
     }
     return res;
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
int longsubarray(int arr[],int n)
{
    unordered_map<int,int> h;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        arr[i] = -1;
    }
    int res = maxlength(arr,n,0);
    return res;

}
int main()
{
  int  arr[]=  {1,0,0,0,1,0,1};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<longsubarray(arr,n);
   return 0;
}