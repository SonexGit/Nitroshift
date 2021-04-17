#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "entite.h"
#include "render.h"
#include "header.h"

// ==============================================
// Personnage
// ==============================================

/* Création du personnage */
void creationPersonnage(){

    v1.nom = "Personnage";

    // Faire les if des cliques pour sélect
    v1.classe = "Tank";

    v1.id = 1;
    v1.equipe = ALLIES;
    v1.niveau = 1;
    v1.paMax = 6;
    v1.pmMax = 3;
    v1.experience = 0;

    if(strcmp(v1.classe,"Soldat") == 0){
        v1.hpMax = 100;
        v1.nitroMax = 100;
        v1.attaque = 30;
        v1.defense = 10;
    }
    else if(strcmp(v1.classe,"Tank") == 0){
        v1.hpMax = 200;
        v1.nitroMax = 100;
        v1.attaque = 15;
        v1.defense = 20;
    }
    else if(strcmp(v1.classe,"Sniper") == 0){
        v1.hpMax = 50;
        v1.nitroMax = 100;
        v1.attaque = 60;
        v1.defense = 2;
    }
    else if(strcmp(v1.classe,"Assassin") == 0){
        v1.hpMax = 80;
        v1.nitroMax = 100;
        v1.attaque = 60;
        v1.defense = 5;
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

    a1.zone2 = 0;
    a1.z2.niveau1 = 0;
    a1.z2.niveau2 = 0; /* Cela signifie : Niveau 2 de la zone 2 par exemple */
    a1.z2.niveau3 = 0;

    a1.zone3 = 0;
    a1.z3.niveau1 = 0;
    a1.z3.niveau2 = 0;
    a1.z3.niveau3 = 0;

    a1.zone4 = 0;
    a1.z4.niveau1 = 0;
    a1.z4.niveau2 = 0;
    a1.z4.niveau3 = 0;

    a1.zone5 = 0;
    a1.z5.niveau1 = 0;
    a1.z5.niveau2 = 0;
    a1.z5.niveau3 = 0;
}

// Textures du personnage
void init_textures_personnage() {

    if(strcmp(v1.classe,"Soldat") == 0){
        v1.surface = IMG_Load("../data/personnages/personnageDPS.png");
    }
    else if(strcmp(v1.classe,"Tank") == 0){
        v1.surface = IMG_Load("../data/personnages/personnageTank.png");
    }
    else if(strcmp(v1.classe,"Sniper") == 0){
        v1.surface = IMG_Load("../data/personnages/personnageSniper.png");
    }
    else if(strcmp(v1.classe,"Assassin") == 0){
        v1.surface = IMG_Load("../data/personnages/personnageHealer.png");
    }

	v1.texture = SDL_CreateTextureFromSurface(ren, v1.surface);

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
void dessiner_personnage(entite p, int case_x, int case_y, cell_T plat[plateau_y][plateau_x], int sprite) {
	int pos_x, pos_y, img_w, img_h;
	img_w = p.surface->w;
	img_h = p.surface->h;
	pos_x = plat[case_y][case_x].pc.x - (img_w / (perso_row * 2));
	pos_y = plat[case_y][case_x].pc.y - img_h + 5;
	dest_perso.x = pos_x;
	dest_perso.y = pos_y;
	dest_perso.w = img_w / perso_row;
	dest_perso.h = img_h / perso_col;

	SDL_RenderCopy(ren, p.texture, &src_perso[sprite], &dest_perso);
}

// Free général des fonctions personnage
void free_personnage_c() {
	SDL_DestroyTexture(v1.texture);
	SDL_FreeSurface(v1.surface);
}

// Déplacements du personnage
void deplacements_personnage(int direction) {
	/*
	printf("AVANT DEPLACEMENTS\n");
	for (int i = 0; i < plateau_x; i++) {
		for (int j = 0; j < plateau_y; j++) {
			printf("%d ", plateau[i][j].solide);
		}
		printf("\n");
	}
	*/
	if (v1.pm > 0) {
		switch (direction) {
			case UP:
				sprite = STAND_UP;
				if (!plateau[v1.positionY-1][v1.positionX].solide) {
					if (v1.positionY == 0 && v1.positionX == 14);
					else if (v1.positionY == 0);
					else {
						plateau[v1.positionY][v1.positionX].solide = 0;
						v1.positionY--;
						plateau[v1.positionY][v1.positionX].solide = 1;
					}
					v1.pm--;
				}
				break;
			case RIGHT:
				sprite = STAND_RIGHT;
				if (!plateau[v1.positionY][v1.positionX+1].solide) {
					if (v1.positionX == 14);
					else {
						plateau[v1.positionY][v1.positionX].solide = 0;
						v1.positionX++;
						plateau[v1.positionY][v1.positionX].solide = 1;
					}
					v1.pm--;
				}
				break;
			case DOWN:
				sprite = STAND_DOWN;
				if (!plateau[v1.positionY+1][v1.positionX].solide) {
					if (v1.positionY == 14);
					else { 
						plateau[v1.positionY][v1.positionX].solide = 0;
						v1.positionY++;
						plateau[v1.positionY][v1.positionX].solide = 1;
					}
					v1.pm--;
				}
				break;
			case LEFT:
				sprite = STAND_LEFT;
				if (!plateau[v1.positionY][v1.positionX-1].solide) {
					if (v1.positionX == 0);
					else {
						plateau[v1.positionY][v1.positionX].solide = 0;
						v1.positionX--;
						plateau[v1.positionY][v1.positionX].solide = 1;
					} 
					v1.pm--;
				}
				break;
		}
	}
	else {
		printf("v1 n'a plus de pm\n");
	}
	/*
	printf("APRES DEPLACEMENTS\n");
	for (int i = 0; i < plateau_x; i++) {
		for (int j = 0; j < plateau_y; j++) {
			printf("%d ", plateau[i][j].solide);
		}
		printf("\n");
	}
	*/
}

// ==============================================
// Ennemis
// ==============================================

/* Création de l'ennemi */
void creationEnnemi(){
    
    e1.nom = "Ennemi1";
    e1.id = 101;    
    e1.hpMax = 100;
    e1.nitroMax = 200;
    e1.paMax = 3;
    e1.pmMax = 3;
    e1.attaque = 30;
    e1.defense = 20;
    e1.flag = 0;
    e1.mort = 0;
    e1.equipe = ENNEMIS;

    e2.nom = "Ennemi2";
    e2.id = 102;  
    e2.hpMax = 200;
    e2.nitroMax = 100;
    e2.paMax = 6;
    e2.pmMax = 3;
    e2.attaque = 30;
    e2.defense = 20;
    e2.flag = 0;
    e2.mort = 0;
    e2.equipe = ENNEMIS;

    e3.nom = "Ennemi3";   
    e3.id = 201;
    e3.niveau = 1;
    e3.hpMax = 200;
    e3.nitroMax = 300;
    e3.paMax = 6;
    e3.pmMax = 3;
    e3.attaque = 70;
    e3.defense = 50;
    e3.flag = 0;
    e3.mort = 0;
    e3.equipe = ENNEMIS;

    e4.nom = "Ennemi4";   
    e4.id = 202;
    e4.niveau = 1;
    e4.hpMax = 200;
    e4.nitroMax = 300;
    e4.paMax = 6;
    e4.pmMax = 3;
    e4.attaque = 70;
    e4.defense = 50;
    e4.flag = 0;
    e4.mort = 0;
    e4.equipe = ENNEMIS;

    e5.nom = "Ennemi5";    
    e5.id = 301;
    e5.niveau = 1;
    e5.hpMax = 200;
    e5.nitroMax = 300;
    e5.paMax = 6;
    e5.pmMax = 3;

    e5.attaque = 70;
    e5.defense = 50;
    e5.flag = 0;
    e5.mort = 0;
    e5.equipe = ENNEMIS;

    e6.nom = "Ennemi6";   
    e6.id = 302;
    e6.niveau = 1;
    e6.hpMax = 200;
    e6.nitroMax = 300;
    e6.paMax = 6;
    e6.pmMax = 3;
    e6.attaque = 70;
    e6.defense = 50;
    e6.flag = 0;
    e6.mort = 0;
    e6.equipe = ENNEMIS;

    e7.nom = "Ennemi7";  
    e7.id = 401;
    e7.niveau = 1;
    e7.hpMax = 200;
    e7.nitroMax = 300;
    e7.paMax = 6;
    e7.pmMax = 3;
    e7.attaque = 70;
    e7.defense = 50;
    e7.flag = 0;
    e7.mort = 0;
    e7.equipe = ENNEMIS;

    e8.nom = "Ennemi8";   
    e8.id = 402;
    e8.niveau = 1;
    e8.hpMax = 200;
    e8.nitroMax = 300;
    e8.paMax = 6;
    e8.pmMax = 3;
    e8.attaque = 70;
    e8.defense = 50;
    e8.flag = 0;
    e8.mort = 0;
    e8.equipe = ENNEMIS;

    e9.nom = "Ennemi9";   
    e9.id = 501;
    e9.niveau = 1;
    e9.hpMax = 200;
    e9.nitroMax = 300;
    e9.paMax = 6;
    e9.pmMax = 3;
    e9.attaque = 70;
    e9.defense = 50;
    e9.flag = 0;
    e9.mort = 0;
    e9.equipe = ENNEMIS;

    e10.nom = "Ennemi10";  
    e10.id = 502;
    e10.niveau = 1;
    e10.hpMax = 200;
    e10.nitroMax = 300;
    e10.paMax = 6;
    e10.pmMax = 3;
    e10.attaque = 70;
    e10.defense = 50;
    e10.flag = 0;
    e10.mort = 0;
    e10.equipe = ENNEMIS;

    b1.nom = "Boss1";  
    b1.id = 100;
    b1.niveau = 1;
    b1.hpMax = 300;
    b1.nitroMax = 100;
    b1.paMax = 3;
    b1.pmMax = 3;
    b1.attaque = 45;
    b1.defense = 20;
    b1.flag = 0;
    b1.mort = 0;
    b1.equipe = ENNEMIS;

    b2.nom = "Boss2"; 
    b2.id = 200;
    b2.niveau = 1;
    b2.hpMax = 200;
    b2.paMax = 6;
    b2.pmMax = 3;
    b2.attaque = 70;
    b2.defense = 50;
    b2.flag = 0;
    b2.mort = 0;
    b2.equipe = ENNEMIS;

    b3.nom = "Boss3"; 
    b3.id = 300;
    b3.niveau = 1;
    b3.hpMax = 200;
    b3.nitroMax = 300;
    b3.paMax = 6;
    b3.pmMax = 3;
    b3.attaque = 70;
    b3.defense = 50;
    b3.flag = 0;
    b3.mort = 0;
    b3.equipe = ENNEMIS;

    b4.nom = "Boss4";
    b4.id = 400;
    b4.niveau = 1;
    b4.hpMax = 200;
    b4.nitroMax = 300;
    b4.paMax = 6;
    b4.pmMax = 3;
    b4.attaque = 70;
    b4.defense = 50;
    b4.flag = 0;
    b4.mort = 0;
    b4.equipe = ENNEMIS;

    b5.nom = "Boss5";  
    b5.id = 500;
    b5.niveau = 1;
    b5.hpMax = 200;
    b5.nitroMax = 300;
    b5.paMax = 6;
    b5.pmMax = 3;
    b5.attaque = 70;
    b5.defense = 50;
    b5.flag = 0;
    b5.mort = 0;
    b5.equipe = ENNEMIS;
}

// Textures des ennemis
void init_textures_ennemis() {
	e1.surface = IMG_Load("../data/ennemis/mobTest.png");
	e1.texture = SDL_CreateTextureFromSurface(ren, e1.surface);
	e2.surface = IMG_Load("../data/ennemis/mobTest.png");
	e2.texture = SDL_CreateTextureFromSurface(ren, e2.surface);
	b1.surface = IMG_Load("../data/ennemis/mobTest.png");
	b1.texture = SDL_CreateTextureFromSurface(ren, b1.surface);

	int i = 0, j = 0, k = 0;

	while (i < ennemi_col) {
		for(; j < ennemi_row; j++) {
			src_ennemi[j].w = 40;
			src_ennemi[j].h = 80;
			src_ennemi[j].x = j * src_ennemi[j].w;
			src_ennemi[j].y = i * src_ennemi[j].h;
			k++;
		}
		k = 0;
		i++;
	}
}

// Dessiner l'ennemi sur le plateau
void dessiner_ennemi(entite e, int case_x, int case_y, cell_T plat[plateau_y][plateau_x], int sprite) {
	
    if(e.mort == 0){
        int pos_x, pos_y, img_w, img_h;
        img_w = e.surface->w;
        img_h = e.surface->h;
        pos_x = plat[case_y][case_x].pc.x - (img_w / (ennemi_row * 2));
        pos_y = plat[case_y][case_x].pc.y - img_h + 5;
        dest_ennemi.x = pos_x;
        dest_ennemi.y = pos_y;
        dest_ennemi.w = img_w / ennemi_row;
        dest_ennemi.h = img_h / ennemi_col;

        SDL_RenderCopy(ren, e.texture, &src_ennemi[sprite], &dest_ennemi);
    }
}

// Free général des fonctions ennemis
void free_ennemi_c() {
	SDL_DestroyTexture(e1.texture);
	SDL_FreeSurface(e1.surface);
	SDL_DestroyTexture(e2.texture);
	SDL_FreeSurface(e2.surface);
	SDL_DestroyTexture(b1.texture);
	SDL_FreeSurface(b1.surface);
}

// Entités

void dessiner_entite(entite e, int case_x, int case_y, cell_T plat[plateau_y][plateau_x], int sprite) {
	if (e.equipe == ALLIES) {
		dessiner_personnage(e, case_x, case_y, plat, sprite);
	}
	else if (e.equipe == ENNEMIS) {
		dessiner_ennemi(e, case_x, case_y, plat, 0); // il faudra remplacer 0 à un moment
	}
	else {
		// Ne rien faire
	}
}

// Niveaux
void gestionNiveaux(int niv){

    switch(niv){
        case 2 :
            v1.hpMax += 20;
            v1.nitroMax += 100;
            v1.attaque += 5;
            v1.defense += 5;
            break;
        case 3 :
            v1.hpMax += 20;
            v1.nitroMax += 100;
            v1.attaque += 5;
            v1.defense += 5;
            break;
        case 4 :
            v1.hpMax += 20;
            v1.nitroMax += 100;
            v1.attaque += 5;
            v1.defense += 5;
            break;
        case 5 :
            v1.hpMax += 20;
            v1.nitroMax += 100;
            v1.attaque += 5;
            v1.defense += 5;
            break;
        case 6 :
            v1.hpMax += 20;
            v1.nitroMax += 100;
            v1.attaque += 5;
            v1.defense += 5;
            break;
        case 7 :
            v1.hpMax += 20;
            v1.nitroMax += 100;
            v1.attaque += 5;
            v1.defense += 5;
            break;
        case 8 :
            v1.hpMax += 20;
            v1.nitroMax += 100;
            v1.attaque += 5;
            v1.defense += 5;
            break;
        case 9 :
            v1.hpMax += 20;
            v1.nitroMax += 100;
            v1.attaque += 5;
            v1.defense += 5;
            break;
        case 10 :
            v1.hpMax += 20;
            v1.nitroMax += 100;
            v1.attaque += 5;
            v1.defense += 5;
            break;
        default :
            printf("Erreur du niveau...\n");
            break;
    }
}

void levelUp(){

    int maxExp[10] = {0, 100, 300, 700, 1300, 2100, 3100, 4300, 5700, 7300}; // Niveau de 1 à 10

    if(v1.experience > maxExp[v1.niveau]){
        printf("\n! LEVEL UP !\n");
        v1.niveau++;
        gestionNiveaux(v1.niveau);
        printf("Vous venez de passer niveau %i\n", v1.niveau);
        printf("Voici vos nouvelles statistiques :\n");
        printf("HP : %i\n", v1.hpMax);
        printf("Nitro : %i\n", v1.nitroMax);
        printf("Attaque : %i\n", v1.attaque);
        printf("Defense : %i\n", v1.defense);
    }
}