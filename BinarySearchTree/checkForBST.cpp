#include<bits/stdc++.h>
using namespace std;
// check whether the binary tree is binary search tree or not
struct Node{
    int data;
    Node *left,*right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
bool isBST(Node *root , int min , int max)
{
    if(root == NULL) return true;
    return (root->data > min && root->data < max && isBST(root->left,min,root->data) && isBST(root->right,root->data,max));
}
int prevv = INT_MIN;
bool checkBST(Node *root)
{
    if(root == NULL) return true;
    if(checkBST(root->left) == false) return false; 
    if(root->data <= prevv) return false;
    prevv = root->data;
    return checkBST(root->right);
}
int main()
{
    Node *root = new Node(15);
    root->left = new Node(12);
    root->left->left = new Node(6);
    root->right = new Node(16);
    root->right->right = new Node(19);
    cout<<checkBST(root);
    return 0;
}