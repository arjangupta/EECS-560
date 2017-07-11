/*
 * @file: Hash.hpp
 * @author: Arjan Gupta
 * @date: 2.5.2017
 * @purpose: HPP file for Hash class, lab 2, EECS 560
 */

template <typename T>
Hash<T>::Hash(){
	int inputNum = 0;
	std::string inputStr = "";
	
	std::ifstream myFile;
	myFile.open("data.txt");
	
	myFile >> inputStr;
	m_hash_num = std::stoi(inputStr);
	
	m_dll_arr = new DoubleLinkedList<T>*[m_hash_num];
	
	for(int i=0; i<m_hash_num; i++){
		m_dll_arr[i] = new DoubleLinkedList<T>();
	}
	
	while(myFile >> inputStr){
		inputNum = std::stoi(inputStr);
		m_dll_arr[hash(inputNum)]->insert(inputNum);		
	}
	myFile.close();
}

template <typename T>
Hash<T>::~Hash(){
	for(int i=0; i<m_hash_num; i++){
		delete m_dll_arr[i];
	}
	delete[] m_dll_arr;
}

template <typename T>
void Hash<T>::insert(T value){
	m_dll_arr[hash(value)]->insert(value);
}

template <typename T>
void Hash<T>::deletenode(T value){
	m_dll_arr[hash(value)]->deletenode(value);
}


template <typename T>
void Hash<T>::print(){
	for(int i=0; i<m_hash_num; i++){
		std::cout << i << ": ";
		m_dll_arr[i]->print();		
	}
}

template <typename T>
bool Hash<T>::find(T value){
	return m_dll_arr[hash(value)]->find(value);
}


template <typename T>
int Hash<T>::hash(T value){
	return value%(m_hash_num);
}
