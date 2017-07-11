/*
 * @file: Hash.h
 * @author: Arjan Gupta
 * @date: 2.5.2017
 * @purpose: Header of heap class in lab 2, EECS 560
 */

#ifndef HASH_H
#define HASH_H

#include <fstream>
#include <string>
#include "DoubleLinkedList.h"

template <typename T>
class Hash
{
public:
	Hash();
	~Hash();
	void insert(T value);
	void deletenode(T value);
	void print();
	bool find(T value);
private:
	DoubleLinkedList<T>** m_dll_arr;
	T m_hash_num;
	int hash(T value);
};

#include "Hash.hpp"
#endif //HASH_H
