#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "render.h"
#include "header.h"
#include "entite.h"
#include "initialisation.h"
#include "combat.h"
#include "sorts.h"

int tourTermine;

void statsMaximum(entite * e){

    e->pm = e->pmMax;
    e->pa = e->paMax;
    e->nitro = e->nitroMax;
}

int estUnBoss(entite * e){

    if(e->id == 100 || e->id == 200 || e->id == 300 || e->id == 400 || e->id == 500){
        return VRAI;
    }

    return FAUX;
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
            return sortsEnnemi1[0].degats;
            break;
        case 102 :
            return sortsEnnemi2[0].degats;
            break;
        case 201 :
            return sortsEnnemi3[0].degats;
            break;
        case 202 :
            return sortsEnnemi4[0].degats;
            break;
        case 301 :
            return sortsEnnemi5[0].degats;
            break;
        case 302 :
            return sortsEnnemi6[0].degats;
            break;
        case 401 :
            return sortsEnnemi7[0].degats;
            break;
        case 402 :
            return sortsEnnemi8[0].degats;
            break;
        case 501 :
            return sortsEnnemi9[0].degats;
            break;
        case 502 :
            return sortsEnnemi10[0].degats;
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
                    e->nitro += sortsEnnemi1[1].degats; /* On ajoute la nitro du boost */
                    printf("Boost de %s : +%i\n", e->nom, sortsEnnemi1[1].degats);
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
                    e->pm += sortsEnnemi2[1].degats; /* On ajoute les PM du boost */
                    printf("Boost de %s : +%i\n", e->nom, sortsEnnemi2[1].degats);
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
                    v1.hp -= e->attaque; /* On retire les dégâts de l'ennemi du corps à corps aux HP du personnage */
                    printf("Attaque au corps a corps de %s : %i\n", e->nom, e->attaque);
                    e->pa -= 3; /* On retire 3 PA car c'est le coût d'une attaque au corps à corps */
                    printf("Points de vies restant du personnage : %i\n", v1.hp);
                    if(v1.hp < 0){
                        printf("%s est mort.\n", v1.nom);
                        exit(EXIT_SUCCESS);
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
                            if(v1.hp < 0){
                                printf("%s est mort.\n", v1.nom);
                                exit(EXIT_SUCCESS);
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
                    v1.hp -= e->attaque; /* On retire les dégâts de l'ennemi du corps à corps aux HP du personnage */
                    printf("Attaque au corps a corps de %s : %i\n", e->nom, e->attaque);
                    e->pa -= 3; /* On retire 3 PA car c'est le coût d'une attaque au corps à corps */
                    printf("Points de vies restant du personnage : %i\n", v1.hp);
                    if(v1.hp < 0){
                        printf("%s est mort.\n", v1.nom);
                        exit(EXIT_SUCCESS);
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
                            if(v1.hp < 0){
                                printf("%s est mort.\n", v1.nom);
                                exit(EXIT_SUCCESS);
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
                    v1.hp -= e->attaque; /* On retire les dégâts de l'ennemi du corps à corps aux HP du personnage */
                    printf("Attaque au corps a corps de %s : %i\n", e->nom, e->attaque);
                    e->pa -= 3; /* On retire 3 PA car c'est le coût d'une attaque au corps à corps */
                    printf("Points de vies restant du personnage : %i\n", v1.hp);
                    if(v1.hp < 0){
                        printf("%s est mort.\n", v1.nom);
                        exit(EXIT_SUCCESS);
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
                            if(v1.hp < 0){
                                printf("%s est mort.\n", v1.nom);
                                exit(EXIT_SUCCESS);
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
                    v1.hp -= e->attaque; /* On retire les dégâts de l'ennemi du corps à corps aux HP du personnage */
                    printf("Attaque au corps a corps de %s : %i\n", e->nom, e->attaque);
                    e->pa -= 3; /* On retire 3 PA car c'est le coût d'une attaque au corps à corps */
                    printf("Points de vies restant du personnage : %i\n", v1.hp);
                    if(v1.hp < 0){
                        printf("%s est mort.\n", v1.nom);
                        exit(EXIT_SUCCESS);
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
                            if(v1.hp < 0){
                                printf("%s est mort.\n", v1.nom);
                                exit(EXIT_SUCCESS);
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

    boss = estUnBoss(e);

    if(!boss){
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
    }
    if(e->flag == 1){
        e->pm--;
    }
    else{
        
    }
}    

void actionEnnemi(entite * e){

    int tempsActuel;

    tempsActuel = SDL_GetTicks();

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

void deroulementCombat(int level){
    
    tourTermine = 0;

    switch(level){
        case 1 :
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
                    v1.pm = 4;
                    statsMaximum(&e1);
                    statsMaximum(&e2);
                    finTempsAllie = 0;
                }
            }
            
    }
}
