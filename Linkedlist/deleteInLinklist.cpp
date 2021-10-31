#include<iostream>
using namespace std;

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
Node *deleteHead(Node *head)
{
    // delete node at the head of the linklists
    if(head == NULL){
     return NULL;
    }
     else{
         Node *temp = head;
         head = head->next;
         delete temp;
         return head;
     }
}
Node *deleteAtEnd(Node *head)
{
    // delete a node at the end of the linklist
    if(head == NULL){
     return NULL;
    }
    if(head->next == NULL)
    {
        delete head;
        return NULL;
    }
    Node*curr = head;
    while(curr->next->next!=NULL)
    {
        curr = curr->next;
    }
    delete(curr->next);
    curr->next = NULL;
    return head;
}
int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp1;
    temp1->next = temp2;
    head = deleteHead(head);
    printLinkedlist(head);
    return 0;
}