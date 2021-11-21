#include<iostream>
using namespace std;
#define N 4
bool isSafe(int arr[N][N],int x,int y)
{
  for(int row = 0 ; row < x ; row++){
      if(arr[row][y] == 1)
      return false;
  }
  int row = x;
  int col = y;
  while(row >= 0 && col >= 0)
  {
      if(arr[row][col] == 1)
      return false;

      row--;
      col--;
  }
   row = x;
   col = y;
   while(row >= 0 && col <N)
  {
      if(arr[row][col] == 1)
      return false;
      row--;
      col++;
  }
  return true;
}
bool nQueen( int arr[N][N],int x,int y)
{
    if(x>=N)
    return true;

    for(int col = 0 ; col < N; col++)
    {
         if (isSafe(arr,x,col))
         {
           arr[x][col] =1;

           if(nQueen(arr,x+1,N))
           return true;
           
           arr[x][col] = 0;
         }
    }
    return false;
}
void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}
 int main(){

    int sol[N][N]= {0};
    nQueen(sol,0,0);
        printSolution(sol);
     return 0;
 }