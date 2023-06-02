// SingleLinkList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct node {
	int key;
	node *next;
};

node* insert(int key, node *head) {
	node *newNode = (struct node*)malloc(sizeof(struct node));//get a new Node
	newNode->key = key;

	node *tempNode = head;	//store the address of head in tempNode

	if (head == NULL) {
		newNode->next = head;//if head is NULL, just insert the new node
		tempNode = newNode;
	}
	else if (head != NULL) {
		bool lessThanAll = false;
		while (head!=NULL)
		{
			 if (key > head->key&&head->next==NULL) {//insert the new node to the last position
				newNode->next = NULL;
				head->next = newNode;
				lessThanAll = true;
			}
			 else if (key > head->key&&head->next != NULL) {//insert the new node to right position in ascend order
				 if (key < head->next->key) {
                    newNode->next = head->next;
				    head->next = newNode;
				    lessThanAll = true;
				 }	
			}
			 head = head->next;
			
		}
		if (lessThanAll == false) {//if the key of newNode is less than all nodes'
			newNode->next = tempNode;
			tempNode = newNode;
		}
	}

	return tempNode;
}

void traverse(node* head) {
	while (head != NULL) {
		cout << head->key<<"   ";
		head = head->next;
	}
}

node* deleteNode(int key,node* head) {
	
	if (head->key == key) {//if the first is the one to delete
		head = head->next;
		return head;
	}
	node* tempHead = head;//store the address of head
	node* tempNode = head;
	while (head->next!= NULL) {
		head = head->next;
		
		if (head->key == key){//delete the node and link the pre and next
			tempNode->next = head->next;
			head->next = NULL;
			return tempHead;
		}
		else if(head->key != key){//key is not in the list
			tempNode = head;
		}
	}
	cout <<"\n"<< key << " is not in the list\n";
	return tempHead;

}

int main()
{ 
	node *head;
	
	head = NULL;//creat an empty linklist
	
	head = insert(894, head);
	head = insert(98417, head);
	head = insert(3131, head);
	head = insert(458, head);
	head = insert(748, head);
	head = insert(103, head);
	head = insert(84, head);
	head = insert(1898, head);
	head = insert(1389, head);
	head = insert(7843, head);
    traverse(head);

	head = deleteNode(3131, head);
	head = deleteNode(84, head);
	head = deleteNode(555, head);
	traverse(head);

	system("pause");
    return 0;
}

