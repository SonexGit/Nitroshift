#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "render.h"
#include "header.h"
#include "entite.h"
#include "initialisation.h"

void initCombat(int numCarte){

    int i, j;
    entite temp;

    ordrePassage[0] = v1;
    nbEntite = 1;

    if(numCarte == 1){

        e1.positionX = 2;
        e1.positionY = 2;

        e2.positionX = 2;
        e2.positionY = 3;

        v1.positionX = 13;
        v1.positionY = 13;

        ordrePassage[1] = e1;
        ordrePassage[2] = e2;
        nbEntite += 2;
        
    }

    /* Faire chaque If */

    for(i = 0; i < nbEntite; i++){
        for(j = i + 1; j < nbEntite; j++){
            if(ordrePassage[i].initiative < ordrePassage[j].initiative){
                temp = ordrePassage[i];
                ordrePassage[i] = ordrePassage[j];
                ordrePassage[j] = temp;
            }
        }
    }
    /* Affichage du tableau (qui joue quand ?) */
    
    printf("\n\n\n");
    for(i = 0; i < nbEntite; i++){
        printf("%i|", ordrePassage[i].initiative);
    }
    printf("\n");
    
}