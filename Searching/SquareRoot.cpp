#include<iostream>
using namespace std;
// find the nearest square root of the element  
int square(int n)
{
  int i=1;
  while(i*i<=n)
   i++;
  return i-1;
}
int sqRootBinary(int x)
{
    int low =1,high =x,ans =-1;
    while (low<=high)
    {
        int mid = (low+high)/2;
        int msq = mid*mid;
        if(msq==x)
        return mid;
        else if(msq>x)
        high=mid-1;
        else{
            low = mid+1;
            ans = mid;
        }
    }
    return ans;
    
}
int main()
{
 cout<<sqRootBinary (24);
}