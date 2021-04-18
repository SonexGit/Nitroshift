CFLAGS=-W -Wall -pedantic

all:render.o entite.o initialisation.o combat.o sorts.o main.o menujeu.o mesmodif.o pile.o shifumi.o apropos.o shop.o perdu.o amelioration.o gagnant.o niveau.o niveau.o zone.o saveok.o nitroshift

render.o: ./src/render.c ./src/render.h
	gcc ${CFLAGS} -c ./src/render.c -o ./src/render.o -m32 -L./lib -I./include

entite.o: ./src/entite.c ./src/entite.h
	gcc ${CFLAGS} -c ./src/entite.c -o ./src/entite.o -m32 -L./lib -I./include

initialisation.o: ./src/initialisation.c ./src/initialisation.h
	gcc ${CFLAGS} -c ./src/initialisation.c -o ./src/initialisation.o -m32 -L./lib -I./include

combat.o: ./src/combat.c ./src/combat.h
	gcc ${CFLAGS} -c ./src/combat.c -o ./src/combat.o -m32 -L./lib -I./include

sorts.o: ./src/sorts.c ./src/sorts.h
	gcc ${CFLAGS} -c ./src/sorts.c -o ./src/sorts.o -m32 -L./lib -I./include

main.o: ./src/main.c ./src/header.h
	gcc ${CFLAGS} -c ./src/main.c -o ./src/main.o -m32 -L./lib -I./include

menujeu.o: ./src/menujeu.c ./src/menujeu.h
	gcc ${CFLAGS} -c ./src/menujeu.c -o ./src/menujeu.o -m32 -L./lib -I./include

mesmodif.o: ./src/mesmodif.c	./src/mesmodif.h
	gcc ${CFLAGS} -c ./src/mesmodif.c -o ./src/mesmodif.o -m32 -L./lib -I./include

pile.o: ./src/pile.c ./src/pile.h
	gcc ${CFLAGS} -c ./src/pile.c -o ./src/pile.o -m32 -L./lib -I./include

shifumi.o: ./src/shifumi.c ./src/shifumi.h
	gcc ${CFLAGS} -c ./src/shifumi.c -o ./src/shifumi.o -m32 -L./lib -I./include

apropos.o: ./src/apropos.c ./src/apropos.h
	gcc ${CFLAGS} -c ./src/apropos.c -o ./src/apropos.o -m32 -L./lib -I./include

shop.o: ./src/shop.c ./src/shop.h
	gcc ${CFLAGS} -c ./src/shop.c -o ./src/shop.o -m32 -L./lib -I./include

amelioration.o: ./src/amelioration.c ./src/amelioration.h
	gcc ${CFLAGS} -c ./src/amelioration.c -o ./src/amelioration.o -m32 -L./lib -I./include

perdu.o: ./src/perdu.c ./src/perdu.h
	gcc ${CFLAGS} -c ./src/perdu.c -o ./src/perdu.o -m32 -L./lib -I./include

gagnant.o: ./src/gagnant.c ./src/gagnant.h
	gcc ${CFLAGS} -c ./src/gagnant.c -o ./src/gagnant.o -m32 -L./lib -I./include

niveau.o: ./src/niveau.c ./src/niveau.h
	gcc ${CFLAGS} -c ./src/niveau.c -o ./src/niveau.o -m32 -L./lib -I./include

zone.o: ./src/zone.c ./src/zone.h
	gcc ${CFLAGS} -c ./src/zone.c -o ./src/zone.o -m32 -L./lib -I./include

saveok.o: ./src/saveok.c ./src/saveok.h
	gcc ${CFLAGS} -c ./src/saveok.c -o ./src/saveok.o -m32 -L./lib -I./include


nitroshift: ./src/main.o ./src/render.o ./src/entite.o ./src/initialisation.o ./src/combat.o ./src/sorts.o ./src/amelioration.o ./src/shop.o ./src/shifumi.o ./src/pile.o ./src/mesmodif.o ./src/menujeu.o ./src/perdu.o ./src/gagnant.o ./src/niveau.o ./src/zone.o ./src/saveok.o
	gcc ${CFLAGS} ./src/main.o ./src/render.o ./src/entite.o ./src/initialisation.o ./src/combat.o ./src/sorts.o ./src/amelioration.o ./src/shop.o ./src/apropos.o ./src/shifumi.o ./src/pile.o ./src/mesmodif.o ./src/menujeu.o ./src/perdu.o ./src/gagnant.o ./src/niveau.o ./src/zone.o ./src/saveok.o -o ./src/nitroshift -m32 -L./lib -I./include -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
