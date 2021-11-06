#include<bits/stdc++.h>
using namespace std;
// design the deque of the following properties 
// getmin, getmax, extractmin,extractmax,insertmax,insertmin;
struct MyDS{
 deque<int> dq;
 void inserntMin(int x){
     dq.push_front(x);
 }
 void insertMax(int x){
     dq.push_back(x);
 }
 int getMin(){
     return dq.front();
 }
 int getMax(){
     return dq.back();
 }
 int extractMin()
{
    return dq.pop_front();
} 
int extractMax(){
    return dq.pop_back();
}
};
int main()
{

    deque<int> dq;
    return 0;
}