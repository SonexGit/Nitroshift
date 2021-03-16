#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "header.h"
#include "render.h"

// extern SDL_Renderer *ren;
int screen_w, screen_h;

const int grid_cell_size = (900 / (plateau_x+1));

const int grid_cell_size_iso_x = 80; // à modifier, pas "dynamique", +30 en x par point suivant
const int grid_cell_size_iso_y = 40; // à modifier, pas "dynamique", +15 en y par point suivant

SDL_Rect grid_cursor;
SDL_Rect grid_cursor_ghost;

/* Déclaration de l'activité du curseur */
SDL_bool mouse_active = SDL_FALSE;
SDL_bool mouse_hover = SDL_FALSE;
SDL_bool mouse_toofar = SDL_FALSE;
SDL_bool mouse_solide = SDL_FALSE;

int total_points = ((plateau_x + 1) * plateau_y) + (plateau_y + 1);

SDL_Point points[plateau_x*plateau_y];

SDL_Point points_centre[plateau_x*plateau_y];
SDL_Point pc_2D[plateau_x*plateau_y];

SDL_Point souris;

SDL_Rect grid_cursor = {
	.x = (plateau_x - 1) / 2 * grid_cell_size,
	.y = (plateau_y - 1) / 2 * grid_cell_size,
	.w = grid_cell_size,
	.h = grid_cell_size,
};

SDL_Rect grid_cursor_ghost = {0, 0, grid_cell_size_iso_x, grid_cell_size_iso_y};

int total_wheel_down = 0, total_wheel_up = 0;

SDL_Surface * surface_test;
SDL_Texture * textures_plateau;
SDL_Rect dest_plateau[plateau_x*plateau_y];

SDL_Rect tiles[tiles_row*tiles_col];

int save;

// Pour faire qu'une fois certaines fonctions dans la boucle while (1) du main (c'est du test)
int ip2d_done = 0;
int ipc_done = 0;
int lpcc_done = 0;

/*
	FINI - Objectif 1 : Placer un point au centre de chaque case pour pouvoir savoir sur quelle case le curseur se trouvera
		FINI - Objectif 1.5 : Lier les cases à la matrice du plateau
	FINI - Objectif 2 : Prendre la position de la souris, trouver dans quelle case elle se trouve et la mettre en surbrillance
		FINI (à revoir) - Objectif 2.5 : Si trop distant d'une case, quand on est en dehors du plateau, enlever le mouse_hover
	FINI - Objectif 3 : Essayer d'afficher quelque chose dans l'une des cases (une texture quoi)
		FINI - Objectif 3.5 : Mettre les tiles dans une feuille (atlas) et les découper pour optimiser/récupérer des FPS
	FINI - Objectif 4 : Gérer les collisions sur certaines cases
		FINI - Objectif 4.1 : Enlever le mouse_hover si une case est solide
		FINI - Objectif 4.5 : La dernière colonne du plateau ne fonctionne pas avec le hover, à résoudre.
	- Objectif 5 : Optimiser un maximum
		- Objectif 5.5 : Faire en sorte que le jeu s'adapte à toutes les tailles de fenêtre
	- Objectif 6 : Implémenter les personnages avec les programmes annexes

	Problème 1 : Le mouse_hover bug (le curseur change pas de forme)
*/

SDL_Point Coord2DToIso(SDL_Point point) {
	int temp_x = point.x - point.y;
	int temp_y = (point.x + point.y) * 0.5;
	temp_x = floor((screen_w / 2) + temp_x);
	temp_y = floor(60 + temp_y);
	point.x = temp_x;
	point.y = temp_y;
	return point;
}

SDL_Point CoordIsoTo2D(SDL_Point point) {
	int temp_x = ceil(point.x - (screen_w / 2));
	int temp_y = ceil(point.y - 60);
	temp_x = (2 * temp_y + temp_x) * 0.5;
	temp_y = (2 * temp_y - temp_x);
	point.x = temp_x;
	point.y = temp_y;
	return point;
}

size_t handle_keys() {

	SDL_Event event;

	/* Pour le SDL_MOUSEMOTION */
	int dist = 10000;
	int dist_x, dist_y;
	int temp_dist_x, temp_dist_y, temp_dist;

	float scale_x, scale_y;

	float ratio = 2;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				return 1;
				break;
			
			case SDL_MOUSEWHEEL:
				if (event.wheel.y > 0) {
					SDL_RenderGetScale(ren, &scale_x, &scale_y);
					if (total_wheel_up < 1) {
						total_wheel_up++;
						total_wheel_down--;
						SDL_RenderSetScale(ren, scale_x * ratio, scale_y * ratio);
					}
				}
				if (event.wheel.y < 0) {
					SDL_RenderGetScale(ren, &scale_x, &scale_y);
					if (total_wheel_down < 1 && total_wheel_up > 0) {
						total_wheel_down++;
						total_wheel_up--;
						SDL_RenderSetScale(ren, scale_x / ratio, scale_y / ratio);
					}
				}
				break;
			
			case SDL_MOUSEMOTION:
				souris.x = event.motion.x;
				souris.y = event.motion.y;

				// printf("souris - x : %i, y : %i\n", souris.x, souris.y);

				souris = CoordIsoTo2D(souris);

				// printf("souris ISO - x : %i, y : %i\n", souris.x, souris.y);

				for (int i = 0; i < (plateau_x * plateau_y); i++) {
					temp_dist_x = abs(pc_2D[i].x - souris.x);
					temp_dist_y = abs(pc_2D[i].y - souris.y);
					temp_dist = sqrt(temp_dist_x * temp_dist_x + temp_dist_y * temp_dist_y);

					if (temp_dist < dist) {
						dist = temp_dist;
						dist_x = temp_dist_x;
						dist_y = temp_dist_y;
						save = i;
					}
				}
				// printf("Voici le point sauvegardé : pc[%i] : %i, %i\n", save, points_centre[save].x, points_centre[save].y);
				grid_cursor_ghost.x = points_centre[save].x - (grid_cell_size_iso_x / 2);
				grid_cursor_ghost.y = points_centre[save].y - (grid_cell_size_iso_y / 2);
				// printf("Voici le gcg : %i, %i\n", grid_cursor_ghost.x, grid_cursor_ghost.y);

				if (!mouse_active)
					mouse_active = SDL_TRUE;
				if (dist_x > (grid_cell_size_iso_x / 2) || dist_y > (grid_cell_size_iso_y / 2))
					mouse_toofar = SDL_TRUE;
				else if (dist_x < (grid_cell_size_iso_x / 2) || dist_y < (grid_cell_size_iso_y / 2))
					mouse_toofar = SDL_FALSE;
				if (dist > 25)
					mouse_toofar = SDL_TRUE;
				else if (dist < 25)
					mouse_toofar = SDL_FALSE;
				break;
			
			case SDL_WINDOWEVENT:
				if (event.window.event == SDL_WINDOWEVENT_ENTER && !mouse_hover)
					mouse_hover = SDL_TRUE;
				else if (event.window.event == SDL_WINDOWEVENT_LEAVE && mouse_hover)
					mouse_hover = SDL_FALSE;
				break;
		}
	}
	return 0;
}

void init_points_2D(SDL_Point points_2D[]) {
	int h = 0;
	int i = 0;
	int j = 0;
	while(j < (plateau_y + 1)) {
		for(i; h < plateau_x+1; i++) {
			// points_2D[i].x = (h * (650 / (plateau_x+1)));
			// points_2D[i].y = (j * (650 / (plateau_y+1)));
			points_2D[i].x = (h * 40);
			points_2D[i].y = (j * 40);
			// printf("points_2D[%i] = x : %i, y : %i\n", i, points_2D[i].x, points_2D[i].y);
			h++;
		}
		h=0;
		j++;
	}
}

void dessiner_grille(SDL_Point points[]) {

	int h = 0;
	int i = 0;
	int j = 0;
	int checker_hori, checker_vert;
	int temp_point_x, temp_point_y;

	/* Dessine les 4 coins d'une cellule du plateau */

	while(j < (plateau_y+1)) {
		checker_hori = j * (plateau_x+1);
		for(i; h < plateau_x+1; i++) {
			/*
			if (i > 0 && i != checker_hori) {
					// Dessine les lignes horizontales du plateau, en prenant en compte le passage à une nouvelle ligne
					SDL_RenderDrawLine(ren, points[i-1].x, points[i-1].y, points[i].x, points[i].y);
			}
			*/
			// points[i].x = (h * (650 / (plateau_x+1)));
			// points[i].y = (j * (650 / (plateau_y+1)));
			points[i].x = (h * grid_cell_size_iso_y);
			points[i].y = (j * grid_cell_size_iso_y);

			/* Conversion en coordonnées isométriques */
			points[i] = Coord2DToIso(points[i]);

			h++;
			// printf("points[%i] = %i, %i\n", i, points[i].x, points[i].y);
		}
		h=0;
		j++;
	}

	/* Dessine les lignes verticales du plateau */
	
	SDL_SetRenderDrawColor(ren, 255, 0, 255, 255);
	/*
	for(int multiple = (plateau_y+1); multiple<((plateau_y)*2+2); multiple++) {
		for (int x = multiple; x<(plateau_x*plateau_y+((plateau_x)*2)+1); x+=(plateau_x+1)) {
			SDL_RenderDrawLine(ren, points[x-(plateau_x+1)].x, points[x-(plateau_x+1)].y, points[x].x, points[x].y);
		}
	}
	*/

	/*
	for(int i=0; i<442; i++) {
		printf("points[%i] : %i, %i\n", i, points[i].x, points[i].y);
	}
	*/

}

void init_point_centre(SDL_Point pc[], SDL_Point pts[]) {
	int prev, check;
	int actuel = (plateau_x + 2);
	int ligne_actuelle = 1;
	for (int i = 0; i < (plateau_x * plateau_y); i++) {
		check = plateau_x * ligne_actuelle + (1 * (ligne_actuelle-1)); // BONNE normalement
		prev = actuel - (plateau_x + 2);
		if (prev != check) {
			// printf("Prev : %i\n", prev);
			// printf("pc[%i] = %i, %i\npts[%i] : %i, %i et pts[%i] : %i, %i\n", i, pc[i].x, pc[i].y,prev, pts[prev].x, pts[prev].y, actuel, pts[actuel].x, pts[actuel].y);
			pc[i].x = pts[prev].x + ((pts[actuel].x - pts[prev].x) / 2);
			pc[i].y = pts[prev].y + ((pts[actuel].y - pts[prev].y) / 2);
			actuel++;
		}
		else {
			i--;
			actuel++;
			// printf("Point de fin de ligne : %i\n", prev);
			ligne_actuelle++;
		}
	}
}

void init_point_centre_2D(SDL_Point points_centre[], SDL_Point points[]) {
	int prev, check;
	int actuel = (plateau_x + 2);
	int ligne_actuelle = 1;
	for (int i = 0; i < (plateau_x * plateau_y); i++) {
		check = plateau_x * ligne_actuelle + (1 * (ligne_actuelle-1)); // BONNE normalement
		prev = actuel - (plateau_x + 2);
		if (prev != check) {
			// printf("Prev : %i\n", prev);
			// printf("points_centre[%i] = %i, %i\npoints[%i] : %i, %i et points[%i] : %i, %i\n", i, points_centre[i].x, points_centre[i].y,prev, points[prev].x, points[prev].y, actuel, points[actuel].x, points[actuel].y);
			points_centre[i].x = points[prev].x + ((points[actuel].x - points[prev].x) / 2);
			points_centre[i].y = points[prev].y + ((points[actuel].y - points[prev].y) / 2);
			actuel++;
		}
		else {
			i--;
			actuel++;
			// printf("Point de fin de ligne : %i\n", prev);
			ligne_actuelle++;
		}
	}
}

void fileListPoints(SDL_Point pts[], SDL_Point pc[]) {
	FILE * fichier;
	fichier = fopen("../points.txt", "w");

	for (int i = 0; i < (plateau_x + 1)*plateau_y; i++)
	{
		fprintf(fichier, "points[%i] : x: %i, y: %i\n", i, pts[i].x, pts[i].y);
	}
	for (int i = 0; i < plateau_x*plateau_y; i++)
	{
		fprintf(fichier, "points_centre[%i] : x: %i, y: %i\n", i, pc[i].x, pc[i].y);
	}

	fclose(fichier);
}

void lien_pc_cases(SDL_Point pc[], cell_T plat[plateau_y][plateau_x]) {
	int h = 0;
	int i = 0;
	int j = 0;
	while(j < plateau_y) {
		for(i; h < plateau_x; i++) {
			plat[j][h].pc = pc[i];
			// printf("plateau[%i][%i].pc = pc[%i] (x : %i, y : %i)\n", j, h, i, pc[i].x, pc[i].y);
			// printf("plateau[%i][%i].pc = x : %i, y : %i\n", j, h, plat[j][h].pc.x, plat[j][h].pc.y);
			h++;
		}
		h=0;
		j++;
	}
}

int trouver_case_pc(SDL_Point pc, cell_T plat[plateau_y][plateau_x], int* x, int* y) {
	int h = 0;
	int i = 0;
	int j = 0;
	// printf("plat[7][13] = x : %i, y : %i\n", plat[7][13].pc.x, plat[7][13].pc.y);
	// printf("plat[7][14] = x : %i, y : %i\n", plat[7][14].pc.x, plat[7][14].pc.y);
	while(j < plateau_y) {
		for(i; h < plateau_x; i++) {
			// printf("plat[%i][%i] = x : %i, y : %i\npc       = x : %i, y: %i\n", j, h, plat[j][h].pc.x, plat[j][h].pc.y, pc.x, pc.y);
			if (plat[j][h].pc.x == pc.x && plat[j][h].pc.y == pc.y) {
				*x = h;
				*y = j;
				// printf("TROUVÉE : plateau[%i][%i].pc = pc[%i]\n", j, h, i);
				return 0;
			}
			h++;
		}
		h=0;
		j++;
	}
}

void init_texture_cases(int num_carte, SDL_Point pc[]) {
	FILE * fichier_texture;

	int longueur = snprintf(NULL, 0, "%d", num_carte);
	char * num_carte_string = malloc(longueur + 1);
	snprintf(num_carte_string, longueur + 1, "%d", num_carte);
	char * repertoire_cartes = malloc(sizeof(char) * 36);
	strcpy(repertoire_cartes, "../data/cartes/textures_carte");
	strcat(repertoire_cartes, num_carte_string);
	strcat(repertoire_cartes, ".txt");

	fichier_texture = fopen(repertoire_cartes, "r");

	int n = (plateau_x * plateau_y);
	char * buffer = (char *) malloc(sizeof(int) * n);
	// fgets(buffer, n, fichier_texture);
	// printf("Le buffer : %s", buffer);

	const char * delim = " \t\r\n\v\f";
	char * curseur;
	int check = 0;

	char * repertoire = "../data/tiles/tiles.png";

	int first_load_file = 0;

	int x, y;
	int i;

	surface_test = IMG_Load(repertoire);
	textures_plateau = SDL_CreateTextureFromSurface(ren, surface_test);

	// à rendre dynamique
	tiles[0].x = 0;
	tiles[0].y = 0;
	tiles[0].w = 80;
	tiles[0].h = 40;

	tiles[1].x = 80;
	tiles[1].y = 0;
	tiles[1].w = 80;
	tiles[1].h = 40;

	tiles[2].x = 160;
	tiles[2].y = 0;
	tiles[2].w = 80;
	tiles[2].h = 40;

	tiles[3].x = 240;
	tiles[3].y = 0;
	tiles[3].w = 80;
	tiles[3].h = 40;

	int pos_x, pos_y, img_w, img_h;
	int pos_tiles;
	while (fgets(buffer, n, fichier_texture)) {

		if(first_load_file == 0) {
			x=0, y=0, i=0;
			first_load_file = 1;
		}

		curseur = strtok(buffer, delim);
		pos_tiles = atoi(curseur);
		// printf("repertoire : %s\n", repertoire);

		pos_x = pc[i].x - (grid_cell_size_iso_x/2);
		pos_y = pc[i].y - (grid_cell_size_iso_y/2);
		img_w = surface_test->w;
		img_h = surface_test->h;
		dest_plateau[i].x = pos_x;
		dest_plateau[i].y = pos_y;
		dest_plateau[i].w = img_w / tiles_row;
		dest_plateau[i].h = img_h / tiles_col;
		SDL_RenderCopy(ren, textures_plateau, &tiles[pos_tiles], &dest_plateau[i]);

		/* Ajouter jusqu'a fin de fgets */
		x++;

		if (x >= plateau_x) {
			y++;
			x=0;
		}

		curseur = strtok(NULL, delim);
		i++;
	}
	
	free(num_carte_string);
	free(repertoire_cartes);
	free(buffer);
	fclose(fichier_texture);
}

void free_texture_cases() {
	int h = 0;
	int i = 0;
	int j = 0;
	while(j < (plateau_y)) {
		for(i; h < plateau_x; i++) {
			SDL_DestroyTexture(textures_plateau); // si ça crash dans cette fonction en général c'est parce que le i va jusqu'a 224 mais s'il n'y a pas 225 textures...
			h++;
		}
		h=0;
		j++;
	}
}

void init_cases_solide(int num_carte, cell_T plat[plateau_y][plateau_x]) {
	FILE * fichier_texture;

	int longueur = snprintf(NULL, 0, "%d", num_carte);
	char * num_carte_string = malloc(longueur + 1);
	snprintf(num_carte_string, longueur + 1, "%d", num_carte);
	char * repertoire_cartes = malloc(sizeof(char) * 36);
	strcpy(repertoire_cartes, "../data/cartes/textures_carte");
	strcat(repertoire_cartes, num_carte_string);
	strcat(repertoire_cartes, ".txt");

	fichier_texture = fopen(repertoire_cartes, "r");

	int n = (plateau_x * plateau_y);
	char * buffer = (char *) malloc(sizeof(int) * n);
	// fgets(buffer, n, fichier_texture);
	// printf("Le buffer : %s", buffer);

	const char * delim = " \t\r\n\v\f";
	char * curseur;
	int check = 0;

	int first_load_file = 0;

	int x, y;
	int i;

	int isSolid = 0;

	while (fgets(buffer, n, fichier_texture)) {
		if(first_load_file == 0) {
			x=0, y=0, i=0;
			first_load_file = 1;
		}

		curseur = strtok(buffer, delim);
		curseur = strtok(NULL, delim);
		isSolid = atoi(curseur);
		// printf("isSolid : %i\n", isSolid);

		if (isSolid == 1) {
			plat[y][x].solide = 1;
			// printf("plat[%i][%i].solide = %i\n", y, x, plat[y][x].solide);
		}

		/* Ajouter jusqu'a fin de fgets */
		x++;

		if (x >= plateau_x) {
			y++;
			x=0;
		}

		i++;
	}
	
	free(num_carte_string);
	free(repertoire_cartes);
	free(buffer);
	fclose(fichier_texture);
}

void test(SDL_Point pc[], cell_T plat[plateau_y][plateau_x]) {
	printf("==== TEST ====");
	int h = 0;
	int i = 0;
	int j = 0;
	while(j < plateau_y) {
		for(i; h < plateau_x; i++) {
			printf("plateau[%i][%i].pc = pc[%i] (x : %i, y : %i)\n", j, h, i, pc[i].x, pc[i].y);
			printf("plateau[%i][%i].pc = x : %i, y : %i\n", j, h, plat[j][h].pc.x, plat[j][h].pc.y);
			h++;
		}
		h=0;
		j++;
	}
}

int main(int argc, char** argv)
{
	rendering();

	SDL_SetRenderDrawBlendMode(ren, SDL_BLENDMODE_BLEND);

	// Récuperer taille de la fenêtre
	SDL_GetWindowSize(win, &screen_w, &screen_h);

	// Permet de à la fenêtre de s'adapter à n'importe quelle taille
	SDL_RenderSetLogicalSize(ren, screen_w, screen_h);

	// Plateau
	cell_T plateau[plateau_y][plateau_x];
	
	// SDL_Rect grid_cursor_ghost = {grid_cursor.x, grid_cursor.y, grid_cell_size, grid_cell_size};

	points_centre[plateau_x*plateau_y];

	SDL_Point pts_2D[plateau_x*plateau_y];

	SDL_Cursor * cursor;
	cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
	SDL_Cursor * cursor_hover;
	cursor_hover = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);

	// Met toutes les cases non solides et voir toutes les cases solides/pas solides sur le terminal
	for (int i = 0; i < plateau_x; i++) {
        for (int j = 0; j < plateau_y; j++) {
            plateau[i][j].solide = 0;
			// plateau[5][6].solide = 1;
        }
    }
	/*
	for (int i = 0; i < plateau_x; i++) {
		for (int j = 0; j < plateau_y; j++) {
			printf("%d ", plateau[i][j].solide);
		}
		printf("\n");
	}
	*/

	SDL_Surface * surface_mouse_hover = IMG_Load("../data/tiles/mouse_hover.png");
	SDL_Texture * texture_mouse_hover = SDL_CreateTextureFromSurface(ren, surface_mouse_hover);

	// Ne marche plus pour une raison que j'ignore
	SDL_Surface * icon = IMG_Load("../data/icon.png");
	SDL_SetWindowIcon(win, icon);

	// Pour voir si case solide
	int pc_x, pc_y;

	while (1) {
		SDL_SetRenderDrawColor(ren, 140, 140, 140, 0);
		SDL_RenderClear(ren);

		if (handle_keys() == 1) {
			break;
		}

		// ==============================================
		// Dessin du plateau
		// ==============================================

		SDL_SetRenderDrawColor(ren, 0, 255, 255, 255);

		/* Dessine la grille (carré 4:3 dans 16:9) */

		dessiner_grille(points);
		if (!ip2d_done) init_points_2D(pts_2D);
		ip2d_done = 1;

		/* Dessine les points en coins de chaque cellule */
		// SDL_RenderDrawPoints(ren, points, total_points);
		// SDL_RenderDrawPoints(ren, pts_2D, total_points);

		/* Dessine le centre de chaque cellule (isométrique et cartésienne) à travers des points centre */
		if (!ipc_done) init_point_centre(points_centre, points);
		if (!ipc_done) init_point_centre(pc_2D, pts_2D);
		ipc_done = 1;
		
		if (!lpcc_done) lien_pc_cases(points_centre, plateau);
		lpcc_done = 1;

		// test(points_centre, plateau);

		SDL_SetRenderDrawColor(ren, 255, 255, 0, 255);
		// SDL_RenderDrawPoints(ren, points_centre, plateau_x*plateau_y);
		// SDL_RenderDrawPoints(ren, pc_2D, plateau_x*plateau_y);

		// Liste de points mises dans un fichier pour pouvoir suivre le fonctionnement plus facilement
		fileListPoints(points, points_centre);

		// On initialise les textures de toutes les cases de la carte 1 (premier argument), le deuxième est une constante cependant
		init_texture_cases(1, points_centre);

		trouver_case_pc(points_centre[save], plateau, &pc_x, &pc_y);

		init_cases_solide(1, plateau);

		/*
		for (int i = 0; i < plateau_x; i++) {
			for (int j = 0; j < plateau_y; j++) {
				printf("plat[%i][%i] = pc x : %i, pc y : %i\n", i, j, plateau[i][j].pc.x, plateau[i][j].pc.y);
			}
			printf("\n");
		}
		*/

		// printf("pc_x : %i, pc_y : %i", pc_x, pc_y);

		if (plateau[pc_y][pc_x].solide >= 1) {
			// SDL_Delay(10);
			mouse_solide = SDL_TRUE;
			// SDL_SetCursor(cursor);
			// printf("la case [%i][%i] est solide !\n", pc_y, pc_x);
		}
		else {
			// SDL_Delay(10);
			mouse_solide = SDL_FALSE;
			// SDL_SetCursor(cursor_hover);
			// printf("la case [%i][%i] n'est pas solide !\n", pc_y, pc_x);
		}

		// Curseur "hover"
		if (mouse_active && mouse_hover) {
			if (!mouse_toofar && !mouse_solide) {
				SDL_SetRenderDrawColor(ren, 255, 0, 0, 127);
				// SDL_RenderFillRect(ren, &grid_cursor_ghost);
				SDL_RenderCopy(ren, texture_mouse_hover, NULL, &grid_cursor_ghost);
				printf("je suis devenu hover\n");
				SDL_SetCursor(cursor_hover);
			}
			else {
				printf("je suis devenu normal\n");
				SDL_SetCursor(cursor_hover);
			}
        }

		SDL_RenderPresent(ren);
		free_texture_cases();
		SDL_Delay(10);
	}
	
	SDL_FreeSurface(icon);
	SDL_DestroyTexture(texture_mouse_hover);
	SDL_FreeSurface(surface_mouse_hover);
	SDL_FreeSurface(surface_test);
	SDL_FreeCursor(cursor);
	SDL_FreeCursor(cursor_hover);
	stopRendering();
}