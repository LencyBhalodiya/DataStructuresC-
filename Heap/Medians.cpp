#include<bits/stdc++.h>
using namespace std;
// find the median of the array 
void printMedian(int arr[],int n )
{
 priority_queue<int> s;
 priority_queue<int,vector<int>,greater<int>> g;
 s.push(arr[0]);
 cout<<arr[0]<<endl;

 for(int i =1 ; i<n ; i++)
 {
     int x = arr[i];
     if(s.size() > g.size())
     {
         if(s.top() > x)
          {
              g.push(s.top());
              s.pop();
              s.push(x);
          }
          else
          g.push(x);
          cout<<(s.top() + g.top())/2.0<<endl;  
     }
     else{
         if(x <= s.top())
         s.push(x);
         else{
             g.push(x);
             s.push(g.top());
             g.pop();
         }
         cout<<s.top()<<endl;
     }
 }
}
int main()
{
    int arr[]= {5,11,10,20,8,25,18};
    int n = sizeof(arr)/sizeof(arr[0]);
    printMedian(arr,n);
    return 0;
}