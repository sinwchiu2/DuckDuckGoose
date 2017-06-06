#include<iostream>
#include"DataNode.h"
#include"DoublyLinkedList.h"
using namespace std;

int main() 
{
	int num;		//store the number of input data
	int data;		//store the data
	char option;	//store the option perform
	int index;		//store the index number of the list
	DoublyLinkedList<int> myList;	//create a doubly-linked-list with integer as data

	//prompt the user to input data
	cout << "Number of input data: ";
	cin >> num;
	cout << "Enter all your data: ";
	for(int i=0;i<num; i++)
	{
		cin >> data;
		myList.insertBack(data);
	}

	//Display the list
	cout << "Data in the doubly linked list: ";
	myList.printList();

	//Display the list with sorting
	myList.sort(0);//sort the list from the beginning to the end
	cout << endl << "After sorting of the whole list: ";
	myList.printList();

	//Ask for option
	cout << endl << endl << "i = insert; d = delete; g = get data; s = sorting; p = printing; q = quit: ";
	cin >> option;
	while(option != 'q')//loop until enter 'q' to quit the program
	{
		switch(option)//use switch for different option
		{
		case 'i':
			cout  << "Data to insert: ";
			cin >> data;
			cout << "Where to insert: ";
			cin >> index;
			myList.insertNode(data, index);
			break;
		case 'd':
			cout << "Index to delete: ";
			cin >> index;
			myList.deleteNode(index);
			break;
		case 'g':
			cout << "Index to get: ";
			cin >> index;
			cout << "The data at " << index << " is " << myList.get(index) << endl;
			break;				
		case 's':
			cout << "After sorting: ";
			myList.sort(0);
			myList.printList();
			cout << endl;
			break;				
		case 'p':
			cout << "Data in the doubly linked list: ";
			myList.printList();
			cout << endl;
			break;
		default://error control
			cout << "Invalid input!" << endl;
			break;
		}
		cout << endl << "i = insert; d = delete; g = get data; s = sorting; p = printing; q = quit: ";
		cin >> option;
	}
	cout << "End of program." << endl;
	system("pause");

}