#include<iostream>
#include<unordered_map>
using namespace std;

void printFreq(int arr[],int n)
{
   for(int i=0;i<n;i++)
  {
      bool flag = false;
      for(int j=0;j<i;j++)
       if(arr[i] == arr[j])
       {
           flag = true;
           break;
       }
       if(flag == true)
       {
           continue;
       }
       int freq = 1;
       for(int j=i+1;j<n;j++)
       {
           if(arr[i]==arr[j])
           {
               freq++;
           }
       }
         cout<<arr[i]<<" "<<freq<<endl;
  }
}
int countFr(int arr[],int n)
{
    unordered_map<int,int> h;
    for(int i = 0; i < n; i++)
        h[arr[i]]++;

    for(auto i: h)
    cout<<i.first<<" "<<i.second<<endl;
}
int main()
{
  int arr[]=  {5,10,23,7,7,5,10,7};
  int n = sizeof(arr)/sizeof(arr[0]);
   printFreq(arr,n);
   return 0;
}