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
    Node *p = head;
    do{
        cout<<p->data<<" ";
        p = p->next;
    }while(p!=head);
}
Node *deleteAtBegin(Node *head)
{
  if(head == NULL) return NULL;
  if(head->next == head){
      delete head;
      return NULL;
  }
  Node *curr = head;
  while(curr->next!=head)
  curr = curr->next;

  curr->next = head->next;
  delete head;
  return (curr->next);
}
Node *deleteAtBeginPro(Node *head)
{
  if(head == NULL) return NULL;
  if(head->next == head){
      delete head;
      return NULL;
  }
   head->data = head->next->data;
   Node *temp = head->next;
   head->next = head->next->next;
   delete temp;
   return head;
}
int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp1;
    temp1->next = temp2;
    temp2->next = head;
    head = deleteAtBegin(head);
    printLinkedlist(head);
    return 0;
}