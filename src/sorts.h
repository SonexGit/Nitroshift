#ifndef _SORTS_H_
#define _SORTS_H_

#include "header.h"

#define MAX_SORTS 100

typedef struct sort_S {
	int id;
	char * nom;
	char * description;
	int degatsMin;
	int degatsMax;
	int portee;
	int coutPA;
	int coutNitro;
	SDL_Surface * surface;
	SDL_Texture * texture;
	int id_lanceur;
	// Faire un pointeur sur fonction "lancement_sort(sort)" ?
} sort_T;

sort_T sorts[MAX_SORTS];

SDL_Rect liste_sorts[10];

SDL_Rect rect_prep_sort[plateau_x*plateau_y];

// NULL si aucun sort en cours - ID du sort si un sort en cours
int prepaSort;

// Déclarations des fonctions
void affichage_sorts();
void init_sorts();
void lancement_sort(entite * lanceur, int cible_x, int cible_y, sort_T s);
void prep_sort_cercle(entite * lanceur, sort_T s, int rayon, cell_T * plat[]);
void clic_sort(entite * lanceur, sort_T s);
void preparation_sort(entite * lanceur, sort_T s);

#endif // _SORTS_H_