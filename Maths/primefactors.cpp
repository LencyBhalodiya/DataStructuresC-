#include<iostream>
using namespace std;

bool prime(int a){
    for(int i =2;i*i<a;i++){
        if(a%i==0){
            return false;
        }else{
            return true;
        }
    }
}
int PrimeFactors(int n){
    // find the prime factors of the given number
   if(n<=1){
       return 1;
       }
       for(int i=2;i*i<=n;i++){
           while(n%i==0){
              cout<<i<<" "; 
              n=n/i;
           }
       }
       if(n>1){
           cout<<n;
       }
}
void PrintDivisor(int n){
    int i;
    // code not working
    for(i=1;i*i<=n;i++){
           if(n%i==0){
              cout<<i<<" ";  
              
           }
       }
       
}
int main(){
PrimeFactors(12);
}