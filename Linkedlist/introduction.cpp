#include<iostream>
using namespace std;
// traverse the linkedlist using the recursive and while loop method
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
void recursivePrint(Node *head)
{
  if(head == NULL)
   return;   
   cout<<head->data<<" ";
   recursivePrint(head->next);
}
int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    temp1->next = new Node(30);//another method of representation of creating new node
    head->next = temp1;
    recursivePrint(head);
    return 0;
}