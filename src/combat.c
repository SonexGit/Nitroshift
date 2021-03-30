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

void iaEnnemi(entite * e){

    int boss, prec, ligne, colonne, comparaisonLigne, comparaisonColonne;
    int flag = 0;

    boss = estUnBoss(e);

    if(!boss){
        if(e->positionX == v1.positionX){ /* Même colonne */
            if(v1.positionY - e->positionY > 0){ /* Ennemi doit descendre */
                if(!(plateau[e->positionY+1][e->positionX].solide)){ /* Case non solide en bas */
                    prec = e->positionY;
                    e->positionY++;
                    e->pm--;
                    flag = 0;
                }
                else{ /* Case solide */
                    if(!(plateau[e->positionY][e->positionX-1].solide)){ /* Case non solide à gauche */
                        prec = e->positionX;
                        e->positionX--;
                        e->pm--;
                        flag = 1;                        
                    }
                    else{ /* Case solide donc il va à droite*/
                        prec = e->positionX;
                        e->positionX++;
                        e->pm--;
                        flag = 1;   
                    }
                }
            }
            else{ /* Ennemi doit monter */
                if(!(plateau[e->positionY-1][e->positionX].solide)){ /* Case non solide en haut */
                    prec = e->positionY;
                    e->positionY--;
                    e->pm--;
                    flag = 0;
                }
                else{ /* Case solide */
                    if(!(plateau[e->positionY][e->positionX-1].solide)){ /* Case non solide à gauche */
                        prec = e->positionX;
                        e->positionX--;
                        e->pm--;
                        flag = 1;                        
                    }
                    else{ /* Case solide donc il va à droite*/
                        prec = e->positionX;
                        e->positionX++;
                        e->pm--;
                        flag = 1;   
                    }
                }
            }
        }
        else if(e->positionY == v1.positionY){ /* Même ligne */
            if(v1.positionX - e->positionX > 0){ /* Ennemi doit aller à droite */
                if(!(plateau[e->positionY][e->positionX+1].solide)){ /* Case non solide à droite */
                    e->positionX++;
                    e->pm--;
                    flag = 0;
                }
                else{ /* Case solide */
                    if(!(plateau[e->positionY-1][e->positionX].solide)){ /* Case non solide en haut */
                        e->positionY--;
                        e->pm--;
                        flag = 2;                         
                    }
                    else{ /* Case solide donc il va en bas*/
                        e->positionY++;
                        e->pm--;
                        flag = 2;    
                    }
                }
            }
            else{ /* Ennemi doit aller à gauche */
                if(!(plateau[e->positionY][e->positionX-1].solide)){ /* Case non solide à gauche */
                    e->positionX--;
                    e->pm--;
                    flag = 0; 
                }
                else{ /* Case solide */
                    if(!(plateau[e->positionY-1][e->positionX].solide)){ /* Case non solide en haut */
                        e->positionY--;
                        e->pm--;
                        flag = 2;                         
                    }
                    else{ /* Case solide donc il va en bas*/
                        e->positionY++;
                        e->pm--;
                        flag = 2;   
                    }
                }
            }
        }
        else{ /* Aucun des deux */

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

            if((comparaisonLigne >= comparaisonColonne && flag == 0) || flag == 2){ /* Ennemi va se mettre sur la même colonne en premier (car moins loin ou égal sans compter les obstacles) */
                if(v1.positionX - e->positionX > 0){ /* Ennemi doit aller à droite */
                    if(!(plateau[e->positionY][e->positionX+1].solide)){ /* Case non solide à droite */
                        e->positionX++;
                        e->pm--;
                    }
                    else{ /* Case solide */
                        if(!(plateau[e->positionY-1][e->positionX].solide)){ /* Case non solide en haut */
                            e->positionY--;
                            e->pm--;                        
                        }  
                        else{ /* Case solide donc il va en bas*/
                            e->positionY++;
                            e->pm--;   
                        }
                    }
                }
                else{ /* Ennemi doit aller à gauche */
                    if(!(plateau[e->positionY][e->positionX-1].solide)){ /* Case non solide en bas */
                        e->positionX--;
                        e->pm--;
                    }
                    else{ /* Case solide */
                        if(!(plateau[e->positionY-1][e->positionX].solide)){ /* Case non solide en haut */
                            e->positionY--;
                            e->pm--;                        
                        }
                        else{ /* Case solide donc il va en bas*/
                            e->positionY++;
                            e->pm--;   
                        }
                    }
                }
            }
            else{ /* Ennemi va se mettre sur la même ligne en premier (car moins loin sans compter les obstacles) */
                if(v1.positionY - e->positionY > 0){ /* Ennemi doit descendre */
                    if(!(plateau[e->positionY+1][e->positionX].solide)){ /* Case non solide en bas */
                        e->positionY++;
                        e->pm--;
                    }
                    else{ /* Case solide */
                        if(!(plateau[e->positionY][e->positionX-1].solide)){ /* Case non solide à gauche */
                            e->positionX--;
                            e->pm--;                        
                        }
                        else{ /* Case solide donc il va à droite*/
                            e->positionX++;
                            e->pm--;   
                        }
                    }
                }
                else{ /* Ennemi doit monter */
                    if(!(plateau[e->positionY-1][e->positionX].solide)){ /* Case non solide en haut */
                        e->positionY--;
                        e->pm--;
                    }
                    else{ /* Case solide */
                        if(!(plateau[e->positionY][e->positionX-1].solide)){ /* Case non solide à gauche */
                            e->positionX--;
                            e->pm--;                        
                        }
                        else{ /* Case solide donc il va à droite*/
                            e->positionX++;
                            e->pm--;   
                        }
                    }
                }
            }
        }
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
                if(e2.pm == 0){
                    v1.pm = 4;
                    e1.pm = e1.pmMax;
                    e2.pm = e2.pmMax;
                    finTempsAllie = 0;
                }
            }
            
    }
}
