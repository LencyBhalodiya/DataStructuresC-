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
void vSumR(Node *root , int hd , map<int,int> mp)
{
   if(root == NULL) return;
   vSumR(root->left,hd-1,mp);
   mp[hd]+=root->key;
   vSumR(root->right,hd+1,mp);
}
void vSUM(Node *root){
    map<int,int> mp;
    vSumR(root,0,mp);
    for(auto sum : mp)
    cout<<sum.second<<" ";
}
 int main()
 {
    Node *root = new Node(15);
    root->left = new Node(6);
    root->left->left = new Node(6);
    root->right = new Node(12);
    root->right->right = new Node(19);
    vSUM(root);
      return 0;
 }