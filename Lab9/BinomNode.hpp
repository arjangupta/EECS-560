/*
 * @file: BinomNode.hpp
 * @author: Arjan Gupta
 * @date: 04.03.2017
 * @purpose: BinomNode class HPP file for Lab 9 in EECS 560
 */

template <typename T>
BinomNode<T>::BinomNode(){
  m_key = T();
  m_order = 0;
  m_lSib = this;
  m_rSib = nullptr;
  m_fChild = nullptr;
}

template <typename T>
BinomNode<T>::~BinomNode(){
  //nothing needed here
}

template <typename T>
T BinomNode<T>::getKey(){
  return m_key;
}

template <typename T>
void BinomNode<T>::setKey(T val){
  m_key = val;
}

template <typename T>
int BinomNode<T>::getOrder(){
  return m_order;
}

template <typename T>
void BinomNode<T>::setOrder(int order){
  m_order = order;
}

template <typename T>
BinomNode<T>* BinomNode<T>::getLeftSibling(){
  return m_lSib;
}

template <typename T>
void BinomNode<T>::setLeftSibling(BinomNode<T>* left){
  m_lSib = left;
}

template <typename T>
BinomNode<T>* BinomNode<T>::getRightSibling(){
  return m_rSib;
}

template <typename T>
void BinomNode<T>::setRightSibling(BinomNode<T>* right){
  m_rSib = right;
}

template <typename T>
BinomNode<T>* BinomNode<T>::getFirstChild(){
  return m_fChild;
}

template <typename T>
void BinomNode<T>::setFirstChild(BinomNode<T>* child){
  m_fChild = child;
}
