#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "render.h"
#include "header.h"
#include "entite.h"
#include "sorts.h"
#include "initialisation.h"
#include "combat.h"

void initCombat(int level){

    if(level == 1){

        sortsEnnemi1[0].id = 0;
        sortsEnnemi1[0].nom = "Lame de glace";
        sortsEnnemi1[0].description = "Test";
        sortsEnnemi1[0].relance = 0;
        sortsEnnemi1[0].degats = 100;
        sortsEnnemi1[0].portee = 3;
        sortsEnnemi1[0].coutPA = 0;
        sortsEnnemi1[0].coutNitro = 100;
        sortsEnnemi1[0].surface = NULL;
        sortsEnnemi1[0].texture = NULL;

        sortsEnnemi1[1].id = 1;
        sortsEnnemi1[1].nom = "Boost Nitro";
        sortsEnnemi1[1].description = "Test";
        sortsEnnemi1[1].relance = 3;
        sortsEnnemi1[1].degats = 100;
        sortsEnnemi1[1].portee = 0;
        sortsEnnemi1[1].coutPA = 3;
        sortsEnnemi1[1].coutNitro = 0;
        sortsEnnemi1[1].surface = NULL;
        sortsEnnemi1[1].texture = NULL;

        sortsEnnemi2[0].id = 0;
        sortsEnnemi2[0].nom = "Lame de feu";
        sortsEnnemi2[0].description = "Test";
        sortsEnnemi2[0].relance = 0;
        sortsEnnemi2[0].degats = 100;
        sortsEnnemi2[0].portee = 3;
        sortsEnnemi2[0].coutPA = 0;
        sortsEnnemi2[0].coutNitro = 100;
        sortsEnnemi2[0].surface = NULL;
        sortsEnnemi2[0].texture = NULL;

        sortsEnnemi2[1].id = 1;
        sortsEnnemi2[1].nom = "Boost PM";
        sortsEnnemi2[1].description = "Test";
        sortsEnnemi2[1].relance = 3;
        sortsEnnemi2[1].degats = 3;
        sortsEnnemi2[1].portee = 0;
        sortsEnnemi2[1].coutPA = 3;
        sortsEnnemi2[1].coutNitro = 100;
        sortsEnnemi2[1].surface = NULL;
        sortsEnnemi2[1].texture = NULL;        
        
        e1.tempsRelance = 0;
        e1.relanceBoost = 1;
        statsMaximum(&e1);
        e1.positionX = 7;
        e1.positionY = 13;

        e2.tempsRelance = 0;
        e2.relanceBoost = 1;
        statsMaximum(&e2);
        e2.positionX = 8;
        e2.positionY = 13;

        v1.positionX = 8;
        v1.positionY = 2;          
    }

    /* Faire chaque niveau */

}
