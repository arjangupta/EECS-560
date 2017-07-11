/**
*	@file : SkewHeap.hpp
*	@author : Arjan Gupta
*	@date : March 26, 2017
*	Purpose : Class for Skew Heap, Lab8, EECS 560
*/

template <typename T>
SkewHeap<T>::SkewHeap(){
    	m_root = nullptr;
}

template <typename T>
SkewHeap<T>::~SkewHeap(){
    	deleteSubTree(m_root);
}

template <typename T>
void SkewHeap<T>::insert(T value){
	SkewNode<T>* newNode = new SkewNode<T>(value);
    	m_root = merge(m_root, newNode);
}

template <typename T>
void SkewHeap<T>::deletemin(){
	if(m_root != nullptr){
        	SkewNode<T>* min = m_root;
        	SkewNode<T>* leftChild = m_root->getLeft();
        	SkewNode<T>* rightChild = m_root->getRight();
        	delete min;
        	min = nullptr;
        	m_root = merge(leftChild, rightChild);
	}
}

template <typename T>
void SkewHeap<T>::preorder(){
    	if(m_root == nullptr){
        	std::cout << "\nThe heap is empty!\n";
    	}else{
        	std::cout << "\npreorder: ";
        	preorder_helper(m_root);
    	}
    	std::cout << "\n";
}

template <typename T>
void SkewHeap<T>::inorder(){
   	 if(m_root == nullptr){
        	std::cout << "\nThe heap is empty!\n";
    	}else{
        	std::cout << "\ninorder: ";
        	inorder_helper(m_root);
    	}
    	std::cout << "\n";
}

template <typename T>
void SkewHeap<T>::levelorder()
{
    	Queue<SkewNode<T>*>* myQueue = new Queue<SkewNode<T>*>();
    	std::cout << "\nLevelorder: \n";
    	if(m_root != nullptr){
        	int endLn = 1;
		int curr = 1;
		SkewNode<T>* track;
        	bool isNewLnPrint = false;
		myQueue->enqueue(m_root);
		//do it once and keep doin
        	do{
            		track = myQueue->peekFront();
            		myQueue->dequeue();
			if(curr == endLn){
				if(isNewLnPrint == true){
					break;
				}	
				std::cout << "\n";
				isNewLnPrint = true;
				endLn = 2 * endLn;
			}
           		if(track->getValue() == -1){
                		curr++;
            		}else{
	            		std::cout << track->getValue() << " ";
				isNewLnPrint = false;
				curr++;
			}
            		if(track->getLeft() != nullptr)
            		{
                		myQueue->enqueue(track->getLeft());
            		}
            		if(track->getLeft() == nullptr){
                		SkewNode<T>* emptyNode = new SkewNode<T>(-1);
				myQueue->enqueue(emptyNode);
            		}
			if(track->getRight() != nullptr){
                		myQueue->enqueue(track->getRight());
            		}
            		if(track->getRight() == nullptr){
                		SkewNode<T>* emptyNode = new SkewNode<T>(-1);
                		myQueue->enqueue(emptyNode);
			}
        	}while(!(myQueue->isEmpty()));
	}
	delete myQueue;
}

template <typename T>
SkewNode<T>* SkewHeap<T>::merge(SkewNode<T>* leftKid, SkewNode<T>* rightKid){
    	if(leftKid == nullptr){
        	return rightKid;
    	}
    	else if(rightKid == nullptr){
        	return leftKid;
    	}else{
        	if(leftKid->getValue() > rightKid->getValue()){
            		SkewNode<T>* temp;
            		temp = leftKid;
            		leftKid = rightKid;
            		rightKid = temp;
        	}
        	SkewNode<T>* tempTree;
        	tempTree = leftKid->getRight();
        	leftKid->setRight(leftKid->getLeft());
        	leftKid->setLeft(merge(tempTree, rightKid));
        	return leftKid;
   	}
}

template <typename T>
void SkewHeap<T>::preorder_helper(SkewNode<T>* subTree){
    if(subTree != nullptr){
        std::cout << subTree->getValue() << " ";
        preorder_helper(subTree->getLeft());
        preorder_helper(subTree->getRight());
    }
}

template <typename T>
void SkewHeap<T>::inorder_helper(SkewNode<T>* subTree){
	if(subTree != nullptr){
        	inorder_helper(subTree->getLeft());
        	std::cout << subTree->getValue() << " ";
        	inorder_helper(subTree->getRight());
    	}
}

template <typename T>
void SkewHeap<T>::deleteSubTree(SkewNode<T>* subTree){
    	if(subTree->getLeft() != nullptr){
        	deleteSubTree(subTree->getLeft());
    	}
    	if(subTree->getRight() != nullptr){
        	deleteSubTree(subTree->getRight());
    	}
    	delete subTree;
}
