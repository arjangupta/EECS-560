/**
 * @file: BSTNode.h
 * @author: Arjan Gupta
 * @date: 01.29.2017
 * @purpose: Header file for BSTNode class, Lab01, EECS 560
 */

#ifndef BSTNODE_H
#define BSTNODE_H

template <typename T>
class BSTNode
{
public:
	BSTNode();
	~BSTNode();
	T getValue() const;
	void setValue(T value);
	BSTNode<T>* getLeft() const;
	void setLeft(BSTNode<T>* left);
	BSTNode<T>* getRight() const;
	void setRight(BSTNode<T>* right);
	BSTNode<T>* getParent() const;
	void setParent(BSTNode<T>* parent);
private:
	T m_value;
	BSTNode<T>* m_left;
	BSTNode<T>* m_right;
	BSTNode<T>* m_parent;
};

#include "BSTNode.hpp"
#endif //BSTNODE_H
