#include<iostream>
#include<string>
#include<algorithm>
#include<limits.h>
using namespace std;
// check whether the given pattern is present or not in the string and return its starting index or first letter of the pattern
void patternS(string &str,string &pat)
{
    int n = str.length();
    int m = pat.length();
    for(int i=0;i<n-m; )
    {
        int j;
        for(j=0;j<m;j++)
        {
            if(pat[j]!=str[i+j])
            break;
        }
         
            if(j==m)
            cout<<i<<" ";
            if(j==0)
             i++;
            else
            i=(i+j);
    }
}
int main()
{
  string str = "abcab";
  string pat = "b";
  patternS(str,pat);
    return 0;
}