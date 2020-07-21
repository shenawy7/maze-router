How to use:

	The user must input the size of the grid and the number of layers along side an input file that is called input.txt in the same directory of the project that  will specify the nets and their pins and their corresponding layers and coordinates as shown in the example in the handout
	
	In order to build the program, you must copy and paste all "cpp" files into 1 file (includes first then global variables (all found in main.cpp) then functions in the given order: process, filling, backtracing, route_net, main)and then compile with g++ (there is a makefile with the assumption that this 1 file is called routing.cpp (you could change routing.cpp to be the name you assigned to this 1 file) so you could just type "make all" on the terminal in the directory and it will work)

	In order to run the program, just type in the terminal "./exe" (assuming that the user compiled using the makefile; if the user chose another file name then just type "./file_name")

Limitations:

	The program will not work if it found a pin that has the same exact coordinates of a metal from a previous routing step


CSCE3304
AUC
DR.Mohamed Shalan
