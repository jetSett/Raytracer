all: main.cpp
	g++ -Wall -I/usr/include/python2.7 main.cpp -lpython2.7 -o main

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf main
