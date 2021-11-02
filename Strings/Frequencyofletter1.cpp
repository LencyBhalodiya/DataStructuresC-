#include<iostream>
#include<string>
using namespace std;
// find the frequency of letter in the given string
int main()
{
    string str = "acddee";
    int count[26]={0};
    for(int i=0;i<str.length();i++)
    {
        count[str[i] - 'a']++;
    }
    for(int i=0;i<26;i++) 
    {
        if(count[i]>0){
        cout<<(char)(i+'a')<<" ";
        cout<<count[i]<<endl;
        }
    }
    return 0;
}