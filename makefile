tetris: tetris.o graphics.o
	g++ -g -o tetris tetris.o graphics.o `sdl2-config --libs`

tetris.o: tetris.cpp
	g++ -g `sdl2-config --cflags` -c tetris.cpp

graphics.o: graphics.cpp graphics.h
	g++ -g `sdl2-config --cflags` -c graphics.cpp

