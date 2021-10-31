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
Node *deleteAtKth(Node *head,int k)
{
  if(head == NULL) return NULL;
  if(k == 1){
    return deleteAtBeginPro(head);
  }
  Node *curr = head;
  for(int i=0;i<k-2;i++)
      curr = curr->next;
   Node *temp = curr->next;
   curr->next = curr->next->next;
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
    head = deleteAtKth(head,2);
    printLinkedlist(head);
    return 0;
}