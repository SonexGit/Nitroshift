#ifndef HEADER_H_
#define HEADER_H_

// Taille du plateau
#define plateau_x 15
#define plateau_y 15

// Tiles.png (l'atlas des textures des cases du plateau)
#define tiles_row 4 // Combien de textures par ligne ?
#define tiles_col 1 // Combien de textures par colonne ?

// Structure d'une cellule du plateau
typedef struct cell_S {
	float x;
	float y;
	int solide;
	SDL_Point pc; // Quel point centre pour cette cellule ?
} cell_T;

#endif // HEADER_H_