/*
 * @file: main.cpp
 * @author: Arjan Gupta
 * @date: 2.27.2017
 * @purpose: Main file for Lab 5, EECS 560
 */

#include "BST.h"
#include <string>
#include <fstream>

void printMenu()
{
    std::cout << 	"\n\n......................................\n"
				<<  "Please choose one of the following commands:\n"
        <<	"1- insert\n"
        <<	"2- remove\n"
        <<	"3- deletemin\n"
        <<	"4- deletemax\n"
        <<	"5- preorder\n"
				<<  "6- inorder\n"
				<<  "7- levelorder\n"
				<<  "8- exit\n"
        << 	"> ";
}

int main(){
	BST<int>* myBST = new BST<int>();
	int menuInput = 0;
	std::string inputStr = " ";
	int inputNum = 0;

	std::ifstream myFile;
	myFile.open("data.txt");

	std::cout << "\ndata.txt elements: ";

	while(myFile >> inputStr){
		inputNum = std::stoi(inputStr);
		std::cout << inputNum << " ";
		myBST->insert(inputNum);
	}

	myFile.close();

	while(menuInput != 8)
	{
		printMenu();
		std::cin >> menuInput;
		std::cout << "\n";

		if(menuInput == 1)
		{
			int numToBeIns;
			std::cout << "Please insert the number that you want to be inserted in the tree" << std::endl;
			std::cout << "> ";
			std::cin >> numToBeIns;
			myBST->insert(numToBeIns);
		}else if(menuInput == 2){
			int numToBeDel;
			std::cout << "Which number do you like to remove from the tree?" << std::endl;
			std::cout << "> ";
			std::cin >> numToBeDel;
			myBST->remove(numToBeDel);
		}else if(menuInput == 3){
			myBST->deletemin();
		}else if(menuInput == 4){
			myBST->deletemax();
		}else if(menuInput == 5){
			myBST->preorder();
		}else if(menuInput == 6){
			myBST->inorder();
		}else if(menuInput == 7){
			myBST->levelorder();
		}else if(menuInput == 8){
			std::cout << "Program ending" << std::endl;
		}
	}

	delete myBST;

	return 0;
}
