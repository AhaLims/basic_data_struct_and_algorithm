#include"stack.h"
#include<iostream>
template<typename t>
stack<t>::stack()
{
	maxsize = 255;
	ptr = new int[maxsize];
	//size = 0;
	head = 0;
}

template<typename t>
stack<t>::stack(int ms)
{
	maxsize = ms;
	ptr = new int[maxsize];
	//size = 0;
	head = -1;
}

template<typename t>
t stack<t>::top()
{
	if (!empty())
	{
		return ptr[head];
	}
	else
		std::cerr << "wrong becase the stack is empty!\n";
	return 0; //emmmmm
}

template<typename t>
void stack<t>::push(const t& value)
{
	if (head < maxsize)
	{
		ptr[++head] = value;
		//size++;
	}
	else
	{
		maxsize *= 2;
		t *tmp = new t[maxsize];
		for (int i = 0;i <= head; i++)
		{
			tmp[i] = ptr[i];
		}
		delete ptr;
		ptr = tmp;
		ptr[++head] = value;
		//size++;
	}
}

template<typename t>
t stack<t>::pop()
{
	if (empty() == true)
	{
		std::cout << "there is no element in the stack\n";
		return 0;
	}
	return ptr[head--];

}

template<typename t>
bool stack<t>::empty()
{
	if (head == -1)return true;
	else return false;
}

template<typename t>
void stack<t>::clear()
{
	head = 0;
}

//int main()
//{
//	stack<int> Stack(255);
//	std::cout<<Stack.empty();
//	int a;
//	std::cin >> a;
//	Stack.push(a);
//	std::cin >> a;
//	Stack.push(a);
//	std::cin >> a;
//	Stack.push(a);
//	std::cin >> a;
//	Stack.push(a);
//	while (!Stack.empty())
//	{
//		std::cout << Stack.pop() << std::endl;
//	}
//	std::cin >> a;
//
//}




