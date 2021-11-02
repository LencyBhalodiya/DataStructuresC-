#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
void reversee(char str[],int low,int high)
{
    while(low<=high)
    {
        swap(str[low],str[high]);
        low++;
        high--;
    }
}
void reverseWord(char str[],int n)
{
    int start = 0;
    for(int end = 0;end<n;end++)
    {
        if(str[end] == ' ')
        {
            reversee(str,start,end-1);
            start = end+1;
        }
    }
    reversee(str,start,n-1);
    reversee(str,0,n-1);
}

int main(){
  char str[50] = "my name";
  int n  = sizeof(str)/sizeof(str[0]);
// int n = 8;
  reverseWord(str,n);
 return 0;
}