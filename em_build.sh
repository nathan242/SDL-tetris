#!/bin/bash

em++ -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS=["png"] -s ASYNCIFY tetris.cpp graphics.cpp -o tetris.html --preload-file textures
