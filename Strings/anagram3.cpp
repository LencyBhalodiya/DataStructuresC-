#include<iostream>
#include<string>
#include<algorithm>
// const int CHAR = 256;
using namespace std;
// check whether the string is anagram or not means whether both string contains the same letter with same frequency in the string irrespective of the order
int anagramNaive(string str,string str2)
{
    if(str.length() != str2.length())
     return false;

    sort(str.begin(),str.end());
    sort(str2.begin(),str2.end());
    if(str == str2)
    return true;

}
int anagram(string &s, string &s1)
{
    if(s.length()!= s1.length())
     return false;
     int CHAR = 256;
     int count[CHAR] = {0};
     for(int i =0;i<s1.length();i++)
     {
         count[s[i]]++;
         count[s1[i]]--;
     }
     for(int i=0;i<CHAR;i++)
     {
         if(count[i]!=0)
         return false;
     }
     return true;
}
int main()
{
  string str = "abed";
  string str1 = "abde";
  cout<<anagram(str,str1);
    return 0;
}