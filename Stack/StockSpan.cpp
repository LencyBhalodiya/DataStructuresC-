#include<bits/stdc++.h>
using namespace std;

// find the stock span in the array
// you should find the consecutive previous element which is lesser than the given element;

void printSpan(int arr[],int n)
{
    for(int i =0;i<n;i++)
    {
        int span = 1;
        for(int j= i-1;j>=0 && arr[j] <= arr[i]; j--)
         span++;
         cout<<span<<" ";
    }
}
void printStockSpan(int arr[],int n)
{
    stack<int> s;
    s.push(0);
    cout<<"1"<<" ";
    for(int i=1;i<n;i++)
    {
        while(s.empty() == false && arr[s.top()]<=arr[i]){
            s.pop();
        }
        int span = s.empty()?i+1:i-s.top();
        cout<<span<<" ";
        s.push(i);
    }
}
int main()
{
    int arr[]={2,3,1,4,5,2,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printStockSpan(arr,n);
    return 0;
}