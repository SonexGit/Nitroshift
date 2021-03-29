CFLAGS=-W -Wall -pedantic

all:render.o entite.o initialisation.o combat.o sort.o main.o nitroshift

render.o: ./src/render.c ./src/render.h
	gcc ${CFLAGS} -c ./src/render.c -o ./src/render.o -m32 -L./lib -I./include

entite.o: ./src/entite.c ./src/entite.h
	gcc ${CFLAGS} -c ./src/entite.c -o ./src/entite.o -m32 -L./lib -I./include

initialisation.o: ./src/initialisation.c ./src/initialisation.h
	gcc ${CFLAGS} -c ./src/initialisation.c -o ./src/initialisation.o -m32 -L./lib -I./include

combat.o: ./src/combat.c ./src/combat.h
	gcc ${CFLAGS} -c ./src/combat.c -o ./src/combat.o -m32 -L./lib -I./include

sort.o: ./src/sort.c ./src/sort.h
	gcc ${CFLAGS} -c ./src/sort.c -o ./src/sort.o -m32 -L./lib -I./include

main.o: ./src/main.c ./src/header.h
	gcc ${CFLAGS} -c ./src/main.c -o ./src/main.o -m32 -L./lib -I./include

nitroshift: ./src/main.o ./src/render.o ./src/entite.o ./src/initialisation.o ./src/combat.o
	gcc ${CFLAGS} ./src/main.o ./src/render.o ./src/entite.o ./src/initialisation.o ./src/combat.o ./src/sort.o -o ./src/nitroshift -m32 -L./lib -I./include -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer
