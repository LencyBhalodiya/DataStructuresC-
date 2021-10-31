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
void Middleprint(Node *head)
{
    // print the middle element of the linklist naive solution
    int  count = 0;
   if(head == NULL)
    cout<<"No element present";
   if(head->next == NULL)
   cout<<head->data;  
   Node *curr;
   for(curr = head; curr!=NULL;curr = curr->next)
    count++;

    curr = head;
    for(int i=0;i<count/2;i++)
     curr = curr->next;

     cout<<curr->data;
}
void MiddleprintPro(Node *head)
{
   if(head == NULL)
    return;
    
    Node *slow = head;
    Node *fast = head;
    while(fast!= NULL && fast->next!=NULL);
    {
        slow = slow->next;
        fast = fast->next->next;
    }
     cout<<(slow->data);
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
     MiddleprintPro(head);
    // printLinkedlist(head);
    return 0;
}