/*
 * @file: main.cpp
 * @author: Arjan Gupta
 * @date: 03.06.2017
 * @purpose: Main file for Lab 6, EECS 560
 */

 #include "MinHeap.h"
 #include <string>
 #include <fstream>

 void printMenu()
 {
     std::cout << 	"\n\n......................................\n"
 			 <<  "Please choose one of the following commands:\n"
       <<	"1- insert\n"
       <<	"2- deletemin\n"
       <<	"3- deletemax\n"
       << "4- remove\n"
 			 << "5- levelorder\n"
 			 << "6- exit\n"
       << "> ";
 }

int main(){
  	int menuInput = 0;
	std::string inputStr = " ";
	int inputNum = 0;

	std::ifstream myFile;
	myFile.open("data.txt");

	std::cout << "\ndata.txt elements: ";
	
	
	myFile >> inputStr;
	int arrSize = std::stoi(inputStr);
	int* arr = new int[arrSize];
	int i = 0;
	while(myFile >> inputStr){
		inputNum = std::stoi(inputStr);
		std::cout << inputNum << " ";
		arr[i] = inputNum;
		i++;
	}

	myFile.close();
	
	MinHeap<int>* myMinHeap = new MinHeap<int>(200, 3, arr, arrSize);

	while(menuInput != 6)
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
			myMinHeap->insert(numToBeIns);
		}else if(menuInput == 2){
      			myMinHeap->deletemin();
    		}else if(menuInput == 3){
      			myMinHeap->deletemax();
		}else if(menuInput == 4){
			int numToBeDel;
			std::cout << "Please insert the number that you want to remove from the 3-Heap" << std::endl;
			std::cout << "> ";
			std::cin >> numToBeDel;
			myMinHeap->remove(numToBeDel);
    		}else if(menuInput == 5){
      			myMinHeap->levelorder();
		}else if(menuInput == 6){
			std::cout << "Program ending" << std::endl;
		}
	}

	delete[] arr;
	delete myMinHeap;

  return 0;
}
