#include<iostream>
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
Node *sortedInsert(Node *head,int x)
{
    // insert an element in sorted linklist in proper position
    Node *temp = new Node(x);
    if(head == NULL)
    return temp;
    if(x < head->data)
    {
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    while(curr->next!=NULL && curr->next->data<x)
    {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}
int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp1;
    temp1->next = temp2;
    head = sortedInsert(head,25);
    printLinkedlist(head);
    return 0;
}