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

void initCombat(int level){

    if(level == 1){

        e1.pm = e1.pmMax;
        e1.positionX = 2;
        e1.positionY = 2;

        e2.pm = e2.pmMax;
        e2.positionX = 2;
        e2.positionY = 3;

        v1.positionX = 13;
        v1.positionY = 13;          
    }

    /* Faire chaque niveau */

}
