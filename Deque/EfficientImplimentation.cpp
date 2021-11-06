#include<bits/stdc++.h>
using namespace std;
struct Deque{
    int size,cap,front;
    int *arr;
    Deque(int c)
    {
        cap = c;
        size = 0;
        front = 0;
        arr = new int[cap];
    }
    bool isFull()
    {
        return(size == cap);
    }
    bool isEmpty(){
        return (size == 0);
    }
    void insertRear(int x){
        if(isFull()) return;
        int new_rear = (front+size)%cap;
        arr[new_rear]  = x;
        size++;
    }
    void deleteRear(){
        if(isEmpty()) return;
        size--;
    }
    int getRear(){
        if(isEmpty()) return -1;
        else return(front+size-1)%cap;
    }
    void insertFront(int x)
    {
        if(isFull()) return;
        front = (front+cap-1)%cap;
        arr[front] = x;
        size++;
    }
    void deleteFront(){
        if(isEmpty()) return;
        front = (front+1)%cap;
        size--;
    }
    int getFront(){
        if(isEmpty()) return -1;
        else return front;
    }
};
int main()
{
    Deque d(10);
    return 0;
}
