#include<iostream>
using namespace std;
#include<climits>

class MinHeap
{
	int *harr; 
	int capacity; 
	int heap_size; 
  public:
	int parent(int i) { return (i-1)/2; }

	int left(int i) { return (2*i + 1); }

	int right(int i) { return (2*i + 2); }

    MinHeap::MinHeap(int cap)
    {
        heap_size = 0;
        capacity = cap;
        harr = new int[cap];
    }
};
int main()
{
    return 0;
}