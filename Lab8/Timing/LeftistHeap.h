/**
*	@file : LeftistHeap.h
*	@author : Arjan Gupta
*	@date : March 26, 2017
*	Purpose : Header file for Leftist Heap part of Lab 8, EECS 560
*/

#ifndef LEFTISTHEAP_H
#define LEFTISTHEAP_H

#include "LeftistNode.h"
#include "Queue.h"
#include <iostream>

template<typename T>
class LeftistHeap
{
public:
    LeftistHeap();
    ~LeftistHeap();
    void insert(T value);
    void deletemin();
    void preorder();
    void inorder();
    void levelorder();
private:
    LeftistNode<T>* merge(LeftistNode<T>* leftTree, LeftistNode<T>* rightTree);
    void preorder_helper(LeftistNode<T>* subTree);
    void inorder_helper(LeftistNode<T>* subTree);
    void deleteSubTree(LeftistNode<T>* subTree);
    LeftistNode<T>* m_root;
};

#include "LeftistHeap.hpp"

#endif
