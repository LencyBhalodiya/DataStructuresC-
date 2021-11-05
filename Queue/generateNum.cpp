#include<iostream>
using namespace std;
#include<queue>
void printFirstN(int n)
{
    queue<string> q;
    q.push("5");
    q.push("6");
    for(int count = 0; count<n ; count++)
    {
        string curr = q.front();
        cout<<curr<<" ";
        q.pop();
        q.push(curr + "5");
        q.push(curr + "6");
    }

}
int main()
{
    printFirstN(7);
    return 0;
}