#include<iostream>
using namespace std;
 

 int GCD(int a, int b){
    //  finding HCF naive solution
   int res = min(a,b);
   while(res>0){
       if(a%res==0 && b%res ==0){
           break;
       }
      res--;
   }
   return res;
 }
 int gcd(int a ,int b){
//   Euclidain algorithm
     while(a!=b){
         if(a>b){
             a= a-b;
         }else{
             b=b-a;
         }
         return a;
     }
 }
 int Rgcd(int a ,int b){
    //  using recursion find hcf
     if(b==0)
     return a;
      else 
      return gcd(b,a%b); 
 }
int LCM(int a ,int b){
    // LCM naive solution
  int c = max(a,b);
  while(true){
      if(c%a==0 &&c%b==0){
          return c;
      }
      c++;
  }
}
int lcm(int a ,int b){
    // LCM optimize solution
    return (a*b)/Rgcd(a,b);
}
bool prime(int a){
    // check whether a number is prime or not
    for(int i =2;i*i<a;i++){
        if(a%i==0){
            return false;
        }else{
            return true;
        }
    }
}
 int main(){
    cout<<GCD(5,10);
 } 