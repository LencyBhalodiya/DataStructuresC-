#include<iostream>
using namespace std;
 

void checkset(int n,int s){
     int c= 1<<s;
     if(n&c!=0){
         cout<<"bit is set ";
     }else{
         cout<<"bit in not set";
     }

 }
 int countsetBits(int n){
    //  brian kerningam's method 
   int res = 0;
    while(n>0){
        n = (n&(n-1));
        res++;
    }
    return res;
 }
//  check whether the number is power of 2 or not
bool Power(int n ){
    if(n==0){
        return false;
    }
    return ((n&(n-1))==0);
}
 int main(){
   cout<<Power(16);
 }