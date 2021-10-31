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
Node *insertBegin(Node *head,int x)
{
    Node *temp = new Node(x);
    if(head==NULL){
     temp->next = temp;
     return temp;
    }
     else{
         Node *curr = head;
         while(curr->next!= head)
          curr = curr->next;
          temp->next = head;
          curr->next = temp;
          return temp;
     }
}
Node *insertBeginPro(Node *head,int x)
{
    // time complexity is O(1);
    Node *temp = new Node(x);
    if(head==NULL){
     temp->next = temp;
     return temp;
    }
     else{
      temp->next = head->next;
      head->next = temp;
      int t = head->data;
      head->data = temp->data;
      temp->data = t;
      return head;
     }
}
Node *insertAtEnd(Node *head,int x)
{
    Node *temp = new Node(x);
    if(head==NULL){
     temp->next = temp;
     return temp;
    }
     else{
         Node *curr = head;
         while(curr->next!= head)
          curr = curr->next;
          curr->next = temp;
          temp->next = head;
          return head;
     }
}
Node *insertAtEndPro(Node *head,int x)
{
    Node *temp = new Node(x);
    if(head==NULL){
     temp->next = temp;
     return temp;
    }
     else{
       temp->next = head->next;
       head->next = temp;

       int t = temp->data;
       temp->data = head->data;
       head->data = t;
       return temp;
     }
}
int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp1;
    temp1->next = temp2;
    temp2->next = head;
    head = insertBeginPro(head,45);
    head = insertAtEnd(head,78);
    head = insertAtEndPro(head,123);
    printLinkedlist(head);
    return 0;
}