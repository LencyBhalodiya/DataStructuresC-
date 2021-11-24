#include<bits/stdc++.h>
using namespace std;
// print the closest k elements of element x;
void printKClosest(int arr[],int n,int k,int x)
{
    //time complexity is 0(n2) and space complexity is 0(n)
    bool visited[n] = {false};
    for(int i = 0; i < k; i++)
    {
        int minDiff = INT_MAX;
        int minDIndex ;
        for(int j = 0 ; j < n ; j++)
        {
            if(visited[j] == false && abs(arr[j] -x)<= minDiff)
            {
               minDiff = abs(arr[j]-x);
               minDIndex = j;
            }
        }
        cout<<arr[minDIndex]<<" ";
        visited[minDIndex] = true;
    }
}
void kClosest(int arr[],int n , int k , int x)
{
    priority_queue<pair<int, int> > p ;
    for(int i = 0 ; i< k ; i++)
      p.push({ abs(arr[i] - x), i });

        for (int i = k; i < n; i++) {
         int diff = abs(arr[i] - x);

        if (diff < p.top().first){
        p.pop();
        p.push({ diff, i });
        }
    }
    while (p.empty() == false) {
        cout << arr[p.top().second] << " ";
        p.pop();
    }
}
 

int main()
{
    int arr[]= {5,11,10,20,8,25,18};
    int n = sizeof(arr)/sizeof(arr[0]);
    kClosest(arr,n,3,9);
    return 0;
}