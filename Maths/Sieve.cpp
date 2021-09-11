#include<iostream>
#include <vector>
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
void sieve(int n){ 
    int prime[100]={0};
    for(int i=2;i*i<=n;i++){
        for(int j=2*i;j<=n;j+=i)
            {
                prime[j]=1;
            }
        
    }
    for(int i=2;i<=n;i++){
        if(prime[i]==0){
            cout<<i<<" ";
        }
    }
}
// sieve method is used to find prime numbers before an given input
int main(){
    int n =7;
   sieve(n);
}