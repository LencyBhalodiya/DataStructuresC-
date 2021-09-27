#include<iostream>
using namespace std;
// find the inversion of the array which satisfy the following condition where i<j and arr[i]>arr[j]

int countInverse(int arr[],int n)
{
//   naive solution
int count = 0;
for(int i=0;i<n;i++)
{
    for(int j=i+1;j<n;j++)
    {
        if(arr[i]>arr[j])
        count++;
    }
}
return count++;
}
int countandMerge(int arr[],int l,int m,int r)
{
    int n1 = m - l + 1;
  int n2 = r - m;

  int left[n1], right[n2];

  for (int i = 0; i < n1; i++)
    left[i] = arr[l + i];
  for (int j = 0; j < n2; j++)
    right[j] = arr[m + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = l;
  int res =0;

  while (i < n1 && j < n2) {
    if (left[i] <= right[j]) {
      arr[k] = left[i];
      i++;
    } else {
      arr[k] = right[j];
      j++;
      res = res+(n1-i);
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = left[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = right[j];
    j++;
    k++;
  }
return res;
}
int countInv(int arr[],int l,int r)
{
    int res=0;
    if(l<r)
    {
        int m = l+(r-l)/2;
        res += countInv(arr,l,m);
        res += countInv(arr,m+1,r);
        res += countandMerge(arr,l,m,r);
    }
    return res;
}
void printarray(int arr[],int n){
    for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
}
int main()
{
    int arr[]={2,4,1,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<countInv(arr,0,n)<<endl;
    return 0;
}