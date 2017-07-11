lab8: main.o Timer.o
	g++ -std=c++11 -g main.o Timer.o -o lab8
	rm *.o

main.o: main.cpp Timer.h LeftistHeap.h LeftistHeap.hpp LeftistNode.h LeftistNode.hpp SkewHeap.h SkewHeap.hpp SkewNode.h SkewNode.hpp QueueNode.h QueueNode.hpp Queue.h Queue.hpp
	g++ -std=c++11 -g -c main.cpp

Timer.o: Timer.h Timer.cpp
	g++ -std=c++11 -g -c Timer.cpp

clean:
	rm lab8
	echo clean done
