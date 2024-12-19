
all: main

main: main.cc fenster.h game.hh
	g++ -g3 -o main main.cc -lX11 -lasound 

clean:
	rm -f main