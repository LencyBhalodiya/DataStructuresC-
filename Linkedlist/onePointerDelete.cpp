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
void deleteNode(Node *ptr)
{
    // delete node with only pointer given to a particular node
    Node *temp = ptr->next;
    ptr->data = temp->data;
    ptr->next = temp->next;
    delete temp;
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
    deleteNode(head);
    printLinkedlist(head);
    return 0;
}