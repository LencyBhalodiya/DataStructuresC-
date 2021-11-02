#include<iostream>
#include<string>
#include<algorithm>
#include<limits.h>
const int CHAR = 256;
using namespace std;
// check in a string the first leftmost non-repeating element and return its index
int leftmostR(string s)
{
    for(int i=0;i<s.length();i++)
    {
        bool flag = false;
        for(int j=0;j<s.length();j++)
        {
            if(i!=j && s[i]==s[j])
            {
                flag = true;
                break;
            }
        }
        if(flag == false)
        return i;
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
         if(count[s[i]]==1)
         return i;
     }
     return -1;
}
int leftR(string &str)
{
    int CHAR = 256;
    int fi[CHAR];
    fill(fi,fi+CHAR,-1);
    for(int i=0;i<str.length();i++)
    {
       if(fi[str[i]] == -1)
       fi[str[i]] = i;
       else
       fi[str[i]]= -2;
    }
    int res = INT_MAX;
    for(int i=0;i<CHAR;i++)
    {
        if(fi[i]>=0);
        res = min(res,fi[i]);
    }
    return(res==INT_MAX)?-1:res;
}
int main()
{
  string str = "abcc";
  cout<<leftR(str);
    return 0;
}