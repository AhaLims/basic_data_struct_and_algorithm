#pragma once


template<typename T>
class node
{
public:
	node * next;
	T data;
	node(node * nextptr, const T & element = 0) { next = nextptr; data = element; };
};

//insert append
template<typename T>
class list
{
public:
	void show()const;
	list();
	~list();
	void clear();
	void init();
	void deleteAll();
	bool Empty();
	bool Delete(T & element);//delete current element
	bool Delete(int pos,T& element );
	bool Search(const T&, node<T> *);//if found return a ptr
	
	void Insert(const T&);//insert a special element in current pointer
	void append(const T&);//Î²×·¼Ó

	void MoveToStart() { current = head; };
	void MoveToEnd() { current = tail; };
	bool change(const T&);//change current element
	bool MoveForward();
	bool MoveBackward();//move the current pointer
	int currentPos()const;
	bool moveToPos(int pos);
private:
	list operator =(const list &) {};//avoid copy
									 //list list(const list &){};
	node<T> * head;
	node<T> * current;
	node<T> * tail;
	//int maxsize;// for linked list listsize = maxsize
	int listsize;
};
