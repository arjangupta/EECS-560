lab9: main.o
	g++ -std=c++11 -g main.o -o lab9
	rm *.o

main.o: main.cpp Queue.h Queue.hpp QueueNode.h QueueNode.hpp BinomNode.h BinomNode.hpp BinomQueue.h BinomQueue.hpp	
	g++ -std=c++11 -g -c main.cpp

clean:
	rm lab9
	echo clean done
