all:render.o main.o nitroshift

render.o: ./src/render.c ./src/render.h
	gcc -c ./src/render.c -o ./src/render.o -m32 -L./lib -I./include -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer

main.o: ./src/main.c ./src/header.h
	gcc -c ./src/main.c -o ./src/main.o -m32 -L./lib -I./include -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer

nitroshift: ./src/main.o ./src/render.o
	gcc ./src/main.o ./src/render.o -o ./src/nitroshift -m32 -L./lib -I./include -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer