#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
// find the lexicography of the string
int fact(int n)
{
    int fact = 1;
  for(int i=n;i>=0;i--)
    fact = fact*n;

    return fact;
}
int lexRank(string &str)
{
    int ch = 256;
    int res = 1;
    int n = str.length();
    int mul = fact(n);
    int count[ch]={0};
    for(int i=0;i<n;i++)
     count[str[i]]++;
    for(int i=1;i<ch;i++)
    count[i]+=count[i-1];
    for(int i=0;i<n-1;i++)
    {
        mul = mul/(n-i);
        res =res + count[str[i]-1]*mul;
        for(int j = str[i];j<ch;j++)
         count[j]--;
    }
    return res;
    
}

int main()
{
   string str = "bac";
   cout<<lexRank(str);
   
    return 0;
}