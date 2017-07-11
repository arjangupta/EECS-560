/**
 * @file: Node.hpp
 * @author: Arjan Gupta
 * @date: 01.29.2017
 * @purpose: Template file for Node class, Lab 1, EECS 560
 */

template <typename T> 
Node<T>::Node()
{
	m_previous = nullptr;
	m_next = nullptr;
	m_value = T();
}

template <typename T>
T Node<T>::getValue() const
{
	return m_value;
}

template <typename T>
void Node<T>::setValue(T value)
{
	this->m_value = value;
}

template <typename T>
Node<T>* Node<T>::getPrevious() const
{
	return m_previous;
}

template <typename T>
void Node<T>::setPrevious(Node<T>* previous)
{
    this->m_previous = previous;
}

template <typename T>
Node<T>* Node<T>::getNext() const
{
    return m_next;
}

template <typename T>
void Node<T>::setNext(Node<T>* next)
{
    this->m_next = next;
}

