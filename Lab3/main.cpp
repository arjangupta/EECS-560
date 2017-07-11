/**
*	@file : main.cpp
*	@author :  Arjan Gupta
*	@date : 02.13.2017
*	Purpose: Main file for Lab 3, EECS 560
*/

#include "Hash.h"

void printInitMenu()
{
	std::cout << 	"\n\n...........................................\n"
	<< 	"Please choose one of the following hash methods:\n"
        <<	"1- quadratic\n"
        <<	"2- double hashing\n"
        <<	"3- exit\n"
        << 	"> ";
}

void printMenu()
{
    std::cout << 	"\n\n...........................................\n"
	<< 	"Please choose one of the following commands:\n"
        <<	"1- insert\n"
        <<	"2- delete\n"
        <<	"3- print\n"
        <<	"4- exit\n"
        << 	"> ";
}
 
int main()
{
	int init_choice;
	do{	
		printInitMenu();
		std::cin >> init_choice;
	}while(init_choice > 3 || init_choice < 1);
	
	if(init_choice == 3){
		exit(0);
	}

	Hash<int>* myHashFn = new Hash<int>(init_choice);
	
	int menuInput = 0;
	
	while(menuInput != 4)
	{
		printMenu();
		std::cin >> menuInput;
		std::cout << "\n";
		
		if(menuInput == 1)
		{
			int numToBeIns;
			std::cout << "Which number do you want to insert into the hash table?" << std::endl;
			std::cout << "> ";
			std::cin >> numToBeIns;
			myHashFn->insert(numToBeIns);
		}else if(menuInput == 2){
			int numToBeDel;
			std::cout << "Which number do you want to remove from the hash table?" << std::endl;
			std::cout << "> ";
			std::cin >> numToBeDel;
			myHashFn->deletenode(numToBeDel);
		}else if(menuInput == 3){
			myHashFn->print();		
		}else if(menuInput == 4){
			std::cout << "Program ending\n\n" << std::endl;
		}			
	}

	delete myHashFn;
	
	return 0;
}
