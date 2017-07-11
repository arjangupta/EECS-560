/**
*	@file : main.cpp
*	@author : Arjan Gupta
*	@date : March 26, 2017
*	Purpose : Main file for lab 8, EECS 560
*/

#include <string>
#include <fstream>
#include "SkewHeap.h"

void printMenu(){ //print method for menu
	std::cout << "\n\n-------------------------------------------\n"
		<< "Please choose one of the following commands:\n"
		<< "1- insert\n"
		<< "2- deletemin\n"
                << "3- preorder\n"
                << "4- inorder\n"
                << "5- levelorder\n"
                << "6- exit\n\n"
		<< "> ";
}

int main(){
	SkewHeap<int>* mySkewHeap = new SkewHeap<int>(); //yeah, it's a pretty slanted heap.
	int userChoice = 0;
	int userValue = 0;
	int inputData = 0;
        std::ifstream myFile;
	myFile.open("data.txt");
	if(myFile.is_open()){
		std::cout << "\ndata.txt elements: ";
		while(myFile >> inputData){
                        mySkewHeap->insert(inputData);
			std::cout << inputData << " ";
		}
		std::cout << "\n";
		myFile.close();
	}
	while(userChoice != 6){
		printMenu();
		std::cin >> userChoice;
		switch(userChoice){
			case 1:
				std::cout << "Please choose the number that you want to insert in the heap: \n> ";
				std::cin >> userValue;
                       		mySkewHeap->insert(userValue);
				break;
			case 2:
                        	mySkewHeap->deletemin();
				break;
                        case 3:
                        	mySkewHeap->preorder();
				break;
                        case 4:
                        	mySkewHeap->inorder();
				break;
                        case 5:
                             	mySkewHeap->levelorder();
                              	break;
                        case 6:
                       		break;
			default:
				//keep looping
				break;
		}
        }
	delete mySkewHeap;
	return 0;
}
