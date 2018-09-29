
#include"Heap.h"
#include"priority_queue.h"
template <typename T>
PriorityQueue<T>::PriorityQueue()//有动态调整大小的部分吗
{
	heap = new Heap;
}

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
	delete heap;
}

template <typename T>
bool PriorityQueue<T>::empty()const
{
	if (heap->size() == 0)return true;
	else return false;
}

template <typename T>
T PriorityQueue<T>::pop()
{
	T tmp = heap->removeFirst();
	return tmp;//if empty()????
}

template <typename T>
void PriorityQueue<T>::push(const T & e)
{
	heap->insert(e);
}

template <typename T>
int PriorityQueue<T>::size()const
{
	return heap->size();
}

template <typename T>
T PriorityQueue<T>::top()
{
	return heap->getFirst();
}



