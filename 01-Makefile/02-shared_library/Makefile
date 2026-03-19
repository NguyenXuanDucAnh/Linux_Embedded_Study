
createObjectFile:
#tao folder build
	mkdir -p build
# biên dịch các file .c .cpp của thư viện thành file object có đuôi .o:
	gcc -c src/mylibraryA.c -I . -o build/mylibA.o
	g++ -c src/mylibraryB.cpp -I . -o build/mylibB.o


createStaticLibrary: createObjectFile
	mkdir -p lib
	ar rcs lib/libmylibA.a build/mylibA.o
	ar rcs lib/libmylibB.a build/mylibB.o

linkerLibraryA: createObjectFile createStaticLibrary
	mkdir -p bin
	g++ main.cpp -o bin/run -Iinclude -Llib -l mylibA  

linkerLibraryB: createObjectFile createStaticLibrary
	mkdir -p bin
	g++ main.cpp -o bin/run -Iinclude -Llib -l mylibB  

clean:
	rm -rf bin build lib