/*
 * @file: MinMaxHeap.h
 * @author: Arjan Gupta
 * @date: 03.13.2017
 * @purpose: Header file for Min-Max Heap class of Lab 7, EECS 560
 */

#ifndef MINMAXHEAP_H
#define MINMAXHEAP_H

#include <iostream>
#include <cmath>

template <typename T>
class MinMaxHeap
{
public:
	MinMaxHeap();
	~MinMaxHeap();
	void levelorder();
	void insert(int val);
	bool deletemin();
	bool deletemax();
	void add(int val);
	void buildBottomUp();
private:
	int* m_arr;
	int m_last;
	int m_numChildren;
	int kChildOfi(int i, int k);
	int parent(int i);
	void bubbleUp(int i);
	void bubbleUpMin(int i);
	void bubbleUpMax(int i);
	void trickleDown(int i);
	void trickleDownMin(int i);
	void trickleDownMax(int i);
	int findSmallestGrandChild(int i);
	int findLargestGrandChild(int i);
	int findSmallestChild(int i);
	int findLargestChild(int i);
	void swapValues(int &value1, int &value2);
	bool isMinLevel(int i);
};

#include "MinMaxHeap.hpp"

#endif //MINMAXHEAP_H
