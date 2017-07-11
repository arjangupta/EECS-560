/*
 * @file: Queue.h
 * @author: Arjan Gupta
 * @date: 2.27.2017
 * @purpose: Queue class HPP file for Lab 5, EECS 560
 */

template <typename T>
Queue<T>::Queue(){
	m_front = nullptr;
	m_back = nullptr;
	m_size = 0;
}

template <typename T>
Queue<T>::~Queue(){
	while(!isEmpty()){
		dequeue();
	}
}

template <typename T>
bool Queue<T>::isEmpty() const{
	return m_size == 0;
}

template <typename T>
void Queue<T>::enqueue(T value){
	QueueNode<T>* temp = new QueueNode<T>();
	temp->setValue(value); 
	if(isEmpty()){
		m_front = temp;
		m_back = m_front;
	}else{
		m_back->setNext(temp);
		m_back = temp;
	}	
	m_size++;
}

template <typename T>
T Queue<T>::dequeue(){
	QueueNode<T>* temp = m_front;
	T tempValue = temp->getValue();
	if(isEmpty()){
		std::cout << "Queue is empty, nothing to remove" << std::endl;
	}else if(m_size == 1){
		m_front = nullptr;
		m_back = nullptr;
		delete temp;
	}else{
		QueueNode<T>* temp = m_front;
		m_front = m_front->getNext();
		delete temp;
	}
	m_size--;
	return tempValue;
}

template <typename T>
T Queue<T>::peekFront(){
	return m_front->getValue();
}

template <typename T>
void Queue<T>::print() const{
	QueueNode<T>* temp = m_front;
	while(temp != nullptr){
		std::cout << temp->getValue() << " ";
		temp = temp->getNext();
	}
	std::cout << "\n";
}
