#pragma once


/*
1.check the heap class by making more examples
2.encapsulate the class into a priority queue
*/
template <typename T>
class Heap
{
private:
	T * data;
	int maxsize;//max size of the heap
	int size_;//actually size
	void ShiftDown(int pos);
public:
	Heap(T * d,int num,int Max = 255);
	//Heap();
	~Heap() {delete[] data; };
	int size()const { return n; };
	bool isLeaf(int pos)const;
	int LeftChild(int pos)const;
	int RightChild(int pos)const;
	int parent(int pos)const;
	void bulidHeap();
	void insert(const T & item);//add
	T removeFirst();//remove the top element of the Heap
	T remove(int pos);//remove any pos of the heap

	void show()const
	{
		for (int i = 0; i < size_; i++)
			cout << data[i] << " ";
		cout << std::endl;
	}
	//search find
	//change





};


namespace Comp
{
	template<typename T>
	bool Compare(const T & a, const T & b)//if want to get a small root heap,just need to change the compare rule
	{
		if (a > b) return true;
		return false;
	}

}
