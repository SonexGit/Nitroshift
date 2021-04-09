#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "sorts.h"
#include "entite.h"
#include "render.h"

sort_T sorts[MAX_SORTS] = {
	{0, "Attaque de base", "Test", 25, 40, 1, 1, 2, 0, NULL, NULL, 1},
	{1, "Tir rapide", "Tirez une salve avec votre arme", 100, 125, 2, 4, 1, 3, NULL, NULL, 1},
	{2, "Téléportation", "Test", 0, 0, 5, 5, 0, 5, NULL, NULL, 1},
	{3, "Boost PM", "Test", 0, 0, 4, 0, 0, 0, NULL, NULL}
};

void affichage_sorts() {
	char * repertoire = malloc(sizeof(char) * 16);
	char * id_sort = malloc(sizeof(char) * 2);
	for (int i = 0; i < 3; i++) {
		strcpy(repertoire, "../data/sorts/");
		snprintf(id_sort, 2, "%d", sorts[i].id);
		strcat(repertoire, id_sort);
		strcat(repertoire, ".png");
		if (sorts[i].id_lanceur == 1) {
			sorts[i].surface = IMG_Load(repertoire);
			sorts[i].texture = SDL_CreateTextureFromSurface(ren, sorts[i].surface);

			liste_sorts[i].x = 1000 + (i * 50);
			liste_sorts[i].y = 750;
			liste_sorts[i].h = 40;
			liste_sorts[i].w = 40;
			SDL_RenderCopy(ren, sorts[i].texture, NULL, &liste_sorts[i]);
			SDL_FreeSurface(sorts[i].surface);
		}
	}
	free(repertoire);
	free(id_sort);
}

void lancement_sort(entite * lanceur, int cible_x, int cible_y, sort_T s) {
	switch (s.id) {
		case 0: // Attaque de base • Sort 0
			printf("\nAttaque de base!\n");
			break;
		case 2: // Téléportation • Sort 2
			lanceur->positionX = cible_x;
			lanceur->positionY = cible_y;
			break;
	}
}

void clic_sort(entite * lanceur, sort_T s) {
	prepaSort = s.id;
}

void prep_sort_cercle(entite * lanceur, sort_T s, int rayon, cell_T * plat[]) {
    int i,j;
	int compteur = 0;

	// printf("TESTETSTEST\npc x, y : %i, %i\n", plat[0][0].pc.x, plat[0][0].pc.y);
    for (i=0; i<=2*rayon; i++)
    {
        for (j=0; j<=2*rayon; j++)
        {
            double distance = sqrt((double)(i-rayon)*(i-rayon) + (j-rayon)*(j-rayon));
			int og_y = lanceur->positionY-rayon+i;
			int og_x = lanceur->positionX-rayon+j;
			// printf("OG_Y : %i\nOG_X : %i", og_y, og_x);
            if (distance>rayon-0.5 && distance<rayon+0.5 && og_y < plateau_y && og_x < plateau_x) {
                plateau[og_y][og_x].sort_surface = IMG_Load("../data/tiles/cast_able.png");
				plateau[og_y][og_x].sort_texture = SDL_CreateTextureFromSurface(ren, plateau[og_y][og_x].sort_surface);
				rect_prep_sort[compteur].x = plateau[og_y][og_x].pc.x - (grid_cell_size_iso_x/2);
				rect_prep_sort[compteur].y = plateau[og_y][og_x].pc.y - (grid_cell_size_iso_y/2);
				rect_prep_sort[compteur].w = grid_cell_size_iso_x;
				rect_prep_sort[compteur].h = grid_cell_size_iso_y;
				SDL_RenderCopy(ren, plateau[og_y][og_x].sort_texture, NULL, &rect_prep_sort[compteur]);
				SDL_FreeSurface(plateau[og_y][og_x].sort_surface);
				printf("x");
			}
			else if (distance == 0) {
				printf("o");
			}
			else if (distance < rayon && og_y < plateau_y && og_x < plateau_x) {
				plateau[og_y][og_x].sort_surface = IMG_Load("../data/tiles/cast_able.png");
				plateau[og_y][og_x].sort_texture = SDL_CreateTextureFromSurface(ren, plateau[og_y][og_x].sort_surface);
				rect_prep_sort[compteur].x = plateau[og_y][og_x].pc.x - (grid_cell_size_iso_x/2);
				rect_prep_sort[compteur].y = plateau[og_y][og_x].pc.y - (grid_cell_size_iso_y/2);
				rect_prep_sort[compteur].w = grid_cell_size_iso_x;
				rect_prep_sort[compteur].h = grid_cell_size_iso_y;
				SDL_RenderCopy(ren, plateau[og_y][og_x].sort_texture, NULL, &rect_prep_sort[compteur]);
				SDL_FreeSurface(plateau[og_y][og_x].sort_surface);
				printf("x");
			}
            else
            	printf(" "); // Extérieur du cercle
			
			compteur++;
        }
        printf("\n");
    }
	// Free des textures
    for (i=0; i<=2*rayon; i++)
    {
        for (j=0; j<=2*rayon; j++)
        {
            double distance = sqrt((double)(i-rayon)*(i-rayon) + (j-rayon)*(j-rayon));
			int og_y = lanceur->positionY-rayon+i;
			int og_x = lanceur->positionX-rayon+j;
			// printf("OG_Y : %i\nOG_X : %i", og_y, og_x);
            if (distance>rayon-0.5 && distance<rayon+0.5 && og_y < plateau_y && og_x < plateau_x) {
                SDL_DestroyTexture(plateau[og_y][og_x].sort_texture);
			}
			else if (distance == 0);
			else if (distance < rayon && og_y < plateau_y && og_x < plateau_x) {
				SDL_DestroyTexture(plateau[og_y][og_x].sort_texture);
			}
            else;
			compteur++;
        }
        printf("\n");
    }
}

void preparation_sort(entite * lanceur, sort_T s) {
	SDL_Surface * surface_prep_sort = IMG_Load("../data/tiles/cast_able.png");
	SDL_Texture * texture_prep_sort = SDL_CreateTextureFromSurface(ren, surface_prep_sort);

	switch (s.id) {
		case 0:
			lancement_sort(lanceur, 1, 1, sorts[0]);
			break;
		case 2:
			prep_sort_cercle(lanceur, s, 3, plateau);
			break;
	}
	SDL_FreeSurface(surface_prep_sort);
	SDL_DestroyTexture(texture_prep_sort);
}