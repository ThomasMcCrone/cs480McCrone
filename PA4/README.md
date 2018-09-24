Thomas McCrone
CS480
9:00-9:50 MWF
PA4

Dependencies
	
	For both of the operating systems to run this project installation of these three programs are required [GLEW](http://glew.sourceforge.net/), [GLM](http://glm.g-truc.net/0.9.7/index.html), and [SDL2](https://wiki.libsdl.org/Tutorials).

	This project uses OpenGL 3.3. Some computers, such as virtual machines in the ECC, can not run this version. In in order to run OpenGL 2.7 follow the instructions at [Using OpenGL 2.7](https://github.com/HPC-Vis/computer-graphics/wiki/Using-OpenGL-2.7)

Build
	MAKEFILE
	
	```bash
	
	mkdir build
	
	cd build

	cmake ..

	make

	./Tutorial

	```

Instructions
	
	Before running program, place file to be used in build directory within project directory
	
	Upon file start, the program will ask in the command prompt for the name of the file, when prompted, enter the full file name ex>>> dragon.obj

	

Blender

	the board made via blender is within the project directory, next to the README.md


EXTRA CREDIT

	the board.obj also has a board.mat attached, this is from adding materials to the board in blender