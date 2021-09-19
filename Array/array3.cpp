#include<iostream>
using namespace std;

void Moving0end(int arr[],int n)
{
    // naive solution
   int temp[n];
    int j=0;
   for(int i=0;i<n;i++)
   {
       if(arr[i]>0){
           temp[j++]=arr[i];
       }
   }
   for(int i=0;i<n;i++)
   {
       if(arr[i]==0){
           temp[j++]=arr[i];
       }
   }
   for(int i=0;i<n;i++)
   {
       arr[i]=temp[i];
   }
   for(int i=0;i<n;i++)
   {
       cout<<arr[i]<<" ";
   }
}
void NaiveEndZero(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[j]!=0)
                {
                    swap(arr[i],arr[j]);
                    
                }
            }
        }
    }
     for(int i=0;i<n;i++)
   {
       cout<<arr[i]<<" ";
   }
}
void efficientendZero(int arr[],int n){
    int count =0;
    for(int  i=0;i<n;i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[i],arr[count]);
            count++;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
}
int main(){
    int arr[]={1,2,0,0,4,4};
    int n = sizeof(arr)/sizeof(arr[0]);
   NaiveEndZero(arr,n);
}