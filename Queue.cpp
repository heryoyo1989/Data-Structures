#include "stdafx.h"
#include "Queue.h"
#include <iostream>
using namespace std;


Queue::Queue()
{
}


Queue::~Queue()
{
}


int Queue::enqueue(int num)
{
	
	inStack.push(num);

	cout << "item<" << num << ">enqueued" << "\n";
	return 0;
}

//item <#> enqueued¡±? OR ¡°Item <#> dequeued¡±

int Queue::dequeue()
{
	if (outStack.IsEmpty() == true&&inStack.IsEmpty() !=true) {//if outStack is empty,pop inStack and push it into outStack
		while (inStack.IsEmpty() != true) {
			int temp = inStack.pop();
			outStack.push(temp);
		}
		cout << "item<" << outStack.pop() << ">dequeued" << "\n";
	}
	else if (outStack.IsEmpty() == true && inStack.IsEmpty() == true) {//if the queue is empty
		cout << "There is no element in the queue\n";
	}
	else if (outStack.IsEmpty() == false) {//if outStack is not empty,just pop it 
		cout << "item<" << outStack.pop() << ">dequeued" << "\n";
	}

	return 0;
}
