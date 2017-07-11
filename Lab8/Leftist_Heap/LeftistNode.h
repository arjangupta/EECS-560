/**
*	@file : LeftistNode.h
*	@author : Arjan Gupta
*	@date : March 26, 2017
*	Purpose : Header file for LeftistNode for Lab 8, EECS 560
*/

#ifndef LEFTISTNODE_H
#define LEFTISTNODE_H

template <typename T>
class LeftistNode{
public:
	LeftistNode();
    	LeftistNode(T value);
    	LeftistNode(T value, LeftistNode<T>* leftPtr, LeftistNode<T>* rightPtr);
        LeftistNode(T item, int rank, LeftistNode<T>* leftPtr, LeftistNode<T>* rightPtr);
    	void setValue(T value);
    	T getValue();
    	void setRank(int rank);
    	int getRank();
    	void setLeft(LeftistNode<T>* leftPtr);
    	LeftistNode<T>* getLeft();
        void setRight(LeftistNode<T>* rightPtr);
        LeftistNode<T>* getRight();
private:
    	T m_value;
    	int m_rank;
	LeftistNode<T>* m_left;
    	LeftistNode<T>* m_right;
};

#include "LeftistNode.hpp"

#endif //LEFTISTNODE_H
