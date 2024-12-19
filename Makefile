
all: main

main: main.cc window.hh fenster.h 
	g++ -g3 -o main main.cc -lX11 -lasound 

clean:
	rm -f main