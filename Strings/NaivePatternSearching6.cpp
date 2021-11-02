#include<iostream>
#include<string>
#include<algorithm>
#include<limits.h>
using namespace std;
// check whether the given pattern is present or not in the string and return its starting index or first letter of the pattern
void patternS(string &str,string &pat)
{
    int m = str.length();
    int n = pat.length();
    for(int  i=0;i<=m-n;i++)
    {
        int j;
        for(j=0;j<n;j++)
        {
            
            if(pat[j]!=str[i+j])
            break;
        }
         if(j==n)
          cout<<i<<" ";
    }
}
int main()
{
  string str = "abccab";
  string pat = "ab";
  patternS(str,pat);
    return 0;
}