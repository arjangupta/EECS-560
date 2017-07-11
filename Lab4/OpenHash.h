/*
 * @file: OpenHash.h
 * @author: Arjan Gupta
 * @date: 2.19.2017
 * @purpose: Header of OpenHash class in lab 4, EECS 560
 */

#ifndef OPENHASH_H
#define OPENHASH_H

#include <string>
#include "DoubleLinkedList.h"

template <typename T>
class OpenHash
{
public:
	OpenHash(int size);
	~OpenHash();
	void insert(T value);
	void deletenode(T value);
	void print();
	bool find(T value);
private:
	DoubleLinkedList<T>** m_dll_arr;
	T m_hash_num;
	int hash(T value);
};

#include "OpenHash.hpp"
#endif //OPENHASH_H
