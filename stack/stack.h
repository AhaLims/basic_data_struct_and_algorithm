#pragma once

template <typename t>
class stack
{
public:
	//������������copy ��ֵ
	stack();
	stack(int ms);
	int size() { return head + 1; };
	int maxSize(){ return maxsize; };
	t top();
	void push(const t&);
	t pop();
	bool empty();
	void clear();
private:
	//int size;
	int maxsize;
	t * ptr;
	int head;
};



