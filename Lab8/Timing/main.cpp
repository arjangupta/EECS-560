/**
*	@file : main.cpp
*	@author : Arjan Gupta
*	@date : March 26, 2017
*	Purpose: Main class for timing part of Lab 8, EECS 560
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include "Timer.h"
#include "LeftistHeap.h"
#include "SkewHeap.h"

int generate_Rand(int n){
  return (int) ((rand() % 4*n) + 1);
}

int main(){
	std::cout << "\n";
	//delcare arrays to store times for builds of each D.S.
        double leftBuildTimes[5];
        double skewBuildTimes[5];
	//declare arrays to store times for operations of each D.S.
        double leftOperationTimes[5];
        double skewOperationTimes[5];
        //other paramters to get proper results
	double sum;
	Timer time;
        //Commence all timing for leftist heap
        for(int n = 50000; n <= 400000; n = n*2){
        	for(int i = 0; i < 5; i++){
                        srand(i+1);
                        int* rand_nums = new int[n];
                        for(int s = 0; s < n; s++){
                                rand_nums[s] = generate_Rand(n);
                        }
                        LeftistHeap<int>* myLeftHeap = new LeftistHeap<int>();
                        //start time for build
                        time.start();
                        for(int i = 0; i < n; i++){
                                myLeftHeap->insert(rand_nums[i]);
                        }
                        //end build timer
                        leftBuildTimes[i] = time.stop();
                        double x;
                        int y;
                        //start operations timer
                        time.start();
                        for(int j = 1; j <= (n/10); j++){
                                x = (generate_Rand(n) / (4*n));
				
                                if((0 <= x) && (x < 0.5)){
                                        myLeftHeap->deletemin();
                                }
                                else{
                                        y = generate_Rand(n);
                                        myLeftHeap->insert(y);
                                }
                        }
                        //end Leftist Heap operations timer
                        leftOperationTimes[i] = time.stop();
                        delete myLeftHeap;
                        delete[] rand_nums;
                }
                std::cout << "Timings to build Leftist-Heap with " << n << " numbers:\n";
                for(int i = 0; i < 5; i++){
                        if(i == 0){
                                sum = leftBuildTimes[i];
                        }else{
                                sum = sum + leftBuildTimes[i];
                        }
                        std::cout << leftBuildTimes[i] << " ";
                }
                std::cout << "\nAverage is " << (sum/5) << "\n";
                std::cout << "\n\nTimings to run " << (n/10) << " operations on Leftist-Heap with " << n << " elements to start with:\n";
                for(int i = 0; i < 5; i++){
                        if(i == 0){
                                sum = leftOperationTimes[i];
                       	}else{
                                sum = sum + leftOperationTimes[i];
                        }
                        std::cout << leftOperationTimes[i] << " ";
                }
                std::cout << "\nAverage is " << (sum/5) << "\n";
                std::cout << "\n\n\n";
        }	
	

	

	std::cout << "---------------------------------------------------------\n\n\n";
        


	
	//All the timings for Skew Heap!!
        for(int n = 50000; n <= 400000; n = n*2){		
                for(int i = 0; i < 5; i++){
			srand(i+1);
                        int* rand_nums = new int[n];
                        for(int s = 0; s < n; s++){
				rand_nums[s] = generate_Rand(n);
			}		
                        SkewHeap<int>* mySkewHeap = new SkewHeap<int>();
                        //start build timer
			time.start();
                        for(int i = 0; i < n; i++){
                                mySkewHeap->insert(rand_nums[i]);
			}
                        //end build timer
                        skewBuildTimes[i] = time.stop();
			double x;
                        int y;
                        //start operations timer
			time.start();
                        for(int j = 1; j <= (n/10); j++){
				x = (generate_Rand(n) / (4*n));
                                if((0 <= x) && (x < 0.5)){
                                        mySkewHeap->deletemin();
				}
				else{
					y = generate_Rand(n);
                                        mySkewHeap->insert(y);
				}
			}
                        //end operations timer
                        skewOperationTimes[i] = time.stop();
                        delete mySkewHeap;
			delete[] rand_nums;
		}
                std::cout << "Timings to build Skew-Heap with " << n << " numbers:\n";
                for(int i = 0; i < 5; i++){
			if(i == 0){
                                sum = skewBuildTimes[i];
			}else{
                                sum = sum + skewBuildTimes[i];
			}
                        std::cout << skewBuildTimes[i] << " ";
		}
		std::cout << "\nAverage is " << (sum/5) << "\n";
                std::cout << "\n\nTimes to perform " << (n/10) << " operations on Skew-Heap with " << n << " elements to start with:\n";
                for(int i = 0; i < 5; i++){
			if(i == 0){
                                sum = skewOperationTimes[i];
			}else{
                                sum = sum + skewOperationTimes[i];
			}
                        std::cout << skewOperationTimes[i] << " ";
		}
		std::cout << "\nAverage is " << (sum/5) << "\n";
		std::cout << "\n\n\n";
	}
	return 0;
}
