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
#include "combat.h"

// sort : id, nom, description, degatsMin, degatsMax, relanceMax, relanceActuel, portee, coutPA, coutNitro, surface, texture, id_lanceur
sort_T sorts[MAX_SORTS] = {
	{0, "Attaque de base", "Test", 25, 40, 1, 0, 1, 2, 0, NULL, NULL, 1},
	{1, "Tir rapide", "Tirez une salve avec votre arme", 100, 125, 2, 0, 4, 1, 3, NULL, NULL, 1},
	{2, "Téléportation", "Téléportez vous sur la case ciblée", 0, 0, 5, 0, 5, 0, 5, NULL, NULL, 1},
	{3, "Boost PM", "Test", 0, 0, 4, 0, 0, 0, 0, NULL, NULL}
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

void reset_castable() {
	for (int i = 0; i < plateau_y; i++) {
		for (int j = 0; j < plateau_x; j++) {
			plateau[i][j].castable = 0;
		}
	}
}

void sort_relance_fintour() {
	for (int i = 0; i < MAX_SORTS; i++) {
		if (sorts[i].relanceActuel > 0) {
			sorts[i].relanceActuel--;
		}
	}
}

int numero_aleatoire(int minimum, int maximum) {
	srand(time(NULL));
	int nombre = (rand() % (maximum - minimum + 1)) + minimum;
	return nombre;
}

void infliger_degats(entite * lanceur, int cible_x, int cible_y, sort_T * s) {
	int degats = numero_aleatoire(s->degatsMin, s->degatsMax);

	if (plateau[cible_y][cible_x].e.id != 0) {
		printf("\nJE FAIS DES DEGATS !! : %i\n", degats);
		printf("\nVOICI LA VIE DE L'ENNEMI AVANT : %i\n", plateau[cible_y][cible_x].e.hp);
		plateau[cible_y][cible_x].e.hp -= degats;
		printf("\nVOICI LA VIE DE L'ENNEMI APRES : %i\n", plateau[cible_y][cible_x].e.hp);
		if(plateau[cible_y][cible_x].e.hp <= 0){
			plateau[cible_y][cible_x].e.mort = 1;
		}
	}
}

void lancement_sort(entite * lanceur, int cible_x, int cible_y, sort_T * s) {
	switch (s->id) {
		case 0: // Attaque de base • Sort 0
			infliger_degats(lanceur, cible_x, cible_y, s);
			break;
		case 1: // Tir rapide • Sort 1
			infliger_degats(lanceur, cible_x, cible_y, s);
			break;
		case 2: // Téléportation • Sort 2
			lanceur->positionX = cible_x;
			lanceur->positionY = cible_y;
			break;
	}

	prepaSort = -1; // On arrête la préparation du sort pour la suite

	s->relanceActuel = s->relance;
	if (lanceur->pa - s->coutPA > 0) lanceur->pa -= s->coutPA;
	else lanceur->pa = 0;
	if (lanceur->nitro - s->coutNitro > 0) lanceur->nitro -= s->coutNitro;
	else lanceur->nitro = 0;

	reset_castable();
}

void clic_sort(entite * lanceur, sort_T s) {
	printf("\n PA LANCEUR : %i \n NITRO LANCEUR : %i", lanceur->pa, lanceur->nitro);
	printf("\nRELANCE ACTUEL : %i\n", s.relanceActuel);
	if (s.relanceActuel == 0 && lanceur->pa >= s.coutPA && lanceur->nitro >= s.coutNitro) {
		prepaSort = s.id;
	}
	else {
		printf("Le sort est en charge...\n");
	}
}

void init_sort_surftext() {
	for (int i = 0; i < plateau_y; i++) {
		for (int j = 0; j < plateau_x; j++) {
			plateau[i][j].sort_surface = IMG_Load("../data/tiles/cast_able.png");
			plateau[i][j].sort_texture = SDL_CreateTextureFromSurface(ren, plateau[i][j].sort_surface);

			SDL_FreeSurface(plateau[i][j].sort_surface);
		}
	}
}

void free_sort_text() {
	for (int i = 0; i < plateau_y; i++) {
		for (int j = 0; j < plateau_x; j++) {
			SDL_DestroyTexture(plateau[i][j].sort_texture);
		}
	}
}

void prep_sort_plus(entite * lanceur, sort_T s, int distance, cell_T plat[plateau_y][plateau_x]) {

	int compteur = 0;

	for (int i = 0 - distance; i <= distance; i++) {
		if (i == 0) i++;
		int og_y = lanceur->positionY + i;
		int og_x = lanceur->positionX;

		plateau[og_y][og_x].sort_surface = IMG_Load("../data/tiles/cast_able.png");
		plateau[og_y][og_x].sort_texture = SDL_CreateTextureFromSurface(ren, plateau[og_y][og_x].sort_surface);

		plateau[og_y][og_x].castable = 1;

		rect_prep_sort[compteur].x = plateau[og_y][og_x].pc.x - (grid_cell_size_iso_x/2);
		rect_prep_sort[compteur].y = plateau[og_y][og_x].pc.y - (grid_cell_size_iso_y/2);
		rect_prep_sort[compteur].w = grid_cell_size_iso_x;
		rect_prep_sort[compteur].h = grid_cell_size_iso_y;

		SDL_RenderCopy(ren, plateau[og_y][og_x].sort_texture, NULL, &rect_prep_sort[compteur]);
		SDL_FreeSurface(plateau[og_y][og_x].sort_surface);

		compteur++;
	}
	for (int j = 0 - distance; j <= distance; j++) {
		if (j == 0) j++;
		int og_y = lanceur->positionY;
		int og_x = lanceur->positionX + j;

		plateau[og_y][og_x].sort_surface = IMG_Load("../data/tiles/cast_able.png");
		plateau[og_y][og_x].sort_texture = SDL_CreateTextureFromSurface(ren, plateau[og_y][og_x].sort_surface);
		
		plateau[og_y][og_x].castable = 1;

		rect_prep_sort[compteur].x = plateau[og_y][og_x].pc.x - (grid_cell_size_iso_x/2);
		rect_prep_sort[compteur].y = plateau[og_y][og_x].pc.y - (grid_cell_size_iso_y/2);
		rect_prep_sort[compteur].w = grid_cell_size_iso_x;
		rect_prep_sort[compteur].h = grid_cell_size_iso_y;
		
		SDL_RenderCopy(ren, plateau[og_y][og_x].sort_texture, NULL, &rect_prep_sort[compteur]);
		SDL_FreeSurface(plateau[og_y][og_x].sort_surface);

		compteur++;
	}
}

void prep_sort_cercle(entite * lanceur, sort_T s, int rayon, cell_T plat[plateau_y][plateau_x]) {
    int i,j;
	int compteur = 0;


    for (i=0; i<=2*rayon; i++)
    {
        for (j=0; j<=2*rayon; j++)
        {
            double distance = sqrt((double)(i-rayon)*(i-rayon) + (j-rayon)*(j-rayon));
			int og_y = lanceur->positionY-rayon+i;
			int og_x = lanceur->positionX-rayon+j;
			// printf("OG_Y : %i\nOG_X : %i", og_y, og_x);
            if (distance>rayon-0.5 && distance<rayon+0.5 && og_y < plateau_y && og_x < plateau_x && (plateau[og_y][og_x].solide == 0 || plateau[og_y][og_x].e.id != 0)) {
                plateau[og_y][og_x].sort_surface = IMG_Load("../data/tiles/cast_able.png");
				plateau[og_y][og_x].sort_texture = SDL_CreateTextureFromSurface(ren, plateau[og_y][og_x].sort_surface);

				plateau[og_y][og_x].castable = 1;

				rect_prep_sort[compteur].x = plateau[og_y][og_x].pc.x - (grid_cell_size_iso_x/2);
				rect_prep_sort[compteur].y = plateau[og_y][og_x].pc.y - (grid_cell_size_iso_y/2);
				rect_prep_sort[compteur].w = grid_cell_size_iso_x;
				rect_prep_sort[compteur].h = grid_cell_size_iso_y;

				SDL_RenderCopy(ren, plateau[og_y][og_x].sort_texture, NULL, &rect_prep_sort[compteur]);
				SDL_FreeSurface(plateau[og_y][og_x].sort_surface);
				// printf("x");
			}
			else if (distance == 0) {
				// printf("o");
			}
			else if (distance < rayon && og_y < plateau_y && og_x < plateau_x && (plateau[og_y][og_x].solide == 0 || plateau[og_y][og_x].e.id != 0)) {
				plateau[og_y][og_x].sort_surface = IMG_Load("../data/tiles/cast_able.png");
				plateau[og_y][og_x].sort_texture = SDL_CreateTextureFromSurface(ren, plateau[og_y][og_x].sort_surface);

				plateau[og_y][og_x].castable = 1;

				rect_prep_sort[compteur].x = plateau[og_y][og_x].pc.x - (grid_cell_size_iso_x/2);
				rect_prep_sort[compteur].y = plateau[og_y][og_x].pc.y - (grid_cell_size_iso_y/2);
				rect_prep_sort[compteur].w = grid_cell_size_iso_x;
				rect_prep_sort[compteur].h = grid_cell_size_iso_y;

				SDL_RenderCopy(ren, plateau[og_y][og_x].sort_texture, NULL, &rect_prep_sort[compteur]);
				SDL_FreeSurface(plateau[og_y][og_x].sort_surface);
				// printf("x");
			}
            else
            	// printf(" "); // Extérieur du cercle
			
			compteur++;
        }
        // printf("\n");
    }
	// Free des textures (a mettre dans une autre fonction plus tard ! pour l'instant ce n'est pas grave il ne gêne absolument rien)
	/*
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
        // printf("\n");
    }
	*/
}

void preparation_sort(entite * lanceur, sort_T s) {
	SDL_Surface * surface_prep_sort = IMG_Load("../data/tiles/cast_able.png");
	SDL_Texture * texture_prep_sort = SDL_CreateTextureFromSurface(ren, surface_prep_sort);

	switch (s.id) {
		case 0:
			prep_sort_plus(lanceur, s, 1, plateau);
			break;
		case 1:
			prep_sort_plus(lanceur, s, 3, plateau);
			break;
		case 2:
			prep_sort_cercle(lanceur, s, 3, plateau);
			break;
	}
	SDL_FreeSurface(surface_prep_sort);
	SDL_DestroyTexture(texture_prep_sort);
}