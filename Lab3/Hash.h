/*
 * @file: Hash.h
 * @author: Arjan Gupta
 * @date: 2.5.2017
 * @edited: 2.13.2017
 * @purpose: Header of Hash class in lab 3, EECS 560
 */

#ifndef HASH_H
#define HASH_H

#include <fstream>
#include <iostream>
#include <string>

template <typename T>
class Hash
{
public:
	Hash(int quadordh_flag);
	~Hash();
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

#include "Hash.hpp"
#endif //HASH_H
