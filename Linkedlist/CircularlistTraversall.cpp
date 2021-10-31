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
//     if(head == NULL)
//     return ;

//  cout<<head->data<<" ";
//  for(Node *p = head->next;p!=head; p=p->next)
//  {
//    cout<<p->data<<" ";
//  }
//  another method of traversal
    Node *p = head;
    do{
        cout<<p->data<<" ";
        p = p->next;
    }while(p!=head);

}

int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp1;
    temp1->next = temp2;
    temp2->next = head;
    printLinkedlist(head);
    return 0;
}