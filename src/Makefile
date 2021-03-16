CFLAGS=-W -Wall -pedantic

all:render.o main.o nitroshift

render.o: ./src/render.c ./src/render.h
	gcc ${CFLAGS} -c ./src/render.c -o ./src/render.o -m32 -L./lib -I./include

main.o: ./src/main.c ./src/header.h
	gcc ${CFLAGS} -c ./src/main.c -o ./src/main.o -m32 -L./lib -I./include

nitroshift: ./src/main.o ./src/render.o
	gcc ${CFLAGS} ./src/main.o ./src/render.o -o ./src/nitroshift -m32 -L./lib -I./include -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer