#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
struct MyStack
{
    int *arr;
    int cap;
    int top;
  MyStack(int c)
  {
      cap = c;
      arr = new int[cap];
      top = -1;
  }
  void push(int x)
  {
      if(top == cap-1)
      {
          cout<<"stack overflow";
      }
      top++;
      arr[top] = x;
  }
  int pop()
  {
      if(top == -1)
      {
        cout<<"stack underflow";
      }
      int res = arr[top];
      top--;
      return res;
  }
  int peek()
  {
      if(top == -1)
      {
          cout<<"stack is empty";
      }
      return arr[top];
  }
  int size()
  {
      return (top+1);
  }
  bool isEmpty()
  {
      return (top== -1);
  }
};
struct Mystack 
{
  vector<int> v;
  void push(int x)
  {
      v.push_back(x);
  }
  int pop(){
      int res = v.back();
      v.pop_back();
      return res;
  }
  int size()
  {
      return v.size();
  }
  bool isEmpty()
  {
      return v.empty();
  }
  int peek()
  {
      return v.back();
  }
};
int main()
{
    MyStack s(6);
    s.push(5);
    s.push(17);
    cout<<s.size()<<endl;
    return 0;
}