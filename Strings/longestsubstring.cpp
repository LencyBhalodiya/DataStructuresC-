#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
// find the longest substring which as distinct characters
bool areDistinct(string str,int i,int j)
{
    vector<bool> visited(256);
    for(int k = i;k<=j;k++)
    {
      if(visited[str[k]]==true)
       return false;
       visited[str[k]]=true;
    }
    return true;
}
int longestDistinct(string str)
{
    int n = str.length(),res=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(areDistinct(str,i,j))
            res = max(res,j-i+1);
        }
    }
    return res;
}
int longestdistinctn2(string str)
{
    int n = str.size(),res=0;
    for(int i=0;i<n;i++)
    {
        vector<bool> visited(256);
        for(int j=i;j<n;j++)
        {
            if(visited[str[j]]==true)
            break;
            else{
                res = max(res,j-i+1);
                visited[str[j]];
            }
        }
    }
    return res;
}
int longDist(string str)
{
    int n = str.length(),res=0;
    vector<int> prev(266,-1);
    int i=0;
    for(int j=0;j<n;j++)
    {
        i = max(i,prev[str[j]]+1);
        int maxEnd = j-i+1;
        res = max(res,maxEnd);
        prev[str[j]]=j;
    }
    return res;
}
int main()
{
   string str = "aabacceed";
   cout<<longDist(str);
   
    return 0;
}