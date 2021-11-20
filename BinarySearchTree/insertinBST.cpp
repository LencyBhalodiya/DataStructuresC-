#include<bits/stdc++.h>
using namespace std;
// Insert in the binary search tree
struct Node{
    int key;
    Node *left,*right;
    Node(int x)
    {
        key = x;
        left = right = NULL;
    }
};
Node* insert(Node *root,int x)
{
    if(root == NULL)
     return new Node(x);
     else if(root->key < x)
     root->right = insert(root->right,x);
     else if(root->key > x)
     root->left = insert(root->left,x);

     return root;
}
Node* insertIterative(Node *root,int x)
{
   Node *temp = new Node(x);
   Node *parent = NULL, *curr = root;
   while(curr!=NULL)
   {
       parent = curr;
       if(curr->key > x)
       curr = curr->left;
       else if(curr->key < x)
       curr = curr->right;
       else
        return root;
   }
       if(parent == NULL)
        return temp;
        if(parent->key > x)
        parent->left = temp;
        else 
        parent->right = temp;
        return root;
}
void printLevelLinePart2(Node *root)
{
    if(root == NULL) return ;
    queue<Node *> q;
    q.push(root);
    while(q.empty() == false){
       int count = q.size();
       for(int i=0;i<count;i++)
       {
           Node *curr = q.front();
           q.pop();
           cout<<(curr->key)<<" ";
           if(curr->left!=NULL)
            q.push(curr->left);
           if(curr->right!=NULL)
            q.push(curr->right);
       }
       cout<<endl;
     }
 }
int main()
{
    Node *root = NULL;
    root = insertIterative(root,5);
    insert(root,1);
    insert(root,2);
    insertIterative(root,4);
    insert(root,7);

    printLevelLinePart2(root);
    return 0;
}