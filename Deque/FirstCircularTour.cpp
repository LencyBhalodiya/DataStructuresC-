#include<bits/stdc++.h>
using namespace std;
// find the petrol pump which can enable vehicle to make a whole loop and come back to it again and if the petrol becomes negative or zero before reaching the starting point then return -1

int firstPetrolPump(int petrol[],int dist[],int n)
{
    for(int start = 0; start < n;start++)
    {
        int curr_petrol = 0;
        int end = start;
        while(true)
        {
            curr_petrol +=(petrol[end] - dist[end]);
            if(curr_petrol < 0)
             break;
             end = (end + 1)%n;
             if(end == start)
             return (start+1);
        }
    }
}
int petrolpump(int petrol[],int dist[],int n)
{
    int start = 0, curr_pet = 0;
    int prev_pet = 0;
    for(int i=0;i<n;i++)
    {
        curr_pet += (petrol[i] - dist[i]);
        if(curr_pet < 0)
        {
            start = i+1;
            prev_pet = curr_pet;
            curr_pet = 0;
        }
    }
    return((curr_pet + prev_pet) >= 0)?(start+1):1;
}
int main()
{
    int petrol[] = {4,8,7,4};
    int dist[] = {6,5,3,5};
    int n = sizeof(petrol)/sizeof(petrol[0]);
    int m = sizeof(dist)/sizeof(dist[0]);
    cout<<petrolpump(petrol,dist,n);
    return 0;
}