lab12: main.o
	g++ -std=c++11 -g main.o -o lab12
	rm *.o

main.o: main.cpp DijkstraAlg.h DijkstraAlg.hpp
	g++ -std=c++11 -g -c main.cpp

clean:
	rm lab12
	echo clean done
