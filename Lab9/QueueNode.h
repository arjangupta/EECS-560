/**
 * @file: QueueNode.h
 * @author: Arjan Gupta
 * @date: 02.27.2017
 * @purpose: Header file for QueueNode class for Lab 5, 8 & 9 in EECS 560
 */

#ifndef QUEUENODE_H
#define QUEUENODE_H

template <typename T>
class QueueNode
{
public:
	QueueNode();
	T getValue() const;
	void setValue(T value);
	QueueNode<T>* getNext() const;
	void setNext(QueueNode<T>* next);
private:
	T m_value;
	QueueNode<T>* m_next;
};

#include "QueueNode.hpp"
#endif //QUEUENODE_H
