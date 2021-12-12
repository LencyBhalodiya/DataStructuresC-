#include<bits/stdc++.h>
using namespace std;
//implement trie data structure 
struct TrieNode
{
    TrieNode *child[26];
    bool isEnd;
    TrieNode()
    {
        for(int i = 0 ; i < 26 ; i++)
         child[i] = NULL;
        isEnd = false;
    }
};
TrieNode *root = new TrieNode();
bool search(string &key)
{
    TrieNode *curr = root;
    for(int i = 0 ; i <key.length(); i++)
    {
      int index = key[i] - 'a';
      if(curr->child[index] == NULL)
       return false;

       curr = curr->child[index];
    }
    return curr->isEnd;
}
void insert(string key)
{
    TrieNode *curr = root;

    for(int i = 0 ; i <key.length(); i++)
    {
      int index = key[i] - 'a';
      if(curr->child[index] == NULL)
       curr->child[index] = new TrieNode();
       curr = curr->child[index];
    }
    curr->isEnd = true;
}
bool isEmpty(TrieNode *root)
{
    for(int i = 0 ; i < 26 ; i++)
    {
        if(root->child[i]!=NULL)
         return false;
    }
    return true;
}
TrieNode *deleteKey(TrieNode *root,string &key,int i)
{
    if(root == NULL) return NULL;
    if( i == key.length())
    {
        root->isEnd = false;
        if(isEmpty(root) == true)
        {
            delete(root);
            root = NULL;
        }
        return root;
    }
    int index = key[i]-'a';
    root->child[index] = deleteKey(root->child[index],key,i+1);
    if(isEmpty(root) && root->isEnd == false)
    {
        delete(root);
        root = NULL;
    }
    return root;
}

int main()
{
    string s1 = "hellp";
    insert(s1);
    insert("fok");
    string s2 = "fok";
    cout<<search(s1);
    deleteKey(root,s1,0);
    cout<<search(s1);

    return 0;
}