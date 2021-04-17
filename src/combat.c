#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#include "render.h"
#include "header.h"
#include "entite.h"
#include "initialisation.h"
#include "combat.h"
#include "sorts.h"

int tourTermine;

void boutonPasserTour(){

    SDL_Surface *imageBoutonPasserTour = NULL;
    SDL_Texture *textureBoutonPasserTour = NULL;

    imageBoutonPasserTour=IMG_Load("../data/combat/passerTour.png");

    if(imageBoutonPasserTour == NULL){
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
    }

    textureBoutonPasserTour = SDL_CreateTextureFromSurface(ren, imageBoutonPasserTour);

    /* Libération de la surface car on en a plus besoin */
    SDL_FreeSurface(imageBoutonPasserTour);

    if(textureBoutonPasserTour == NULL){
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
    }
    
    // L'image est chargée en mémoire


    /* Chargement de la texture */
    SDL_Rect rectangleBoutonPasserTour;

    if(SDL_QueryTexture(textureBoutonPasserTour, NULL, NULL, &rectangleBoutonPasserTour.w, &rectangleBoutonPasserTour.h) != 0){
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
    }
    /* Positionnement du bouton */
    rectangleBoutonPasserTour.x = 1150;
    rectangleBoutonPasserTour.y = 750;

    /* Affichage de l'image */
    if(SDL_RenderCopy(ren, textureBoutonPasserTour, NULL, &rectangleBoutonPasserTour) != 0){
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
    }
    SDL_DestroyTexture(textureBoutonPasserTour);
}

void statsMaximum(entite * e){

    e->pm = e->pmMax;
    e->pa = e->paMax;
    e->nitro = e->nitroMax;
}

int recherchePorteeSort(entite * e){

    switch(e->id){
        case 101 :
            return sortsEnnemi1[0].portee;
            break;
        case 102 :
            return sortsEnnemi2[0].portee;
            break;
        case 201 :
            return sortsEnnemi3[0].portee;
            break;
        case 202 :
            return sortsEnnemi4[0].portee;
            break;
        case 301 :
            return sortsEnnemi5[0].portee;
            break;
        case 302 :
            return sortsEnnemi6[0].portee;
            break;
        case 401 :
            return sortsEnnemi7[0].portee;
            break;
        case 402 :
            return sortsEnnemi8[0].portee;
            break;
        case 501 :
            return sortsEnnemi9[0].portee;
            break;
        case 502 :
            return sortsEnnemi10[0].portee;
            break;
    }
}

int rechercheDegatSort(entite * e){

    switch(e->id){
        case 101 :
            return sortsEnnemi1[0].degatsMin;
            break;
        case 102 :
            return sortsEnnemi2[0].degatsMin;
            break;
        case 201 :
            return sortsEnnemi3[0].degatsMin;
            break;
        case 202 :
            return sortsEnnemi4[0].degatsMin;
            break;
        case 301 :
            return sortsEnnemi5[0].degatsMin;
            break;
        case 302 :
            return sortsEnnemi6[0].degatsMin;
            break;
        case 401 :
            return sortsEnnemi7[0].degatsMin;
            break;
        case 402 :
            return sortsEnnemi8[0].degatsMin;
            break;
        case 501 :
            return sortsEnnemi9[0].degatsMin;
            break;
        case 502 :
            return sortsEnnemi10[0].degatsMin;
            break;
    }
}

int rechercheCoutNitroSort(entite * e){

    switch(e->id){
        case 101 :
            return sortsEnnemi1[0].coutNitro;
            break;
        case 102 :
            return sortsEnnemi2[0].coutNitro;
            break;
        case 201 :
            return sortsEnnemi3[0].coutNitro;
            break;
        case 202 :
            return sortsEnnemi4[0].coutNitro;
            break;
        case 301 :
            return sortsEnnemi5[0].coutNitro;
            break;
        case 302 :
            return sortsEnnemi6[0].coutNitro;
            break;
        case 401 :
            return sortsEnnemi7[0].coutNitro;
            break;
        case 402 :
            return sortsEnnemi8[0].coutNitro;
            break;
        case 501 :
            return sortsEnnemi9[0].coutNitro;
            break;
        case 502 :
            return sortsEnnemi10[0].coutNitro;
            break;
    }
}

int rechercheCoutPaBoost(entite * e){

    switch(e->id){
        case 101 :
            return sortsEnnemi1[1].coutPA;
            break;
        case 102 :
            return sortsEnnemi2[1].coutPA;
            break;
        case 201 :
            return sortsEnnemi3[1].coutPA;
            break;
        case 202 :
            return sortsEnnemi4[1].coutPA;
            break;
        case 301 :
            return sortsEnnemi5[1].coutPA;
            break;
        case 302 :
            return sortsEnnemi6[1].coutPA;
            break;
        case 401 :
            return sortsEnnemi7[1].coutPA;
            break;
        case 402 :
            return sortsEnnemi8[1].coutPA;
            break;
        case 501 :
            return sortsEnnemi9[1].coutPA;
            break;
        case 502 :
            return sortsEnnemi10[1].coutPA;
            break;
    }    
}

int rechercheRelanceBoost(entite * e){

    switch(e->id){
        case 101 :
            return sortsEnnemi1[1].relance;
            break;
        case 102 :
            return sortsEnnemi2[1].relance;
            break;
        case 201 :
            return sortsEnnemi3[1].relance;
            break;
        case 202 :
            return sortsEnnemi4[1].relance;
            break;
        case 301 :
            return sortsEnnemi5[1].relance;
            break;
        case 302 :
            return sortsEnnemi6[1].relance;
            break;
        case 401 :
            return sortsEnnemi7[1].relance;
            break;
        case 402 :
            return sortsEnnemi8[1].relance;
            break;
        case 501 :
            return sortsEnnemi9[1].relance;
            break;
        case 502 :
            return sortsEnnemi10[1].relance;
            break;
    }    
}

int boostEnnemi(entite * e){

    int cout;

    cout = rechercheCoutPaBoost(e);

    if(e->pa - cout >= 0){
        switch(e->id){
            case 101 :
                if(e->relanceBoost == 1){
                    e->nitro += sortsEnnemi1[1].degatsMin; /* On ajoute la nitro du boost */
                    printf("Boost de %s : +%i\n", e->nom, sortsEnnemi1[1].degatsMin);
                    e->pa -= 3; /* On retire 3 PA car c'est le coût d'un boost */
                    printf("PA restant : %i\n", e->pa);
                    printf("Nitro restante : %i\n", e->nitro);
                    e->relanceBoost = 0;
                    e->tempsRelance = rechercheRelanceBoost(e);         
                    return 1;
                    break;
                }
                return 0;
                break;
            case 102 :
                if(e->relanceBoost == 1){
                    e->pm += sortsEnnemi2[1].degatsMin; /* On ajoute les PM du boost */
                    printf("Boost de %s : +%i\n", e->nom, sortsEnnemi2[1].degatsMin);
                    e->pa -= 3; /* On retire 3 PA car c'est le coût d'un boost */
                    printf("PA restant : %i\n", e->pa);
                    printf("PM restant : %i\n", e->pm);
                    e->relanceBoost = 0;
                    e->tempsRelance = rechercheRelanceBoost(e);            
                    return 1;
                    break;
                }
                return 0;
                break;
            case 201 :
                return 0;
                break;
            case 202 :
                return 0;
                break;
            case 301 :
                return 0;
                break;
            case 302 :
                return 0;
                break;
            case 401 :
                return 0;
                break;
            case 402 :
                return 0;
                break;
            case 501 :
                return 0;
                break;
            case 502 :
                return 0;
                break;
        }
    }
}

void passerTour(){

}

void attaqueEnnemi(entite * e){

    int nbPO, i;
    int arret = 0;

    if(e->positionX != v1.positionX && e->positionY != v1.positionY){
        boostEnnemi(e);
    }
    else if(e->positionX == v1.positionX){ /* Même colonne */
        if(v1.positionY - e->positionY > 0){ /* Le personnage est en bas donc il va vérifier si il a la PO déjà pour attaquer */
            nbPO = v1.positionY - e->positionY;
            if(nbPO == 1){ /* En priorité l'ennemi va taper au corps à corps si il y a un PO d'écart c'est qu'ils sont collés donc pas besoin de check */
                e->flag = 1;
                while(e->pa - 3 >= 0){ /* On vérifie que si on enlève 3 PA on est toujours à 0 ou + */
                    v1.hp -= (e->attaque - v1.defense); /* On retire les dégâts de l'ennemi du corps à corps aux HP du personnage */
                    printf("Attaque au corps a corps de %s : %i\n", e->nom, e->attaque);
                    e->pa -= 3; /* On retire 3 PA car c'est le coût d'une attaque au corps à corps */
                    printf("Points de vies restant du personnage : %i\n", v1.hp);
                    if(v1.hp <= 0){
                        printf("%s est mort.\n", v1.nom);
                        exit(EXIT_SUCCESS); // Remplacer ce exit par un renvoi au menu principal (avec le shop et tout)
                    }
                }
            }
            else{
                e->flag = 0;
                if(boostEnnemi(e));
                if(nbPO <= recherchePorteeSort(e)){
                    for(i = 1; nbPO > 1 && arret == 0; i++, nbPO--){ /* ATTENTION : nbPO est initialisé à 1 car il faut compter la case du personnage qui est solide */
                        if((plateau[e->positionY+i][e->positionX].solide)){ /* Case solide en bas */
                            arret = 1;
                        }
                    }
                    if(arret == 0){
                        while(e->nitro - rechercheCoutNitroSort(e) >= 0){
                            v1.hp -= rechercheDegatSort(e); /* On retire les dégâts du sort de l'ennemi aux HP du personnage */
                            printf("Attaque avec sort de %s : %i\n", e->nom, rechercheDegatSort(e));
                            e->nitro -= rechercheCoutNitroSort(e); /* On retire le coût du sort en nitro */
                            printf("Points de vies restant du personnage : %i\n", v1.hp);
                            if(v1.hp <= 0){
                                printf("%s est mort.\n", v1.nom);
                                exit(EXIT_SUCCESS); // Remplacer ce exit par un renvoi au menu principal (avec le shop et tout)
                            }
                        }
                    }
                }         
            }
        }
        else{ /* Le personnage est en haut donc il va vérifier si il a la PO déjà pour attaquer */
            nbPO = e->positionY - v1.positionY;
            if(nbPO == 1){ /* En priorité l'ennemi va taper au corps à corps si il y a un PO d'écart c'est qu'ils sont collés donc pas besoin de check */
                e->flag = 1;
                while(e->pa - 3 >= 0){ /* On vérifie que si on enlève 3 PA on est toujours à 0 ou + */
                    v1.hp -= (e->attaque - v1.defense); /* On retire les dégâts de l'ennemi du corps à corps aux HP du personnage */
                    printf("Attaque au corps a corps de %s : %i\n", e->nom, e->attaque);
                    e->pa -= 3; /* On retire 3 PA car c'est le coût d'une attaque au corps à corps */
                    printf("Points de vies restant du personnage : %i\n", v1.hp);
                    if(v1.hp <= 0){
                        printf("%s est mort.\n", v1.nom);
                        exit(EXIT_SUCCESS); // Remplacer ce exit par un renvoi au menu principal (avec le shop et tout)
                    }
                }
            }
            else{
                e->flag = 0;
                if(boostEnnemi(e));
                if(nbPO <= recherchePorteeSort(e)){
                    for(i = 1; nbPO > 1 && arret == 0; i++, nbPO--){ /* ATTENTION : nbPO est initialisé à 1 car il faut compter la case du personnage qui est solide */
                        if((plateau[e->positionY-i][e->positionX].solide)){ /* Case solide en haut */
                            arret = 1;
                        }
                    }
                    if(arret == 0){
                        while(e->nitro - rechercheCoutNitroSort(e) >= 0){
                            v1.hp -= rechercheDegatSort(e); /* On retire les dégâts du sort de l'ennemi aux HP du personnage */
                            printf("Attaque avec sort de %s : %i\n", e->nom, rechercheDegatSort(e));
                            e->nitro -= rechercheCoutNitroSort(e); /* On retire le coût du sort en nitro */
                            printf("Points de vies restant du personnage : %i\n", v1.hp);
                            if(v1.hp <= 0){
                                printf("%s est mort.\n", v1.nom);
                                exit(EXIT_SUCCESS); // Remplacer ce exit par un renvoi au menu principal (avec le shop et tout)
                            }
                        }
                    }
                }           
            }
        }
    }
    else if(e->positionY == v1.positionY){ /* Même ligne */
        if(v1.positionX - e->positionX > 0){ /* Le personnage est à droite donc il va vérifier si il a la PO déjà pour attaquer */
            nbPO = v1.positionX - e->positionX;
            if(nbPO == 1){ /* En priorité l'ennemi va taper au corps à corps si il y a un PO d'écart c'est qu'ils sont collés donc pas besoin de check */
                e->flag = 1;
                while(e->pa - 3 >= 0){ /* On vérifie que si on enlève 3 PA on est toujours à 0 ou + */
                    v1.hp -= (e->attaque - v1.defense); /* On retire les dégâts de l'ennemi du corps à corps aux HP du personnage */
                    printf("Attaque au corps a corps de %s : %i\n", e->nom, e->attaque);
                    e->pa -= 3; /* On retire 3 PA car c'est le coût d'une attaque au corps à corps */
                    printf("Points de vies restant du personnage : %i\n", v1.hp);
                    if(v1.hp <= 0){
                        printf("%s est mort.\n", v1.nom);
                        exit(EXIT_SUCCESS); // Remplacer ce exit par un renvoi au menu principal (avec le shop et tout)
                    }
                }
            }
            else{
                e->flag = 0;
                if(boostEnnemi(e));
                if(nbPO <= recherchePorteeSort(e)){
                    for(i = 1; nbPO > 1 && arret == 0; i++, nbPO--){ /* ATTENTION : nbPO est initialisé à 1 car il faut compter la case du personnage qui est solide */
                        if((plateau[e->positionY][e->positionX+i].solide)){ /* Case solide à droite */
                            arret = 1;
                        }
                    }
                    if(arret == 0){
                        while(e->nitro - rechercheCoutNitroSort(e) >= 0){
                            v1.hp -= rechercheDegatSort(e); /* On retire les dégâts du sort de l'ennemi aux HP du personnage */
                            printf("Attaque avec sort de %s : %i\n", e->nom, rechercheDegatSort(e));
                            e->nitro -= rechercheCoutNitroSort(e); /* On retire le coût du sort en nitro */
                            printf("Points de vies restant du personnage : %i\n", v1.hp);
                            if(v1.hp <= 0){
                                printf("%s est mort.\n", v1.nom);
                                exit(EXIT_SUCCESS); // Remplacer ce exit par un renvoi au menu principal (avec le shop et tout)
                            }
                        }
                    }
                }           
            }
        }
        else{ /* Le personnage est à gauche donc il va vérifier si il a la PO déjà pour attaquer */
            nbPO = e->positionX - v1.positionX;
            if(nbPO == 1){ /* En priorité l'ennemi va taper au corps à corps si il y a un PO d'écart c'est qu'ils sont collés donc pas besoin de check */
                e->flag = 1;
                while(e->pa - 3 >= 0){ /* On vérifie que si on enlève 3 PA on est toujours à 0 ou + */
                    v1.hp -= (e->attaque - v1.defense); /* On retire les dégâts de l'ennemi du corps à corps aux HP du personnage */
                    printf("Attaque au corps a corps de %s : %i\n", e->nom, e->attaque);
                    e->pa -= 3; /* On retire 3 PA car c'est le coût d'une attaque au corps à corps */
                    printf("Points de vies restant du personnage : %i\n", v1.hp);
                    if(v1.hp <= 0){
                        printf("%s est mort.\n", v1.nom);
                        exit(EXIT_SUCCESS); // Remplacer ce exit par un renvoi au menu principal (avec le shop et tout)
                    }
                }
            }
            else{
                e->flag = 0;
                if(boostEnnemi(e));
                if(nbPO <= recherchePorteeSort(e)){
                    for(i = 1; nbPO > 1 && arret == 0; i++, nbPO--){ /* ATTENTION : nbPO est initialisé à 1 car il faut compter la case du personnage qui est solide */
                        if((plateau[e->positionY][e->positionX-i].solide)){ /* Case solide à gauche */
                            arret = 1;
                        }
                    }
                    if(arret == 0){
                        while(e->nitro - rechercheCoutNitroSort(e) >= 0){
                            v1.hp -= rechercheDegatSort(e); /* On retire les dégâts du sort de l'ennemi aux HP du personnage */
                            printf("Attaque avec sort de %s : %i\n", e->nom, rechercheDegatSort(e));
                            e->nitro -= rechercheCoutNitroSort(e); /* On retire le coût du sort en nitro */
                            printf("Points de vies restant du personnage : %i\n", v1.hp);
                            if(v1.hp <= 0){
                                printf("%s est mort.\n", v1.nom);
                                exit(EXIT_SUCCESS); // Remplacer ce exit par un renvoi au menu principal (avec le shop et tout)
                            }
                        }
                    }
                }           
            }
        }
    }
}

void iaEnnemi(entite * e){

    int boss, ligne, colonne, comparaisonLigne, comparaisonColonne;

    attaqueEnnemi(e);
    if(e->positionX == v1.positionX && e->flag == 0){ /* Même colonne */
        if(v1.positionY - e->positionY > 0){ /* Ennemi doit descendre */
            if(!(plateau[e->positionY+1][e->positionX].solide)){ /* Case non solide en bas */
                e->positionY++;
                e->pm--;
                attaqueEnnemi(e);
            }
            else{ /* Case solide */
                if(!(plateau[e->positionY][e->positionX-1].solide)){ /* Case non solide à gauche */
                    e->positionX--;
                    e->pm--;
                    attaqueEnnemi(e);                      
                }
                else{ /* Case solide donc il va à droite*/
                    e->positionX++;
                    e->pm--;
                    attaqueEnnemi(e);
                }
            }
        }
        else{ /* Ennemi doit monter */
            if(!(plateau[e->positionY-1][e->positionX].solide)){ /* Case non solide en haut */
                e->positionY--;
                e->pm--;
                attaqueEnnemi(e);
            }
            else{ /* Case solide */
                if(!(plateau[e->positionY][e->positionX-1].solide)){ /* Case non solide à gauche */
                    e->positionX--;
                    e->pm--;
                    attaqueEnnemi(e);                     
                }
                else{ /* Case solide donc il va à droite*/
                    e->positionX++;
                    e->pm--;
                    attaqueEnnemi(e);   
                }
            }
        }
    }
    else if(e->positionY == v1.positionY && e->flag == 0){ /* Même ligne */
        if(v1.positionX - e->positionX > 0){ /* Ennemi doit aller à droite */
            if(!(plateau[e->positionY][e->positionX+1].solide)){ /* Case non solide à droite */
                e->positionX++;
                e->pm--;
                attaqueEnnemi(e);
            }
            else{ /* Case solide */
                if(!(plateau[e->positionY-1][e->positionX].solide)){ /* Case non solide en haut */
                    e->positionY--;
                    e->pm--;
                    attaqueEnnemi(e);                     
                }
                else{ /* Case solide donc il va en bas*/
                    e->positionY++;
                    e->pm--;
                    attaqueEnnemi(e);   
                }
            }
        }
        else{ /* Ennemi doit aller à gauche */
            if(!(plateau[e->positionY][e->positionX-1].solide)){ /* Case non solide à gauche */
                e->positionX--;
                e->pm--;
                attaqueEnnemi(e);
            }
            else{ /* Case solide */
                if(!(plateau[e->positionY-1][e->positionX].solide)){ /* Case non solide en haut */
                    e->positionY--;
                    e->pm--;
                    attaqueEnnemi(e);                     
                }
                else{ /* Case solide donc il va en bas*/
                    e->positionY++;
                    e->pm--;
                    attaqueEnnemi(e); 
                }
            }
        }
    }
    else{ /* Aucun des deux */
        if(e->positionX != v1.positionX && e->positionY != v1.positionY){

            e->flag = 0;

            // ---------------------------------------------------------

            ligne = v1.positionY - e->positionY; // 6 - 12
            colonne = v1.positionX - e->positionX; // 8 - 7
            if(ligne >= 0){
                comparaisonLigne = ligne;
            }
            else{
                comparaisonLigne = e->positionY - v1.positionY;
            }

            if(colonne >= 0){
                comparaisonColonne = colonne;
            }
            else{
                comparaisonColonne = e->positionX - v1.positionX;
            }

            // ---------------------------------------------------------

            attaqueEnnemi(e);
            if(comparaisonLigne >= comparaisonColonne){ /* Ennemi va se mettre sur la même colonne en premier (car moins loin ou égal sans compter les obstacles) */
                if(v1.positionX - e->positionX > 0){ /* Ennemi doit aller à droite */
                    if(!(plateau[e->positionY][e->positionX+1].solide)){ /* Case non solide à droite */
                        attaqueEnnemi(e);
                        e->positionX++;
                        e->pm--;
                        attaqueEnnemi(e); 
                    }
                    else{ /* Case solide */
                        if(!(plateau[e->positionY-1][e->positionX].solide)){ /* Case non solide en haut */
                            attaqueEnnemi(e);
                            e->positionY--;
                            e->pm--;
                            attaqueEnnemi(e);                        
                        }  
                        else{ /* Case solide donc il va en bas*/
                            attaqueEnnemi(e);
                            e->positionY++;
                            e->pm--;
                            attaqueEnnemi(e);    
                        }
                    }
                }
                else{ /* Ennemi doit aller à gauche */
                    if(!(plateau[e->positionY][e->positionX-1].solide)){ /* Case non solide en bas */
                        attaqueEnnemi(e);
                        e->positionX--;
                        e->pm--;
                        attaqueEnnemi(e); 
                    }
                    else{ /* Case solide */
                        if(!(plateau[e->positionY-1][e->positionX].solide)){ /* Case non solide en haut */
                            attaqueEnnemi(e);
                            e->positionY--;
                            e->pm--;
                            attaqueEnnemi(e);                      
                        }
                        else{ /* Case solide donc il va en bas*/
                            attaqueEnnemi(e);
                            e->positionY++;
                            e->pm--;
                            attaqueEnnemi(e);
                        }
                    }
                }
            }
            else{ /* Ennemi va se mettre sur la même ligne en premier (car moins loin sans compter les obstacles) */
                if(v1.positionY - e->positionY > 0){ /* Ennemi doit descendre */
                    if(!(plateau[e->positionY+1][e->positionX].solide)){ /* Case non solide en bas */
                        attaqueEnnemi(e);
                        e->positionY++;
                        e->pm--;
                        attaqueEnnemi(e);
                    }
                    else{ /* Case solide */
                        if(!(plateau[e->positionY][e->positionX-1].solide)){ /* Case non solide à gauche */
                            attaqueEnnemi(e);
                            e->positionX--;
                            e->pm--;
                            attaqueEnnemi(e);                     
                        }
                        else{ /* Case solide donc il va à droite*/
                            attaqueEnnemi(e);
                            e->positionX++;
                            e->pm--;
                            attaqueEnnemi(e);
                        }
                    }
                }
                else{ /* Ennemi doit monter */
                    if(!(plateau[e->positionY-1][e->positionX].solide)){ /* Case non solide en haut */
                        attaqueEnnemi(e);
                        e->positionY--;
                        e->pm--;
                        attaqueEnnemi(e); 
                    }
                    else{ /* Case solide */
                        if(!(plateau[e->positionY][e->positionX-1].solide)){ /* Case non solide à gauche */
                            attaqueEnnemi(e);
                            e->positionX--;
                            e->pm--;
                            attaqueEnnemi(e);                       
                        }
                        else{ /* Case solide donc il va à droite*/
                            attaqueEnnemi(e);
                            e->positionX++;
                            e->pm--;
                            attaqueEnnemi(e);
                        }
                    }
                }
            }
        }
    }
    if(e->flag == 1){
        e->pm--;
    }
}    

void actionEnnemi(entite * e){

    int tempsActuel;

    tempsActuel = SDL_GetTicks();

    if(e->mort == 0){
        if(e->pm > 0){
            if(tempsActuel - tempsDebutPlateau > 1000){
                iaEnnemi(e);
                tempsDebutPlateau = SDL_GetTicks();
            }
        }
        else{
            tourTermine = 1;
        }
    }
}

void update_barre_vie() {

	// Initialisation des polices nécessaires
	TTF_Font * font = TTF_OpenFont("../data/police/Roboto-BlackItalic.ttf", 32);

	SDL_Color color_white = {255, 255, 255, 255};

	SDL_Surface * surface_vie = IMG_Load("../data/combat/health.png");
	SDL_Surface * surface_vie_fond = IMG_Load("../data/combat/health_bg.png");
	SDL_Texture * texture_vie = SDL_CreateTextureFromSurface(ren, surface_vie);
	SDL_Texture * texture_vie_fond = SDL_CreateTextureFromSurface(ren, surface_vie_fond);

	float percent_vie_restante = (float)v1.hp / (float)v1.hpMax;
	percent_vie_restante = roundf(percent_vie_restante * 100) / 100;
	float percent_vie_perdue = 1 - percent_vie_restante;

	srcrect_vie.x = 0;
	srcrect_vie.y = 164 * percent_vie_perdue;
	srcrect_vie.w = 184;
	srcrect_vie.h = 164 * percent_vie_restante;

	dstrect_vie.x = 200;
	dstrect_vie.y = 700 + 164 * percent_vie_perdue;
	dstrect_vie.w = 184;
	dstrect_vie.h = 164 * percent_vie_restante;

	dstrect_vie_fond.x = 200;
	dstrect_vie_fond.y = 700;
	dstrect_vie_fond.w = 184;
	dstrect_vie_fond.h = 164;

	int longueur = snprintf(NULL, 0, "%d/%d", v1.hp, v1.hpMax);
	char * hp_texte = malloc(sizeof(char) * longueur + 1);
	snprintf(hp_texte, longueur + 1, "%d/%d", v1.hp, v1.hpMax);
	SDL_Surface * surface_vie_texte = TTF_RenderText_Blended(font, hp_texte, color_white);
	SDL_Texture * texture_vie_texte = SDL_CreateTextureFromSurface(ren, surface_vie_texte);

	int temp_w, temp_h;
	SDL_QueryTexture(texture_vie_texte, NULL, NULL, &temp_w, &temp_h);

	dstrect_vie_texte.x = dstrect_vie_fond.x + dstrect_vie_fond.w / 2 - temp_w / 2;
	dstrect_vie_texte.y = dstrect_vie_fond.y + dstrect_vie_fond.h / 2 - temp_h / 2;
	dstrect_vie_texte.w = temp_w;
	dstrect_vie_texte.h = temp_h;

	SDL_RenderCopy(ren, texture_vie_fond, NULL, &dstrect_vie_fond);
	SDL_RenderCopy(ren, texture_vie, &srcrect_vie, &dstrect_vie);
	SDL_RenderCopy(ren, texture_vie_texte, NULL, &dstrect_vie_texte);

	free(hp_texte);
    SDL_FreeSurface(surface_vie);
    SDL_FreeSurface(surface_vie_fond);
    SDL_DestroyTexture(texture_vie);
    SDL_DestroyTexture(texture_vie_fond);
    SDL_FreeSurface(surface_vie_texte);
    SDL_DestroyTexture(texture_vie_texte);
	TTF_CloseFont(font);
}

void update_barre_nitro() {

	// Initialisation des polices nécessaires
	TTF_Font * font = TTF_OpenFont("../data/police/Roboto-BlackItalic.ttf", 32);

	SDL_Color color_white = {255, 255, 255, 255};

	SDL_Surface * surface_nitro = IMG_Load("../data/combat/nitro.png");
	SDL_Surface * surface_nitro_fond = IMG_Load("../data/combat/nitro_bg.png");
	SDL_Texture * texture_nitro = SDL_CreateTextureFromSurface(ren, surface_nitro);
	SDL_Texture * texture_nitro_fond = SDL_CreateTextureFromSurface(ren, surface_nitro_fond);

	float percent_nitro_restante = (float)v1.nitro / (float)v1.nitroMax;
	percent_nitro_restante = roundf(percent_nitro_restante * 100) / 100;
	float percent_nitro_perdue = 1 - percent_nitro_restante;

	srcrect_nitro.x = 0;
	srcrect_nitro.y = 164 * percent_nitro_perdue;
	srcrect_nitro.w = 184;
	srcrect_nitro.h = 164 * percent_nitro_restante;

	dstrect_nitro.x = 400;
	dstrect_nitro.y = 700 + 164 * percent_nitro_perdue;
	dstrect_nitro.w = 184;
	dstrect_nitro.h = 164 * percent_nitro_restante;

	dstrect_nitro_fond.x = 400;
	dstrect_nitro_fond.y = 700;
	dstrect_nitro_fond.w = 184;
	dstrect_nitro_fond.h = 164;

	int longueur = snprintf(NULL, 0, "%d/%d", v1.nitro, v1.nitroMax);
	char * nitro_texte = malloc(sizeof(char) * longueur + 1);
	snprintf(nitro_texte, longueur + 1, "%d/%d", v1.nitro, v1.nitroMax);
	SDL_Surface * surface_nitro_texte = TTF_RenderText_Blended(font, nitro_texte, color_white);
	SDL_Texture * texture_nitro_texte = SDL_CreateTextureFromSurface(ren, surface_nitro_texte);

	int temp_w, temp_h;
	SDL_QueryTexture(texture_nitro_texte, NULL, NULL, &temp_w, &temp_h);

	dstrect_nitro_texte.x = dstrect_nitro_fond.x + dstrect_nitro_fond.w / 2 - temp_w / 2;
	dstrect_nitro_texte.y = dstrect_nitro_fond.y + dstrect_nitro_fond.h / 2 - temp_h / 2;
	dstrect_nitro_texte.w = temp_w;
	dstrect_nitro_texte.h = temp_h;

	SDL_RenderCopy(ren, texture_nitro_fond, NULL, &dstrect_nitro_fond);
	SDL_RenderCopy(ren, texture_nitro, &srcrect_nitro, &dstrect_nitro);
	SDL_RenderCopy(ren, texture_nitro_texte, NULL, &dstrect_nitro_texte);

	free(nitro_texte);
    SDL_FreeSurface(surface_nitro);
    SDL_FreeSurface(surface_nitro_fond);
    SDL_DestroyTexture(texture_nitro);
    SDL_DestroyTexture(texture_nitro_fond);
    SDL_FreeSurface(surface_nitro_texte);
    SDL_DestroyTexture(texture_nitro_texte);
	TTF_CloseFont(font);
}

void affichage_infos_ennemi(int cible_x, int cible_y) {
	TTF_Font * font = TTF_OpenFont("../data/police/Roboto-Italic.ttf", 16);

	SDL_Color color_white = {255, 255, 255, 255};

	entite ennemi = plateau[cible_y][cible_x].e;

	int longueur = snprintf(NULL, 0, "%d/%d", ennemi.hp, ennemi.hpMax);
	char * vie_texte = malloc(sizeof(char) * longueur + 1);
	snprintf(vie_texte, longueur + 1, "%d/%d", ennemi.hp, ennemi.hpMax);
	SDL_Surface * surface_vie_texte = TTF_RenderText_Blended(font, vie_texte, color_white);
	SDL_Texture * texture_vie_texte = SDL_CreateTextureFromSurface(ren, surface_vie_texte);

	int temp_w, temp_h;
	SDL_QueryTexture(texture_vie_texte, NULL, NULL, &temp_w, &temp_h);

	SDL_Rect dstrect_vie_ennemi_texte;
	dstrect_vie_ennemi_texte.x = plateau[cible_y][cible_x].pc.x - temp_w / 2;
	dstrect_vie_ennemi_texte.y = plateau[cible_y][cible_x].pc.y - 100;
	dstrect_vie_ennemi_texte.h = temp_h;
	dstrect_vie_ennemi_texte.w = temp_w;

	SDL_RenderCopy(ren, texture_vie_texte, NULL, &dstrect_vie_ennemi_texte);

	free(vie_texte);
    SDL_FreeSurface(surface_vie_texte);
    SDL_DestroyTexture(texture_vie_texte);
	TTF_CloseFont(font);
}

void init_interface_combat() {
	sur_ennemi_x = -1, sur_ennemi_y = -1;
}

void update_interface_combat() {
	update_barre_vie();
    update_barre_nitro();
	if (sur_ennemi_x != -1 && sur_ennemi_y != -1) {
		affichage_infos_ennemi(sur_ennemi_x, sur_ennemi_y);
	}
}

void deroulementCombat(int level){
    
    tourTermine = 0;
    int money, exp;

    switch(level){
        case 1 :
            if(e1.mort == 0 && e2.mort == 0){
                actionEnnemi(&e1);
                if(tourTermine == 1){
                    actionEnnemi(&e2);
                    if(e2.pm <= 0){
                        if(e1.tempsRelance > 0){
                            e1.tempsRelance--;
                        }
                        else{
                            e1.relanceBoost = 1;
                        }
                        if(e2.tempsRelance > 0){
                            e2.tempsRelance--;
                        }
                        else{
                            e2.relanceBoost = 1;
                        }
                        statsMaximum(&e1);
                        statsMaximum(&e2);
                        statsMaximum(&v1);
                        v1.passerTour = 0;
                        finTempsAllie = 0;
                    }
                }
            }
            else if(e1.mort == 1 && e2.mort == 0){
                actionEnnemi(&e2);
                if(e2.pm <= 0){
                    if(e2.tempsRelance > 0){
                        e2.tempsRelance--;
                    }
                    else{
                        e2.relanceBoost = 1;
                    }
                    statsMaximum(&e2);
                    statsMaximum(&v1);
                    v1.passerTour = 0;
                    finTempsAllie = 0;
                }               
            }
            else if(e1.mort == 0 && e2.mort == 1){
                actionEnnemi(&e1);
                if(e1.pm <= 0){
                    if(e1.tempsRelance > 0){
                        e1.tempsRelance--;
                    }
                    else{
                        e1.relanceBoost = 1;
                    }
                    statsMaximum(&e1);
                    statsMaximum(&v1);
                    v1.passerTour = 0;
                    finTempsAllie = 0;
                }          
            }
            else{
                printf("\nBravo vous avez gagne le niveau %i !\n", level);
                srand(time(NULL));
                money = rand() % 40 + 10;
                printf("Vous avez remporte %i nitroDollars.\n", money);
                printf("[%i --> ", v1.nitroDollars);
                v1.nitroDollars += money;
                printf("%i]\n", v1.nitroDollars);
                exp = rand() % 100 + 90;
                printf("Vous avez remporte %i points d'experiences.\n", exp);
                printf("[%i --> ", v1.experience);
                v1.experience += exp;
                printf("%i]\n", v1.experience);
                levelUp();
                exit(EXIT_SUCCESS); // Remplacer ce exit par un renvoi au menu principal (avec le shop et tout)
            }
            break;    
    }
}
