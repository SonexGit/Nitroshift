#ifndef _HEADER_H_
#define _HEADER_H_

#include <SDL2/SDL_ttf.h>

// Taille du plateau
#define plateau_x 15
#define plateau_y 15

// Tiles.png (l'atlas des textures des cases du plateau)
#define tiles_row 21 // Combien de textures par ligne ?
#define tiles_col 1 // Combien de textures par colonne ?

// Taille d'une cellule
#define grid_cell_size_iso_x 80 // à modifier, pas "dynamique", +30 en x par point suivant
#define grid_cell_size_iso_y 40 // à modifier, pas "dynamique", +15 en y par point suivant

typedef struct entite_S {
	int id;
	int etiquetteClasse;
	char * nom;
	char * classe;
	int niveau;
	int hp;
	int hpMax;
	int nitro;
	int nitroMax;
	int pa;
	int paMax;
	int pm;
	int pmMax;
	int attaque;
	int defense;
	int positionX;
	int positionY;
	int profondeur; // 0 = le plus loin de "nous"
	int equipe; // ALLIES ou ENNEMIS
	int nitroDollars;
	int experience;
	int flag;
	int mort;
	int passerTour;
	int tempsRelance;
	int relanceBoost;
	SDL_Surface * surface;
	SDL_Texture * texture;
} entite;

// Structure d'une cellule du plateau
typedef struct cell_S {
	float x;
	float y;
	int solide;
	int profondeur; // 0 = le plus loin de "nous"
	int castable; // 1 = true, 0 = false
	entite e;
	SDL_Point pc; // Quel point centre pour cette cellule ?
	SDL_Surface * sort_surface;
	SDL_Texture * sort_texture;
} cell_T;

cell_T plateau[plateau_y][plateau_x];

SDL_Point pts_2D[plateau_x*plateau_y];

int isCombat;

int levelCombat;

int numeroZone;

int affichageSort;

// Déclaration des polices
TTF_Font * font;
TTF_Font * font_titre;
TTF_Font * font_barres;
TTF_Font * font_barres2;
TTF_Font * font_degats;
TTF_Font * font_tour;

// Texture du personnage
int sprite;

// Utile

#define VRAI 1
#define FAUX 0

int finTempsAllie;
int finTourComplet;
int tempsDebutPlateau;

#endif // HEADER_H_