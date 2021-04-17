#ifndef _ENTITE_H_
#define _ENTITE_H_

#include "header.h"

/* Sous structure des zones*/
typedef struct zone_D {
    int niveau1;
    int niveau2;
    int niveau3;
}zone;

/* Structure des accès ou non aux zones et niveaux */
typedef struct acces_D {
    /* Les types zones sont pour les différents niveaux */
    int zone1;
    zone z1;
    int zone2;
    zone z2;
    int zone3;
    zone z3;
    int zone4;
    zone z4;
    int zone5;
    zone z5;
}acces;

/* Liste des accès */
acces a1;

// Différentes directions (pour les sprites)
#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3

#define STAND_LEFT 0
#define STAND_UP 1
#define STAND_RIGHT 2
#define STAND_DOWN 3

// Définition des sprites
#define perso_row 4 // Combien de textures par ligne ?
#define perso_col 1 // Combien de textures par colonne ?

// Définitions des sprites
#define ennemi_row 1 // Combien de textures par ligne ?
#define ennemi_col 1 // Combien de textures par colonne ?

// Déclarations
SDL_Rect src_perso[perso_row*perso_col];
SDL_Rect dest_perso;
SDL_Rect src_ennemi[ennemi_row*ennemi_col];
SDL_Rect dest_ennemi;

// Quelle équipe ?
#define ALLIES 0
#define ENNEMIS 1

// Joueurs
entite v1;

// Ennemis 

/* Zone 1 */
entite e1;
entite e2;
/* Zone 2 */
entite e3;
entite e4;
/* Zone 3 */
entite e5;
entite e6;
/* Zone 4 */
entite e7;
entite e8;
/* Zone 5 */
entite e9;
entite e10;

// Boss
entite b1;
entite b2;
entite b3;
entite b4;
entite b5;

/* Fonction(s) utilisée(s) */
// Personnages
void creationPersonnage();
void creationAcces();

void init_textures_personnage();
void dessiner_personnage(entite p, int case_x, int case_y, cell_T plat[plateau_y][plateau_x], int sprite);
void free_personnage_c();
void deplacements_personnage(int direction);

// Ennemis
void creationEnnemi();

void init_textures_ennemis(int lev);
void dessiner_ennemi(entite e, int case_x, int case_y, cell_T plat[plateau_y][plateau_x], int sprite);
void free_ennemi_c(int lev);

// Entités
void dessiner_entite(entite e, int case_x, int case_y, cell_T plat[plateau_y][plateau_x], int sprite);

// Niveaux
void gestionNiveaux(int niv);
void levelUp();
#endif // _ENTITE_H_