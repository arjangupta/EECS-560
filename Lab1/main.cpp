/**
*	@file : main.cpp
*	@author :  Arjan Gupta
*	@date : 01.29.2017
*	Purpose: Main file for Lab 1, EECS 560
*/

#include "DoubleLinkedList.h"
#include <fstream>
#include <string>

void printMenu()
{
    std::cout << 	"\n\nPlease choose one of the following commands:\n"
        <<	"1- insert\n"
        <<	"2- delete\n"
        <<	"3- reverse\n"
        <<	"4- print\n"
        <<	"5- exit\n"
        << 	"> ";
}
 
int main()
{
	DoubleLinkedList<int>* myList = new DoubleLinkedList<int>();
	int menuInput = 0;
	std::string inputStr = " ";
	int inputNum = 0; 
	
	std::ifstream myFile;
	myFile.open("data.txt");

	while(myFile >> inputStr){
		inputNum = std::stoi(inputStr);
		myList->insert(inputNum);		
	}

	while(menuInput != 5)
	{
		printMenu();
		std::cin >> menuInput;
		std::cout << "\n";
		
		if(menuInput == 1)
		{
			int numToBeIns;
			std::cout << "Choose a number to be added to the list:" << std::endl;
			std::cout << "> ";
			std::cin >> numToBeIns;
			myList->insert(numToBeIns);
		}else if(menuInput == 2){
			int numToBeDel;
			std::cout << "Choose a number to be deleted from the list:" << std::endl;
			std::cout << "> ";
			std::cin >> numToBeDel;
			myList->deletenode(numToBeDel);
		}else if(menuInput == 3){
			myList->reverse();	
		}else if(menuInput == 4){
			myList->print();	
		}else{
			std::cout << "Program ending" << std::endl;
		}			
	}
	
	delete myList;
	
	return 0;
}
