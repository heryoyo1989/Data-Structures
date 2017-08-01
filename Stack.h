#pragma once
class Stack
{
public:
	Stack();
	~Stack();
	int stackSize;
    int a[5];//use array to build a stack
    int point;

	int push(int num);
	int pop();
	bool IsEmpty();
	bool IsFull();

	void traverse();
	
};

