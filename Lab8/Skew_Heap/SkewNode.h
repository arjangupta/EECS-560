/**
*	@file : SkewNode.h
*	@author : Arjan Gupta
*	@date : March 26, 2017
*	Purpose : Header file for Skew Node, Lab8, EECS 560
*/

#ifndef SKEWNODE_H
#define SKEWNODE_H

template <typename T>
class SkewNode{
public:
      	SkewNode();
	SkewNode(T value);
    	SkewNode(T value, SkewNode<T>* leftPtr, SkewNode<T>* rightPtr);
    	void setValue(T value);
    	T getValue();
    	void setLeft(SkewNode<T>* leftPtr);
      	SkewNode<T>* getLeft();
      	void setRight(SkewNode<T>* rightPtr);
      	SkewNode<T>* getRight();
private:
	T m_value;
     	SkewNode<T>* m_left;
	SkewNode<T>* m_right;
};

#include "SkewNode.hpp"

#endif //SKEWNODE_H
