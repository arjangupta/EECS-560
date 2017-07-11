/**
 * @file: BSTNode.hpp
 * @author: Arjan Gupta
 * @date: 02.27.2017
 * @purpose: Template file for BSTNode class, Lab 5, EECS 560
 */

template <typename T>
BSTNode<T>::BSTNode()
{
	m_left = nullptr;
	m_right = nullptr;
	m_parent = nullptr;
	m_value = T();
}

template <typename T>
T BSTNode<T>::getValue() const
{
	return m_value;
}

template <typename T>
void BSTNode<T>::setValue(T value)
{
	this->m_value = value;
}

template <typename T>
BSTNode<T>* BSTNode<T>::getLeft() const
{
	return m_left;
}

template <typename T>
void BSTNode<T>::setLeft(BSTNode<T>* left)
{
    this->m_left = left;
}

template <typename T>
BSTNode<T>* BSTNode<T>::getRight() const
{
    return m_right;
}

template <typename T>
void BSTNode<T>::setRight(BSTNode<T>* right)
{
    this->m_right = right;
}

template <typename T>
BSTNode<T>* BSTNode<T>::getParent() const
{
    return m_parent;
}

template <typename T>
void BSTNode<T>::setParent(BSTNode<T>* parent)
{
    this->m_parent = parent;
}
