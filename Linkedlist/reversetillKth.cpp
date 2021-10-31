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

// remove duplicates from the sorted array
 Node *reverseKth(Node *head,int k)
 {
     Node*curr = head;
     Node *prev = NULL,*next = NULL;
     int count = 0;
     while(curr!=NULL && count < k)
     {
         next = curr->next;
         curr->next = prev;
         prev = curr;
         curr = next;
         count++;
     }
     if(next!=NULL)
     {
         Node *rest_head =  reverseKth(next,k);
         head->next = rest_head;
     }
     return prev;
 }
  Node *reverseKthiterative(Node *head,int k)
 {
    //  code not working
     Node*curr = head,*prevfirst = NULL;
     bool isFirstPass = true;
     while(curr!=NULL)
     {
         Node *first = curr,*prev = NULL;
         int count = 0;
         while(curr!=NULL && count< k)
         {
             Node *next = curr->next;
             curr->next = prev;
             prev = curr;
             curr = next;
             count++;
         }
         if(isFirstPass)
         {
             head = prev;
             isFirstPass = false;
         }else{
             prevfirst->next = prev;
             prevfirst  = first;
         }
     }
     return head;
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
     head= reverseKthiterative(head,2);
    printLinkedlist(head);
    return 0;
}