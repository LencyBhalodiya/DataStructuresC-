#include<iostream>
#include<unordered_set>
using namespace std;
// find the subarray whose sum is equal to 0
bool subarrayzero(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        bool flag = false;
         int currSum = 0;
        for(int j=i;j<n;j++)
        {
            currSum+=arr[j];
            if(currSum == 0)
              return true;
        }
    }
    return false;
}
bool subarray0(int arr[],int n)
{
    unordered_set<int> h;
    int pre_sum = 0;
    for(int i=0;i<n;i++)
    {
        pre_sum+=arr[i];
        if(h.find(pre_sum)!=h.end())
         return true;
        if(pre_sum == 0)
         return true;
        h.insert(arr[i]);
    }
    return false;
}
int main()
{
  int arr[]=  {1,1,-6,3,6,12};
  int n = sizeof(arr)/sizeof(arr[0]);
   cout<<subarrayzero(arr,n);
   return 0;
}