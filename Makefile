all: main.o Complex.o FFT.o
	g++ -g main.o Complex.o FFT.o -o program

main.o:	main.cpp
	g++ -g -c main.cpp

Complex.o: Complex.cpp
	g++ -g -c Complex.cpp

FFT.o:	FFT.cpp
	g++ -g -c FFT.cpp

clean: 
	rm -f *.o program
