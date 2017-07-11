/*
 * @file: ClosedHash.h
 * @author: Arjan Gupta
 * @date: 2.5.2017
 * @edited: 2.20.2017
 * @purpose: Header of ClosedHash class in lab 4, EECS 560
 */

#ifndef CLOSEDHASH_H
#define CLOSEDHASH_H

#include <iostream>
#include <string>

template <typename T>
class ClosedHash
{
public:
	ClosedHash(int size, int quadordh_flag);
	~ClosedHash();
	void insert(T value);
	void deletenode(T value);
	void print();
private:
	T* m_num_arr;
	bool* m_bool_arr;
	T m_hash_num;
	bool m_is_quad;
	bool find(T value);
	int hash(T value, int i);
};

#include "ClosedHash.hpp"
#endif //CLOSEDHASH_H
