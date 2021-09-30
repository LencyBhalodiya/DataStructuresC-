#include<iostream>
#include<unordered_map>
using namespace std;
// find the common longest sum of subarray between two arrays
int longTwoArray(int a[],int  b[],int m,int n)
{
    int res = 0;
    for(int i=0;i<n;i++)
    {
        int sum=0,sum2=0;
        for(int j=i;j<n;j++)
        {
            sum+=a[j];
            sum2+=b[j];
            if(sum = sum2)
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
int longsub(int a[],int b[],int h ,int n)
{
    unordered_map<int,int> m;
    int temp[n],pre_sum=0;
    int sum = 0;
    for(int i=0;i<n;i++)
    temp[i]= a[i]-b[i];
    int res = maxlength(temp,n,0);
    return res;
}

int main()
{
  int  arr[]=  {0,1,0,1,1};
  int arr2[]={0,0,1,0,0};
  int n = sizeof(arr)/sizeof(arr[0]);
  int m = sizeof(arr2)/sizeof(arr[0]);
  cout<<longsub(arr,arr2,n,m);
   return 0;
}