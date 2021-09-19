#include<iostream>
using namespace std;

int MaxevenOdd(int arr[], int n)
{
    int res =1;
    for(int i=0;i<n;i++)
    {
        int curr =1;
      for(int j =i+1;j<n;j++)
      {
          if((arr[j]%2 == 0 && arr[j-1]%2!= 0)|| (arr[j]%2!=0 && arr[j-1]%2 ==0))
          {
            curr++;
          }else break;
      }
      res =max(res,curr);
    }
    return res;
}
int MaxevenOddE(int arr[], int n)
{
    int res = 1;
    int current = 1 ; 
    for(int i=1;i<n;i++)
    {
        if((arr[i]%2 == 0 && arr[i-1]%2!= 0)|| (arr[i]%2!=0 && arr[i-1]%2 ==0))
        {
            current++;
            res = max(res,current);
        }else{
            current = 1;
        }
    }
    return res;
}
int main()
{
  int arr[]={1,2,3,4,6};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<MaxevenOddE(arr,n);
}