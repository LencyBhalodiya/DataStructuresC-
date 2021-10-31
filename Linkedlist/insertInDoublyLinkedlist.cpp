#include<iostream>
using namespace std;
// define doubly linklist
struct Node
{
  int data;
  Node *prev;
  Node *next;
  Node(int x)
  {
      data = x;
      prev = NULL;
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
Node *insertAtBegin(Node *head,int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    if(head!=NULL)
     head->prev = temp;

    return temp;
}
Node *insertAtEnd(Node *head,int x)
{
    Node *temp = new Node(x);
    if(head == NULL){
     return temp;
    }
    Node *curr = head;
    while(curr->next!= NULL)
        curr = curr->next;
     
     curr->next =temp;
     temp->prev = curr;
     return head;
}
int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;
    head = insertAtBegin(head,5);
    head = insertAtEnd(head,35);
    printLinkedlist(head);
    return 0;
}