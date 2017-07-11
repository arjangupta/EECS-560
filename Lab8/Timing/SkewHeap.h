/**
*	@file : SkewHeap.h
*	@author : Arjan Gupta
*	@date : March 26, 2017
*	Purpose : Header file for SkewHeap, Lab 8, EECS 560
*/

#ifndef SKEWHEAP_H
#define SKEWHEAP_H

#include "SkewNode.h"
#include "Queue.h"
#include <iostream>

template<typename T>
class SkewHeap{
public:
	SkewHeap();
   	~SkewHeap();
       	void insert(T value);
        void deletemin();
        void preorder();
        void inorder();
    	void levelorder();
private:
    	SkewNode<T>* merge(SkewNode<T>* leftKid, SkewNode<T>* rightKid);
    	void preorder_helper(SkewNode<T>* subTree);
        void inorder_helper(SkewNode<T>* subTree);
     	void deleteSubTree(SkewNode<T>* subTree);
    	SkewNode<T>* m_root;
};

#include "SkewHeap.hpp"

#endif //SKEWHEAP_H
