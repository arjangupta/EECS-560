/**
 * @file: DoubleLinkedList.h
 * @author: Arjan Gupta
 * @date: 01.29.2017
 * @purpose: Part of DoubleLinkedList class in Lab1 for EECS 560
 */

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "Node.h"
#include <iostream>

template <typename T>
class DoubleLinkedList
{
public:
	DoubleLinkedList();
	~DoubleLinkedList();
	bool isEmpty() const;
	int size() const;
	void insert(T value);
	void deletenode(T value);
	void print();
	void reverse();
private:
	int insertRec(Node<T>* temp, T value);
	int deletenodeRec(Node<T>* temp, T value);
	int reverseRec(Node<T>* pivot);
	Node<T>* m_front;
	Node<T>* m_back;
	int m_size;
};

#include "DoubleLinkedList.hpp"
#endif //DOUBLELINKEDLIST_H
