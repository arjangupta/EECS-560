/**
*	@file : LeftistNode.hpp
*	@author : Arjan Gupta
*	@date : March 26, 2017
*	Purpose : Class for Leftist Node for Lab 8, EECS 560
*/

template <typename T>
LeftistNode<T>::LeftistNode()
{
    m_value = T();
    m_rank = -1;
    m_left = nullptr;
    m_right = nullptr;
}

template <typename T>
LeftistNode<T>::LeftistNode(T value)
{
    m_value = value;
    m_rank = 1;
    m_left = nullptr;
    m_right = nullptr;
}

template <typename T>
LeftistNode<T>::LeftistNode(T value, LeftistNode<T>* leftPtr, LeftistNode<T>* rightPtr)
{
    m_value = value;
    m_rank = 1;
    m_left = leftPtr;
    m_right = rightPtr;
}

template <typename T>
LeftistNode<T>::LeftistNode(T value, int rank, LeftistNode<T>* leftPtr, LeftistNode<T>* rightPtr)
{
    m_value = value;
    m_rank = rank;
    m_left = leftPtr;
    m_right = rightPtr;
}

template <typename T>
void LeftistNode<T>::setValue(T value)
{
    m_value = value;
}

template <typename T>
T LeftistNode<T>::getValue()
{
    return m_value;
}

template <typename T>
void LeftistNode<T>::setRank(int rank)
{
    m_rank = rank;
}

template <typename T>
int LeftistNode<T>::getRank()
{
    return m_rank;
}

template <typename T>
void LeftistNode<T>::setLeft(LeftistNode<T>* leftPtr)
{
    m_left = leftPtr;
}

template <typename T>
LeftistNode<T>* LeftistNode<T>::getLeft()
{
    return m_left;
}

template <typename T>
void LeftistNode<T>::setRight(LeftistNode<T>* rightPtr)
{
    m_right = rightPtr;
}

template <typename T>
LeftistNode<T>* LeftistNode<T>::getRight()
{
    return m_right;
}
