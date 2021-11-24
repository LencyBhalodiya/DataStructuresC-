#include<bits/stdc++.h>
using namespace std;
#include<climits>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
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

void MinHeap::insertKey(int k)
{
    if (heap_size == capacity) return; 
  
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;
  
    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}
void MinHeap::minHeapify(int i)
{
    int lt = left(i),rt = right(i);
    int smallest = i;
    if(lt<heap_size && harr[lt] < harr[i])
     smallest = lt;
    if(rt < heap_size && harr[rt] < harr[smallest])
     smallest = rt;
     if(smallest!= i)
     {
         swap(harr[i],harr[smallest]);
         minHeapify(smallest);
     }
}
int MinHeap::extractMin()
{
    if(heap_size == 0)
    return INT_MAX;
    if(heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
    swap(harr[0],harr[heap_size-1]);
    heap_size--;
    minHeapify(0);
    return harr[heap_size];
}
void decreaseKey(int i , int x)
{
    harr[i] = x;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(harr[i], harr[parent(i)]);
       i = parent(i);
    }
}
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}
  void buildHeap()
  {
      for(int i = (heap_size -2)/2; i >= 0 ; i--)
      minHeapify(i);
  }
};
int main()
{
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.insertKey(5);

    // cout << h.extractMin() << " ";
    h.decreaseKey(1,2);
    // cout << h.getMin() << " ";
    return 0;
}