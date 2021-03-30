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

int tourTermine;

int estUnBoss(entite * e){

    if(e->id == 100 || e->id == 200 || e->id == 300 || e->id == 400 || e->id == 500){
        return VRAI;
    }

    return FAUX;
}

void actionEnnemi(entite * e){

    int boss, prec, tempsActuel;
    int flag = 0;

    boss = estUnBoss(e);
    tempsActuel = SDL_GetTicks();

    if(e->pm > 0){
        if(tempsActuel - tempsDebutPlateau > 1000){
            if(e->positionX == 14);
            else{
                e->positionX++;
                e->pm--;
                tempsDebutPlateau = SDL_GetTicks();
            }
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
                if(e2.pm == 0){
                    v1.pm = 4;
                    e1.pm = e1.pmMax;
                    e2.pm = e2.pmMax;
                    finTempsAllie = 0;
                }
            }
            
    }
}

/*
void actionEnnemi(entite * e){

    int boss, prec;
    int flag = 0;

    boss = estUnBoss(e);

    if(e->pm > 0){
        if(!boss){
            if(e->positionX == v1.positionX){
                
            }
            else if(e->positionY == v1.positionY){

            }
            else{

            }
        }
        else{
            
        }
    }
    else{
        tourTermine = 1;
    }
}
*/