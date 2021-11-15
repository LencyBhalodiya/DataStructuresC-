#include<bits/stdc++.h>
using namespace std;
// given the coin available find the minimum coin to give the change for an given amount
int miCoins(int coins[],int n,int amount)
{
  int res = 0;
  for(int i=0;i<n;i++)
  {
      if(coins[i]<=amount)
      {
          int c = floor(amount/coins[i]);
          res = res + c;
          amount = amount - c*coins[i];
      }
      if(amount == 0)
      break;
  }
  return res;
}
int main()
{
    int arr[] = {5,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<miCoins(arr,n,16);
    return 0;
}