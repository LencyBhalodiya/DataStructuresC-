#include<iostream>
#include<algorithm>
using namespace std;
// sort the two array of different types
void hoare(int arr[],int n)
{
    int i=-1;
    int j = n+1;
      while(true)
  {
      do{
          i++;
      }while(arr[i] < 0);

      do{
          j--;
      }while(arr[j] >= 0);

        if(i>=j) 
        return ;

       swap(arr[i],arr[j]);
  }
}



void printarray(int arr[],int n){
    for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
}
int main()
{
    int arr[]={5,4,-2,9,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    hoare(arr,n);
    printarray(arr,n);
}