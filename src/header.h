#ifndef HEADER_H_
#define HEADER_H_

// Taille du plateau
#define plateau_x 15
#define plateau_y 15

// Tiles.png (l'atlas des textures des cases du plateau)
#define tiles_row 4 // Combien de textures par ligne ?
#define tiles_col 1 // Combien de textures par colonne ?

// Taille d'une cellule
#define grid_cell_size_iso_x 80 // à modifier, pas "dynamique", +30 en x par point suivant
#define grid_cell_size_iso_y 40 // à modifier, pas "dynamique", +15 en y par point suivant

// Structure d'une cellule du plateau
typedef struct cell_S {
	float x;
	float y;
	int solide;
	SDL_Point pc; // Quel point centre pour cette cellule ?
} cell_T;

cell_T plateau[plateau_y][plateau_x];

#endif // HEADER_H_