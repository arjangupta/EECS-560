/*
 * @file: MinMaxHeap.hpp
 * @author: Arjan Gupta
 * @date: 03.13.2017
 * @purpose: Template file for Min-Max Heap class of Lab 7, EECS 560
 */

template <typename T>
MinMaxHeap<T>::MinMaxHeap(){
	m_arr = new int[300];
	m_numChildren = 2;
	for(int i=0; i<200; i++){
		m_arr[i] = -1;
	}
	m_last = -1;
}

template <typename T>
MinMaxHeap<T>::~MinMaxHeap(){
	delete[] m_arr;
}

template <typename T>
void MinMaxHeap<T>::buildBottomUp()
{
	int init = parent(m_last);
	for(int i=init; i>=0; i--){
		trickleDown(i);
	}
}

template <typename T>
void MinMaxHeap<T>::levelorder(){
	if(m_last < 0){
		std::cout << "Heap is empty, nothing to print.\n" << std::endl;
	}else{
		std::cout << "Level order:\n";
		int endLine = 1;
		for(int i=1; i <= m_last+1; i++){
			if(i == endLine){
				std::cout << "\n";
				endLine = 2*endLine;
			}
			std::cout << m_arr[i-1] << " ";
		}
		std::cout << "\n";
	}
}

template <typename T>
void MinMaxHeap<T>::insert(int val){
	if(m_last >= 299){
		std::cout << "Heap is at capacity, cannot add more\n";
	}else{
		m_last++;
		m_arr[m_last] = val;
		bubbleUp(m_last);
	}
}
	
template <typename T>
bool MinMaxHeap<T>::deletemin(){
	if(m_last == -1){
		std::cout << "Heap is empty, nothing to delete\n";
		return false;
	}else{
		m_arr[0] = m_arr[m_last];
		m_arr[m_last] = -1;
		m_last--;
		trickleDown(0);
		return true;
	}
}

template <typename T>
bool MinMaxHeap<T>::deletemax(){
	if(m_last == -1){
		std::cout << "Heap is empty, nothing to delete\n";
		return false;
	}else if(m_last == 0){
		m_arr[0] = -1;
		m_last--;
		return true;
	}else{
		int largest = 1;
		for(int i=2; i <= m_numChildren; i++){
			if(i > m_last){
				break;
			}
			if(m_arr[largest] < m_arr[i]){
				largest = i;
			}
		}
		m_arr[largest] = m_arr[m_last];
		m_arr[m_last] = -1;
		m_last--;
		trickleDown(largest);
	}
}

template <typename T>
void MinMaxHeap<T>::add(int val){
	if(m_last >= 299){
		std::cout << "Heap is at capacity, cannot add more\n";
	}else{
		m_last++;
		m_arr[m_last] = val;
	}
}

template <typename T>
int MinMaxHeap<T>::kChildOfi(int i, int k){
	int indexOfChild = (m_numChildren*i)+k;
	if(indexOfChild > m_last){
		return -1;
	}else{
		return indexOfChild;
	}
}

template <typename T>
int MinMaxHeap<T>::parent(int i){
	if(i <= 0){
		return -1;
	}else{
		return floor((i-1)/(double(m_numChildren)));
	}
}
	
template <typename T>
void MinMaxHeap<T>::bubbleUp(int i){
	int parentIndex = parent(i);
	if(parentIndex == -1){
		//do nothing
	}else if(isMinLevel(i)){
		if(m_arr[i] > m_arr[parentIndex]){
			swapValues(m_arr[i], m_arr[parentIndex]);
			bubbleUpMax(parentIndex);
		}else{
			bubbleUpMin(i);
		}
	}else{
		if(m_arr[i] < m_arr[parentIndex]){
			swapValues(m_arr[i],m_arr[parentIndex]);
			bubbleUpMin(parentIndex);
		}else{
			bubbleUpMax(i);
		}
	}
}

template <typename T>
void MinMaxHeap<T>::bubbleUpMin(int i){
	int grandParent = parent(parent(i));
	if(grandParent == -1){
		//do nothing
	}else if(m_arr[i] < m_arr[grandParent]){
		swapValues(m_arr[i],m_arr[grandParent]);
		bubbleUpMin(grandParent);
	}else{
		//do nothing
	}
}

template <typename T>
void MinMaxHeap<T>::bubbleUpMax(int i){
	int grandParent = parent(parent(i));
	if(grandParent == -1){
		//do nothing
	}else if(m_arr[i] > m_arr[grandParent]){
		swapValues(m_arr[i],m_arr[grandParent]);
		bubbleUpMax(grandParent);
	}else{
		//do nothing
	}
}

template <typename T>
void MinMaxHeap<T>::trickleDown(int i){
	if(isMinLevel(i)){
		trickleDownMin(i);
	}else{
		trickleDownMax(i);
	}
}

template <typename T>
void MinMaxHeap<T>::trickleDownMin(int i){
	if(kChildOfi(i,1)>(-1)){
		int smallestChild = findSmallestChild(i);
		int smallestGrandChild = findSmallestGrandChild(i);
		int smallest = 0;
		if((smallestGrandChild > -1) && (m_arr[smallestChild] > m_arr[smallestGrandChild])){
			smallest = smallestGrandChild;
			if(m_arr[smallest] < m_arr[i]){
				swapValues(m_arr[smallest], m_arr[i]);
				if(m_arr[smallest] > m_arr[parent(smallest)]){
					swapValues(m_arr[smallest], m_arr[parent(smallest)]);
				}
				trickleDownMin(smallest);
			}
		}else{
			smallest = smallestChild;
			if(m_arr[smallest] < m_arr[i]){
				swapValues(m_arr[i], m_arr[smallest]);
			} 
		}
	}
}

template <typename T>
void MinMaxHeap<T>::trickleDownMax(int i){
	if(kChildOfi(i,1) < m_last){
		int largestChild = findLargestChild(i);
		int largestGrandChild = findLargestGrandChild(i);
		int largest = 0;
		if((largestGrandChild > 0) && (m_arr[largestChild] < m_arr[largestGrandChild])){
			largest = largestGrandChild;
			if(m_arr[largest] > m_arr[i]){
				swapValues(m_arr[largest], m_arr[i]);
				if(m_arr[largest] < m_arr[parent(largest)]){
					swapValues(m_arr[largest], m_arr[parent(largest)]);
				}
				trickleDownMax(largest);
			}
		}else{
			largest = largestChild;
			if(m_arr[largest] > m_arr[i]){
				swapValues(m_arr[i], m_arr[largest]);
			} 
		}
	}
}

template <typename T>
int MinMaxHeap<T>::findSmallestGrandChild(int i){
	if(kChildOfi(i,1) == -1){
		return -1;
	}
	if(kChildOfi(kChildOfi(i,1),1) == -1){
		return -1;
	}
	
	int smallest = kChildOfi(kChildOfi(i,1),1);
	for(int j=1; j <= m_numChildren; j++){
		for(int k=1; k <= m_numChildren; k++){
			if(kChildOfi(kChildOfi(i,j),k) == -1){
				break;
			}
			if(m_arr[kChildOfi(kChildOfi(i,j),k)] < m_arr[smallest]){
				smallest = kChildOfi(kChildOfi(i,j),k);
			}
		}
	}
	return smallest;
}
	
template <typename T>
int MinMaxHeap<T>::findLargestGrandChild(int i){
	if(kChildOfi(i,1) == -1){
		return -1;
	}
	if(kChildOfi(kChildOfi(i,1),1) == -1){
		return -1;
	}
	
	int largest = kChildOfi(kChildOfi(i,1),1);
	for(int j=1; j <= m_numChildren; j++){
		for(int k=1; k <= m_numChildren; k++){
			if(kChildOfi(kChildOfi(i,j),k) == -1){
				break;
			}
			if(m_arr[kChildOfi(kChildOfi(i,j),k)] > m_arr[largest]){
				largest = kChildOfi(kChildOfi(i,j),k);
			}
		}
	}
	return largest;
}
	
template <typename T>
int MinMaxHeap<T>::findSmallestChild(int i){
	if(kChildOfi(i,1) == -1){
		return -1;
	}
	int smallest = kChildOfi(i,1);
	for(int j=2; j <= m_numChildren; j++){
		if(kChildOfi(i,j) == -1){
			break;
		}
		if(m_arr[smallest] > m_arr[kChildOfi(i,j)]){
			smallest = kChildOfi(i,j);
		}
	}
	return smallest;
}
	
template <typename T>
int MinMaxHeap<T>::findLargestChild(int i){
	if(kChildOfi(i,1) == -1){
		return -1;
	}
	int largest = kChildOfi(i,1);
	for(int j=2; j <= m_numChildren; j++){
		if(kChildOfi(i,j) == -1){
			break;
		}
		if(m_arr[largest] < m_arr[kChildOfi(i,j)]){
			largest = kChildOfi(i,j);
		}
	}
	return largest;

}

template <typename T>
void MinMaxHeap<T>::swapValues(int &value1, int &value2){
	int temp = value1;
	value1 = value2;
	value2 = temp;
}
	
template <typename T>
bool MinMaxHeap<T>::isMinLevel(int i){
	int level;
	if(m_numChildren == 2){
		level = ceil(log2(i+2)-1);
	}else{
		level = ceil(log(i+2)/(log(m_numChildren)-1));
	}

	if(level%2 == 0){
		return true;
	}else{
		return false;
	}
}

