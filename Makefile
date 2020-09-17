.PHONY:
	clear format all run

all: make_dir bin/main format

make_dir:
	mkdir -p obj
	mkdir -p bin

bin/main: obj/main.o obj/prog.o
	g++ -Wall -Werror obj/main.o obj/prog.o -o bin/main

obj/main.o: src/main.cpp include/prog.h
	g++ -Wall -Werror -I src -c src/main.cpp -o obj/main.o

obj/prog.o: src/prog.cpp
	g++ -Wall -Werror -I src -c src/prog.cpp -o obj/prog.o

format: src/prog.cpp include/prog.h src/main.cpp
	clang-format -i src/main.cpp src/prog.cpp include/prog.h

clear:
	rm -rf bin/main  obj/prog.o obj/main.o
	rmdir obj bin

run:
	./bin/main