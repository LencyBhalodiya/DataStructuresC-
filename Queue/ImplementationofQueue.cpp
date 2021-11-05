#include<iostream>
using namespace std;
struct queue{
    int size,cap;
    int *arr;
    queue(int c)
    {
        cap = c;
        size = 0;
        arr = new int[cap];
    }
    bool isFull(){
        return(size == cap);
    }
    bool isEmpty(){
        return(size == 0);
    }
    void enque(int x){
        if(isFull()) return;
        arr[size] = x;
        size++;
    }
    void deque(){
        if(isEmpty()) return;
        for(int i=0;i<size-1;i++)
        arr[i]=arr[i+1];
        size--;
    }
    int getFront(){
        if(isEmpty()) return -1;
        else return 0;
    }
    int getRear()
    {
        if(isEmpty())
        return -1;
        else 
        return size-1;
    }
};
int main()
{
    queue s(5);
    s.enque(3);
    s.enque(4);
    s.enque(4);
    cout<<s.isFull();
    
    return 0;
}