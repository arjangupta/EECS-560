/**
*	@file : main.cpp
*	@author :  Arjan Gupta
*	@date : 02.20.2017
*	Purpose: Main file for Lab 4, EECS 560
*/

#include "OpenHash.h"
#include "ClosedHash.h"
#include "Timer.h"
#include <cstdlib>
#include <fstream>

int main()
{
  //DECLARATIONS
  const int tableSize = 600011;
  int numOfKeys = 0;
  double durationOfInserts[8][6][3];
  Timer timer;
  int seed = 0;
  long randMax = 2147483647;
  double loadFactor = 0.0;

  std::cout << "-----------------------------------------------------------------\n"
  << "We will time the insertion duration for three types of 600011 size"
  << " hash tables in this lab. \n\n"
  << "BEGIN INSERTION TIMNGS-\n";

  for(int j=2; j<10; j++){
    loadFactor = j*0.1;
    numOfKeys = loadFactor*tableSize;
    std::cout << "\n\n-------------- LOAD FACTOR: " << loadFactor << ", NO. OF KEYS: " << numOfKeys << " --------------\n";

    for(int k=0; k<5; k++){
      std::cout << "Iteration #" << k+1 << "\n";

      OpenHash<long>* openHash = new OpenHash<long>(tableSize);
      ClosedHash<long>* quadHash = new ClosedHash<long>(tableSize,1);
      ClosedHash<long>* doubleHash = new ClosedHash<long>(tableSize,0);

      seed = k;

      for(int i=0; i<3; i++){
        switch(i){
          case 0:{
            std::cout << "Duration for open hashing: ";
            break;
          }case 1:{
            std::cout << "Duration for closed hashing with quadratic probing: ";
            break;
          }case 2:{
            std::cout << "Duration for closed hashing with doubling hashing: ";
            break;
          }default:
            break;
        }
        srand(seed);
        timer.start();
        for(int l=0; l<numOfKeys; l++){
          switch(i){
            case 0:{
              openHash->insert(rand()%randMax+1);
              break;
            }case 1:{
              quadHash->insert(rand()%randMax+1);
              break;
            }case 2:{
              doubleHash->insert(rand()%randMax+1);
              break;
            }default:
              break;
          }
        }
        durationOfInserts[j-2][k][i] = timer.stop();
        std::cout << durationOfInserts[j-2][k][i] << " seconds.\n";
      }
      delete openHash;
      delete quadHash;
      delete doubleHash;
    }
    std::cout << "\n\nAVERAGE TIMINGS FOR LOAD FACTOR " << loadFactor << ": \n";
    for(int i=0; i<3; i++){
      double averageTime = 0.0;
      for(int k=0; k<5; k++){
        averageTime += durationOfInserts[j-2][k][i];
      }
      averageTime /= 5.00;
      durationOfInserts[j-2][5][i] = averageTime;
      switch(i){
        case 0:{
          std::cout << "The average time for open hashing is " << durationOfInserts[j-2][5][i] << " seconds.\n";
          break;
        }case 1:{
          std::cout << "The average time for closed hashing with quadratic probing is " << durationOfInserts[j-2][5][i] << " seconds.\n";
          break;
        }case 2:{
          std::cout << "The average time for closed hashing with double hashing is " << durationOfInserts[j-2][5][i] << " seconds.\n----------------------------------------------------------------------\n\n";
          break;
        }default:
          break;
      }
    }
  }

  //WRITE ALL THE DATA TO A FILE SO THAT YOU CAN USE IT IN EXCEL
  std::ofstream myFile;
	myFile.open("data.txt");

  for(int i=0; i<3; i++){
    myFile << "\n\n" << i+1 << "(1 = OH, 2 = QP, 3 = DH): \n\n";
    for(int j=0; j<8; j++){
      myFile << "loadFactor 0." << j+2 << " iteration: \n";
      for(int k=0; k<6; k++){
        myFile << durationOfInserts[j][k][i] << "\n";
      }
    }
  }

	myFile.close();

	return 0;
}
