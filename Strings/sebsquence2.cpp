#include<iostream>
#include<string>
using namespace std;
// check whether the given second array has subsequence of array first
void subsequence(string a,string b){
    int i=0,j=0;
    while(i < a.length()-1){
      if(a[i] == b[j])
      {
          i++;
          j++;
      }else{
          i++;
      }
    }
    if(j == b.length())
    cout<<"it is a subsequence";
    else{
        cout<<"it is not subsequence";
    }
}
int main()
{
  string str = "abed";
  string str1 = "ade";
  subsequence(str,str1);
    return 0;
}