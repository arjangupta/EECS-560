/**
*	@file: DijkstraAlg.hpp
*	@author: Arjan Gupta
*	@date: May 4, 2017
*	@purpose: HPP file for Dijkstra's algorithm class, lab 12, EECS 560
*/

DijkstraAlg::DijkstraAlg(int size){
  m_sizeOfGraph = size;
  m_storedGraph = new int*[size];
  for(int i =0; i < size; i++){
    m_storedGraph[i] = new int[size];
    for(int j = 0; j < size; j++){
        m_storedGraph[i][j] = 0; //set initial values to graph
    }
  }
  //contructor end
}

DijkstraAlg::~DijkstraAlg(){
  for(int i=m_sizeOfGraph-1; i>=0; i--){
    delete[] m_storedGraph[i];
  }
  delete[] m_storedGraph;
  //destructor end
}

void DijkstraAlg::build(int a, int b, int val){
  //Insert the value into the matrix, where a is the row and b is the column specified.
  m_storedGraph[a][b] = val;
}

void DijkstraAlg::sPathFinder(int init){
  //declarations of shortest path set and shortest distance set
  bool sPathSet[m_sizeOfGraph]; int sDistance[m_sizeOfGraph];

  for(int i = 0; i < m_sizeOfGraph; i++){
    sDistance[i] = INT_MAX; //set distances to infinity~!
    sPathSet[i] = false;
  }

  sDistance[init] = 0; //source vertex is 0
  for(int i=0; i<m_sizeOfGraph-1; i++){
    int minDistanceIndx = indxOfMinDist(sDistance, sPathSet);
    sPathSet[minDistanceIndx] = true; //mark this as done
    for(int v = 0; v < m_sizeOfGraph; v++){
      //update the shortest path set
      if((!sPathSet[v]) && (m_storedGraph[minDistanceIndx][v] != 0) &&
      (sDistance[minDistanceIndx] != INT_MAX) &&
      ((sDistance[minDistanceIndx] + m_storedGraph[minDistanceIndx][v]) < sDistance[v])){
        sDistance[v] = sDistance[minDistanceIndx] + m_storedGraph[minDistanceIndx][v];
      }
    }
  }

  /*
  *
  */

  //print out the result!!! :)
  for(int i = 0; i < m_sizeOfGraph; i++){
    std::cout << sDistance[i] << " ";
  }
  std::cout << std::endl;
}

int DijkstraAlg::indxOfMinDist(int sDistance[], bool sPathSet[]){
  //initializations
  int i = 0; int minimum = INT_MAX;
  //self explanatory stuff
  for(int j = 0; j < m_sizeOfGraph; j++){
    if((!sPathSet[j]) && (sDistance[j] <= minimum)){
      minimum = sDistance[j];
      i = j;
    }
  }
  return i;
}
