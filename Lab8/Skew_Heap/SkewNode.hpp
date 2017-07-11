/**
*	@file : SkewNode.hpp
*	@author : Arjan Gupta
*	@date : March 26, 2017
*	Purpose : SkewNode class for Lab 8, EECS 560
*/

template <typename T>
SkewNode<T>::SkewNode(){
    m_value = T();
    m_left = nullptr;
    m_right = nullptr;
}

template <typename T>
SkewNode<T>::SkewNode(T value){
    m_value = value;
    m_left = nullptr;
    m_right = nullptr;
}

template <typename T>
SkewNode<T>::SkewNode(T value, SkewNode<T>* leftPtr, SkewNode<T>* rightPtr){
    m_value = value;
    m_left = leftPtr;
    m_right = rightPtr;
}

template <typename T>
void SkewNode<T>::setValue(T value){
    m_value = value;
}

template <typename T>
T SkewNode<T>::getValue(){
    return m_value;
}

template <typename T>
void SkewNode<T>::setLeft(SkewNode<T>* leftPtr){
    m_left = leftPtr;
}

template <typename T>
SkewNode<T>* SkewNode<T>::getLeft(){
    return m_left;
}

template <typename T>
void SkewNode<T>::setRight(SkewNode<T>* rightPtr){
    m_right = rightPtr;
}

template <typename T>
SkewNode<T>* SkewNode<T>::getRight(){
    return m_right;
}
