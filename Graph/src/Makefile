all: static shared
	cp *.h ../include

static: dgraph.h ugraph.h graph.h search.h
	g++ -c dgraph.cpp ugraph.cpp graph.cpp search.cpp -std=c++11 -Wall
	ar -cru libgraph.a dgraph.o ugraph.o graph.o search.o
	mv ./libgraph.a ../lib
	rm ./*.o

shared: dgraph.h ugraph.h graph.h search.h
	g++ -fPIC -c dgraph.cpp ugraph.cpp graph.cpp search.cpp -std=c++11
	g++ -shared dgraph.o ugraph.o graph.o search.o -o libgraph.so
	mv ./libgraph.so ../lib
	rm ./*.o

clean:
	rm ./*.o ./*.so ./*.a
