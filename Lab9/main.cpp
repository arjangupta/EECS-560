/*
 * @file: main.cpp
 * @author: Arjan Gupta
 * @date: 04.03.2017
 * @purpose: main file for Lab 9 in EECS 560
 */

#include "BinomQueue.h"
#include <fstream>

void printMenu(){ //print method for menu
	std::cout << "\n\n-------------------------------------------\n"
		        << "Please choose one of the following commands:\n"
		        << "1- insert\n"
		        << "2- deletemin\n"
            << "3- levelorder\n"
            << "4- exit\n\n"
		        << "> ";
}

int main(){
  BinomQueue<int>* myBinomQueue = new BinomQueue<int>();
  int userChoice = 0;
	int userValue = 0;
	int inputData = 0;
	bool isNotEmpty = false;

  std::ifstream myFile;
	myFile.open("data.txt");
	if(myFile.is_open()){
	   std::cout << "\ndata.txt elements: ";
     while(myFile >> inputData){
       myBinomQueue->insert(inputData);
       std::cout << inputData << " ";
     }
     std::cout << "\n";
     myFile.close();
	}


	while(userChoice != 4){
    printMenu();
		std::cin >> userChoice;
		switch(userChoice){
      case 1:
        std::cout << "Please insert the number that you want to be inserted in the Binomial queue: \n> ";
				std::cin >> userValue;
        myBinomQueue->insert(userValue);
				break;
			case 2:
        isNotEmpty = myBinomQueue->deletemin();
				if(!isNotEmpty){
					std::cout << "\nThis queue is empty. Nothing to delete.";
				}
				break;
      case 3:
        myBinomQueue->levelorder();
        break;
      case 4:
        //exit this loop
				//myBinomQueue->test();
        break;
			default:
				//keep looping
				break;
		}
  }
	delete myBinomQueue;
  return 0;
}
