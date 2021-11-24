#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> pq; //this create max heap
    priority_queue<int,vector<int>,greater<int>> p; // creates min heap
    p.push(10);
    p.push(34);
    p.push(43);
    p.push(3);
     
   cout<<p.size()<<" "<<endl;
   cout<<p.top()<<endl;
   while(p.empty() == false)
   {
       cout<<p.top()<<" ";
       p.pop();
   }
//    another way of the constructor
  int arr[] = {10,5,3,54};
   priority_queue<int> pg(arr,arr+3);
   cout<<endl;
   while(pq.empty() == false)
   {
       cout<<pg.top()<<" ";
       pq.pop();
   }
   return 0;
}