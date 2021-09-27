#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

void cyclesort(int arr[],int n)
{
for(int cs=0;cs<n-1;cs++)
{
    int item = arr[cs];
    int pos = cs;
    for(int i = cs+1;i<n;i++)
    {
        if(arr[i]<item)
        pos++;
    }
        if(pos == cs)
         continue;
        while(item == arr[pos])
         pos+=1;

    swap(item,arr[pos]);

    while(pos!=cs){
        pos = cs;
        for(int i= cs+1; i<n; i++)
        {
            if(arr[i]<item)
            pos++;
        }
        while(item == arr[pos])
        pos++;
        swap(item,arr[pos]);
    }
}
}
void printarray(int arr[],int n){
    for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
}
int main()
{
    int arr[]={5,3,7,6,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cyclesort(arr,n);
    printarray(arr,n);
}