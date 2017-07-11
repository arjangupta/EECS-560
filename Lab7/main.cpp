/*
 * @file: main.cpp
 * @author: Arjan Gupta
 * @date: 03.13.2017
 * @purpose: Main file for Lab 7, EECS 560
 */

 #include "MinMaxHeap.h"
 #include <string>
 #include <fstream>

void printMenu()
{
      std::cout << "\n\n......................................\n"
      <<  "Please choose one of the following commands:\n"
      <<  "1- insert\n"
      <<  "2- deletemin\n"
      <<  "3- deletemax\n"
      <<  "4- levelorder\n"
      <<  "5- exit\n"
      <<  "> ";
}

int main(){
  	int menuInput = 0;
	std::string inputStr = " ";
	int inputNum = 0;
	
	MinMaxHeap<int>* myMinMaxHeap = new MinMaxHeap<int>();

	std::ifstream myFile;
	myFile.open("data.txt");

	std::cout << "\ndata.txt elements: ";
	
	while(myFile >> inputStr){
		inputNum = std::stoi(inputStr);
		std::cout << inputNum << " ";
		myMinMaxHeap->add(inputNum);	
	}

	myFile.close();

	myMinMaxHeap->buildBottomUp();
	
	while(menuInput != 5)
	{
		printMenu();
		std::cin >> menuInput;
		std::cout << "\n";
		if(menuInput == 1)
		{
			int numToBeIns;
			std::cout << "Please insert the number that you want to be inserted in the heap" << std::endl;
			std::cout << "> ";
			std::cin >> numToBeIns;
			myMinMaxHeap->insert(numToBeIns);
		}else if(menuInput == 2){
      			myMinMaxHeap->deletemin();
    		}else if(menuInput == 3){
      			myMinMaxHeap->deletemax();
    		}else if(menuInput == 4){
      			myMinMaxHeap->levelorder();
		}else if(menuInput == 5){
			std::cout << "Program ending" << std::endl;
		}
	}

	delete myMinMaxHeap;

  return 0;
}
