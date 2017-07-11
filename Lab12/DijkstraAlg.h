/**
*	@file: DijkstraAlg.h
*	@author: Arjan Gupta
*	@date: May 4, 2017
*	@purpose: Header file for Dijkstra's algorithm class, lab 12, EECS 560
*/

#ifndef DIJKSTRAALG_H
#define DIJKSTRAALG_H

#include <iostream>
#include <limits.h>

class DijkstraAlg{
public:
    DijkstraAlg(int size);
    ~DijkstraAlg();
    void build(int a, int b, int val);
    void sPathFinder(int init);
private:
    int indxOfMinDist(int sDistance[], bool sPathSet[]);
    int m_sizeOfGraph;
    int** m_storedGraph;
};

#include "DijkstraAlg.hpp"

#endif //DIJKSTRAALG_H
