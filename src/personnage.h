#ifndef _PERSONNAGE_H_
#define _PERSONNAGE_H_

#include "header.h"

/* Structure du personnage */
typedef struct personnage_S {
    char * pseudo;
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
    int initiative;
    int attaque;
    int defense;
    int positionX;
    int positionY;
    int zone;
    int niveauZone;
}personnage;

/* Joueur 1 */
personnage v1;

/* Sous structure des zones*/
typedef struct zone_D {
    int niveau1;
    int niveau2;
    int niveau3;
    int niveau4;
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

// Définition des sprites
#define perso_row 4 // Combien de textures par ligne ?
#define perso_col 1 // Combien de textures par colonne ?

// Déclarations
SDL_Surface * surface_perso;
SDL_Texture * texture_perso;
SDL_Rect src_perso[perso_row*perso_col];
SDL_Rect dest_perso;

#define STAND_LEFT 0
#define STAND_UP 1
#define STAND_RIGHT 2
#define STAND_DOWN 3

/* Fonction(s) utilisée(s) */
void creationPersonnage(personnage * p);
void creationAcces();
void affichagePersonnage(personnage p);

void init_textures_personnage();
void dessiner_personnage(personnage p, int case_x, int case_y, cell_T plat[plateau_y][plateau_x], int sprite);

#endif