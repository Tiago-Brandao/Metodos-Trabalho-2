ALL: main

main: ./build/main.o ./build/lu.o ./build/metodo.o
	g++ ./build/main.o ./build/lu.o ./build/metodo.o -o main

./build/main.o: main.cpp
	g++ -c main.cpp -o ./build/main.o

./build/metodo.o:./lib/metodo.cpp
	g++ -c ./lib/metodo.cpp -o ./build/metodo.o

./build/lu.o: ./lib/lu.cpp
	g++ -c ./lib/lu.cpp -o ./build/lu.o