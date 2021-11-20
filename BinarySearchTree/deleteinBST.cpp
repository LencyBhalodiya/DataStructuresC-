#include<bits/stdc++.h>
using namespace std;
// delete in the binary search tree
struct Node{
    int key;
    Node *left,*right;
    Node(int x)
    {
        key = x;
        left = right = NULL;
    }
};
Node *getSuccessor(Node *curr)
{
    curr = curr->right;
    while(curr!=NULL && curr->left!= NULL)
    curr = curr->left;
    return curr;
}
Node *delNode(Node *root,int x)
{
    if(root == NULL) return root;
    if(root->key > x)
    root->left = delNode(root->left,x);
    else if(root->key < x)
    root->right = delNode(root->right,x);
    else{
        if(root->left == NULL)
        {
            Node *temp =  root->right;
            delete root;
            return temp;
        }else if(root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else{
            Node *succ = getSuccessor(root);
            root->key = succ->key;
            root->right = delNode(root->right,succ->key);
        }
    }
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
    Node *root = new Node(15);
    root->left = new Node(12);
    root->left->left = new Node(6);
    root->right = new Node(17);
    root->right->right = new Node(19);
    delNode(root,15);
    printLevelLinePart2(root);
    return 0;
}