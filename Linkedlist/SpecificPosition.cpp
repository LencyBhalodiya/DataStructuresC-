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
Node *insertPos(Node *head, int pos,int data)
{
  Node *temp = new Node(data);
  if(pos == 1)
  {
      temp->next = head;
      return temp;
  }
  Node *curr = head;
  for(int i=1;i<=pos-2 &&curr!=NULL;i++)
  {
     curr = curr->next;
  }
  if(curr == NULL)
   return head;

   temp->next = curr->next;
   curr->next = temp;
   return head;
}
Node *deletePos(Node *head,int pos)
{
  Node *temp = head;
  if(pos == 1)
  {
    head = head->next;
    delete temp;
    return head;
  }else{
  Node *ptr = head->next;
   for(int i=1;i<pos-1;i++)
   {
     temp = temp->next;
     ptr = ptr->next;
   }
   temp->next = ptr->next;
   delete ptr;
   return head;
  }
}
int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp1;
    temp1->next = temp2;
    // insertPos(head,3,25);
    printLinkedlist(head);
    head =  deletePos(head,1);
    cout<<endl<<"Linkedlist after the deletion: "<<endl;
    printLinkedlist(head);
    return 0;
}