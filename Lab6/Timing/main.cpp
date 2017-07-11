/*
*	@file : main.cpp
*	@author : Arjan Gupta
*	@date : 03.06.2017
*	@purpose: Main class for lab 6, EECS 560
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include "Timer.h"
#include "BST.h"
#include "MinHeap.h"

int generateRandoms(int n){
  return (int) ((rand() % 4*n) + 1);
}

int main(){
	std::cout << "\n\n";
	//DECLARATIONS
	double timing_buildingBST[5]; //arrays to store building/operations of the data structures
	double timing_buildingMin3Heap[5];
	double timing_operationsBST[5];
	double timing_operationMin3Heap[5];
        double sum; //to calculate averages
	Timer time;

	std::cout << "COMMENCE TIMING FOR BST FOR DIFFERENT n\n\n";
		
        //All timings for BST
        for(int n = 50000; n <= 400000; n = n*2){
                for(int i = 0; i < 5; i++){
                        srand(i+1);
                        int* randomNums = new int[n];
			
                        for(int s = 0; s < n; s++){
                                randomNums[s] = generateRandoms(n);
                        }
			
                        BST<int>* myBST = new BST<int>();

                        //Start BST build timer
                        time.start();
                        for(int i = 0; i < n; i++){
                                myBST->insert(randomNums[i]);
                        }
                        //End BST build timer
                        timing_buildingBST[i] = time.stop();
			
                        double a;
                        int b;
                        //Start BST operations timer
                        time.start();
                        for(int j = 1; j <= (n/10); j++){
                                a = (generateRandoms(n) / (4*n));	
                                if((0 <= a) && (a < 0.1)){
                                        myBST->deletemin();
                                }else if((0.1 <= a) && (a < 0.2)){
                                        myBST->deletemax();
                                }else if((0.2 <= a) && (a < 0.5)){
                                        b = generateRandoms(n);
                                        myBST->remove(b);
                                }else{
                                        b = generateRandoms(n);
                                        myBST->insert(b);
                                }
                        }
                        //End BST operations timer
                        timing_operationsBST[i] = time.stop();
			
                        delete myBST;
                        delete[] randomNums;
                }
		
                std::cout << "Timings to build BST with " << n << " numbers:\n";
                for(int i = 0; i < 5; i++){
                        if(i == 0){
                                sum = timing_buildingBST[i];
                        }else{
                                sum = sum + timing_buildingBST[i];
                        }
                        std::cout << timing_buildingBST[i] << " ";
                }
                std::cout << "\nAverage: " << sum / 5 << "\n";
		
                std::cout << "\n\nTimings to perform " << n/10 << " operations on BST with " << n << " initial elements:\n";
                for(int i = 0; i < 5; i++){
                        if(i == 0){
                                sum = timing_operationsBST[i];
                        }else{
                                sum = sum + timing_operationsBST[i];
                        }
                        std::cout << timing_operationsBST[i] << " ";
                }
                std::cout << "\nAverage: " << sum / 5 << "\n";

                std::cout << "\n\n\n";
        }

	std::cout << "---------------------------------------------------------\n\n\n";
	
	std::cout << "COMMENCE TIMING FOR BST FOR DIFFERENT n\n\n";

	//All timing for Min 3 Heap
        for(int n = 50000; n <= 400000; n = n*2){		
                for(int i = 0; i < 5; i++){
			srand(i+1);
                        int* randomNums = new int[n];
                        for(int s = 0; s < n; s++){
				randomNums[s] = generateRandoms(n);
			}
                        MinHeap<int>* minHeap_3 = new MinHeap<int>(440000, 3);
			//Start Min 3 Heap build timer
			time.start();
                        for(int i = 0; i < n; i++){
				minHeap_3->add(randomNums[i]);
			}
			minHeap_3->buildBottomUp();
			//End Min 3 Heap build timer
			timing_buildingMin3Heap[i] = time.stop();
			
			double a;
                        int b;
			
			//Start Min 3 Heap operations timer
			time.start();
                        for(int j = 1; j <= (n/10); j++){
				a = (generateRandoms(n) / (4*n));
				if((0 <= a) && (a < 0.1)){
					minHeap_3->deletemin();
				}else if((0.1 <= a) && (a < 0.2)){
					minHeap_3->deletemax();
				}else if((0.2 <= a) && (a < 0.5)){
					b = generateRandoms(n);
					minHeap_3->remove(b);
				}else{
					b = generateRandoms(n);
					minHeap_3->insert(b);
				}
			}
			//End Min 3 Heap operations timer
			timing_operationMin3Heap[i] = time.stop();
			
			delete minHeap_3;
			delete[] randomNums;
		}
		
		std::cout << "Times to build Min 3 Heap with " << n << " numbers:\n";
                for(int i = 0; i < 5; i++){
			if(i == 0){
				sum = timing_buildingMin3Heap[i];
			}else{
				sum = sum + timing_buildingMin3Heap[i];
			}

			std::cout << timing_buildingMin3Heap[i] << " ";
		}
		std::cout << "\nAverage: " << sum / 5 << "\n";
		
		std::cout << "\n\nTimes to perform " << n/10 << " operations on Min 3 Heap with " << n << " initial elements:\n";
                for(int i = 0; i < 5; i++){
			if(i == 0){
				sum = timing_operationMin3Heap[i];
			}else{
				sum = sum + timing_operationMin3Heap[i];
			}

			std::cout << timing_operationMin3Heap[i] << " ";
		}
		std::cout << "\nAverage: " << sum / 5 << "\n";
		
		std::cout << "\n\n\n";
	}
	
	return(0);
}

