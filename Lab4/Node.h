/**
 * @file: Node.h
 * @author: Arjan Gupta
 * @date: 01.29.2017
 * @purpose: Header file for Node class, Lab01, EECS 560
 */

#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
public:
	Node();
	T getValue() const;
	void setValue(T value);
	Node<T>* getPrevious() const;
	void setPrevious(Node<T>* previous);
	Node<T>* getNext() const;
	void setNext(Node<T>* next);
private:
	T m_value;
	Node<T>* m_previous;
	Node<T>* m_next;
};

#include "Node.hpp"
#endif //NODE_H
