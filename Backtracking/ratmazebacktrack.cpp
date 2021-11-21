#include<iostream>
using namespace std;
#define N 4
bool isSafe(int arr[N][N],int x,int y)
{
    if(x<N && y<N && arr[x][y] == 1)
    return true;

    return false;
}
bool ratinMaze(int arr[N][N],int x ,int y ,int sol[N][N])
{
    if(x==N-1 && y == N-1)
    {
        sol[x][y] = 1;
        return true;
    }
    if(isSafe(arr,x,y))
    {
        sol[x][y] = 1;
        if(ratinMaze(arr,x+1,y,sol))
        {
            return true;
        }
        if(ratinMaze(arr,x,y+1,sol))
        {
            return true;
        }
        sol[x][y] = 0;
        return false;
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
     int maze[N][N] = { { 1, 0, 0, 0 },
                        { 1, 1, 0, 1 },
                        { 0, 1, 0, 0 },
                        { 1, 1, 1, 1} };
    int sol[N][N]= {0};
        ratinMaze(maze,0,0,sol);
        printSolution(sol);
     return 0;
 }