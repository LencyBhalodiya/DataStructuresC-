#include<iostream>
using namespace std;

void rotation(int arr[],int n)
{
    // just for one rotation
  int temp = arr[0];
  for(int i=0;i<n;i++)
  {
      arr[i]=arr[i+1];
  }
  arr[n-1]=temp;
  
}
void Drotate(int arr[],int n,int rotate)
{
    // n rotation using recursion
    for(int i=0;i<rotate;i++)
    {
     rotation(arr,n);
    }
}
void Drotation(int arr[],int n,int d)
{
    // Effective method
    int temp[d];
    for(int i=0;i<d;i++){
        temp[i]=arr[i];
    }
    for(int i=d;i<n;i++){
        arr[i-d]=arr[i];
    }
    for(int i=0;i<d;i++){
        arr[n-d+i]=temp[i];
    }

}
void reverse(int arr[],int low,int high){
    
    while(low<high){
        int temp = arr[low];
        arr[low]= arr[high];
        arr[high]=temp;
        low++;
        high--; 
    }
    
}
void leftRotateRecursion(int arr[],int n,int rotate)
{
    // Effective method using recursion
    reverse(arr,0,rotate-1);
    reverse(arr,rotate,n-1);
    reverse(arr,0,n-1);
}

int main(){
  int arr[]={1,2,5,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    leftRotateRecursion(arr,n,2);
  for(int i=0;i<n;i++)
  {
      cout<<arr[i]<<" ";
  }
}