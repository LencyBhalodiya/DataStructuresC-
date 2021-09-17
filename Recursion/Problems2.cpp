#include<iostream>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;
int countNaivesum(int arr[],int n ,int sum)
{
    // count the sum the subset which is equal to given sum
   for(int i=0;i<n;i++)
   {
       int res= 0;
       for(int j=i;j<n;j++)
       {
         res = res+arr[j];
         if(res==sum)
         {
             return 1;
         }
       }
   }
   return 0;
}
int countSubset(int arr[],int n,int sum){
    // count the sum the subset which is equal to given sum
    if(n==0){
        return (sum==0)?1:0;
    }
    return countSubset(arr,n-1,sum);
    + countSubset(arr,n-1,sum-arr[n-1]);
}
void Permutation(string str,int i=0){
    if(i==str.length()-1){
        cout<<str<<endl;
    }
    for(int j=i;j<str.length();j++)
    {
        swap(str[i],str[j]);
        Permutation(str,i+1);
        swap(str[j],str[i]);

    }
    
}


int main(){
    int arr[]={10,20,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 35;
    cout<<countSubset(arr,n,sum);
}