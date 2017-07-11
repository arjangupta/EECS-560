/*
 * @file: ClosedHash.hpp
 * @author: Arjan Gupta
 * @date: 2.13.2017
 * @purpose: HPP file for ClosedHash class, lab 4, EECS 560
 */

template <typename T>
ClosedHash<T>::ClosedHash(int size, int quadordh_flag){
	if(quadordh_flag == 1){
		m_is_quad = true;
	}else{
		m_is_quad = false;
	}

	m_hash_num = size;
	m_num_arr = new T[m_hash_num];
	m_bool_arr = new bool[m_hash_num];

	for(int i=0; i<m_hash_num; i++){
		m_bool_arr[i] = false;
		m_num_arr[i] = -1;
	}
}

template <typename T>
ClosedHash<T>::~ClosedHash(){
	delete[] m_num_arr;
	delete[] m_bool_arr;
}

template <typename T>
void ClosedHash<T>::insert(T value){
	for(int i=0; i<60000; i++){
		if(!find(value) && m_num_arr[hash(value, i)] == -1){
			m_num_arr[hash(value, i)] = value;
			break;
		}
	}
}

template <typename T>
void ClosedHash<T>::deletenode(T value){
	for(int i=0; i<m_hash_num; i++){
		if(m_num_arr[hash(value,i)] == value){
			m_num_arr[hash(value,i)] = -1;
			m_bool_arr[hash(value,i)] = true;
		}else{
			if(m_num_arr[hash(value,i)] == -1 && !m_bool_arr[hash(value,i)]){
				break; //break the for loop to optimize the search
				std::cout << "The given value does not exist in the table.";
			}
		}
	}
}


template <typename T>
void ClosedHash<T>::print(){
	for(int i=0; i<m_hash_num; i++){
		std::cout << i << ": " << m_num_arr[i] << " flag = ";
		if(m_bool_arr[i]){
			std::cout << "true";
		}else{
			std::cout << "false";
		}
		std::cout << "\n";
	}
}

template <typename T>
bool ClosedHash<T>::find(T value){
	for(int i=0; i<m_hash_num; i++){
		if(m_num_arr[hash(value,i)] == value){
			return true;
		}else{
			if(m_num_arr[hash(value,i)] == -1 && !m_bool_arr[hash(value,i)]){
					return false;
			}
		}
	}
}


template <typename T>
int ClosedHash<T>::hash(T value, int i){
	if(m_is_quad){
		return ((value%m_hash_num) + i*i)%m_hash_num;
	}else{
		return ((value%m_hash_num) + i*(5 - (value%5)))%m_hash_num;
	}
}
