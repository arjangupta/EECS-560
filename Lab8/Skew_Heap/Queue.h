/*
 * @file: Queue.h
 * @author: Arjan Gupta
 * @date: 2.27.2017
 * @purpose: Queue class header file for Lab 5, EECS 560
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "QueueNode.h"
#include <iostream>

template <typename T>
class Queue{
public:
	Queue();
	~Queue();
	bool isEmpty()  const;
	void enqueue(T value);
	T dequeue();
	void print() const;
	T peekFront();
private:
	QueueNode<T>* m_front;
	QueueNode<T>* m_back;
	int m_size;
};

#include "Queue.hpp"

#endif //QUEUE_H
