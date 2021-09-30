#include<iostream>
#include<unordered_set>
using namespace std;
// Find the unique element or non repeating element in the array
int countDistinct(int arr[],int n)
{
    // niave solution
    int res = 0;
    for(int i=0;i<n;i++)
    {
        bool flag = true;
        for(int j=0;j<i;j++)
        {
            if(arr[i]== arr[j])
            {
                flag = false;
                 break;
            }
        }
        if(flag == true)
        res++;
    }
    return res;
}
int countD(int arr[],int n)
{
    unordered_set<int> s;
    for(int i=0;i<n;i++)
    {
        s.insert(arr[i]);
    }
    return s.size();
    // improve technique which is optimal
    // unordered_set<int> s(arr,arr+n);
    // return s.size();
}
int main()
{
  int arr[]=  {10,23,7,7,5,10,20};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<countDistinct(arr,n);
}