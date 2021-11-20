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

int CeilBST(Node *root,int x)
{
    Node *res = NULL;
    while(root!= NULL)
    {
            if(root->key == x)
             return root->key;
            
            else if(root->key < x)
            root = root->right;
            else{
                res = root;
                root = root->left;
            }
    }
    return res->key;
    
}
int main()
{
    Node *root = new Node(15);
    root->left = new Node(12);
    root->left->left = new Node(6);
    root->right = new Node(17);
    root->right->right = new Node(19);
    cout<<CeilBST(root,7);
    return 0;
}