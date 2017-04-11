// hw2-2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;



int Tertiary(int *arr,int fi,int la,int key) {
	//when fi is bigger than la,return -1
	if (fi > la) {
		return -1;
	}
	//when the length is 1,test if the only item is equal to the index
	if (fi == la) {
		if(arr[fi]==key)return fi;
		if (arr[fi] != key)return -1;
	}
	//when the length is 2,test the two 
	if (la - fi == 1) {
		if (arr[fi] == key) {
			return fi;
		}
		else if (arr[la] == key) {
			return la;
		}
		else {
			return -1;
		}
	}
	//when the length is 3,test the three
	if (la - fi == 2) {
		if (arr[fi] == key) {
			return fi;
		}
		else if (arr[fi + 1] == key) {
			return fi + 1;
		}
		else if (arr[la] == key) {
			return la;
		}
		else {
			return -1;
		}
	}
	//when the length is larger than 3,divide the length into 3 groups
	if (la - fi > 2) {
		int a = Tertiary(arr, fi, fi + (la - fi) / 3, key);
		//cout << fi <<" one third is "<< fi + (la - fi) / 3 <<"  "<<la<< endl;
		int b = Tertiary(arr, 1 + fi + (la - fi) / 3, fi + 2*(la - fi) / 3, key);
		//cout << fi << " two thirds is "<< fi + 2 * (la - fi) / 3 <<"  "<<la<< endl;
		int c = Tertiary(arr, 1 + fi + 2 * (la - fi) / 3, la, key);
		if (a != -1)return a;
		if (b != -1)return b;
		if (c != -1)return c;
		else return -1;

	}
	//recursion
	return -1;
}


int main()
{
	int a[14] = { 2,4,6,8,10,12,14,16,18,20,22,24,26,28 };
	
	cout << "If the index is -1, it means the item is not in the array" << endl;

	cout <<"Item index in array is "<< Tertiary(a, 0, 13, 12) << endl;

	cout << "Item index in array is " << Tertiary(a, 0, 13, 2) << endl;

	cout << "Item index in array is " << Tertiary(a, 0, 13, 28) << endl;

	cout << "Item index in array is " << Tertiary(a, 0, 13, 100) << endl;

	cout << "Items of the array are ";
	for (int i = 0; i < 14; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	system("pause");
    return 0;
}

