#ifndef _SORTS_H_
#define _SORTS_H_

#include "header.h"

#define MAX_SORTS 100

int debutSorts;
typedef struct sort_S {
	int id;
	char * nom;
	char * description;
	int degatsMin;
	int degatsMax;
	int relance; // Nombre de tours pour recharger le sort après l'avoir utilisé
	int relanceActuel; // 0 = il peut lancer le sort, relanceActuel passe a relanceMax et -- chaque tour
	int portee;
	int coutPA;
	int coutNitro;
	SDL_Surface * surface;
	SDL_Texture * texture;
	int id_lanceur;
} sort_T;

sort_T sorts[MAX_SORTS];

sort_T sortsEnnemi1[MAX_SORTS];
sort_T sortsEnnemi2[MAX_SORTS];
sort_T sortsEnnemi3[MAX_SORTS];
sort_T sortsEnnemi4[MAX_SORTS];
sort_T sortsEnnemi5[MAX_SORTS];
sort_T sortsEnnemi6[MAX_SORTS];
sort_T sortsEnnemi7[MAX_SORTS];
sort_T sortsEnnemi8[MAX_SORTS];
sort_T sortsEnnemi9[MAX_SORTS];
sort_T sortsEnnemi10[MAX_SORTS];

sort_T sortsBoss1[MAX_SORTS];
sort_T sortsBoss2[MAX_SORTS];
sort_T sortsBoss3[MAX_SORTS];
sort_T sortsBoss4[MAX_SORTS];
sort_T sortsBoss5[MAX_SORTS];

SDL_Rect liste_sorts[10];

SDL_Rect rect_prep_sort[plateau_x*plateau_y];

// Variables
int prepaSort; // NULL si aucun sort en cours - ID du sort si un sort en cours
int degats_inflige, degats_cible_x, degats_cible_y;
int temps_debut, temps_actuel, flag_temps;

// Déclarations des fonctions
void affichage_sorts(entite * joueur);
void affichage_infos_sort(sort_T s);
void init_sorts();
entite * rechercherEntite(int id);
int numero_aleatoire(int minimum, int maximum);
void afficher_degats(int degats, int cible_x, int cible_y);
void infliger_degats(int cible_x, int cible_y, sort_T * s);
void lancement_sort(entite * lanceur, int cible_x, int cible_y, sort_T * s);
void init_sort_surftext();
void free_sort_text();
void prep_sort_plus(entite * lanceur, int distance);
void prep_sort_cercle(entite * lanceur, int rayon);
void clic_sort(entite * lanceur, sort_T s);
void preparation_sort(entite * lanceur, sort_T s);

#endif // _SORTS_H_