 #include<iostream>
using namespace std;
struct queue{
    int front,size,cap;
    int *arr;
    queue(int c)
    {
        arr = new int[cap];
        cap = c;
        size = 0;
        front = 0;
    }
    bool isFull(){
        return(size == cap);
    }
    bool isEmpty(){
        return(size == 0);
    }
    void enque(int x){
        if(isFull()) return;
        int rear = getRear();
        rear = (rear+1)%cap;
        arr[rear] = x;
        size++;
    }
    void deque(){
        if(isEmpty()) return;
        front = (front+1)%cap;
        size--;
    }
    int getFront(){
        if(isEmpty()) return -1;
        else
         return front;
    }
    int getRear()
    {
        if(isEmpty())
        return -1;
        else 
        return (front+size-1)%cap;
    }
};
int main()
{
    queue s(5);
    s.enque(3);
    s.enque(4);
    s.enque(4);
    s.enque(4);
    s.enque(4);
    cout<<s.isFull()<<" ";
    cout<<s.isEmpty(); 
    return 0;
}