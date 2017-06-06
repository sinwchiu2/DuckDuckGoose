#include<iostream>
#include<string>
#include<time.h>
#include<stdlib.h>
#include"DataNode.h"
#include"DoublyLinkedList.h"
using namespace std;

int main() 
{
	//varibles
	int num;							//number of players
	int round;							//number of rounds
	int move;							//move of the picker calls "Duck" until a "Goose" is called
	bool clockwise;						//clockwise or anti-clockwise direction
	bool pickerWin;						//the "Goose" or the "picker" wins
	string name;						//players' name
	string picker;						//picker's name
	string goose;						//goose's name
	DoublyLinkedList<string> myList;	//Doubly Linked List circle with players' name

	srand (time(NULL));

	//prompt the user to input the number of player 
	cout << "This is our Duck, Duck, Goose game\n" << endl;
	cout << "=================================================================" << endl;
	cout << "Please input the total number of players: ";
	cin >> num;
	//prompt the user to input the name of player
	for(int i=1;i<(num+1);i++)
	{
		cout << "Please enter the name of player " << i << ": ";
		cin >> name;
		myList.insertBack(name);
	}
	//prompt the user to input the number of round to be played 
	cout << "Please enter the total number of rounds of the simulation: ";
	cin >> round;
	cout << "=================================================================\n" << endl;

	cout << "The initial circle is: ";	//display the initial list
	myList.printList();
	cout << endl;

	picker = myList.removeFront();		//the first node is initially chosen to be the picker;
	for(int j=1;j<(round+1);j++)
	{
		cout << "=================================================================" << endl;
		cout << "\t\t\t\tRound " << j << endl;
		cout << "Picker in this round: " << picker << endl;
		cout << "The circle now: ";
		myList.printList();
		cout << endl;

		move = rand() % (num - 1);		//generate a random number between 0 and (players-1) to decide the move
		clockwise = rand() % 2;			//generate random number, 0 is false; 1 is true to decide the direction
		if(clockwise == true)
		{
			cout << "The Picker is walking in clockwise direction!" << endl;
			cout << "Picker: ";
			for(int y=0;y<move;y++)		//picker say duck for the number of time that randomly generated
				cout << "Duck! "<< endl;
			cout << "Goose! " << endl;
			goose = myList.get(move);	
			cout << "The Goose in this round is: " << goose << endl;
			myList.deleteNode(move);
		}
		//for anti-clockwise direction
		else
		{
			//change the list to anti-clockwise
			string temp;
			for(int i=0;i<(num-2);i++)
			{
				temp = myList.removeBack();
				myList.insertNode(temp, i+1);
			}
			cout << "Picker walk in anti-clockwise direction!" << endl;
			cout << "Picker: ";
			for(int y=0;y<move;y++)
				cout << "Duck! ";	//picker say duck for the number of time that randomly generated
			cout << "Goose! " << endl;
			goose = myList.get(move);
			cout << "Goose in this round is: " << goose << endl;
			myList.deleteNode(move);
		}
		pickerWin = rand() % 2;		//generate random number, 0 is false; 1 is true
		if(pickerWin == true)
		{
			cout << "Picker win the race! " << endl;
			myList.insertNode(picker, move);
			picker = goose;
			if(!clockwise)
			{
				string temp;
				for(int i=0;i<(num-2);i++)
				{
					temp = myList.removeBack();
					myList.insertNode(temp, i+1);	//insert the picker to the position
				}
			}
		}
		else
		{
			cout << "Goose win the race! " << endl;
			myList.insertNode(goose, move);
			if(!clockwise)
			{
				string temp;
				//change back the order of the list
				for(int i=0;i<(num-2);i++)
				{
					temp = myList.removeBack();
					myList.insertNode(temp, i+1);	//insert the goose to the position
				}
			}
		}
		cout << "The circle after round " << j << " :";
		myList.printList();
		cout << endl;
		system("pause");
		cout << "\n";
	}
	cout << "=================================================================" << endl;
	system("pause");
}