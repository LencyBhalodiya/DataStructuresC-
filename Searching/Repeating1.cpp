#include<iostream>
using namespace std;
//  find the only one element which is repeating in the array n no of times 
// also in this array 0 is always and every number is present in array which is less than max number is the array
// therefore we conclude that 0<arr[max]<n-2
int findR(int arr[],int n)
{
    int slow = arr[0];
    int fast = arr[0];
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow!=fast);
    slow = arr[0];
    while(slow!=fast){
      slow = arr[slow];
      fast = arr[fast];
    }
    return slow;
}
int main()
{
  int arr[]={1,3,4,5,4,56,7,8};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<findR(arr,n);
}