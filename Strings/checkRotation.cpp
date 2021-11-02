#include<iostream>
#include<string>

using namespace std;
// check whether the given pattern is a rotation of the string given 
bool checkRotation(string &str,string &pat)
{
  if(str.length()!= pat.length())
  return false;
  return ((str+str).find(pat)!=string::npos);
}
int main()
{
  string str = "abcd";
  string pat = "dabc";
  cout<<checkRotation(str,pat);
    return 0;
}