// DynamicArraysE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "includes.h"
#include "dynamicArray.h"
#include "LinkedList.h"

unsigned int iterate = 0;

void dynamicArrayTest()
{
	dynamicArray<int> mIntArray;
	dynamicArray<string> mStringArray;

	//cout << "Enter a number: ";
	//cin >> iterate;

	//for (size_t i = 0; i < iterate; i++)
	//{
	//	mIntArray.push(10 * i);
	//	mStringArray.push("HELLO");

	//}

	cout << mIntArray[0];
	mIntArray[2] = 23;
	mIntArray[1]++;
	mIntArray.set(1, mIntArray.get(1) + 1);

	for (size_t i = 0; i < mIntArray.size(); i++)
	{
		cout << mIntArray[i] << " ";
		cout << mStringArray[i] << " ";
		cout << endl;
	}

	mIntArray.push(70);
	mIntArray.push(-1);
	mIntArray.push(23);

	mIntArray.sort();

	mStringArray.push("Mike");
	mStringArray.push("Dave");
	mStringArray.push("Pat");
	mStringArray.push("John");

	mStringArray.sort();


}

void linkedListTest()
{
	LinkedList<int> m_linkedList1;

	m_linkedList1.pushFront(7);
	m_linkedList1.pushFront(6);
	m_linkedList1.pushFront(3);
	m_linkedList1.pushFront(6);
	m_linkedList1.pushFront(3);
	m_linkedList1.pushFront(1);
	m_linkedList1.pushFront(3);


	m_linkedList1.pushBack(5);

	cout << m_linkedList1.count() << endl;
	m_linkedList1.toString();

	system("PAUSE");

	int temp = 0;
	int search = 0;
	cout << "Number to insert: " ;
	cin >> temp;
	cout << endl;
	cout << "Position to insert: ";
	cin >> search;
	cout << endl;
	m_linkedList1.insert(temp,search);

	cout << m_linkedList1.count() << endl;
	m_linkedList1.toString();
	
	/*m_linkedList1.popBack();

	cout << m_linkedList1.count() << endl;
	m_linkedList1.toString();

	system("PAUSE");

	m_linkedList1.popFront();

	cout << m_linkedList1.count() << endl;
	m_linkedList1.toString();

	system("PAUSE");

	m_linkedList1.searchAndDestroy(3);

	cout << m_linkedList1.count() << endl;
	m_linkedList1.toString();

	system("PAUSE");

	m_linkedList1.clear();
	cout << "Should be clear" << endl;
	cout << m_linkedList1.count() << endl;
	m_linkedList1.toString();

	system("PAUSE");

	m_linkedList1.pushFront(7);

	cout << "Should be one entry in list" << endl;

	cout << m_linkedList1.count() << endl;
	m_linkedList1.toString();

	system("PAUSE");
	m_linkedList1.searchAndDestroy(7);

	cout << m_linkedList1.count() << endl;
	m_linkedList1.toString();
	*/

}

int main()
{
	dynamicArrayTest();


	system("PAUSE");
	return 0;
}

