#include<bits/stdc++.h>
using namespace std;

// find the next first greater element of an given index or number
void nextGreater(int arr[],int n)
{
    for(int i =0;i<n;i++)
    {
       for(int j=i+1;j<n;j++)
       {
           if(arr[j]>arr[i]){
               cout<<arr[j]<<" ";
               break;
           }
           if(j==n-1)
           cout<<"-1"<<" ";
       }
    }
}
void greaterElementStack(int arr[],int n)
{
    stack<int> s;
    s.push(arr[n-1]);
    cout<<"-1"<<" ";
    for(int i =n-2;i>=0;i--)
    {
        while(s.empty() == false && s.top()<=arr[i])
         s.pop();

         int nextGreater = s.empty()?-1:s.top();
         cout<<nextGreater<<" ";
         s.push(arr[i]);
        //  this prints in the reverse order
        // if you want to print in correct order than use vector and get values store in vector and then reverse the vector and then print the value
    }
 
}
int main()
{
    int arr[]={5,4,3,2,1,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    greaterElementStack(arr,n);
    return 0;
}