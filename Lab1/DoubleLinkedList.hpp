/**
 * @file: DoubleLinkedList.hpp
 * @author: Arjan Gupta
 * @date: 01.29.2017
 * @purpose: Template HPP file for DoubleLinkedList class, Lab 1, EECS 560
 */

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
	m_front = nullptr;
	m_back = nullptr;
	m_size = 0;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	while(m_front != nullptr){
		deletenode(m_front->getValue());
	}
}

template <typename T>
bool DoubleLinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int DoubleLinkedList<T>::size() const
{
	return(m_size);
}

template <typename T>
void DoubleLinkedList<T>::insert(T value)
{
	if(insertRec(m_front, value) == 0){			
		Node<T>* freshNode = new Node<T>();
		freshNode->setValue(value);
		if(isEmpty()){
			m_front = freshNode;
			m_back = m_front;
		}else{
			m_back->setNext(freshNode);
			freshNode->setPrevious(m_back);
			m_back = freshNode;
		}
		m_size++;
	}else{
		//Do nothing because the value already exists in the list
	}	
}

template <typename T>
int DoubleLinkedList<T>::insertRec(Node<T>* temp, T value)
{
	if(temp == nullptr){
		return 0;
	}else if(temp->getValue() == value){
		return 1;
	}else{
		insertRec(temp->getNext(), value);
	}
}

template <typename T>
void DoubleLinkedList<T>::deletenode(T value)
{
	deletenodeRec(m_front, value);
}

template <typename T>
int DoubleLinkedList<T>::deletenodeRec(Node<T>* temp, T value)
{
	if(temp == nullptr){
		std::cout << "There is nothing in this list, so nothing was removed" << std::endl;
		return 0;
	}else if(temp->getValue() == value){
		//value has been found in the list
		if(m_size == 1){
			//this is the one and only node in the whole list
			//delete it and set everything back to initilization
			m_front = nullptr;
			m_back = nullptr;
		}else if(temp->getPrevious() == nullptr){
			//this is the first node in the list
			//list is longer than 1
			m_front = temp->getNext();
			m_front->setPrevious(nullptr);
		}else if(temp->getNext() == nullptr){
			//we are at the last node in the list
			//list is longer than 1
			m_back = temp->getPrevious();
			m_back->setNext(nullptr);
		}else{
			//delete a node that is somewhere between the first and last nodes
			Node<T>* tempPrev = temp->getPrevious();
			Node<T>* tempNext = temp->getNext();
			tempPrev->setNext(tempNext);
			tempNext->setPrevious(tempPrev);
		}
		delete temp;
		m_size--;
		return 1;
	}else{
		deletenodeRec(temp->getNext(), value);
	}
}

template <typename T>
void DoubleLinkedList<T>::print()
{
	Node<T>* printer = m_front;
	std::cout << "List: ";
	while(printer != nullptr){
		//std::cout << "   test 4 ";
		std::cout << printer->getValue() << " "; 
		printer = printer->getNext();
	}
	std::cout << "\n";	
}

template <typename T>
void DoubleLinkedList<T>::reverse()
{
	if(m_front == nullptr){
		//list is empty, nothing to do
		std::cout << "Empty list" << std::endl;
	}else{ 
		reverseRec(m_front);
		std::cout << "List reversed." << std::endl;
	}
}

template <typename T>
int DoubleLinkedList<T>::reverseRec(Node<T>* pivot)
{
	if(pivot->getNext() == nullptr){
		//no more nodes to reverse
		//set pivot as the m_back
		m_back = pivot;
		return 0;
	}else{
		Node<T>* tempFront = pivot->getNext();
		Node<T>* newPivotNext = tempFront->getNext();
		tempFront->setPrevious(nullptr); //step 1
		tempFront->setNext(m_front); //step 2
		m_front->setPrevious(tempFront); //step 3
		pivot->setNext(newPivotNext); //step 4
		if(newPivotNext != nullptr){ //step 5
			//if this is not the last node to reverse, then
			//join the pivot to the next node 
			newPivotNext->setPrevious(pivot);
		}
		m_front = tempFront; //step 6
		reverseRec(pivot); // recurse!
	}
}
