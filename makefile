ALL: main

main: ./build/main.o ./build/lu.o ./build/ldp.o ./build/metodo.o ./build/pivot.o ./build/view.o
	g++ ./build/main.o ./build/lu.o ./build/ldp.o ./build/metodo.o ./build/pivot.o ./build/view.o -o main

./build/main.o: main.cpp
	g++ -c main.cpp -o ./build/main.o

./build/metodo.o:./lib/metodo.cpp
	g++ -c ./lib/metodo.cpp -o ./build/metodo.o

./build/pivot.o:./lib/pivot.cpp
	g++ -c ./lib/pivot.cpp -o ./build/pivot.o

./build/lu.o: ./lib/lu.cpp
	g++ -c ./lib/lu.cpp -o ./build/lu.o

./build/ldp.o: ./lib/ldp.cpp
	g++ -c ./lib/ldp.cpp -o ./build/ldp.o

./build/view.o: ./lib/view.cpp
	g++ -c ./lib/view.cpp -o ./build/view.o
