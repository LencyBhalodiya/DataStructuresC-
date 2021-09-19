#include<iostream>
using namespace std;

int majority(int arr[],int n)
{
   //naive solution or brute force approach
   for(int i=0;i<n;i++)
   {
       int count =1;
       for(int j=i+1;j<n;j++)
       {
           if(arr[i]==arr[j])
           {
              count++;
           }
           if(count >n/2)
           {
            return arr[i];
           }
       }
   }
   return -1;
}
int majorityE(int arr[],int n)
{
  int ansIndex =0;
  int countt =1;
  for(int i=0;i<n;i++){
      if(arr[i]==arr[ansIndex])
      {
          countt+=1;
      }else{
      countt-=1;
      }
      if(countt==0)
      {
          ansIndex =i;
          countt =1;
      }
  }
  countt=0;
  for(int i=0;i<n;i++)
  {
      if(arr[ansIndex]==arr[i])
      countt+=1;
      if(countt<=n/2)
      ansIndex= -1;
  }
  return ansIndex;
}
int main()
{
  int arr[]={0,1,2,34,4,6};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<majorityE(arr,n);
}