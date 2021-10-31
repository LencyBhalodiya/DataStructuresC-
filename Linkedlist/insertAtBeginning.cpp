#include<iostream>
using namespace std;

// insert the element int the beginning of the linklist

struct Node
{
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
Node *insertBegin(Node *head,int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}
Node *insertAtEnd(Node *head,int x)
{
    // insert element at the end of the linked list
    Node *temp = new Node(x);
    if(head == NULL)
    return temp;
    Node *curr = head;
    while(curr->next!=NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}
int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    head->next = temp1;
    head = insertBegin(head,5);
    head = insertAtEnd(head,2);
    head = insertAtEnd(head,22);

    printLinkedlist(head);
    return 0;
}