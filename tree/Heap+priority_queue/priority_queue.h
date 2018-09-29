#pragma once
//��ô����Ƚϲ�����...
template <typename T>
class Heap;
template <typename T>
class PriorityQueue
{
private:
	Heap<T> * heap;
public:
	PriorityQueue();
	~PriorityQueue();
	bool empty()const;
	T pop();
	void push(const T &);
	int size()const;
	T top();
};
