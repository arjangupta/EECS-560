/**
 * @file: BST.hpp
 * @author: Arjan Gupta
 * @date: 02.27.2017
 * @purpose: HPP file for BST class, Lab 5, EECS 560
 */

template <typename T>
BST<T>::BST(){
	m_root = nullptr;
}

template <typename T>
BST<T>::~BST(){
	while(m_root != nullptr){
		deletemin();
	}
}

template <typename T>
void BST<T>::insert(T value){
	insertRec(value, this->m_root);
}

template <typename T>
void BST<T>::insertRec(T value, BSTNode<T>* subtree){	
	if(m_root == nullptr){
		BSTNode<T>* firstNode = new BSTNode<T>();
		firstNode->setValue(value);
		m_root = firstNode;
	}else{
		if(value < subtree->getValue()){
			if(subtree->getLeft() == nullptr){
				BSTNode<T>* tempNode = new BSTNode<T>();
				tempNode->setValue(value);
				subtree->setLeft(tempNode);
				tempNode->setParent(subtree);
			}else{
				insertRec(value, subtree->getLeft());
			}
		}else{
			if(subtree->getRight() == nullptr){
				BSTNode<T>* tempNode = new BSTNode<T>();
				tempNode->setValue(value);
				subtree->setRight(tempNode);
				tempNode->setParent(subtree);
			}else{
				insertRec(value, subtree->getRight());
			}
		}
	}
}

template <typename T>
BSTNode<T>* BST<T>::search(T value, BSTNode<T>* subtree) const{
	if(value == subtree->getValue()){
		return subtree;
	}else if(value < subtree->getValue()){
		if(subtree->getLeft() != nullptr){
			search(value, subtree->getLeft());
		}else{
			return nullptr; //return a nullptr because value is not in BST
		}
	}else{
		if(subtree->getRight() != nullptr){
			search(value, subtree->getRight());
		}else{
			return nullptr; //return a nullptr because value is not in BST
		}
	}
}

//Here, in the comments "ntbr" is short for "node to be removed"
template <typename T>
void BST<T>::remove(T value){
	BSTNode<T>* tempPtr = search(value, this->m_root);
	if(tempPtr == nullptr){
		std::cout << "\n" << value << " is not in the tree" << std::endl;
	}else{
		/*
 		 * There are four cases while removing nodes, and each has a m_root case and a subtree case:
 		 * CASE 1: Node has no children, right and left point to null. CASE 1.5: Account for the fact that the node to be removed could be m_root.
 		 * CASE 2: Node has two children. CASE 2.5: Account for m_root as well.
 		 * CASE 3: Node has a right child but no left child. CASE 3.5: Account for m_root. 
 		 * CASE 4: Node has a left child but no right child. CASE 4.5: Account for m_root.
 		 * According to the instructions of this lab, when we remove a node, we replace that node with the smallest value in the right subtree of the node to be removed (draw a tree to picture it!).
 		 * Anyway, in the if-else-if block, you will see that the if statement takes care of CASE 1 and 1.5. 
 		 * The first else-if statement takes care of CASES 2, 2.5, 3, 3.5.
 		 * The second else-if statement takes care of CASE 4.
 		 */ 
		if(tempPtr->getLeft() == nullptr && tempPtr->getRight() == nullptr){
			BSTNode<T>* tempParent = tempPtr->getParent();
			if(tempParent == nullptr){ //hurray, we've found ourself the m_root
				m_root = nullptr;
			}else if(tempParent->getLeft() == tempPtr){
				tempParent->setLeft(nullptr);
			}else{
				tempParent->setRight(nullptr);
			}
			delete tempPtr;
		}else if(tempPtr->getRight() != nullptr){ //we account for m_root, as well as subtrees 
			//Set temp pointers to the right and parent of the ntbr
			BSTNode<T>* tempParent = tempPtr->getParent();
			BSTNode<T>* tempRight = tempPtr->getRight();
			//Set a pointer to find the smallest value in the right subtree of the ntbr
			BSTNode<T>* minRight = tempRight;
			while(minRight->getLeft() != nullptr){ //find the smallest value in the right subtree
				minRight = minRight->getLeft();
			}
			//set the parent of the minRight's left child to be the right of minRight
			//BUT! only do this if the parent of minRight isn't also the tempPtr itself, in which
			//case, leave it
			BSTNode<T>* minRightParent = minRight->getParent();
			if(tempPtr != minRightParent){
					minRightParent->setLeft(minRight->getRight());
					if(minRight->getRight() != nullptr){
						minRight->getRight()->setParent(minRightParent);
					}
			}
			//Now we want to start replacing the tempPtr with minRight, so:
			//Set the left of the minRight to the left of the tempPtr
			minRight->setLeft(tempPtr->getLeft());
			if(tempPtr->getLeft() != nullptr){
				tempPtr->getLeft()->setParent(minRight);
			}
			//Set the parent of tempPtr to point to the minRight, and
			//set minRight's parent as tempPtr's parent
			//only do this if tempParent is not nullptr
			// IF the tempParent is nullptr, naturally tempPtr is the m_root. Make minRight the new root.
			if(tempParent != nullptr){
				if(tempParent->getLeft() == tempPtr){
					tempParent->setLeft(minRight);
				}else{
					tempParent->setRight(minRight);
				}
				minRight->setParent(tempParent);
			}else{
				m_root = minRight;
				minRight->setParent(nullptr);
			}
			//Set the right of minRight to the right of the tempPtr
			//CAREFUL: tempPtr's right might be minRight, in which case do nothing
			//Also, set the parent of the right of the tempPtr to minRight if right of tempPtr is not minRight
			if(tempPtr->getRight() == minRight){
				//do nothing
			}else{
				minRight->setRight(tempPtr->getRight());
				tempPtr->getRight()->setParent(minRight);
			}
			//finally, delete the tempPtr
			delete tempPtr;
		}else if(tempPtr->getLeft() != nullptr){
			//Before you read this code, understand this: if this else-if was evaluated to be true, then you naturally have a node to be removed which has no right children. This is because I've already accounted for the possibility of right children in the previous if-else blocks. Think about it. In essence, this else-if block only accounts for the case where there is a left child but NO right child.	
			if(tempPtr == m_root){
				m_root = tempPtr->getLeft();
				m_root->setParent(nullptr);
			}else{
				BSTNode<T>* tempLeft = tempPtr->getLeft();
				BSTNode<T>* tempParent = tempPtr->getParent();
				tempLeft->setParent(tempParent);
				tempParent->setLeft(tempLeft);
			}
			delete tempPtr;
		}
	}
}

template <typename T>
void BST<T>::deletemin(){
	BSTNode<T>* min = this->m_root;
	if(min == nullptr){
		std::cout << "\nEmpty tree, nothing to delete." << std::endl;
	}else{
		while(min->getLeft() != nullptr){
			min = min->getLeft();
		}
		remove(min->getValue());
	}
}

template <typename T>
void BST<T>::deletemax(){
	BSTNode<T>* max = this->m_root;
	if(max == nullptr){
		std::cout << "\nEmpty tree, nothing to delete." << std::endl;
	}else{
		while(max->getRight() != nullptr){
			max = max->getRight();
		}
		remove(max->getValue());
	}
}

template <typename T>
void BST<T>::preorder() const{
	std::cout << "Preorder: ";
	if(m_root == nullptr){
		std::cout << "Empty tree.";
	}else{
		preorderRec(this->m_root);
	}
	std::cout << "\n";
}

template <typename T>
int BST<T>::preorderRec(BSTNode<T>* subtree) const{
	if(subtree == nullptr){
		return 0;
	}else{
		std::cout << subtree->getValue() << " ";
		preorderRec(subtree->getLeft());
		preorderRec(subtree->getRight());
	}
}

template <typename T>
void BST<T>::inorder() const{
	std::cout << "Inorder: ";
	if(m_root == nullptr){
		std::cout << "Empty tree.";
	}else{
		inorderRec(this->m_root);
	}
	std::cout << "\n";
}

template <typename T>
int BST<T>::inorderRec(BSTNode<T>* subtree) const{
	if(subtree == nullptr){
		return 0;
	}else{
		inorderRec(subtree->getLeft());
		std::cout << subtree->getValue() << " ";
		inorderRec(subtree->getRight());
	}
}

template <typename T>
void BST<T>::levelorder() const{
	std::cout << "Levelorder: ";
	if(m_root == nullptr){
		std::cout << "Empty tree." << std::endl;
	}else{	
		Queue<BSTNode<T>*>* levelQueue = new Queue<BSTNode<T>*>();
		levelQueue->enqueue(m_root);
		BSTNode<T>* dequeuedVal = nullptr;
		while(!levelQueue->isEmpty()){
			dequeuedVal = levelQueue->dequeue();
			std::cout << dequeuedVal->getValue() << " ";
			if(dequeuedVal->getLeft() != nullptr){
				levelQueue->enqueue(dequeuedVal->getLeft());
			}
			if(dequeuedVal->getRight() != nullptr){
				levelQueue->enqueue(dequeuedVal->getRight());
			}
		}
		std::cout << "\n";
		delete levelQueue;
	}
}
