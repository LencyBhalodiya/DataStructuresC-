#include<bits/stdc++.h>
using namespace std;

void printMax(int arr[],int k,int n)
{
    deque<int> d;
    for(int i=0;i<k;i++)
    {
        while(!d.empty() && arr[i]>=arr[d.back()])
        d.pop_back();
        d.push_back(i);
    }
    for(int i=k;i<n;i++)
    {
        cout<<arr[d.front()]<<" ";
        while(!d.empty() && d.front()<=i-k)
        d.pop_front();
        while(!d.empty() && arr[i]>=arr[d.back()])
        d.pop_back();
        d.push_back(i);
    }
    cout<<arr[d.front()]<<" ";
}
int main()
{
    int arr[] = {2,8,7,44,2,112,44,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printMax(arr,3,n);
    return 0;
}