#include<iostream>
using namespace std;
// write an program to find a leader of means right side element of given element should be leess
void Effectiveleader(int arr[],int n)
{
    int curr =  arr[n-1];
    cout << curr << " ";
     
    for (int i = n-2; i >= 0; i--)
    {
        if (curr < arr[i])
        {          
            curr = arr[i];
            cout << curr << " ";
        }
    }  
}
void leader(int arr[],int n)
{
    // Naive solution of time complexity of 0{n2}
    for(int i=0;i<n;i++)
    {
            bool flag =false;
        for(int j=i+1;j<n;j++)
        {
           if(arr[i]<=arr[j])
           {
              flag=true;
              break;
           }

        }
            if(flag==false)
            {
            cout<<arr[i]<<" ";
            }
    }
    
}

int main()   
{
    int arr[]={6,3,5,10,2,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    leader(arr,n);
}