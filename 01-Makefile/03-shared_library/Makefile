createObjectFile:
	mkdir -p build
	gcc -c -fPIC src/mylibraryA.c -I . -o build/mylibA.o
	g++ -c -fPIC src/mylibraryB.cpp -I . -o build/mylibB.o

createSharedLib:
	mkdir -p lib
	gcc -shared -o lib/libmylibA.so build/mylibA.o
	g++ -shared -o lib/libmylibB.so build/mylibB.o

linkerLibraryA: createObjectFile createSharedLib
	mkdir -p bin 
	g++ main.cpp -o bin/run -I . -Llib -lmylibA

linkerLibraryB: createObjectFile createSharedLib
	mkdir -p bin 
	g++ main.cpp -o bin/run -I . -Llib -lmylibB

clean:
	rm -rf bin build lib