#include<iostream>
#include<string>
#include<algorithm>
#include<limits.h>
const int CHAR = 256;
using namespace std;
// check in a string the first left most repeating element and return its index
int leftmostR(string s)
{
    for(int i=0;i<s.length();i++)
    {
        for(int j=i+1;j<s.length();j++)
        {
            if(s[i]==s[j])
            return i;
        }
    }
    return -1;
}
int RepeatLeft(string &s)
{
     int CHAR = 256;
     int count[CHAR] = {0};
     for(int i =0;i<s.length();i++)
     {
        count[s[i]]++;
     }
     for(int i=0;i<s.length();i++)
     {
         if(count[s[i]]>1)
         return i;
     }
     return -1;
}
int leftmost(string &s)
{
    int CHAR = 256;
    bool visited[CHAR];
    fill(visited,visited+CHAR,false);
    int res = -1;
    for(int i=s.length()-1;i>=0;i--)
    {
       if(visited[s[i]])
        res = i;
        else 
        visited[s[i]]= true;
    }
    return res;
}
int leftR(string &str)
{
    int CHAR = 256;
    int findex[CHAR];
    fill(findex,findex+CHAR,-1);
    int res = INT_MAX;
    for(int i=0;i<str.length();i++)
    {
        int fi = findex[str[i]];
        if(fi == -1)
        findex[str[i]]=i;
        else 
         res = min(res,fi);
    }
    return(res==INT_MAX)?-1:res;
}
int main()
{
  string str = "abeed";
  cout<<leftR(str);
    return 0;
}