/**
*	@file : LeftistHeap.hpp
*	@author : Arjan Gupta
*	@date : March 26, 2017
*	Purpose : Class for Leftist Heap, EECS 560 lab 8
*/

template <typename T>
LeftistHeap<T>::LeftistHeap(){
	m_root = nullptr;
}

template <typename T>
LeftistHeap<T>::~LeftistHeap(){
	deleteSubTree(m_root);
}

template <typename T>
void LeftistHeap<T>::insert(T value){
    	LeftistNode<T>* newInsert = new LeftistNode<T>(value);
    	m_root = merge(m_root, newInsert);
}

template <typename T>
void LeftistHeap<T>::deletemin(){
	if(m_root != nullptr){
        	LeftistNode<T>* minNode = m_root;
        	LeftistNode<T>* leftKid = m_root->getLeft();
        	LeftistNode<T>* rightKid = m_root->getRight();
        	delete minNode;
        	minNode = nullptr;
        	m_root = merge(leftKid, rightKid);
    	}else{
		//do nothing	
	}
}

template <typename T>
void LeftistHeap<T>::preorder(){
    	if(m_root == nullptr){
        	std::cout << "\nThe heap is empty\n";
   	}else{
        	std::cout << "\nPreorder: ";
        	preorder_helper(m_root);
    	}
    	std::cout << "\n";
}

template <typename T>
void LeftistHeap<T>::inorder(){
    	if(m_root == nullptr){
        	std::cout << "\nThe heap is empty\n";
    	}else{
        	std::cout << "\nInorder: ";
        	inorder_helper(m_root);
    	}
    	std::cout << "\n";
}

template <typename T>
void LeftistHeap<T>::levelorder(){
	//Works almost perfectly, not 100% though
	Queue<LeftistNode<T>*>* myQueue = new Queue<LeftistNode<T>*>();
    	std::cout << "\nLevelorder: \n";
    	if(m_root != nullptr){ //if not empty
		int crrnt = 1;
		int endLn = 1;
		bool isNewLinePrinted = false;
        	LeftistNode<T>* track;
       		myQueue->enqueue(m_root);		
        	do{
            		track = myQueue->peekFront();
            		myQueue->dequeue();
			if(crrnt == endLn){
				if(isNewLinePrinted == true){
					break;
				}
				std::cout << "\n";
				isNewLinePrinted = true;
				endLn = 2 *endLn;
			}
            		if(track->getValue() == -1){
                		crrnt++;
            		}else{
	            		std::cout << track->getValue() << " ";
				isNewLinePrinted = false;
				crrnt++;
			}
            		if(track->getLeft() != nullptr){
                		myQueue->enqueue(track->getLeft());
            		}
            		if(track->getLeft() == nullptr){
                		LeftistNode<T>* nothing = new LeftistNode<T>(-1);
				myQueue->enqueue(nothing);
            		}
            		if(track->getRight() != nullptr){
              	  		myQueue->enqueue(track->getRight());
            		}
            		if(track->getRight() == nullptr){
                		LeftistNode<T>* nothing = new LeftistNode<T>(-1);
                		myQueue->enqueue(nothing);
            		}			
        	}while(!(myQueue->isEmpty()));
    	}else{
		//do nothing	
	}
	delete myQueue;
}

template <typename T>
LeftistNode<T>* LeftistHeap<T>::merge(LeftistNode<T>* leftSubTree, LeftistNode<T>* rightSubTree){
    	if(leftSubTree == nullptr){ //if the left subtree is null, you want to return because this is a left subtree!!
        	return rightSubTree;
    	}else if(rightSubTree == nullptr){ //if there's no right subtree
        	return leftSubTree;
    	}else{
        	if(leftSubTree->getValue() > rightSubTree->getValue()){
            		LeftistNode<T>* temp1;
            		temp1 = leftSubTree;
            		leftSubTree = rightSubTree;
         	   	rightSubTree = temp1;
        	}
        	leftSubTree->setRight(merge(leftSubTree->getRight(), rightSubTree));
        	if((leftSubTree->getLeft() == nullptr) || (leftSubTree->getLeft()->getRank() < leftSubTree->getRight()->getRank()) ){
            		LeftistNode<T>* temp2;
            		temp2 = leftSubTree->getLeft();
            		leftSubTree->setLeft(leftSubTree->getRight());
            		leftSubTree->setRight(temp2);
        	}
        	if(leftSubTree->getRight() == nullptr){
          	  	leftSubTree->setRank(1);
        	}else{
            		leftSubTree->setRank((leftSubTree->getRight()->getRank()) + 1);
        	}
        	return leftSubTree;
    	}
}

template <typename T>
void LeftistHeap<T>::preorder_helper(LeftistNode<T>* subTree){
    	if(subTree != nullptr){
        	std::cout << subTree->getValue() << " ";
        	preorder_helper(subTree->getLeft());
        	preorder_helper(subTree->getRight());
    	}
}

template <typename T>
void LeftistHeap<T>::inorder_helper(LeftistNode<T>* subTree){
    	if(subTree != nullptr){
        	inorder_helper(subTree->getLeft());
        	std::cout << subTree->getValue() << " ";
        	inorder_helper(subTree->getRight());
    	}
}

template <typename T>
void LeftistHeap<T>::deleteSubTree(LeftistNode<T>* subTree){
	if(subTree->getLeft() != nullptr){
    		deleteSubTree(subTree->getLeft());
    	}
    	if(subTree->getRight() != nullptr){
        	deleteSubTree(subTree->getRight());
    	}
    	delete subTree; //poor subtree
}
