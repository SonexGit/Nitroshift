#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "header.h"
#include "sorts.h"
#include "entite.h"
#include "render.h"
#include "combat.h"

/**
 * \file sorts.c
 * \brief Programme contenant les sorts et ses fonctions
 * \author Allan Lucas Léo Enzo
 * \version 1.0
 * \date 16 avril 2021
*/

// sort : id, nom, description, degatsMin, degatsMax, relanceMax, relanceActuel, portee, coutPA, coutNitro, surface, texture, id_lanceur
sort_T sorts[MAX_SORTS] = {
	// Sorts Assassin
	{0, "Attaque de base", "Attaquez faiblement un ennemi", 25, 40, 1, 0, 1, 2, 0, NULL, NULL, 1},
	{1, "Tir rapide", "Tirez une salve avec votre arme", 100, 125, 2, 0, 4, 1, 24, NULL, NULL, 1},
	{2, "Téléportation", "Téléportez vous sur la case ciblée", 0, 0, 5, 0, 5, 0, 50, NULL, NULL, 1},
	// Sorts Soldat
	{3, "Attaque de base", "Attaquez faiblement un ennemi", 25, 40, 1, 0, 2, 3, 0, NULL, NULL, 1},
	{4, "Grenade", "Lancez une grenade", 200, 300, 4, 0, 4, 5, 60, NULL, NULL, 1},
	{5, "Glissade", "Avancez rapidement vers un emplacement", 0, 0, 3, 0, 2, 3, 0, NULL, NULL, 1},
	// Sorts Tank
	{6, "Attaque de base", "Attaquez faiblement un ennemi", 35, 50, 1, 0, 1, 3, 0, NULL, NULL, 1},
	{7, "Explosion de mine horizontale", "Placez une mine qui explose directement, touchant trois cases perpendiculaire à vous", 150, 200, 5, 0, 2, 3, 60, NULL, NULL, 1},
	{8, "Tacle", "Frappez un ennemi proche de plein fouet", 70, 90, 3, 0, 1, 6, 0, NULL, NULL, 1},
	// Sorts Sniper
	{9, "Attaque de base", "Attaquez faiblement un ennemi", 25, 40, 1, 0, 3, 4, 0, NULL, NULL, 1},
	{10, "Tir de sniper", "Touchez une cible lointaine avec une grande puissance", 280, 300, 5, 0, 7, 5, 75, NULL, NULL, 1},
	{11, "Régénération", "Récupérez quelques points de vie", 0, 0, 3, 0, 0, 3, 33, NULL, NULL, 1}
};

/**
  *\fn void affichage_sorts(entite *)
  *\brief Affiche les sorts du joueur pendant le combat
  *\param joueur de type entite *
*/
void affichage_sorts(entite * joueur) {
	char * repertoire = malloc(sizeof(char) * 16);
	char * id_sort = malloc(sizeof(char) * 3);

	debutSorts = 0;
	if (!strcmp(joueur->classe, "Soldat")) debutSorts = 3;
	else if (!strcmp(joueur->classe, "Tank")) debutSorts = 6;
	else if (!strcmp(joueur->classe, "Sniper")) debutSorts = 9;
	else debutSorts = 0;
	
	for (int i = debutSorts; i < debutSorts + 3; i++) {
		strcpy(repertoire, "../data/sorts/");
		snprintf(id_sort, 3, "%d", sorts[i].id);
		strcat(repertoire, id_sort);
		strcat(repertoire, ".png");
		if (sorts[i].id_lanceur == 1) {
			sorts[i ].surface = IMG_Load(repertoire);
			sorts[i].texture = SDL_CreateTextureFromSurface(ren, sorts[i].surface);

			liste_sorts[i].x = 1000 + ((i - debutSorts) * 50);
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

/**
  *\fn void reset_castable(void)
  *\brief Réinitialise à 0 (impossible) la possibilité de lancer des sorts sur chaque cellule du plateau
*/
void reset_castable() {
	for (int i = 0; i < plateau_y; i++) {
		for (int j = 0; j < plateau_x; j++) {
			plateau[i][j].castable = 0;
		}
	}
}

/**
  *\fn void sort_relance_fintour(void)
  *\brief Réduit de 1 tour les sorts en rechargement
*/
void sort_relance_fintour() {
	for (int i = 0; i < MAX_SORTS; i++) {
		if(sorts[i].relanceActuel > 0){
			sorts[i].relanceActuel--;
		}
	}
}

/**
  *\fn int numero_aleatoire(int, int)
  *\brief Prends un nombre aléatoire entre ses deux paramètres
  *\param minimum de type int, maximum de type int
  *\return Renvoie un int entre minimum et maximum
*/
int numero_aleatoire(int minimum, int maximum) {
	srand(time(NULL));
	int nombre = (rand() % (maximum - minimum + 1)) + minimum;
	return nombre;
}

/**
  *\fn entite * rechercherEntite(int)
  *\brief Trouve l'entité selon son id
  *\param id de type int
  *\return Renvoie l'entité trouvée
*/
entite * rechercherEntite(int id){

	switch(id){
        case 101 :
            return &e1;
            break;
        case 102 :
            return &e2;
            break;
        case 201 :
            return &e3;
            break;
        case 202 :
            return &e4;
            break;
        case 301 :
            return &e5;
            break;
        case 302 :
            return &e6;
            break;
        case 100 :
            return &b1;
            break;
        case 200 :
            return &b2;
            break;
        case 300 :
            return &b3;
            break;
	}
}

/**
  *\fn void afficher_degats(int, int, int)
  *\brief Affiche sur le jeu les dégats infligés
  *\param degats de type int, cible_x de type int, cible_y de type int
*/
void afficher_degats(int degats, int cible_x, int cible_y) {
	SDL_Color color_red = {200, 0, 0};

	int longueur = snprintf(NULL, 0, "-%d", degats);
	char * degats_texte = malloc(sizeof(char) * longueur + 1);
	snprintf(degats_texte, longueur + 1, "-%d", degats);
	SDL_Surface * surface_degats_texte = TTF_RenderText_Blended(font_degats, degats_texte, color_red);
	SDL_Texture * texture_degats_texte = SDL_CreateTextureFromSurface(ren, surface_degats_texte);

	int temp_w, temp_h;
	SDL_QueryTexture(texture_degats_texte, NULL, NULL, &temp_w, &temp_h);

	SDL_Rect dstrect_degats_texte;
	dstrect_degats_texte.x = plateau[cible_y][cible_x].pc.x - temp_w / 2;
	dstrect_degats_texte.y = plateau[cible_y][cible_x].pc.y - 154;
	dstrect_degats_texte.w = temp_w;
	dstrect_degats_texte.h = temp_h;

	SDL_RenderCopy(ren, texture_degats_texte, NULL, &dstrect_degats_texte);

	temps_actuel = SDL_GetTicks();

	if (temps_actuel - temps_debut > 1000) {
		degats_inflige = -1;
		degats_cible_x = -1;
		degats_cible_y = -1;
		flag_temps = 0;
	}

	free(degats_texte);
	SDL_FreeSurface(surface_degats_texte);
	SDL_DestroyTexture(texture_degats_texte);
}

/**
  *\fn void infliger_degats(int, int, sort_T *)
  *\brief Enlève les points de vie à la cible selon les dégats infligés
  *\param cible_x de type int, cible_y de type int, s de type sort_T *
*/
void infliger_degats(int cible_x, int cible_y, sort_T * s) {
	int degats = numero_aleatoire(s->degatsMin, s->degatsMax);

	entite * temp;

	if(plateau[cible_y][cible_x].e.id != 0) {
		printf("\nJE FAIS DES DEGATS !! : %i\n", degats);
		printf("\nVOICI LA VIE DE L'ENNEMI AVANT : %i\n", temp->hp);
		temp = rechercherEntite(plateau[cible_y][cible_x].e.id);
		temp->hp -= degats;
		printf("\nVOICI LA VIE DE L'ENNEMI APRES : %i\n", temp->hp);
		if(temp->hp <= 0){
			temp->mort = 1;
			temp->id = 0;
		}

		degats_inflige = degats;
		degats_cible_x = cible_x;
		degats_cible_y = cible_y;
	}
}

/**
  *\fn void lancement_sort(entite *, int, int, sort_T *)
  *\brief Trouve quel sort est lancé et réalise les effets de ce sort
  *\param lanceur de type entite *, cible_x de type int, cible_y de type int, s de type sort_T *
*/
void lancement_sort(entite * lanceur, int cible_x, int cible_y, sort_T * s) {

	switch (s->id) {
		case 0: // Attaque de base (Assassin) • Sort 0
			infliger_degats(cible_x, cible_y, s);
			break;
		case 1: // Tir rapide (Assassin) • Sort 1
			infliger_degats(cible_x, cible_y, s);
			break;
		case 2: // Téléportation (Assassin) • Sort 2
			lanceur->positionX = cible_x;
			lanceur->positionY = cible_y;
			break;
		case 3: // Attaque de base (Soldat) • Sort 3
			infliger_degats(cible_x, cible_y, s);
			break;
		case 4: // Grenade (Soldat) • Sort 4
			infliger_degats(cible_x, cible_y, s);
			break;
		case 5: // Glissade (Soldat) • Sort 5
			lanceur->positionX = cible_x;
			lanceur->positionY = cible_y;
			break;
		case 6: // Attaque de base (Tank) • Sort 6
			infliger_degats(cible_x, cible_y, s);
			break;
		case 7: // Explosion de mine horizontale (Tank) • Sort 7
			infliger_degats(cible_x, cible_y, s);
			if (cible_x > lanceur->positionX || cible_x < lanceur->positionX) {
				infliger_degats(cible_x, cible_y-1, s);
				infliger_degats(cible_x, cible_y+1, s);
			}
			else if (cible_y > lanceur->positionY || cible_y < lanceur->positionY) {
				infliger_degats(cible_x-1, cible_y, s);
				infliger_degats(cible_x+1, cible_y, s);
			}
			break;
		case 8: // Tacle (Tank) • Sort 8
			infliger_degats(cible_x, cible_y, s);
			break;
		case 9: // Attaque de base (Sniper) • Sort 9
			infliger_degats(cible_x, cible_y, s);
			break;
		case 10: // Tir de sniper (Sniper) • Sort 10
			infliger_degats(cible_x, cible_y, s);
			break;
		case 11: // Régénération (Sniper) • Sort 11
			if (lanceur->hp + 20 < lanceur->hpMax) lanceur->hp += 20;
			else lanceur->hp = lanceur->hpMax;
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

/**
  *\fn void clic_sort(entite *, sort_T)
  *\brief Place l'id du sort dans une variable lorsqu'on clique dessus, et qui permet la mise en place de la préparation du sort
  *\param lanceur de type entite *, s de type sort_T
*/
void clic_sort(entite * lanceur, sort_T s) {
	printf("\n PA LANCEUR : %i \n NITRO LANCEUR : %i", lanceur->pa, lanceur->nitro);
	printf("\nRELANCE ACTUEL : %i\n", s.relanceActuel);
	if (s.relanceActuel == 0 && lanceur->pa >= s.coutPA && lanceur->nitro >= s.coutNitro) {
		prepaSort = s.id;
		printf("prepaSort : %i", prepaSort);
	}
	else {
		printf("Le sort est en charge...\n");
	}
}

/**
  *\fn void affichage_infos_sort(sort_T)
  *\brief Affiche sous forme de tooltip les informations d'un sort (son nom, sa description, sa portée, ses dégats, son temps de récupération)
  *\param s de type sort_T
*/
void affichage_infos_sort(sort_T s) {
	SDL_Color color_white = {255, 255, 255, 255};

	// Affichage du nom du sort
	int longueur = snprintf(NULL, 0, "%s", s.nom);
	char * nom_sort_texte = malloc(sizeof(char) * longueur);
	snprintf(nom_sort_texte, longueur + 1, "%s", s.nom);
	SDL_Surface * surface_sort_texte = TTF_RenderUTF8_Blended(font_titre, nom_sort_texte, color_white);
	SDL_Texture * texture_sort_texte = SDL_CreateTextureFromSurface(ren, surface_sort_texte);

	// Affichage de la description du sort
	longueur = snprintf(NULL, 0, "%s", s.description);
	char * desc_sort_texte = malloc(sizeof(char) * longueur);
	snprintf(desc_sort_texte, longueur + 1, "%s", s.description);
	SDL_Surface * surface_sort_desc_texte = TTF_RenderUTF8_Blended_Wrapped(font, desc_sort_texte, color_white, 400);
	SDL_Texture * texture_sort_desc_texte = SDL_CreateTextureFromSurface(ren, surface_sort_desc_texte);

	// Affichage de la portée du sort
	longueur = snprintf(NULL, 0, "Dégâts : %i-%i • Portée : %i case(s) • Récupération : %i tour(s)", s.degatsMin, s.degatsMax, s.portee, s.relance);
	char * infos_sort_texte = malloc(sizeof(char) * longueur);
	snprintf(infos_sort_texte, longueur + 1, "Dégâts : %i-%i • Portée : %i case(s) • Récupération : %i tour(s)", s.degatsMin, s.degatsMax, s.portee, s.relance);
	SDL_Surface * surface_infos_sort_texte = TTF_RenderUTF8_Blended(font_small, infos_sort_texte, color_white);
	SDL_Texture * texture_infos_sort_texte = SDL_CreateTextureFromSurface(ren, surface_infos_sort_texte);

	int temp_w, temp_h;
	SDL_QueryTexture(texture_sort_texte, NULL, NULL, &temp_w, &temp_h);
	int temp_w2, temp_h2;
	SDL_QueryTexture(texture_sort_desc_texte, NULL, NULL, &temp_w2, &temp_h2);
	int temp_w3, temp_h3;
	SDL_QueryTexture(texture_infos_sort_texte, NULL, NULL, &temp_w3, &temp_h3);

	SDL_Rect dstrect_sort_texte;
	SDL_Point temp_souris = Coord2DToIso(souris);
	dstrect_sort_texte.x = temp_souris.x - temp_w / 2;
	dstrect_sort_texte.y = temp_souris.y - 20 - temp_h - temp_h2 - temp_h3;
	dstrect_sort_texte.h = temp_h;
	dstrect_sort_texte.w = temp_w;

	SDL_Rect dstrect_sort_desc_texte;
	dstrect_sort_desc_texte.x = temp_souris.x - temp_w / 2;
	dstrect_sort_desc_texte.y = temp_souris.y - temp_h - temp_h2 - temp_h3 + 5;
	dstrect_sort_desc_texte.h = temp_h2;
	dstrect_sort_desc_texte.w = temp_w2;

	SDL_Rect dstrect_sort_portee_texte;
	dstrect_sort_portee_texte.x = temp_souris.x - temp_w / 2;
	dstrect_sort_portee_texte.y = temp_souris.y - temp_h - temp_h2 - temp_h3 + 25;
	dstrect_sort_portee_texte.h = temp_h3;
	dstrect_sort_portee_texte.w = temp_w3;

	// Fond des infos d'un sorts
	SDL_Rect fond_sort_texte;
	fond_sort_texte.x = dstrect_sort_texte.x - 10;
	fond_sort_texte.y = dstrect_sort_texte.y - 10;
	fond_sort_texte.h = temp_h + temp_h2 + temp_h3 + 20 + 5;
	if (temp_w > temp_w2 && temp_w > temp_w3) fond_sort_texte.w = temp_w + 20;
	else if (temp_w2 > temp_w && temp_w2 > temp_w3) fond_sort_texte.w = temp_w2 + 20;
	else fond_sort_texte.w = temp_w3 + 20;

	SDL_SetRenderDrawColor(ren, 0, 0, 0, 235);
	SDL_RenderFillRect(ren, &fond_sort_texte);
	SDL_RenderCopy(ren, texture_sort_texte, NULL, &dstrect_sort_texte);
	SDL_RenderCopy(ren, texture_sort_desc_texte, NULL, &dstrect_sort_desc_texte);
	SDL_RenderCopy(ren, texture_infos_sort_texte, NULL, &dstrect_sort_portee_texte);

	free(nom_sort_texte);
	free(desc_sort_texte);
	free(infos_sort_texte);
	SDL_FreeSurface(surface_sort_texte);
	SDL_DestroyTexture(texture_sort_texte);
	SDL_FreeSurface(surface_sort_desc_texte);
	SDL_DestroyTexture(texture_sort_desc_texte);
	SDL_FreeSurface(surface_infos_sort_texte);
	SDL_DestroyTexture(texture_infos_sort_texte);
}

/**
  *\fn void init_sort_surftext(void)
  *\brief Initialise les surfaces et textures pour afficher les cases ou l'on peut lancer ses sorts puis libère les surfaces
*/
void init_sort_surftext() {
	for (int i = 0; i < plateau_y; i++) {
		for (int j = 0; j < plateau_x; j++) {
			plateau[i][j].sort_surface = IMG_Load("../data/tiles/cast_able.png");
			plateau[i][j].sort_texture = SDL_CreateTextureFromSurface(ren, plateau[i][j].sort_surface);

			SDL_FreeSurface(plateau[i][j].sort_surface);
		}
	}
}

/**
  *\fn void free_sort_text(void)
  *\brief Libère la mémoire en détruisant les textures des cases ou l'on peut lancer ses sorts
*/
void free_sort_text() {
	for (int i = 0; i < plateau_y; i++) {
		for (int j = 0; j < plateau_x; j++) {
			SDL_DestroyTexture(plateau[i][j].sort_texture);
		}
	}
}

/**
  *\fn void prep_sort_plus(entite *, int)
  *\brief Affiche les possibilités pour lancer son sort sous forme de plus d'une distance en paramètre
  *\param lanceur de type entite *, distance de type int
*/
void prep_sort_plus(entite * lanceur, int distance) {

	int compteur = 0;

	for (int i = 0 - distance; i <= distance; i++) {
		if (i == 0) i++;
		int og_y = lanceur->positionY + i;
		int og_x = lanceur->positionX;

		if (og_y < plateau_y && og_x < plateau_x && plateau[og_y][og_x].solide == 0 || (plateau[og_y][og_x].e.nom != NULL && plateau[og_y][og_x].solide == 1)) {
			plateau[og_y][og_x].sort_surface = IMG_Load("../data/tiles/cast_able.png");
			plateau[og_y][og_x].sort_texture = SDL_CreateTextureFromSurface(ren, plateau[og_y][og_x].sort_surface);

			plateau[og_y][og_x].castable = 1;

			rect_prep_sort[compteur].x = plateau[og_y][og_x].pc.x - (grid_cell_size_iso_x/2);
			rect_prep_sort[compteur].y = plateau[og_y][og_x].pc.y - (grid_cell_size_iso_y/2);
			rect_prep_sort[compteur].w = grid_cell_size_iso_x;
			rect_prep_sort[compteur].h = grid_cell_size_iso_y;

			SDL_RenderCopy(ren, plateau[og_y][og_x].sort_texture, NULL, &rect_prep_sort[compteur]);
			SDL_FreeSurface(plateau[og_y][og_x].sort_surface);
		}

		compteur++;
	}
	for (int j = 0 - distance; j <= distance; j++) {
		if (j == 0) j++;
		int og_y = lanceur->positionY;
		int og_x = lanceur->positionX + j;

		if (og_y < plateau_y && og_x < plateau_x && plateau[og_y][og_x].solide == 0 || (plateau[og_y][og_x].e.nom != NULL && plateau[og_y][og_x].solide == 1)) {
			plateau[og_y][og_x].sort_surface = IMG_Load("../data/tiles/cast_able.png");
			plateau[og_y][og_x].sort_texture = SDL_CreateTextureFromSurface(ren, plateau[og_y][og_x].sort_surface);
			
			plateau[og_y][og_x].castable = 1;

			rect_prep_sort[compteur].x = plateau[og_y][og_x].pc.x - (grid_cell_size_iso_x/2);
			rect_prep_sort[compteur].y = plateau[og_y][og_x].pc.y - (grid_cell_size_iso_y/2);
			rect_prep_sort[compteur].w = grid_cell_size_iso_x;
			rect_prep_sort[compteur].h = grid_cell_size_iso_y;
			
			SDL_RenderCopy(ren, plateau[og_y][og_x].sort_texture, NULL, &rect_prep_sort[compteur]);
			SDL_FreeSurface(plateau[og_y][og_x].sort_surface);
		}

		compteur++;
	}
}

/**
  *\fn void prep_sort_cercle(entite *, int)
  *\brief Affiche les possibilités pour lancer son sort sous forme de cercle d'un rayon en paramètre
  *\param lanceur de type entite *, rayon de type int
*/
void prep_sort_cercle(entite * lanceur, int rayon) {
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

/**
  *\fn void preparation_sort(entite *, sort_T)
  *\brief Trouve selon l'id du sort sur quelles cellules on peut lancer son sort
  *\param lanceur de type entite *, s de type sort_T
*/
void preparation_sort(entite * lanceur, sort_T s) {
	SDL_Surface * surface_prep_sort = IMG_Load("../data/tiles/cast_able.png");
	SDL_Texture * texture_prep_sort = SDL_CreateTextureFromSurface(ren, surface_prep_sort);

	switch (s.id) {
		case 0:
			prep_sort_plus(lanceur, 1);
			break;
		case 1:
			prep_sort_plus(lanceur, 3);
			break;
		case 2:
			prep_sort_cercle(lanceur, 3);
			break;
		case 3:
			prep_sort_plus(lanceur, s.portee);
			break;
		case 4:
			prep_sort_cercle(lanceur, s.portee);
			break;
		case 5:
			prep_sort_plus(lanceur, s.portee);
			break;
		case 6:
			prep_sort_plus(lanceur, s.portee);
			break;
		case 7:
			prep_sort_plus(lanceur, s.portee);
			break;
		case 8:
			prep_sort_plus(lanceur, s.portee);
			break;
		case 9:
			prep_sort_plus(lanceur, s.portee);
			break;
		case 10:
			prep_sort_plus(lanceur, s.portee);
			break;
		case 11:
			prep_sort_cercle(lanceur, 0);
			break;
	}
	SDL_FreeSurface(surface_prep_sort);
	SDL_DestroyTexture(texture_prep_sort);
}