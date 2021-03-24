#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"

#include <stdlib.h>
#include <string.h>

#include "entite.h"
#include "render.h"
#include "header.h"

// ==============================================
// Personnage
// ==============================================

/* Création du personnage */
void creationPersonnage(entite * p){
    
    printf("Veuillez saisir le nom du personnage : ");
    scanf("%s", p->nom);

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
void affichagePersonnage(entite p){

    printf("\n--Caractéristiques de votre personnage--\n");
    printf("Nom : %s\n", p.nom);
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
	v1.surface = IMG_Load("../data/personnages/personnageTest.png");
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
	pos_x = plat[v1.positionY][v1.positionX].pc.x - (img_w / (perso_row * 2));
	pos_y = plat[v1.positionY][v1.positionX].pc.y - img_h + 5;
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
	if (v1.pm > 0) {
		switch (direction) {
			case UP:
				sprite = STAND_UP;
				if (!plateau[v1.positionY-1][v1.positionX].solide) {
					if (v1.positionY == 0 && v1.positionX == 14);
					else if (v1.positionY == 0);
					else v1.positionY--;
					v1.pm--;
				}
				break;
			case RIGHT:
				sprite = STAND_RIGHT;
				if (!plateau[v1.positionY][v1.positionX+1].solide) {
					if (v1.positionX == 14);
					else v1.positionX++;
					v1.pm--;
				}
				break;
			case DOWN:
				sprite = STAND_DOWN;
				if (!plateau[v1.positionY+1][v1.positionX].solide) {
					if (v1.positionY == 14);
					else v1.positionY++;
					v1.pm--;
				}
				break;
			case LEFT:
				sprite = STAND_LEFT;
				if (!plateau[v1.positionY][v1.positionX-1].solide) {
					if (v1.positionX == 0);
					else v1.positionX--;
					v1.pm--;
				}
				break;
		}
	}
	else {
		printf("v1 n'a plus de pm\n");
	}
}

// ==============================================
// Ennemis
// ==============================================

/* Création de l'ennemi */
void creationEnnemi(){
    
    e1.nom = "Ennemi1";
    
    e1.niveau = 1;
    e1.hpMax = 200;
    e1.nitroMax = 300;
    e1.paMax = 6;
    e1.pmMax = 3;
    e1.initiative = 2000;
    e1.attaque = 70;
    e1.defense = 50;

    e2.nom = "Ennemi2";
    
    e2.niveau = 1;
    e2.hpMax = 200;
    e2.nitroMax = 300;
    e2.paMax = 6;
    e2.pmMax = 3;
    e2.initiative = 10;
    e2.attaque = 70;
    e2.defense = 50;

    e3.nom = "Ennemi3";
    
    e3.niveau = 1;
    e3.hpMax = 200;
    e3.nitroMax = 300;
    e3.paMax = 6;
    e3.pmMax = 3;
    e3.initiative = 40;
    e3.attaque = 70;
    e3.defense = 50;

    e4.nom = "Ennemi4";
    
    e4.niveau = 1;
    e4.hpMax = 200;
    e4.nitroMax = 300;
    e4.paMax = 6;
    e4.pmMax = 3;
    e4.initiative = 20;
    e4.attaque = 70;
    e4.defense = 50;

    e5.nom = "Ennemi5";
    
    e5.niveau = 1;
    e5.hpMax = 200;
    e5.nitroMax = 300;
    e5.paMax = 6;
    e5.pmMax = 3;
    e5.initiative = 30;
    e5.attaque = 70;
    e5.defense = 50;

    e6.nom = "Ennemi6";
    
    e6.niveau = 1;
    e6.hpMax = 200;
    e6.nitroMax = 300;
    e6.paMax = 6;
    e6.pmMax = 3;
    e6.initiative = 100;
    e6.attaque = 70;
    e6.defense = 50;

    e7.nom = "Ennemi7";
    
    e7.niveau = 1;
    e7.hpMax = 200;
    e7.nitroMax = 300;
    e7.paMax = 6;
    e7.pmMax = 3;
    e7.initiative = 100;
    e7.attaque = 70;
    e7.defense = 50;

    e8.nom = "Ennemi8";
    
    e8.niveau = 1;
    e8.hpMax = 200;
    e8.nitroMax = 300;
    e8.paMax = 6;
    e8.pmMax = 3;
    e8.initiative = 100;
    e8.attaque = 70;
    e8.defense = 50;

    e9.nom = "Ennemi9";
    
    e9.niveau = 1;
    e9.hpMax = 200;
    e9.nitroMax = 300;
    e9.paMax = 6;
    e9.pmMax = 3;
    e9.initiative = 100;
    e9.attaque = 70;
    e9.defense = 50;

    e10.nom = "Ennemi10";
    
    e10.niveau = 1;
    e10.hpMax = 200;
    e10.nitroMax = 300;
    e10.paMax = 6;
    e10.pmMax = 3;
    e10.initiative = 100;
    e10.attaque = 70;
    e10.defense = 50;

    e11.nom = "Ennemi11";
    
    e11.niveau = 1;
    e11.hpMax = 200;
    e11.nitroMax = 300;
    e11.paMax = 6;
    e11.pmMax = 3;
    e11.initiative = 100;
    e11.attaque = 70;
    e11.defense = 50;

    e12.nom = "Ennemi12";
    
    e12.niveau = 1;
    e12.hpMax = 200;
    e12.nitroMax = 300;
    e12.paMax = 6;
    e12.pmMax = 3;
    e12.initiative = 100;
    e12.attaque = 70;
    e12.defense = 50;

    e13.nom = "Ennemi13";
    
    e13.niveau = 1;
    e13.hpMax = 200;
    e13.nitroMax = 300;
    e13.paMax = 6;
    e13.pmMax = 3;
    e13.initiative = 100;
    e13.attaque = 70;
    e13.defense = 50;

    e14.nom = "Ennemi14";
    
    e14.niveau = 1;
    e14.hpMax = 200;
    e14.nitroMax = 300;
    e14.paMax = 6;
    e14.pmMax = 3;
    e14.initiative = 100;
    e14.attaque = 70;
    e14.defense = 50;

    e15.nom = "Ennemi15";
    
    e15.niveau = 1;
    e15.hpMax = 200;
    e15.nitroMax = 300;
    e15.paMax = 6;
    e15.pmMax = 3;
    e15.initiative = 100;
    e15.attaque = 70;
    e15.defense = 50;

    e16.nom = "Ennemi16";
    
    e16.niveau = 1;
    e16.hpMax = 200;
    e16.nitroMax = 300;
    e16.paMax = 6;
    e16.pmMax = 3;
    e16.initiative = 100;
    e16.attaque = 70;
    e16.defense = 50;

    e17.nom = "Ennemi17";
    
    e17.niveau = 1;
    e17.hpMax = 200;
    e17.nitroMax = 300;
    e17.paMax = 6;
    e17.pmMax = 3;
    e17.initiative = 100;
    e17.attaque = 70;
    e17.defense = 50;

    e18.nom = "Ennemi18";
    
    e18.niveau = 1;
    e18.hpMax = 200;
    e18.nitroMax = 300;
    e18.paMax = 6;
    e18.pmMax = 3;
    e18.initiative = 100;
    e18.attaque = 70;
    e18.defense = 50;

    e19.nom = "Ennemi19";
    
    e19.niveau = 1;
    e19.hpMax = 200;
    e19.nitroMax = 300;
    e19.paMax = 6;
    e19.pmMax = 3;
    e19.initiative = 100;
    e19.attaque = 70;
    e19.defense = 50;

    e20.nom = "Ennemi20";
    
    e20.niveau = 1;
    e20.hpMax = 200;
    e20.nitroMax = 300;
    e20.paMax = 6;
    e20.pmMax = 3;
    e20.initiative = 100;
    e20.attaque = 70;
    e20.defense = 50;

    b1.nom = "Boss1";
    
    b1.niveau = 1;
    b1.hpMax = 200;
    b1.nitroMax = 300;
    b1.paMax = 6;
    b1.pmMax = 3;
    b1.initiative = 100;
    b1.attaque = 70;
    b1.defense = 50;

    b2.nom = "Boss2";
    
    b2.niveau = 1;
    b2.hpMax = 200;
    b2.nitroMax = 300;
    b2.paMax = 6;
    b2.pmMax = 3;
    b2.initiative = 100;
    b2.attaque = 70;
    b2.defense = 50;

    b3.nom = "Boss3";
    
    b3.niveau = 1;
    b3.hpMax = 200;
    b3.nitroMax = 300;
    b3.paMax = 6;
    b3.pmMax = 3;
    b3.initiative = 100;
    b3.attaque = 70;
    b3.defense = 50;

    b4.nom = "Boss4";
    
    b4.niveau = 1;
    b4.hpMax = 200;
    b4.nitroMax = 300;
    b4.paMax = 6;
    b4.pmMax = 3;
    b4.initiative = 100;
    b4.attaque = 70;
    b4.defense = 50;

    b5.nom = "Boss5";
    
    b5.niveau = 1;
    b5.hpMax = 200;
    b5.nitroMax = 300;
    b5.paMax = 6;
    b5.pmMax = 3;
    b5.initiative = 100;
    b5.attaque = 70;
    b5.defense = 50;
}

/* Affichage des statistiques d'un ennemi */
void affichageEnnemi(entite e){

    printf("\n--Caractéristiques de l'ennemi--\n");
    printf("Nom : %s\n", e.nom);
    printf("Niveau : %d\n", e.niveau);
    printf("PA : %d\n", e.paMax);
    printf("PM : %d\n", e.pmMax);
    printf("Initiative : %d\n", e.initiative);
    printf("HP : %d\n", e.hpMax);
    printf("Nitro : %d\n", e.nitroMax);
    printf("Attaque : %d\n", e.attaque);
    printf("Defense : %d\n", e.defense);
}

// Textures des ennemis
void init_textures_ennemis() {
	e1.surface = IMG_Load("../data/ennemis/mobTest.png");
	e1.texture = SDL_CreateTextureFromSurface(ren, e1.surface);
	e2.surface = IMG_Load("../data/ennemis/mobTest.png");
	e2.texture = SDL_CreateTextureFromSurface(ren, e2.surface);

	int i = 0, j = 0, k = 0;

	while (i < ennemi_col) {
		for(; j < ennemi_row; j++) {
			src_ennemi[j].w = 40;
			src_ennemi[j].h = 40;
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

// Free général des fonctions ennemis
void free_ennemi_c() {
	SDL_DestroyTexture(e1.texture);
	SDL_FreeSurface(e1.surface);
}