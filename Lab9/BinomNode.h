/*
 * @file: BinomNode.h
 * @author: Arjan Gupta
 * @date: 04.03.2017
 * @purpose: BinomNode class header file for Lab 9 in EECS 560
 */

#ifndef BINOMNODE_H
#define BINOMNODE_H

template <typename T>
class BinomNode{
public:
  BinomNode();
  ~BinomNode();
  T getKey();
  void setKey(T val);
  int getOrder();
  void setOrder(int order);
  BinomNode<T>* getLeftSibling();
  void setLeftSibling(BinomNode<T>* left);
  BinomNode<T>* getRightSibling();
  void setRightSibling(BinomNode<T>* right);
  BinomNode<T>* getFirstChild();
  void setFirstChild(BinomNode<T>* child);
private:
  T m_key; //member variable to store the key (value) of this node
  int m_order; //member variable to keep track of the order of this node
  BinomNode<T>* m_lSib; //pointer to the left sibling of this node
  BinomNode<T>* m_rSib; //pointer to the right sibling of this node
  BinomNode<T>* m_fChild; //pointer to the first child of this node
};

#include "BinomNode.hpp"

#endif //BINOMNODE_H
