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

    v1.mort = 0;
    v1.passerTour = 0;
    v1.hp = v1.hpMax;
    statsMaximum(&v1);

    if(level == 1){

        sortsEnnemi1[0].id = 0;
        sortsEnnemi1[0].nom = "Lame de glace";
        sortsEnnemi1[0].description = "Test";
        sortsEnnemi1[0].relance = 0;
        sortsEnnemi1[0].degatsMin = 20;
		sortsEnnemi1[0].degatsMax = 40;
        sortsEnnemi1[0].portee = 3;
        sortsEnnemi1[0].coutPA = 0;
        sortsEnnemi1[0].coutNitro = 100;
        sortsEnnemi1[0].surface = NULL;
        sortsEnnemi1[0].texture = NULL;

        sortsEnnemi1[1].id = 1;
        sortsEnnemi1[1].nom = "Boost Nitro";
        sortsEnnemi1[1].description = "Test";
        sortsEnnemi1[1].relance = 3;
        sortsEnnemi1[1].degatsMin = 100;
		sortsEnnemi1[1].degatsMax = 100;
        sortsEnnemi1[1].portee = 0;
        sortsEnnemi1[1].coutPA = 3;
        sortsEnnemi1[1].coutNitro = 0;
        sortsEnnemi1[1].surface = NULL;
        sortsEnnemi1[1].texture = NULL;

        sortsEnnemi2[0].id = 0;
        sortsEnnemi2[0].nom = "Lame de feu";
        sortsEnnemi2[0].description = "Test";
        sortsEnnemi2[0].relance = 0;
        sortsEnnemi2[0].degatsMin = 20;
		sortsEnnemi2[0].degatsMax = 40;
        sortsEnnemi2[0].portee = 3;
        sortsEnnemi2[0].coutPA = 0;
        sortsEnnemi2[0].coutNitro = 100;
        sortsEnnemi2[0].surface = NULL;
        sortsEnnemi2[0].texture = NULL;

        sortsEnnemi2[1].id = 1;
        sortsEnnemi2[1].nom = "Boost PM";
        sortsEnnemi2[1].description = "Test";
        sortsEnnemi2[1].relance = 3;
        sortsEnnemi2[1].degatsMin = 3;
		sortsEnnemi2[1].degatsMax = 3;
        sortsEnnemi2[1].portee = 0;
        sortsEnnemi2[1].coutPA = 3;
        sortsEnnemi2[1].coutNitro = 100;
        sortsEnnemi2[1].surface = NULL;
        sortsEnnemi2[1].texture = NULL;        
        
        e1.tempsRelance = 0;
        e1.relanceBoost = 1;
        e1.hp = e1.hpMax;
        statsMaximum(&e1);
        e1.positionX = 13;
        e1.positionY = 8;
        e1.tempsRelance = 0;
        e1.relanceBoost = 1;

        e2.tempsRelance = 0;
        e2.relanceBoost = 1;
        e2.hp = e2.hpMax;
        statsMaximum(&e2);
        e2.positionX = 14;
        e2.positionY = 8;
        e2.tempsRelance = 0;
        e2.relanceBoost = 1;

        v1.positionX = 6;
        v1.positionY = 2;        
    }
    else if(level == 2){

        e1.hpMax += 50;
        e1.attaque += 5;
        e1.defense += 5;

        e2.hpMax += 50;
        e2.attaque += 5;
        e2.defense += 5;

        sortsEnnemi1[0].id = 0;
        sortsEnnemi1[0].nom = "Lame de glace";
        sortsEnnemi1[0].description = "Test";
        sortsEnnemi1[0].relance = 0;
        sortsEnnemi1[0].degatsMin = 20;
		sortsEnnemi1[0].degatsMax = 40;
        sortsEnnemi1[0].portee = 3;
        sortsEnnemi1[0].coutPA = 0;
        sortsEnnemi1[0].coutNitro = 100;
        sortsEnnemi1[0].surface = NULL;
        sortsEnnemi1[0].texture = NULL;

        sortsEnnemi1[1].id = 1;
        sortsEnnemi1[1].nom = "Boost Nitro";
        sortsEnnemi1[1].description = "Test";
        sortsEnnemi1[1].relance = 2;
        sortsEnnemi1[1].degatsMin = 100;
		sortsEnnemi1[1].degatsMax = 100;
        sortsEnnemi1[1].portee = 0;
        sortsEnnemi1[1].coutPA = 3;
        sortsEnnemi1[1].coutNitro = 0;
        sortsEnnemi1[1].surface = NULL;
        sortsEnnemi1[1].texture = NULL;

        sortsEnnemi2[0].id = 0;
        sortsEnnemi2[0].nom = "Lame de feu";
        sortsEnnemi2[0].description = "Test";
        sortsEnnemi2[0].relance = 0;
        sortsEnnemi2[0].degatsMin = 20;
		sortsEnnemi2[0].degatsMax = 40;
        sortsEnnemi2[0].portee = 3;
        sortsEnnemi2[0].coutPA = 0;
        sortsEnnemi2[0].coutNitro = 100;
        sortsEnnemi2[0].surface = NULL;
        sortsEnnemi2[0].texture = NULL;

        sortsEnnemi2[1].id = 1;
        sortsEnnemi2[1].nom = "Boost PM";
        sortsEnnemi2[1].description = "Test";
        sortsEnnemi2[1].relance = 2;
        sortsEnnemi2[1].degatsMin = 4;
		sortsEnnemi2[1].degatsMax = 4;
        sortsEnnemi2[1].portee = 0;
        sortsEnnemi2[1].coutPA = 3;
        sortsEnnemi2[1].coutNitro = 100;
        sortsEnnemi2[1].surface = NULL;
        sortsEnnemi2[1].texture = NULL;        
        
        e1.tempsRelance = 0;
        e1.relanceBoost = 1;
        e1.hp = e1.hpMax;
        statsMaximum(&e1);
        e1.positionX = 0;
        e1.positionY = 8;

        e2.tempsRelance = 0;
        e2.relanceBoost = 1;
        e2.hp = e2.hpMax;
        statsMaximum(&e2);
        e2.positionX = 1;
        e2.positionY = 8;

        v1.positionX = 6;
        v1.positionY = 2;           
    }
    else if(level == 3){

        sortsBoss1[0].id = 0;
        sortsBoss1[0].nom = "Lame de glace";
        sortsBoss1[0].description = "Test";
        sortsBoss1[0].relance = 0;
        sortsBoss1[0].degatsMin = 10;
		sortsBoss1[0].degatsMax = 15;
        sortsBoss1[0].portee = 6;
        sortsBoss1[0].coutPA = 0;
        sortsBoss1[0].coutNitro = 100;
        sortsBoss1[0].surface = NULL;
        sortsBoss1[0].texture = NULL;

        sortsBoss1[1].id = 1;
        sortsBoss1[1].nom = "Boost PA";
        sortsBoss1[1].description = "Test";
        sortsBoss1[1].relance = 3;
        sortsBoss1[1].degatsMin = 6;
		sortsBoss1[1].degatsMax = 6;
        sortsBoss1[1].portee = 0;
        sortsBoss1[1].coutPA = 3;
        sortsBoss1[1].coutNitro = 0;
        sortsBoss1[1].surface = NULL;
        sortsBoss1[1].texture = NULL;
        
        b1.tempsRelance = 0;
        b1.relanceBoost = 1;
        b1.hp = b1.hpMax;
        statsMaximum(&b1);
        b1.positionX = 6;
        b1.positionY = 2;

        v1.positionX = 6;
        v1.positionY = 12;     
              
    }
}
