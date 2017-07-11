/**
 * @file: QueueNode.hpp
 * @author: Arjan Gupta
 * @date: 02.27.2017
 * @purpose: Template file for QueueNode class for Lab 5, 8 & 9 in EECS 560
 */

template <typename T>
QueueNode<T>::QueueNode()
{
	m_next = nullptr;
	m_value = T();
}

template <typename T>
T QueueNode<T>::getValue() const
{
	return m_value;
}

template <typename T>
void QueueNode<T>::setValue(T value)
{
	this->m_value = value;
}

template <typename T>
QueueNode<T>* QueueNode<T>::getNext() const
{
    return m_next;
}

template <typename T>
void QueueNode<T>::setNext(QueueNode<T>* next)
{
    this->m_next = next;
}
