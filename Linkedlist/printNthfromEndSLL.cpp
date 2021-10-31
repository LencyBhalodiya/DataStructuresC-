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
void presentNthFromEnd(Node *head,int n)
{
    // print the given position from end;
   int length = 0;
   for(Node *curr = head; curr!= NULL ; curr = curr->next)
    length++;
 
   if(length<n)
   return;

   Node *curr = head;
   for(int i=1;i<length-n+1;i++){
    curr = curr->next;
   }
     
   cout<<(curr->data)<<" ";
}
void presentNthFromEndPro(Node *head,int n)
{
    // both solution have same time complexity
    // but this uses two pointer approach
   if(head == NULL) return  ;
   Node *first = head;
   for(int i=0;i<n;i++)
   {
       if(first == NULL) return ;
       first = first->next;
   }
   Node *second = head;
   while(first!=NULL)
   {
       second = second->next;
        first = first->next;
   }
   cout<<(second->data);
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
    presentNthFromEndPro(head,2);
    // printLinkedlist(head);
    return 0;
}