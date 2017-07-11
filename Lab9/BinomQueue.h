/*
 * @file: BinomQueue.h
 * @author: Arjan Gupta
 * @date: 04.03.2017
 * @purpose: BinomQueue class header file for Lab 9 in EECS 560
 */

#ifndef BINOMQUEUE_H
#define BINOMQUEUE_H

#include "Queue.h"
#include "BinomNode.h"

template <typename T>
class BinomQueue{
public:
  BinomQueue();
  ~BinomQueue();
  void insert(T value);
  bool deletemin();
  void levelorder();
  //void test(); - TESTING
private:
  BinomNode<T>** mergeQueues(BinomNode<T>** originalQueue, BinomNode<T>** tempQueue);
  BinomNode<T>* mergeTrees(BinomNode<T>* root1, BinomNode<T>* root2);
  void swapNodes(BinomNode<T>* &node1, BinomNode<T>* &node2);
  void treeLevelOrder(BinomNode<T>* root);
  int m_queueSize;
  BinomNode<T>** m_mainQueue;
};

#include "BinomQueue.hpp"

#endif //BINOMQUEUE_H
