#pragma once
#include "Stack.h"
class Queue
{
public:
	Queue();
	~Queue();
	Stack inStack;
	Stack outStack;
	int enqueue(int num);
	int dequeue();
};

