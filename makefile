tetris: tetris.o graphics.o
	g++ -g -o tetris -L/usr/local/lib/ -lSDL tetris.o graphics.o

tetris.o: tetris.cpp
	g++ -g `sdl-config --cflags` -c tetris.cpp

graphics.o: graphics.cpp graphics.h
	g++ -g `sdl-config --cflags` -c graphics.cpp

