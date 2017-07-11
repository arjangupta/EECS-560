/*
 * @file: MinHeap.h
 * @author: Arjan Gupta
 * @date: 03.06.2017
 * @purpose: Header file of MinHeap class for Lab 6, EECS 560
 */

#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include <cmath>

template <typename T>
class MinHeap
{
public:
  	MinHeap(int capacity, int numChildren);
  	MinHeap(int capacity, int numChildren, int arr[], int arrSize);
	~MinHeap();
	void insert(T value);
  	void deletemin();
  	void deletemax();
  	void remove(T value);
  	void levelorder() const;
	bool add(T value);
	void buildBottomUp();
private:	
	void removeHelper(T val, bool checkMultiple);
	int search(T value);	
	void pushDown(int index);
	void pushUp(int index);
	int findSmallestChild(int index);
	int kthChildOf(int i, int k);
	int parentOf(int i);
	T* m_arr;
  	int m_capacity;
  	int m_currentSize;
  	int m_numChildren;
};

#include "MinHeap.hpp"
#endif //MINHEAP_H
