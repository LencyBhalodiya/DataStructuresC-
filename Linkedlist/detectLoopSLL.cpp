#include<iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node *next;
  Node(int x)
  {
      data = x;
      next = NULL;
  }
};
void printLinkedlist(Node *head)
{
  while(head!=NULL)
  {
    cout<<head->data<<" ";
    head = head->next;
  }
}
bool isLoop(Node *head)
{
    // detect whether the linkedlist contains loop or not
    Node *temp = new Node(1);
    Node *curr = head;
    while(curr!=NULL)
    {
        if(curr->next == NULL)
         return false;
         if(curr->next == temp)
          return true;
        
        Node *curr_next = curr->next;
        curr->next = temp;
        curr = curr_next;
    }
    return false;
}
bool isLoopHashing(Node *head)
{
    unordered_set<Node *>s;
    for(Node *curr = head; curr!=NULL;curr=curr->next)
    {
        if(s.find(curr)!=s.end())
        return true;
        s.insert(curr);
    }
    return false;
}
int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    Node *temp3 = new Node(50);
    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;
    // temp3->next = temp2;
    cout<<isLoopHashing(head);
    return 0;
}