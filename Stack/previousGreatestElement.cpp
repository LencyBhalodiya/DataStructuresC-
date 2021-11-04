#include<bits/stdc++.h>
using namespace std;
// find the previous closest greater element in the array at the particular element
void previousGreater(int arr[],int n)
{
    // time complexity of this solution is o(n2);
    for(int i =0;i<n;i++)
    {
        int j;
        for( j= i-1;j>=0 ; j--){
            if(arr[j]>arr[i]){
                cout<<arr[j]<<" ";
                 break;
            }
        }
        if(j== -1)
        cout<<"-1"<<" ";
    }
}
void printPrevious(int arr[],int n)
{
    stack<int> s;
    s.push(arr[0]);
    cout<<"-1"<<" ";
    for(int i=1;i<n;i++)
    {
        while(s.empty() == false && s.top()<=arr[i])
        s.pop();

        int pg = (s.empty())?-1:s.top();
        cout<<pg<<" ";
        s.push(arr[i]);
    }
}
int main()
{
    int arr[]={5,1,9,2,8,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    printPrevious(arr,n);
    return 0;
}