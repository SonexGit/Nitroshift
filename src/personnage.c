#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"

#include <stdlib.h>
#include <string.h>

#include "personnage.h"
#include "render.h"
#include "header.h"

/* Création du personnage */
void creationPersonnage(personnage * p){
    
    printf("Veuillez saisir le pseudo du personnage : ");
    scanf("%s", p->pseudo);

    do{
        printf("Veuillez saisir la classe du personnage (DPS, Tank, Sniper, Healer) : ");
        scanf("%s", p->classe);
    }while(!(strcmp(p->classe,"DPS") == 0 || strcmp(p->classe,"Tank") == 0 || strcmp(p->classe,"Sniper") == 0 || strcmp(p->classe,"Healer") == 0));

    p->niveau = 1;
    p->paMax = 6;
    p->pmMax = 3;
    p->initiative = 100;

    if(strcmp(p->classe,"DPS") == 0){
        p->hpMax = 50;
        p->nitroMax = 100;
        p->attaque = 40;
        p->defense = 20;
    }
    else if(strcmp(p->classe,"Tank") == 0){
        p->hpMax = 100;
        p->nitroMax = 70;
        p->attaque = 15;
        p->defense = 40;
    }
    else if(strcmp(p->classe,"Sniper") == 0){
        p->hpMax = 40;
        p->nitroMax = 80;
        p->attaque = 60;
        p->defense = 15;
    }
    else if(strcmp(p->classe,"Healer") == 0){
        p->hpMax = 70;
        p->nitroMax = 200;
        p->attaque = 20;
        p->defense = 20;
    }
}

/* Accès ou non aux zones et niveaux par le personnage */
void creationAcces(){

    /* 0 = Non Accès */
    /* 1 = Accès */
    
    a1.zone1 = 1;
    a1.z1.niveau1 = 1; /* Cela signifie : Niveau 1 de la zone 1 par exemple */
    a1.z1.niveau2 = 0;
    a1.z1.niveau3 = 0;
    a1.z1.niveau4 = 0;

    a1.zone2 = 0;
    a1.z2.niveau1 = 0;
    a1.z2.niveau2 = 0; /* Cela signifie : Niveau 2 de la zone 2 par exemple */
    a1.z2.niveau3 = 0;
    a1.z2.niveau4 = 0;

    a1.zone3 = 0;
    a1.z3.niveau1 = 0;
    a1.z3.niveau2 = 0;
    a1.z3.niveau3 = 0;
    a1.z3.niveau4 = 0;

    a1.zone4 = 0;
    a1.z4.niveau1 = 0;
    a1.z4.niveau2 = 0;
    a1.z4.niveau3 = 0;
    a1.z4.niveau4 = 0;

    a1.zone5 = 0;
    a1.z5.niveau1 = 0;
    a1.z5.niveau2 = 0;
    a1.z5.niveau3 = 0;
    a1.z5.niveau4 = 0;
}

/* Affichage des statistiques du personnage */
void affichagePersonnage(personnage p){

    printf("\n--Caractéristiques de votre personnage--\n");
    printf("Pseudo : %s\n", p.pseudo);
    printf("Classe : %s\n", p.classe);
    printf("Niveau : %d\n", p.niveau);
    printf("PA : %d\n", p.paMax);
    printf("PM : %d\n", p.pmMax);
    printf("Initiative : %d\n", p.initiative);
    printf("HP : %d\n", p.hpMax);
    printf("Nitro : %d\n", p.nitroMax);
    printf("Attaque : %d\n", p.attaque);
    printf("Defense : %d\n", p.defense);
}

// Textures du personnage
void init_textures_personnage() {
	surface_perso = IMG_Load("../data/personnages/personnageTest.png");
	texture_perso = SDL_CreateTextureFromSurface(ren, surface_perso);

	int i = 0, j = 0, k = 0;

	while (i < perso_col) {
		for(; j < perso_row; j++) {
			src_perso[j].w = 30;
			src_perso[j].h = 80;
			src_perso[j].x = j * src_perso[j].w;
			src_perso[j].y = i * src_perso[j].h;
			k++;
		}
		k = 0;
		i++;
	}
}

// Dessiner le personnage sur le plateau
void dessiner_personnage(personnage p, int case_x, int case_y, cell_T plat[plateau_y][plateau_x], int sprite) {
	
	int pos_x, pos_y, img_w, img_h;
	img_w = surface_perso->w;
	img_h = surface_perso->h;
	pos_x = plat[v1.positionY][v1.positionX].pc.x - (img_w / (perso_row * 2));
	pos_y = plat[v1.positionY][v1.positionX].pc.y - img_h + 5;
	dest_perso.x = pos_x;
	dest_perso.y = pos_y;
	dest_perso.w = img_w / perso_row;
	dest_perso.h = img_h / perso_col;

	SDL_RenderCopy(ren, texture_perso, &src_perso[sprite], &dest_perso);
}

// Free général du fichier personnage.c
void free_personnage_c() {
	SDL_DestroyTexture(surface_perso);
	SDL_FreeSurface(surface_perso);
}

// Déplacements du personnage

void deplacements_personnage(int direction) {
	if (v1.pm > 0) {
		switch (direction) {
			case UP:
				sprite = STAND_UP;
				if (v1.positionY == 0 && v1.positionX == 14);
				else if (v1.positionY == 0);
				else v1.positionY--;
				v1.pm--;
				break;
			case RIGHT:
				sprite = STAND_RIGHT;
				if (v1.positionX == 14);
				else v1.positionX++;
				v1.pm--;
				break;
			case DOWN:
				sprite = STAND_DOWN;
				if (v1.positionY == 14);
				else v1.positionY++;
				v1.pm--;
				break;
			case LEFT:
				sprite = STAND_LEFT;
				if (v1.positionX == 0);
				else v1.positionX--;
				v1.pm--;
				break;
		}
	}
	else {
		printf("v1 n'a plus de pm\n");
	}
}