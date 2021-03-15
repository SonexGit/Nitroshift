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
	// char texture_l1; // L1 : Layer 1 (couche inférieure - couche des textures du sol etc)
	// char texture_l2; // L2 : Layer 2 (couche moyenne - couche des personnages et objets solides)
	// char texture_l3; // L3 : Layer 3 (couche supérieur - couche des textures passant au dessus de tout, exemple : un arbre à l'avant plan)
	int solide;
	SDL_Point pc; // Quel point centre pour cette cellule ?
} cell_T;