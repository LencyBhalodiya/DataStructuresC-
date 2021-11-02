#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool areAnagram(string &pat,string &txt,int i){
  int ch = 256;
  int count[ch] = {0};
  for(int j=0;j<txt.length();j++)
  {
      count[pat[i]]++;
      count[txt[i+j]]--;
  }
  for(int j=0;j<ch;j++)
  {
      if(count[i]!=0)
      return false;
  }
  return true;
}
bool  ispresent(string &txt, string &pat)
{
    int n = txt.length();
    int m = pat.length();
    for(int i=0;i<n-m;i++)
    {
        if(areAnagram(pat,txt,i))
        return true;
    }
    return false;
}

int main()
{
   string str = "abcd";
   string str2 = "abcd";
   cout<<ispresent(str,str2);
    return 0;
}