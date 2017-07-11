/**
 * @file: DoubleLinkedList.h
 * @author: Arjan Gupta
 * @date: 01.29.2017
 * @purpose: Part of DoubleLinkedList class in Lab1 for EECS 560
 */

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <iostream>
#include "Node.h"

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
	bool find(T value);
private:
	int insertRec(Node<T>* temp, T value);
	int deletenodeRec(Node<T>* temp, T value);
	int reverseRec(Node<T>* pivot);
	bool findRec(Node<T>* temp, T value);
	Node<T>* m_front;
	Node<T>* m_back;
	int m_size;
};

#include "DoubleLinkedList.hpp"
#endif //DOUBLELINKEDLIST_H
