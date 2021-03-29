#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sorts.h"
#include "entite.h"
#include "render.h"

sort_T sorts[MAX_SORTS] = {
	{0, "Téléportation", "Test", 0, 10, 0, 0, NULL, NULL}
};

void affichage_sorts() {
	char * repertoire = malloc(sizeof(char) * 16);
	char * id_sort = malloc(sizeof(char) * 2);
	for (int i = 0; i < 1; i++) {
		strcpy(repertoire, "../data/sorts/");
		snprintf(id_sort, 2, "%d", sorts[i].id);
		strcat(repertoire, id_sort);
		strcat(repertoire, ".png");
		sorts[i].surface = IMG_Load(repertoire);
		sorts[i].texture = SDL_CreateTextureFromSurface(ren, sorts[i].surface);

		liste_sorts[i].x = 1000;
		liste_sorts[i].y = 750;
		liste_sorts[i].h = 40;
		liste_sorts[i].w = 40;
		SDL_RenderCopy(ren, sorts[i].texture, NULL, &liste_sorts[i]);
	}
	free(repertoire);
	free(id_sort);
}

void lancement_sort(entite * lanceur, int cible_x, int cible_y, sort_T s) {
	switch (s.id) {
		case 0: // Téléportation • Sort 0
			lanceur->positionX = cible_x;
			lanceur->positionY = cible_y;
			break;
	}
}