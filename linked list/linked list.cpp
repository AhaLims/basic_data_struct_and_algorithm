#include <iostream>
#include"list.h"
//倒是没什么大的问题....就是current 怎么放的问题了...特别是在new delete 之后 current的位置

template<typename T>
void list<T>::show()const
{
	node<T> * tmp = head->next;
	std::cout << "the element amount of the linked size is " << listsize << std::endl;
	if (head->next == nullptr)
	{
		std::cout << "It is a null linked list\n";
		return;
	}
	while (tmp != nullptr)
	{
		std::cout << tmp->data << "->";
		tmp = tmp->next;
	}
	std::cout << std::endl;
	return;
}

template<typename T>
list<T>::list()
{
	init();
}

template<typename T>
list<T>::~list()
{
	deleteAll();
}

template<typename T>
void list<T>::clear()
{
	deleteAll();
	init();
}

template<typename T>
void list<T>::init()
{
	listsize = 0;
	head = new node<T>(nullptr, 0);
	tail = current = nullptr;
}
template<typename T>
void list<T>::deleteAll()
{
	while (head != nullptr)
	{
		current = head;
		head = head->next;
		delete current;
	}
	listsize = 0;
}

template<typename T>
bool list<T>::Empty()
{
	if (listsize == 0) return true;
	else return false;
}

template<typename T>
bool list<T>::Delete(T & element)//delete current element and return this element
{
	if (current->next == nullptr)return false;
	node<T> * tmp = current->next;
	element = current->next->data;
	if (tail == current->next)tail = current->next->next;
	current->next = current->next->next;
	delete tmp;
	listsize--;
	return true;
}

template<typename T>
bool list<T>::Delete(int pos, T & element)//from 1 start
{
	T * tmp = head;
	for (int i = 0; i < pos; i++)
	{
		tmp = tmp->next;
		if (tmp == nullptr)return false;//or tmp->next == nullptr??
	}
	element = tmp->data;
	if (tmp->next == tail)tail = tmp->next->next;
	tmp->next = tmp->next->next;
	listsize--;
	delete tmp;
	return true;
}

template<typename T>
bool list<T>::Search(const T& element, node<T> * place)
{
	//
}

template<typename T>
void list<T>::Insert(const T& element)
{
	if (head->next == nullptr)
	{
		current = new node<T>(head->next, element);
		head->next = current;
	}
	else
	{
		current->next = new node<T>(current->next, element);
	}
	if (tail == current)tail = current->next;
	listsize++;
}

template<typename T>
void list<T>::append(const T & element)
{
	tail = tail->next = new node<T>(nullptr, element);
}

template<typename T>
bool list<T>::change(const T& e)//change current element
{
	current->next->element = e;//is there any problem??
}


template<typename T>
bool list<T>::MoveForward()
{
	node<T> * tmp = head;
	while (tmp->next != current)
	{
		if (tmp->next == nullptr)return false;
		tmp = tmp->next;
	}
	current = tmp;
	return true;
}

template<typename T>
bool list<T>::MoveBackward()
{
	if (current == nullptr)return false;
	current = current->next;
	return true;
	
}

template<typename T>
int list<T>::currentPos()const
{
	node * tmp = head;
	int i = 0;
	for (; tmp->next != current; i++)
	{
		tmp = tmp->next;
	}
	return i;
}

template<typename T>
bool list<T>::moveToPos(int pos)
{
	if (listsize < pos)return false;
	node * tmp = head;
	for (int i = 0; i < pos; i++)
	{
		tmp = tmp->next;
	}
	current = tmp;
	return true;
}

