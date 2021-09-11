#include<iostream>
using namespace std;
// find the power of any number using optimize method
int power(int x,int pow){
  int res =1;
  while (pow>0)
  {
     if(pow%2!=0){
         res =res*x;
     }
     x=x*x;
     pow=pow/2;
     
  }
  return res;
}
int binary(int x,int pow){
  int res =1;
  while (pow>0)
  {
     if(pow&1){
         res =res*x;
     }
     x=x*x;
     pow=pow>>1;
     
  }
  return res;
}
int main(){
  cout<<binary(3,3);
    return 0;
}