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
        sortsEnnemi1[0].degatsMin = 40;
		sortsEnnemi1[0].degatsMax = 60;
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
        sortsEnnemi2[0].degatsMin = 40;
		sortsEnnemi2[0].degatsMax = 60;
        sortsEnnemi2[0].portee = 3;
        sortsEnnemi2[0].coutPA = 0;
        sortsEnnemi2[0].coutNitro = 100;
        sortsEnnemi2[0].surface = NULL;
        sortsEnnemi2[0].texture = NULL;

        sortsEnnemi2[1].id = 1;
        sortsEnnemi2[1].nom = "Boost PM";
        sortsEnnemi2[1].description = "Test";
        sortsEnnemi2[1].relance = 2;
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
        sortsBoss1[0].nom = "Lame de vent";
        sortsBoss1[0].description = "Test";
        sortsBoss1[0].relance = 0;
        sortsBoss1[0].degatsMin = 40;
		sortsBoss1[0].degatsMax = 50;
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
    else if(level == 4){

        sortsEnnemi3[0].id = 0;
        sortsEnnemi3[0].nom = "Crachat de viandes";
        sortsEnnemi3[0].description = "Test";
        sortsEnnemi3[0].relance = 0;
        sortsEnnemi3[0].degatsMin = 30;
		sortsEnnemi3[0].degatsMax = 60;
        sortsEnnemi3[0].portee = 3;
        sortsEnnemi3[0].coutPA = 0;
        sortsEnnemi3[0].coutNitro = 100;
        sortsEnnemi3[0].surface = NULL;
        sortsEnnemi3[0].texture = NULL;

        sortsEnnemi3[1].id = 1;
        sortsEnnemi3[1].nom = "Boost de PM";
        sortsEnnemi3[1].description = "Test";
        sortsEnnemi3[1].relance = 3;
        sortsEnnemi3[1].degatsMin = 5;
		sortsEnnemi3[1].degatsMax = 5;
        sortsEnnemi3[1].portee = 0;
        sortsEnnemi3[1].coutPA = 3;
        sortsEnnemi3[1].coutNitro = 0;
        sortsEnnemi3[1].surface = NULL;
        sortsEnnemi3[1].texture = NULL;

        sortsEnnemi4[0].id = 0;
        sortsEnnemi4[0].nom = "Crachat de fraises";
        sortsEnnemi4[0].description = "Test";
        sortsEnnemi4[0].relance = 0;
        sortsEnnemi4[0].degatsMin = 30;
		sortsEnnemi4[0].degatsMax = 60;
        sortsEnnemi4[0].portee = 3;
        sortsEnnemi4[0].coutPA = 0;
        sortsEnnemi4[0].coutNitro = 100;
        sortsEnnemi4[0].surface = NULL;
        sortsEnnemi4[0].texture = NULL;

        sortsEnnemi4[1].id = 1;
        sortsEnnemi4[1].nom = "Boost de PA";
        sortsEnnemi4[1].description = "Test";
        sortsEnnemi4[1].relance = 3;
        sortsEnnemi4[1].degatsMin = 6;
		sortsEnnemi4[1].degatsMax = 6;
        sortsEnnemi4[1].portee = 0;
        sortsEnnemi4[1].coutPA = 3;
        sortsEnnemi4[1].coutNitro = 0;
        sortsEnnemi4[1].surface = NULL;
        sortsEnnemi4[1].texture = NULL;        
        
        e3.tempsRelance = 0;
        e3.relanceBoost = 1;
        e3.hp = e3.hpMax;
        statsMaximum(&e3);
        e3.positionX = 13;
        e3.positionY = 8;
        e3.tempsRelance = 0;
        e3.relanceBoost = 1;

        e4.tempsRelance = 0;
        e4.relanceBoost = 1;
        e4.hp = e4.hpMax;
        statsMaximum(&e4);
        e4.positionX = 14;
        e4.positionY = 8;
        e4.tempsRelance = 0;
        e4.relanceBoost = 1;

        v1.positionX = 6;
        v1.positionY = 2;        
    }
    else if(level == 5){

        e1.hpMax += 100;
        e1.attaque += 10;
        e1.defense += 10;

        e2.hpMax += 100;
        e2.attaque += 10;
        e2.defense += 10;

        sortsEnnemi3[0].id = 0;
        sortsEnnemi3[0].nom = "Crachat de viandes";
        sortsEnnemi3[0].description = "Test";
        sortsEnnemi3[0].relance = 0;
        sortsEnnemi3[0].degatsMin = 40;
		sortsEnnemi3[0].degatsMax = 70;
        sortsEnnemi3[0].portee = 3;
        sortsEnnemi3[0].coutPA = 0;
        sortsEnnemi3[0].coutNitro = 100;
        sortsEnnemi3[0].surface = NULL;
        sortsEnnemi3[0].texture = NULL;

        sortsEnnemi3[1].id = 1;
        sortsEnnemi3[1].nom = "Boost de PM";
        sortsEnnemi3[1].description = "Test";
        sortsEnnemi3[1].relance = 2;
        sortsEnnemi3[1].degatsMin = 5;
		sortsEnnemi3[1].degatsMax = 5;
        sortsEnnemi3[1].portee = 0;
        sortsEnnemi3[1].coutPA = 3;
        sortsEnnemi3[1].coutNitro = 0;
        sortsEnnemi3[1].surface = NULL;
        sortsEnnemi3[1].texture = NULL;

        sortsEnnemi4[0].id = 0;
        sortsEnnemi4[0].nom = "Crachat de fraises";
        sortsEnnemi4[0].description = "Test";
        sortsEnnemi4[0].relance = 0;
        sortsEnnemi4[0].degatsMin = 40;
		sortsEnnemi4[0].degatsMax = 70;
        sortsEnnemi4[0].portee = 3;
        sortsEnnemi4[0].coutPA = 0;
        sortsEnnemi4[0].coutNitro = 100;
        sortsEnnemi4[0].surface = NULL;
        sortsEnnemi4[0].texture = NULL;

        sortsEnnemi4[1].id = 1;
        sortsEnnemi4[1].nom = "Boost de PA";
        sortsEnnemi4[1].description = "Test";
        sortsEnnemi4[1].relance = 2;
        sortsEnnemi4[1].degatsMin = 6;
		sortsEnnemi4[1].degatsMax = 6;
        sortsEnnemi4[1].portee = 0;
        sortsEnnemi4[1].coutPA = 3;
        sortsEnnemi4[1].coutNitro = 0;
        sortsEnnemi4[1].surface = NULL;
        sortsEnnemi4[1].texture = NULL;        
        
        e3.tempsRelance = 0;
        e3.relanceBoost = 1;
        e3.hp = e3.hpMax;
        statsMaximum(&e3);
        e3.positionX = 0;
        e3.positionY = 8;
        e3.tempsRelance = 0;
        e3.relanceBoost = 1;

        e4.tempsRelance = 0;
        e4.relanceBoost = 1;
        e4.hp = e4.hpMax;
        statsMaximum(&e4);
        e4.positionX = 1;
        e4.positionY = 8;
        e4.tempsRelance = 0;
        e4.relanceBoost = 1;

        v1.positionX = 6;
        v1.positionY = 2;         
    }
    else if(level == 6){

        sortsBoss2[0].id = 0;
        sortsBoss2[0].nom = "Crachat de cranes";
        sortsBoss2[0].description = "Test";
        sortsBoss2[0].relance = 0;
        sortsBoss1[0].degatsMin = 50;
		sortsBoss2[0].degatsMax = 60;
        sortsBoss2[0].portee = 6;
        sortsBoss2[0].coutPA = 0;
        sortsBoss2[0].coutNitro = 100;
        sortsBoss2[0].surface = NULL;
        sortsBoss2[0].texture = NULL;

        sortsBoss2[1].id = 1;
        sortsBoss2[1].nom = "Boost de Nitro";
        sortsBoss2[1].description = "Test";
        sortsBoss2[1].relance = 2;
        sortsBoss2[1].degatsMin = 50;
		sortsBoss2[1].degatsMax = 50;
        sortsBoss2[1].portee = 0;
        sortsBoss2[1].coutPA = 3;
        sortsBoss2[1].coutNitro = 0;
        sortsBoss2[1].surface = NULL;
        sortsBoss2[1].texture = NULL;
        
        b2.tempsRelance = 0;
        b2.relanceBoost = 1;
        b2.hp = b2.hpMax;
        statsMaximum(&b2);
        b2.positionX = 6;
        b2.positionY = 2;

        v1.positionX = 6;
        v1.positionY = 12;                  
    }
}