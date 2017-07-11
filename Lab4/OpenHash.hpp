/*
 * @file: OpenHash.hpp
 * @author: Arjan Gupta
 * @date: 2.19.2017
 * @purpose: HPP file for OpenHash class, lab 4, EECS 560
 */

template <typename T>
OpenHash<T>::OpenHash(int size){
	m_hash_num = size;

	m_dll_arr = new DoubleLinkedList<T>*[m_hash_num];

	for(int i=0; i<m_hash_num; i++){
		m_dll_arr[i] = new DoubleLinkedList<T>();
	}

}

template <typename T>
OpenHash<T>::~OpenHash(){
	for(int i=0; i<m_hash_num; i++){
		delete m_dll_arr[i];
	}
	delete[] m_dll_arr;
}

template <typename T>
void OpenHash<T>::insert(T value){
	m_dll_arr[hash(value)]->insert(value);
}

template <typename T>
void OpenHash<T>::deletenode(T value){
	m_dll_arr[hash(value)]->deletenode(value);
}


template <typename T>
void OpenHash<T>::print(){
	for(int i=0; i<m_hash_num; i++){
		std::cout << i << ": ";
		m_dll_arr[i]->print();
	}
}

template <typename T>
bool OpenHash<T>::find(T value){
	return m_dll_arr[hash(value)]->find(value);
}


template <typename T>
int OpenHash<T>::hash(T value){
	return value%(m_hash_num);
}
