#include<iostream>
using namespace std;
#include<vector>

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
Node *reverse(Node *head)
{
    // reverse a linklist 
    Node *curr = head;
    Node *prev = NULL;
    while(curr!=NULL)
    {
        Node *next = curr->next;
         curr->next = prev;
         prev = curr;
         curr = next;
    }
    return prev;
}
bool palindrome(Node *head)
{
    if(head == NULL) return true;
    Node *slow = head, *fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next;
        fast = fast->next->next;
    }
    Node *rev = reverse(slow->next);
    Node *curr = head;
    while(rev!=NULL)
    {
        if(rev->data!= curr->data)
        return false;
        rev = rev->next;
        curr = curr->next;
    }
    return true;
}

int main()
{
    Node *head = new Node('g');
    Node *temp1 = new Node('e');
    Node *temp2 = new Node('e');
    Node *temp3 = new Node('f');
    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;
    cout<<palindrome(head);
    return 0;
}