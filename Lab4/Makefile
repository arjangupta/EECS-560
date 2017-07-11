lab4: main.o Timer.o
	g++ -g -std=c++11 main.o Timer.o -o lab4
main.o: main.cpp ClosedHash.h ClosedHash.hpp OpenHash.h OpenHash.hpp Node.h Node.hpp DoubleLinkedList.h DoubleLinkedList.hpp
	g++ -g -std=c++11 -c main.cpp
Timer.o: Timer.h Timer.cpp
	g++ -g -std=c++11 -c Timer.cpp
clean:
	rm *.o lab4
	clean done
