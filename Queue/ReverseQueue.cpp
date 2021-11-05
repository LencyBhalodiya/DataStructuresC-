#include<iostream>
#include<bits\stdc++.h>
using namespace std;
// reverse the queue 
 void Print(queue<int>& Queue)
{
    while (!Queue.empty()) {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}
 
 void reverse(queue<int> &q)
 {
     stack<int> s;
     while(q.empty()== false)
     {
         s.push(q.front());
         q.pop();
     }
     while(s.empty() == false)
     {
         q.push(s.top());
         s.pop();
     }
 }
 void reverseRecursive(queue<int> &q)
 {
     if(q.empty())
     return;
     int x = q.front();
     q.pop();
     reverseRecursive(q);
     q.push(x);
 }
int main()
{
    queue<int> q;
    q.push(4);
    q.push(2);
    q.push(3);
    q.push(5);
    reverseRecursive(q);
    Print(q);
    return 0;
}