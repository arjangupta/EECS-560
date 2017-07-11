/*
 * @file: Hash.hpp
 * @author: Arjan Gupta
 * @date: 2.13.2017
 * @purpose: HPP file for Hash class, lab 3, EECS 560
 */

template <typename T>
Hash<T>::Hash(int quadordh_flag){
	int inputNum = 0;
	std::string inputStr = "";
	
	if(quadordh_flag == 1){
		m_is_quad = true;	
	}else{
		m_is_quad = false;
	}

	std::ifstream myFile;
	myFile.open("data.txt");
	
	myFile >> inputStr;
	m_hash_num = std::stoi(inputStr);
	
	m_num_arr = new T[m_hash_num];
	m_bool_arr = new bool[m_hash_num];	
	
	for(int i=0; i<m_hash_num; i++){
		m_bool_arr[i] = false;
		m_num_arr[i] = -1;
	}	

	while(myFile >> inputStr){
		inputNum = std::stoi(inputStr);
		insert(inputNum);		
	}
	myFile.close();
}

template <typename T>
Hash<T>::~Hash(){
	delete[] m_num_arr;
	delete[] m_bool_arr;
}

template <typename T>
void Hash<T>::insert(T value){
	for(int i=0; i<m_hash_num; i++){
		if(!find(value) && m_num_arr[hash(value, i)] == -1){
			m_num_arr[hash(value, i)] = value;
		}
	}
}

template <typename T>
void Hash<T>::deletenode(T value){
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
void Hash<T>::print(){
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
bool Hash<T>::find(T value){
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
int Hash<T>::hash(T value, int i){
	if(m_is_quad){
		return ((value%m_hash_num) + i*i)%m_hash_num;
	}else{
		return ((value%m_hash_num) + i*(5 - (value%5)))%m_hash_num;
	}
}
