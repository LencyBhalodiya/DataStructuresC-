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
int search(Node *head,int x)
{
    // search element in single linkedlist 
    int pos = 1;
    Node *curr = head;
    while(curr!= NULL)
    {
        if(curr->data == x){
            return pos;
        }else{
            pos++;
            curr = curr->next;
        }
    }
    return -1;
}
int recursiveSearch(Node *head,int x)
{
    // search element in single linkedlist using recursion
 if(head == NULL)
 return -1;
 if(head->data == x)
  return 1;
  else{
      int res = recursiveSearch(head->next,x);
      if(res == -1) return -1;
      else return res+1;
  }
}
int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp1;
    temp1->next = temp2;
    cout<<recursiveSearch(head, 30);
    return 0;
}