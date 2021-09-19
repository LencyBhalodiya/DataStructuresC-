#include<iostream>
using namespace std;

void removeDuplicates(int arr[],int n)
{
  // naive solution which takes 0(n) and auxilary space 0(n);
    int temp[n];
    int res=1;
    temp[0]=arr[0];
  for(int i=1;i<n;i++)
  {
      if(temp[res-1]!=arr[i])
      {
          temp[res]=arr[i];
          res++;
      }
  }
  for(int i=0;i<res;i++)
  {
      arr[i]=temp[i];
      cout<<arr[i]<<" ";
  }
}
void EffectiveRemoveDuplicates(int arr[],int n){

  // effective solution which takes 0(n) time and space 0(1);
    int res =1;

  for(int i=1;i<n;i++){
    if(arr[i]!=arr[res-1])
    {
       arr[res]= arr[i];
       res++;
       
    }
  }
for(int i=0;i<res;i++)
{
  cout<<arr[i]<<" ";
}
  
}
int main(){
    int arr[]={1,1,1,2,4,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    removeDuplicates(arr,n);
    
}