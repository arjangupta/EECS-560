lab8: main.o
	g++ -std=c++11 -g main.o -o lab8

main.o: main.cpp LeftistHeap.h LeftistHeap.hpp LeftistNode.h LeftistNode.hpp QueueNode.h QueueNode.hpp Queue.h Queue.hpp
	g++ -std=c++11 -g -c main.cpp

clean:
	rm lab8
	rm *.o
	echo clean done
