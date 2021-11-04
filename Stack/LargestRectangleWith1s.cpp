#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int R=4;
const int C=4;
// find the rectangle of largest size in 2d matrix
int getMaxArea(int arr[],int n)
{
    int res =0;
    for(int i=0;i<n;i++)
    {
        int curr = arr[i];
        for(int j = i-1;j>=0;j--)
        {
            if(arr[j]>=arr[i]){
                curr +=arr[i];
            }else{
                break;
            }
        }
        for(int j = i+1;j<n;j++)
        {
            if(arr[j]>=arr[i])
            curr+=arr[i];
            else
            break;
        }
        res = max(res,curr);
    }
    return res;
}
int maxRectangle(int mat[R][C])
{
    int res = getMaxArea(mat[0],C);
    for(int i=1;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(mat[i][j] == 1)
            mat[i][j] +=mat[i-1][j];
        }
        res = max(res,getMaxArea(mat[i],C));
    }
    return res;
}
int main()
{
    int arr[]={6,2,5,4,1,5,6};
    int mat[R][C] = { { 1,0,1,0 },
                    { 0,1,1,1 },
                    { 1,0,1,1 },
                    {1,1,0,1 } };
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxRectangle(mat);
    return 0;
}