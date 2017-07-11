lab6: main.o Timer.o
	g++ -g -std=c++11 main.o Timer.o -o lab6
main.o: main.cpp MinHeap.h MinHeap.hpp Queue.h Queue.hpp BST.h BST.hpp BSTNode.h BSTNode.hpp
	g++ -g -std=c++11 -c main.cpp
Timer.o: Timer.h Timer.cpp
	g++ -g -std=c++11 -c Timer.cpp
clean:
	rm *.o lab6
