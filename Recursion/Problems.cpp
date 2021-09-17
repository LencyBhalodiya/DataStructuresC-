#include<iostream>
#include<algorithm>

using namespace std;

// find the  max cuts done to the rope from the given choices 
int RopeCut(int length, int a ,int b,int c){
  if(length==0) 
  return 0;

  if(length<0) 
  return -1;

  int res = max({RopeCut(length-a,a,b,c),RopeCut(length-b,a,b,c),RopeCut(length-c,a,b,c)});
  if(res== -1){
      return -1;
  };

  return res+1;
}
//find the subset of the string using recursion
void Powerset(string str,string curr="",int i=0){
    
  if(i==str.length()){ 
      cout<<curr<<" ";
      return ;
  }
  Powerset(str,curr,i+1);
  Powerset(str,curr+str[i],i+1);
}
void TowerOfHanoi(int n ,string src,string destination, string helper ){
    if(n==0){
        return;
    }

    TowerOfHanoi(n-1,src,helper,destination);
    cout<<"Move from "<<src<<" "<<"to "<<destination<<endl;
    TowerOfHanoi(n-1,helper,destination,src);
}

int josephus(int n,int k){
    if(n==1){
        return 0;
    }
    return(josephus(n-1,k)+k)%n;
}

int main(){
Powerset("abc");
}