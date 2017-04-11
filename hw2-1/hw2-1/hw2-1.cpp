// hw2-1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define Pi 3.14;

bool IsBST(int *arr,int n) {
	int layerBase = 0;
	int layer = 0;
	int layerNum=1;
	
	for (int i = 0; i < n; i++) {
		
		if (i <= layerBase + layerNum - 1) {
			//get the indexs of left and right child
			int leftChildIndex = layerBase + layerNum + (i - layerBase) * 2;
			int rightChildIndex = layerBase + layerNum + (i - layerBase) * 2+1 ;

			//cout << "i is " << i << "  left is " << leftChildIndex <<" right is "<< rightChildIndex << endl;

			if (leftChildIndex <= n - 1 && rightChildIndex <= n - 1) {
				//get the values of left and right child
				int leftValue = arr[leftChildIndex];
				int rightValue = arr[rightChildIndex];
				//test the relationship between leftchild and rightchild with the root node
				//value could be -1,it means a hole
				if ((arr[i] > leftValue||leftValue==-1) && (arr[i] < arr[rightChildIndex]||rightValue==-1)) {
					//cout << "true" << endl;
				}
				else {
					//cout << "false" ;
					return false;
				}
			}
			
		}
		//change the layerBase and itemNumber
		if (i == layerBase + layerNum - 1) {
			layerBase = layerBase + layerNum ;
			layer++;
			layerNum = pow(2, layer);
		}
			
	}
	//if the items' value 
	return true;
}


int main()
{

	const int N = 31;

	
	int A[N] = { 50 , 35 , 65 , 20 , -1 , 60 , 75 , 10 , 25 , -1 , -1 , 58 , 63, -1 , 80 , 8 ,-1 , 23,  27 ,-1, -1, -1, -1 , 55 , 59,  62 , 64, -1, -1,  79 , 81 };
	int B[N] = { 50 , 35 , 65 , 20 , - 1 , 60 , 75 , 10 , 25 , - 1 , - 1 , 58 , 63 , - 1 , 80 , 8 , - 1 , 23 , 27 , - 1 , - 1 , - 1 , - 1 , 55 , 56 , 62 , 64 , - 1 , - 1 , 79 , 81 };
	

	int rstA = bool(IsBST(A, N));
	if(rstA==1)cout<<"Tree A is a BST"<<endl;
	if(rstA==0)cout<<"Tree A is not a BST"<<endl;
	
	int rstB = bool(IsBST(B, N));
	if (rstB == 1)cout << "Tree B is a BST" << endl;
	if (rstB == 0)cout << "Tree B is not a BST" << endl;


	system("pause");
    return 0;
}

