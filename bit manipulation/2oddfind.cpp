#include<iostream>
using namespace std;
// find the  2 odd occuring times element in array
void naive(int arr[],int n){
  for(int i=0;i<n;i++){
      int count =0;
      for(int j=0;j<n;j++){
          if(arr[j]==arr[i]){
              count++;
          }
      }
      if(count%2!=0){
          cout<<arr[i]<<" ";
      }
  } 
}
void findtwo(int arr[],int n){
  int XOR = 0,res1=0,res2=0;

  for(int i =0;i<n;i++){
        XOR=XOR^arr[i];
    }
    int br = XOR &~(XOR-1);
    
    for(int i =0;i<n;i++){
       if((arr[i]&br)!=0){
           res1= res1^arr[i];
       }else{
           res2 =res2^arr[i];
       }
    }
    cout<<res1<<" "<<res2;
}
 int main(){
     int arr[]={3,4,3,4,2,4,4,6,7,7};
    int n=sizeof(arr)/sizeof(int);
    
     findtwo(arr,n);
     return 0;
 }