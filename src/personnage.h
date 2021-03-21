#ifndef _PERSONNAGE_H_
#define _PERSONNAGE_H_

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

// Déclarations
SDL_Surface * surface_perso;
SDL_Texture * texture_perso;
SDL_Rect dest_perso;

/* Fonction(s) utilisée(s) */
void creationPersonnage(personnage * p);
void creationAcces();
void affichagePersonnage(personnage p);
void dessiner_personnage();

#endif