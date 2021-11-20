#include<bits/stdc++.h>
using namespace std;
// find the pair which is equal to the given sum
struct Node{
    int key;
    Node *left,*right;
    Node(int x)
    {
        key = x;
        left = right = NULL;
    }
};
bool isPairSum(Node *root, int sum, unordered_set<int> &s)
{
    if(root == NULL) return false;
    if(isPairSum(root->left,sum,s) == true)
     return true;
     if(s.find(sum-root->key)!=s.end())
     return true;
     else s.insert(root->key);
     return isPairSum(root->right,sum,s);
}
 int main()
 {
    Node *root = new Node(15);
    root->left = new Node(6);
    root->left->left = new Node(6);
    root->right = new Node(12);
    root->right->right = new Node(19);
    unordered_set<int> s;
    cout<<isPairSum(root,12,s);
      return 0;
 }