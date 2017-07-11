lab8: main.o
	g++ -std=c++11 -g main.o -o lab8
	rm *.o

main.o: main.cpp SkewHeap.h SkewHeap.hpp SkewNode.h SkewNode.hpp QueueNode.h QueueNode.hpp Queue.h Queue.hpp
	g++ -std=c++11 -g -c main.cpp

clean:
	rm lab8
	echo clean done
