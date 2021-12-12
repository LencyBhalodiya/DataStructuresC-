#include<bits/stdc++.h>
using namespace std;
//count the unique row in the matrix
const int m=4;
const int n=4;
bool mat[m][n] = { { 1 , 0 , 0 },
                    { 1 , 1 , 1},
                    { 1 , 0 , 0 },
                    { 0 , 1, 0} };
struct TrieNode
{
    TrieNode *child[2];
    TrieNode()
    {
        child[0] = NULL;
        child[1] = NULL;
    }
};
TrieNode *root = new TrieNode();

bool insert(TrieNode *root , int row)
{
    TrieNode *curr = root;
    bool flag = false;
    for(int i = 0 ; i < n; i++)
    {
        int index = mat[row][i];
      if(curr->child[index] == NULL){
       curr->child[index] = new TrieNode();
       flag = true;
      }
       curr = curr->child[index];
    }
    return flag;
}
int countDist()
{
    TrieNode *root = new TrieNode();
    int res = 0;
     for(int row = 0 ; row<m ; row++)
     {
         if(insert(root,row) == true)
          res++;
     }
     return res;
}
int main()
{
    cout<<countDist();
    return 0;
}