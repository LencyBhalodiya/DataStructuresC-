#include<bits/stdc++.h>
using namespace std;
// find the two Node which is placed incorrectly in bst
struct Node{
    int data;
    Node *left,*right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
Node *prevv = NULL,*first = NULL,*second = NULL;
void checkTwoNodes(Node *root)
{
 if(root == NULL) return;
  checkTwoNodes(root->left);
  if(prevv!=NULL && root->data < prevv->data)
  {
      if(first == NULL)
      first = prevv;
      second = root;
     
  }
  prevv = root;
  checkTwoNodes(root->right);
  cout<<first<<" "<<second<<" ";
}
 int main()
 {
    Node *root = new Node(15);
    root->left = new Node(6);
    root->left->left = new Node(6);
    root->right = new Node(12);
    root->right->right = new Node(19);
    checkTwoNodes(root);
      return 0;
 }