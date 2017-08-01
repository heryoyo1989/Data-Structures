#include "stdafx.h"
#include "Stack.h"
#include <iostream>
using namespace std;


Stack::Stack()
	: stackSize(0)
	, point(-1)
{
}


Stack::~Stack()
{
}


int Stack::push(int num)
{
	if (point < 4) {
		point++;
		a[point] = num;
		stackSize = point + 1;
	}
	return 0;
}


int Stack::pop()
{
	if (point >=0) {
		point--;
		stackSize = point + 1;
		return a[point+1];
	}
	return 0;
}

bool Stack::IsEmpty()
{
	if (point == -1)return true;
	if(point>=0&&point<=4)return false;
}



void Stack::traverse()
{
	for (int i = point; i >= 0; i--) {
		cout << a[i] << "\n";
	}
}


bool Stack::IsFull()
{
	if (point == 4)return true;
	return false;
}
