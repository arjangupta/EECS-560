/**
 * @file: BST.h
 * @author: Arjan Gupta
 * @date: 02.27.2017
 * @purpose: Header file for BST class, Lab 5, EECS 560
 */

#ifndef BST_H
#define BST_H

#include "BSTNode.h"
#include "Queue.h"
#include <iostream>

template <typename T>
class BST
{
public:
	BST();
	~BST();
	void insert(T value);
	void remove(T value);
	void deletemin();
	void deletemax();
	void preorder() const;
	void inorder() const;
	void levelorder() const;
private:
	BSTNode<T>* search(T value, BSTNode<T>* subtree) const;
	void insertRec(T value, BSTNode<T>* subtree);
	int preorderRec(BSTNode<T>* subtree) const;
	int inorderRec(BSTNode<T>* subtree) const;
	BSTNode<T>* m_root;
};

#include "BST.hpp"
#endif //BST_H
