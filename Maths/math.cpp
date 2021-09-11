#include<iostream>
using namespace std;
// find the trailing zeros in the factorial of the number
int Trailingzeros(int n ){
  
  int result = 0;
  for(int i = 5; n / i >= 1; i *= 5){
      result+=n/i;
  }
   return result;
}
int findTrailingZeros(int n)
{
  
    // Initialize result
    int count = 0;
 
    // Keep dividing n by powers of
    // 5 and update count
    for (int i = 5; i<n; i *= 5){
        count += n / i;
    }
    return count;
}
 

int main(){
    int n = 251;
    cout<<Trailingzeros(n);
}
