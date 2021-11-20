#include<bits/stdc++.h>
using namespace std;
// find the pair which is equal to the given sum
struct Node{
    int data;
    Node *left,*right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
void topview(Node *root)
{
    map<int,vector<int>> mp;
    queue<pair<Node *,int>> q;
    q.push({root,0});

    while(q.empty() == false)
    {
        auto p = q.front(); // what is the auto here
        Node *curr = p.first;
        int hd = p.second;
       if (mp.count(hd) == 0)
        mp[hd].push_back(curr->data);
        else{
        mp.erase(hd);
        mp[hd].push_back(curr->data);
        }

        q.pop();
        if(curr->left!=NULL)
        q.push({curr->left,hd-1});
        if(curr->right!=NULL)
        q.push({curr->right,hd+1});
    }
    for(auto p : mp)
    {
        vector<int> v = p.second;
        for(int x : v)
        cout<<x<<" ";
     }
    
}
 int main()
 {
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right = new Node(30);
    root->right->right = new Node(85);
    topview(root);
    return 0;
 }