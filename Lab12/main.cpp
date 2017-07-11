/**
*	@file: main.cpp
*	@author: Arjan Gupta
*	@date: May 4, 2017
*	@purpose: Main class for lab 12, EECS 560
*/

#include <fstream>
#include "DijkstraAlg.h"

int main(){
  int numberOfGraphs, sizeOfGraphs, costOfEdge;

  std::ifstream myFile("data.txt");
  if(!(myFile.is_open())){
    std::cout << "The file you have requested cannot be opened.\n\n";
    return 0;
  }
  myFile >> numberOfGraphs; //read in the number of graphs needed
  DijkstraAlg** dijkstra = new DijkstraAlg*[numberOfGraphs]; //create a instance of the dijkstra algo class

  std::cout << "\ndata.txt contains:\n\n" << numberOfGraphs << "\n";
  for(int i = 0; i < numberOfGraphs; i++){
    myFile >> sizeOfGraphs;
    std::cout << sizeOfGraphs << "\n";
    dijkstra[i] = new DijkstraAlg(sizeOfGraphs);
    for(int row = 0; row < sizeOfGraphs; row++){
      for(int col = 0; col < sizeOfGraphs; col++){
        myFile >> costOfEdge;
        dijkstra[i]->build(row, col, costOfEdge);
        std::cout << costOfEdge << " ";
      }
      std::cout << "\n";
    }
  }
  myFile.close();
  std::cout << "\n--------------------------------------------------\n";
  std::cout << "\nOUTPUT:\n\n";

  //run Dijkstra's algorithm for the given num of graphs
  for(int i=0; i<numberOfGraphs; i++){
      dijkstra[i]->sPathFinder(0);
      std::cout << std::endl;
  }

  //Iteratively free the memory blocks on the heap, allocated in main.cpp
  for(int i = 0; i < numberOfGraphs; i++){
    delete dijkstra[i];
  }

  //Call the D.S. destructor
  delete[] dijkstra;
  return 0;
}
