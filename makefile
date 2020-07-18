all: exe

exe: routing.cpp
	g++ routing.cpp -g -o exe
