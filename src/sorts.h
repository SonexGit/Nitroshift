#ifndef _SORTS_H_
#define _SORTS_H_

#include "header.h"

#define MAX_SORTS 100

typedef struct sort_S {
	int id;
	char * nom;
	char * description;
	int degats;
	int portee;
	int coutPA;
	int coutNitro;
	SDL_Surface * surface;
	SDL_Texture * texture;
	// Faire un pointeur sur fonction "lancement_sort(sort)" ?
} sort_T;

sort_T sorts[MAX_SORTS];

SDL_Rect liste_sorts[10];

// Déclarations des fonctions
void affichage_sorts();
void lancement_sort(entite * lanceur, int cible_x, int cible_y, sort_T s);
void init_sorts();

#endif // _SORTS_H_