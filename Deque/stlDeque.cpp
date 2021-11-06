#include<bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> dq = {10,20,30};
    dq.push_front(4);
    dq.push_back(44);
    for(auto i: dq)
    cout<<i<<" ";
    return 0;
}