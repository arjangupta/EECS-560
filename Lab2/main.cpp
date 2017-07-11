/**
*	@file : main.cpp
*	@author :  Arjan Gupta
*	@date : 01.29.2017
*	Purpose: Main file for Lab 1, EECS 560
*/

#include "Hash.h"

void printMenu()
{
    std::cout << 	"\n\n...........................................\n"
	<< 	"Please choose one of the following commands:\n"
        <<	"1- insert\n"
        <<	"2- delete\n"
        <<	"3- print\n"
        <<	"4- find\n"
        <<	"5- exit\n"
        << 	"> ";
}
 
int main()
{
	Hash<int>* myHashFn = new Hash<int>();
	int menuInput = 0;
	
	while(menuInput != 5)
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
			int numToBeFnd;
			std::cout << "Which number do you want to find in the hash table?" << std::endl;
			std::cout << "> ";
			std::cin >> numToBeFnd;
			if(myHashFn->find(numToBeFnd)){
				std::cout << "\n\nThe find() function returned true. The value is in the hash table!";
			}else{
				std::cout << "\n\nThe find() function returned false. The value is not in the hash table.";
			} 	
		}else if(menuInput == 5){
			std::cout << "Program ending\n\n" << std::endl;
		}			
	}

	delete myHashFn;
	
	return 0;
}
