#include<iostream>
using namespace std;

// find the odd occuring number here in an array
void naive(int arr[],int n){
  for(int i=0;i<n;i++){
      int count =0;
      for(int j=0;j<n;j++){
          if(arr[j]==arr[i]){
              count++;
          }
      }
      if(count%2!=0){
          cout<<arr[i];
      }
  } 
}
// effective method to find the odd time occuring element in the array
int findodd(int arr[],int n){
    int res = 0;
    for(int i =0;i<n;i++){
        res =res^arr[i];
    }
    return res;
}
// question 1 given an array of n number that has values in range [1to n+1].every numbers appears exactly once.Hence find the missiing number

int missing(int arr[],int n){
    int res = 0;
    for(int i =0;i<n;i++){
        res =res^arr[i];
    }
    for(int i=1;i<=n+1;i++){
        res = res^i;
    }
    return res;
}
int main(){
    int arr[]={1,2,3,4,5,7};
    int n=sizeof(arr)/sizeof(int);
     cout<<missing(arr,n);

return 0;
}