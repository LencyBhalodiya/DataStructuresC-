#include<bits/stdc++.h>
using namespace std;
// merge k sorted array in one array
struct Triplet{
    int val,aPos, vPos;
    Triplet(int v, int ap,int vp)
    {
        val = v;
        aPos = ap;
        vPos = vp;
    }
};
struct MyCmp{
    bool operator()(Triplet &t1,Triplet &t2)
    {
     return t1.val > t2.val;
    }
};
void mergeArray(vector<vector<int>> &arr)
{
    vector<int> res;
    priority_queue<Triplet,vector<Triplet>,MyCmp> p;
    
    for(int i = 0; i<arr.size(); i++)
    {
        Triplet t(arr[i][0],i,0);
        p.push(t);
    }
    while(p.empty() == false)
    {
        Triplet curr = p.top();
        p.pop();
        res.push_back(curr.val);
        int ap = curr.aPos,vp = curr.vPos;
        if(vp + 1 < arr[ap].size())
        {
            Triplet t(arr[ap][vp+1],ap,vp+1);
            p.push(t);
        }
    }
   for(int i = 0 ; i<res.size(); i ++)
   cout<<res[i]<<" ";
}
int main()
{
   vector<vector<int>> vec{ { 1, 2, 3 }, 
                         { 4, 5, 6 }, 
                         { 7, 8, 9, 33 } }; 
    mergeArray(vec);
    return 0;
}