#include<bits/stdc++.h>
using namespace std;
// search in the binary search tree
struct Node{
    int key;
    Node *left,*right;
    Node(int x)
    {
        key = x;
        left = right = NULL;
    }
};
bool search(Node *root,int x)
{
    if(root == NULL)
    return false;
    else if(root->key == x)
     return true;
     else if(root->key>x)
     return search(root->left,x);
     else 
     return search(root->right,x);
}
bool searchIterative(Node *root,int x)
{
    while(root!= NULL)
    {
            if(root->key == x)
            return true;
            
            else if(root->key < x)
            root = root->right;
            else
            root = root->left;
        
    }
    return false;
}
int main()
{
    Node *root = new Node(15);
    root->left = new Node(12);
    root->left->left = new Node(6);
    root->right = new Node(17);
    root->right->right = new Node(19);
    cout<<search(root,11);
    return 0;
}