#INCLUDE = \
#	../include/graph.h \
#	../include/ugraph.h \
#	../include/dgraph.h \
#	../include/search.h

all: test_static test_shared
	cd ../build_test

test_static:
	g++ test_static.cpp -L../lib -lgraph -std=c++11 -o $@
	mv ./test_static ../build_test

test_shared:
	g++ test_shared.cpp -L../lib -lgraph -std=c++11 -o $@
	mv ./test_shared ../build_test
	export LD_LIBRARY_PATH=../lib

update_source:
	cp ../src/main.cpp ./test_static.cpp
	cp ../src/main.cpp ./test_shared.cpp

clean:
	@rm ../build_test/test_shared ../build_test/test_static
