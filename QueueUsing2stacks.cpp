// QueueUsing2stacks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Stack.h"
#include "Queue.h"
using namespace std;

int add(int a) {
	return(a);
}

int main()
{
	Queue qu1;
	qu1.enqueue(5);
	
    qu1.dequeue();
	qu1.dequeue();
	
	qu1.enqueue(4);
	qu1.enqueue(3);
    
	qu1.dequeue();

	qu1.dequeue();

	qu1.enqueue(2);
	qu1.enqueue(1);

	qu1.dequeue();
	qu1.dequeue();
	

	system("pause");
    return 0;
}

