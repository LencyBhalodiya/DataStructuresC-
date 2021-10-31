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
    // detection of the cycle using floyd cycle detection method
    Node *slow = head;
    Node *fast = head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        return true;
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
    temp3->next = temp2;
    cout<<isLoop(head);
    return 0;
}