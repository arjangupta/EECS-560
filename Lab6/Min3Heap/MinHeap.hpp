/*
 * @file: MinHeap.hpp
 * @author: Arjan Gupta
 * @date: 03.06.2017
 * @purpose: HPP file of MinHeap class for Lab 6, EECS 560
 */

template <typename T>
MinHeap<T>::MinHeap(int capacity, int numChildren){
 	m_capacity = capacity;
  	m_numChildren = numChildren;
  	m_arr = new T[capacity];
  	m_currentSize = 0;
  	for(int i = 0; i < capacity; i++){
    		m_arr[i] = -1;
  	}
}

template <typename T>
MinHeap<T>::MinHeap(int capacity, int numChildren, int arr[], int arrSize){
	m_capacity = capacity;
	m_numChildren = numChildren;
	m_arr = new T[capacity];
	m_currentSize = arrSize;
	for(int i = 0; i < capacity; i++){
		if(i < arrSize){
			m_arr[i] = arr[i];
		}else{
			m_arr[i] = -1;
		}	
	}
	buildBottomUp();
}

template <typename T>
MinHeap<T>::~MinHeap(){
	delete[] m_arr;
}

template <typename T>
void MinHeap<T>::buildBottomUp(){
	for(int i = (m_currentSize-1); i >= 0; i--){
		pushDown(i);
	}
}

template <typename T>
void MinHeap<T>::pushDown(int index){
	long child;
	T temp = m_arr[index];
	for(; kthChildOf(index, 1) < m_currentSize; index = child){
		child = findSmallestChild(index);
		if(m_arr[child] < temp){
			m_arr[index] = m_arr[child];
		}else{break;}
	}
	m_arr[index] = temp;
}

template <typename T>
void MinHeap<T>::pushUp(int index){
	T temp = m_arr[index];
	while(index > 0 && temp < m_arr[parentOf(index)]){
		m_arr[index] = m_arr[parentOf(index)];
		index = parentOf(index);
	}
	m_arr[index] = temp;
}

template <typename T>
int MinHeap<T>::findSmallestChild(int index){
	int smallestKnown = kthChildOf(index, 1);
	int j = 2;
	int assumeSmaller = kthChildOf(index, j);
	while((j <= m_numChildren) && (assumeSmaller < m_currentSize)){
		if(m_arr[assumeSmaller] < m_arr[smallestKnown]){
			smallestKnown = assumeSmaller;
		}
		j++;
		assumeSmaller = kthChildOf(index, j);
	}
	return smallestKnown;
}

template <typename T>
void MinHeap<T>::insert(T value){
	if(add(value)){
		std::cout << "hello";
		pushUp(m_currentSize-1);
	}
}

template <typename T>
bool MinHeap<T>::add(T value){
	if(m_currentSize == m_capacity){
		std::cout << "Heap is at capacity, cannot add more elements." << std::endl;
		return false;
	}else{
		m_arr[m_currentSize] = value;
		m_currentSize++;
		return true;
	}
}

template <typename T>
void MinHeap<T>::deletemin(){
	if(m_currentSize == 0){
		std::cout << "Heap is empty, nothing to delete." << std::endl;
	}else{
		removeHelper(m_arr[0], false);
	}
}

template <typename T>
void MinHeap<T>::deletemax(){
	if(m_currentSize == 0){
		std::cout << "Heap is empty, nothing to delete." << std::endl;
	}else{
		int indexOfMax = floor((m_currentSize-1)/m_numChildren);
		for(int i = indexOfMax; i < m_currentSize; i++){
			if(m_arr[indexOfMax] < m_arr[i]){
				indexOfMax = i;
			}
		}
	removeHelper(m_arr[indexOfMax], false);
	}	
}

template <typename T>
void MinHeap<T>::remove(T value){
	if(m_currentSize == 0){
		std::cout << "Heap is empty, nothing to remove." << std::endl;
	}else{
		removeHelper(value, true);
	}
}

template <typename T>
void MinHeap<T>::removeHelper(T val, bool checkMultiple){
	bool toContinue = checkMultiple;
	do{
		int indexOfVal = search(val);
		if(indexOfVal != -1){
			m_arr[indexOfVal] = m_arr[m_currentSize-1];
			m_arr[m_currentSize-1];
			m_currentSize--;
			pushDown(indexOfVal);
		}else{
			toContinue = false;
		}
	}while(toContinue);
}

template <typename T>
int MinHeap<T>::search(T value){
	for(int i = 0; i < m_currentSize; i++){
		if(value == m_arr[i]){
			return i;
		}
	}
	return -1;
}

template <typename T>
void MinHeap<T>::levelorder() const{
	if(m_currentSize == 0){
		std::cout << "Heap is empty." << std::endl;
	}else{
		std::cout << "Level order:" << std::endl;
		for(int i = 0; i < m_currentSize; i++){
			std::cout << m_arr[i] << " ";
			if(i%m_numChildren == 0){
				//initialize some printing vars
				bool endOfLevel = false;
				int sum = 0;
				int power = 1;
				while(sum < i){
					sum += pow(m_numChildren, power);
					power++;
					if(i == sum){
						endOfLevel = true;
						break;
					}
				}
				if(endOfLevel || i==0){
					std::cout << "\n";
				}else if(i < m_currentSize && i != m_currentSize-1){
					std::cout << "- ";
				}
			}
		}
		std::cout << "\n";
	}
}

template <typename T>
int MinHeap<T>::kthChildOf(int i, int k){
	return (m_numChildren*i + k);
}

template <typename T>
int MinHeap<T>::parentOf(int i){
	return floor((i-1)/m_numChildren);
}
