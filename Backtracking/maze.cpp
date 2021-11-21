#include<iostream>
using namespace std;
const int n =4;

int countpath(int row ,int col)
{
    if(row==1 || col== 1)
     return 1;
     int left = countpath(row-1,col);
     int right = countpath(col,row-1);
     return left + right;
     
}
void showPath(string p , int r ,int c)
{
    if(r ==1 && c == 1){
        cout<<p<<" ";
        return;
    }
    if(r >1)
    showPath(p + "D",r-1 , c);
  
    if(c >1)
    showPath(p + "R",r , c-1);
}
 int main(){
    showPath(" ",3,3);
     return 0;
 }