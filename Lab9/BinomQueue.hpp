/*
 * @file: BinomQueue.hpp
 * @author: Arjan Gupta
 * @date: 04.03.2017
 * @purpose: BinomQueue class HPP file for Lab 9 in EECS 560
 */

template <typename T>
BinomQueue<T>::BinomQueue(){
  m_queueSize = 50;
  m_mainQueue = new BinomNode<T>*[m_queueSize];
  for(int i=0; i<m_queueSize; i++){
    m_mainQueue[i] = nullptr;
  }
}

template <typename T>
BinomQueue<T>::~BinomQueue(){
  while(deletemin()){}
  delete[] m_mainQueue;
}

template <typename T>
bool BinomQueue<T>::deletemin(){
  int indexOfSmallestKey = -1;
  for(int index = 0; index < m_queueSize; index++){
    if(m_mainQueue[index] != nullptr){
      if(indexOfSmallestKey == -1 || m_mainQueue[index]->getKey() < m_mainQueue[indexOfSmallestKey]->getKey()){
        indexOfSmallestKey = index;
      }
    }
  }

  if(indexOfSmallestKey == -1){
    //This queue is empty. Nothing to delete.
    return false;
  }else if(indexOfSmallestKey == 0){ //it means there is only one element here
    BinomNode<T>* temp = m_mainQueue[indexOfSmallestKey];
    m_mainQueue[indexOfSmallestKey] = nullptr;
    delete temp;
    return true;
  }

  //testing - std::cout << indexOfSmallestKey;

  BinomNode<T>* minRoot = m_mainQueue[indexOfSmallestKey];
  BinomNode<T>* child = minRoot->getFirstChild();
  m_mainQueue[indexOfSmallestKey] = nullptr;

  BinomNode<T>** tempQueue = new BinomNode<T>*[m_queueSize];
  for(int index = 0; index < m_queueSize; index++){
    if(index >= indexOfSmallestKey){
      tempQueue[index] = nullptr;
    }else{
      tempQueue[index] = child;
      child = child->getRightSibling();
      tempQueue[index]->setRightSibling(nullptr);
      tempQueue[index]->setLeftSibling(tempQueue[index]);
    }
  }

  delete minRoot;
  m_mainQueue = mergeQueues(m_mainQueue, tempQueue);

  return true;
}

template <typename T>
void BinomQueue<T>::levelorder(){
  std::cout << "\nLevel order:" << std::endl;
  for(int index = 0; index < m_queueSize; index++){
    BinomNode<T>* tree = m_mainQueue[index];
    if(tree != nullptr){
      //print the Bx binomial tree number and call printTree
      std::cout << "-- B" << index << " ---" << std::endl;
      treeLevelOrder(tree);
      std::cout << "\n";
    }
  }
  std::cout << "-----";
}

template <typename T>
void BinomQueue<T>::treeLevelOrder(BinomNode<T>* root){
  Queue<BinomNode<T>*>* q1 = new Queue<BinomNode<T>*>();
  q1->enqueue(root);
  int currentOrder = root->getOrder()+1;
  while(!q1->isEmpty()){
    BinomNode<T>* popped = q1->dequeue();

    std::cout << popped->getKey() << " ";

    /*TESTING - "(fChild: "; //print
    if(popped->getFirstChild() == nullptr){
      std::cout << "nullptr, ";
    }else{
      std::cout << popped->getFirstChild()->getKey() << ", ";
    }
    std::cout << "rSib: ";
    if(popped->getRightSibling() == nullptr){
      std::cout << "nullptr, ";
    }else{
      std::cout << popped->getRightSibling()->getKey() << ", ";
    }
    std::cout << "lSib: ";
    if(popped->getLeftSibling() == nullptr){
      std::cout << "nullptr) ";
    }else{
      std::cout << popped->getLeftSibling()->getKey() << ") ";
    }*/

    if(popped->getOrder() == currentOrder-1){
      std::cout << "\n";
      currentOrder--;
    }
    if(popped->getRightSibling() != nullptr){
      q1->enqueue(popped->getRightSibling());
    }
    if(popped->getFirstChild() != nullptr){
      q1->enqueue(popped->getFirstChild());
    }
  }
}

template <typename T>
void BinomQueue<T>::insert(T value){
  BinomNode<T>** tempQueue = new BinomNode<T>*[m_queueSize];
  tempQueue[0] = new BinomNode<T>();
  tempQueue[0]->setKey(value);
  for(int i=1; i<m_queueSize; i++){
    tempQueue[i] = nullptr;
  }
  m_mainQueue = mergeQueues(m_mainQueue, tempQueue);
}

/* TESTING -
template <typename T>
void BinomQueue<T>::test(){
  //BinomNode<T>** tmpq1 = new BinomNode<T>*[m_queueSize];
  //BinomNode<T>** tmpq2 = new BinomNode<T>*[m_queueSize];

}*/

template <typename T>
BinomNode<T>** BinomQueue<T>::mergeQueues(BinomNode<T>** originalQueue, BinomNode<T>** tempQueue){
  //create a resultantQueue and a carryQueue
  BinomNode<T>** resultantQueue = new BinomNode<T>*[m_queueSize];
  BinomNode<T>** carryQueue = new BinomNode<T>*[m_queueSize];
  //set both queues to nullptrs
  for(int i=0; i < m_queueSize; i++){
    resultantQueue[i] = nullptr;
    carryQueue[i] = nullptr;
  }

  //iteratively merge all the trees in each queue
  for(int index = 0; index < m_queueSize; index++){
    BinomNode<T>* rootAtIndex = mergeTrees(originalQueue[index], tempQueue[index]);
    if(rootAtIndex == nullptr){
      //do nothing, because there's nothing to do
    }else if(rootAtIndex->getOrder() == index){
      if(resultantQueue[index] == nullptr){
        resultantQueue[index] = rootAtIndex;
      }else{
        carryQueue[index] = rootAtIndex;
      }
    }else{
      if(resultantQueue[index+1] == nullptr){
        resultantQueue[index+1] = rootAtIndex;
      }else{
        carryQueue[index+1] = rootAtIndex;
      }
    }
  }

  //check if the carryQueue is empty, because if it isn't, we'll need to recursively
  // merge carry and resultant queues
  bool isCarryQueueEmpty = true;
  for(int i=0; i < m_queueSize; i++){
    if(carryQueue[i] != nullptr){
      isCarryQueueEmpty = false;
      break; //exit the loop
    }
  }

  if(!isCarryQueueEmpty){
    resultantQueue = mergeQueues(resultantQueue, carryQueue);
  }

  /* TESTING:
  //erase memory leaks
  for(int i=0; i < m_queueSize; i++){
    if(carryQueue[i] != nullptr){
      delete carryQueue[i];
      carryQueue[i] = nullptr;
    }
  }
  delete[] carryQueue;*/

  //return the resultant queue;
  return resultantQueue;

}

template <typename T>
BinomNode<T>* BinomQueue<T>::mergeTrees(BinomNode<T>* root1, BinomNode<T>* root2){
  //if one of the roots is null, return the other
  if(root1 == nullptr){
    return root2;
  }else if(root2 == nullptr){
    return root1;
  }

  //if the key of the root1 is larger than the key of the root2, then swap 'em
  if(root1->getKey() > root2->getKey()){
    swapNodes(root1, root2);
  }

  //increase the order of root1, because that will become the root of the higher order tree
  root1->setOrder(root1->getOrder()+1);

  //check if root1 has no child
  if(root1->getFirstChild() == nullptr){
    //set root2 to be the first child
    root1->setFirstChild(root2);
    //we're done, so return
    return root1;
  }

  //if the root1 has a child, then go to the right-most sibling of that child
  BinomNode<T>* root1LastChild = root1->getFirstChild()->getLeftSibling();
  //perform operations to merge the queues
  root1LastChild->setRightSibling(root2);
  root2->setLeftSibling(root1LastChild);
  root1->getFirstChild()->setLeftSibling(root2);
  //we're done, return
  return root1;
}

template <typename T>
void BinomQueue<T>::swapNodes(BinomNode<T>* &node1, BinomNode<T>* &node2){
  BinomNode<T>* temp = node1;
  node1 = node2;
  node2 = temp;
}
