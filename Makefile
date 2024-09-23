
all: main

main: main.cc fenster.h
	g++ main.cc -lX11 -lasound -o main -O3

clean:
	rm -f main