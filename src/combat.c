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
#include "combat.h"

int parcours = 0;

int estUnBoss(entite e){

    if(e.id == 100 || e.id == 200 || e.id == 300 || e.id == 400 || e.id == 500){
        return VRAI;
    }

    return FAUX;
}

void tourPersonnage(){

    tourP = 1;
}

void tourEnnemi(){

    int boss, prec;
    int flag = 0;
    
    boss = estUnBoss(ordrePassage[parcours]);
    ordrePassage[parcours].pm = ordrePassage[parcours].pmMax;

    while(ordrePassage[parcours].pm > 0){
        if(ordrePassage[parcours].positionY == v1.positionY){ /* Cas où l'ennemi est sur la même colonne que le personnage */
            if(boss == FAUX){
                if(v1.positionX > ordrePassage[parcours].positionX){ /* Cas où la ligne du personnage est supérieur à la ligne de l'ennemi (donc l'ennemi se déplace en bas) */
                    if(plateau[ordrePassage[parcours].positionX + 1][ordrePassage[parcours].positionY].solide){ /* Cas où la case de la prochaine ligne est solide (donc ERREUR l'ennemi fait demi tour) */
                        flag = 1;                                
                        ordrePassage[parcours].positionY--;
                        ordrePassage[parcours].pm--;
                        SDL_Delay(1000);                                              
                    }
                    else{ /* Cas où la case de la prochaine ligne est disponible, donc l'ennemi avance */
                        flag = 0;
                        ordrePassage[parcours].positionX++;
                        ordrePassage[parcours].pm--;
                        SDL_Delay(1000);                                   
                    }
                }
                else{ /* Cas où la ligne du personnage est inférieur à la ligne de l'ennemi (donc l'ennemi se déplace en haut) */
                    if(plateau[ordrePassage[parcours].positionX - 1][ordrePassage[parcours].positionY].solide){ /* Cas où la case de la prochaine ligne est solide (donc ERREUR l'ennemi fait demi tour) */
                        flag = 1;                                
                        ordrePassage[parcours].positionY--;
                        ordrePassage[parcours].pm--;
                        SDL_Delay(1000);                                              
                    }
                    else{ /* Cas où la case de la prochaine ligne est disponible, donc l'ennemi avance */
                        flag = 0;
                        ordrePassage[parcours].positionX--;
                        ordrePassage[parcours].pm--;
                        SDL_Delay(1000);                                   
                    }
                }
            }
            else{
                /* A faire pour les boss */
            }
        }
        else if(ordrePassage[parcours].positionX == v1.positionX){ /* Cas où l'ennemi est sur la même ligne que le personnage */
            if(boss == FAUX){
                if(v1.positionY > ordrePassage[parcours].positionY){ /* Cas où la colonne du personnage est supérieur à la ligne de l'ennemi (donc l'ennemi se déplace à droite) */
                    if(plateau[ordrePassage[parcours].positionX][ordrePassage[parcours].positionY + 1].solide){ /* Cas où la case de la prochaine colonne est solide (donc ERREUR l'ennemi fait demi tour) */
                        flag = 1;                                
                        ordrePassage[parcours].positionX = prec;
                        ordrePassage[parcours].pm--;
                        SDL_Delay(1000);                                              
                    }
                    else{ /* Cas où la case de la prochaine colonne est disponible, donc l'ennemi avance */
                        flag = 0;
                        ordrePassage[parcours].positionY++;
                        ordrePassage[parcours].pm--;
                        SDL_Delay(1000);                                   
                    }
                }
                else{ /* Cas où la ligne du personnage est inférieur à la ligne de l'ennemi (donc l'ennemi se déplace à gauche) */
                    if(plateau[ordrePassage[parcours].positionX - 1][ordrePassage[parcours].positionY].solide){ /* Cas où la case de la prochaine ligne est solide (donc ERREUR l'ennemi fait demi tour) */
                        flag = 1;                                
                        ordrePassage[parcours].positionY = prec;
                        ordrePassage[parcours].pm--;
                        SDL_Delay(1000);                                              
                    }
                    else{ /* Cas où la case de la prochaine ligne est disponible, donc l'ennemi avance */
                        flag = 0;
                        ordrePassage[parcours].positionX--;
                        ordrePassage[parcours].pm--;
                        SDL_Delay(1000);                                   
                    }
                }
            }
            else{
                /* A faire pour les boss */
            }
        }
        else{ /* Cas où l'ennemi n'est pas sur la même ligne et sur la même colonne que le personnage */
            if(boss == FAUX){
                if(v1.positionY > ordrePassage[parcours].positionY){ /* Cas où la colonne du personnage est supérieur à la colonne de l'ennemi (donc l'ennemi se déplace vers la droite) */
                    if(plateau[ordrePassage[parcours].positionX][ordrePassage[parcours].positionY + 1].solide || flag == 1){ /* Cas où la case de la prochaine colonne est solide (donc ERREUR l'ennemi ne peut pas avancer) */
                        if(v1.positionX > ordrePassage[parcours].positionX){ /* Cas où la ligne du personnage est supérieur à la ligne de l'ennemi (donc l'ennemi se déplace en bas) */
                            if(plateau[ordrePassage[parcours].positionX + 1][ordrePassage[parcours].positionY].solide){ /* Cas où la case de la prochaine ligne est solide (donc ERREUR l'ennemi fait demi tour) */
                                flag = 1;                                
                                ordrePassage[parcours].positionY = prec;
                                ordrePassage[parcours].pm--;
                                SDL_Delay(1000);                                              
                            }
                            else{ /* Cas où la case de la prochaine ligne est disponible, donc l'ennemi avance */
                                flag = 0;
                                prec = ordrePassage[parcours].positionX;
                                ordrePassage[parcours].positionX++;
                                ordrePassage[parcours].pm--;
                                SDL_Delay(1000);                                   
                            }
                        }
                        else{ /* Cas où la ligne du personnage est inférieur à la ligne de l'ennemi (donc l'ennemi se déplace en haut) */
                            if(plateau[ordrePassage[parcours].positionX - 1][ordrePassage[parcours].positionY].solide){ /* Cas où la case de la prochaine ligne est solide (donc ERREUR l'ennemi fait demi tour) */
                                flag = 1;                                
                                ordrePassage[parcours].positionY = prec;
                                ordrePassage[parcours].pm--;
                                SDL_Delay(1000);                                              
                            }
                            else{ /* Cas où la case de la prochaine ligne est disponible, donc l'ennemi avance */
                                flag = 0;
                                prec = ordrePassage[parcours].positionX;
                                ordrePassage[parcours].positionX--;
                                ordrePassage[parcours].pm--;
                                SDL_Delay(1000);                                   
                            }
                        }
                    }
                    else{ /* Cas où la case de la prochaine colonne est disponible, donc l'ennemi avance */
                        prec = ordrePassage[parcours].positionY;
                        ordrePassage[parcours].positionY++;
                        ordrePassage[parcours].pm--;
                        SDL_Delay(1000);                        
                    }
                }
                else{ /* Cas où la colonne du personnage est inférieur à la colonne de l'ennemi (donc l'ennemi se déplace vers la gauche) */
                    if(plateau[ordrePassage[parcours].positionX][ordrePassage[parcours].positionY - 1].solide || flag == 1){ /* Cas où la case de la prochaine colonne est solide (donc ERREUR l'ennemi ne peut pas avancer) */
                        if(v1.positionX > ordrePassage[parcours].positionX){ /* Cas où la ligne du personnage est supérieur à la ligne de l'ennemi (donc l'ennemi se déplace en bas) */
                            if(plateau[ordrePassage[parcours].positionX + 1][ordrePassage[parcours].positionY].solide){ /* Cas où la case de la prochaine ligne est solide (donc ERREUR l'ennemi fait demi tour) */
                                flag = 1;                                
                                ordrePassage[parcours].positionY = prec;
                                ordrePassage[parcours].pm--;
                                SDL_Delay(1000);                                              
                            }
                            else{ /* Cas où la case de la prochaine ligne est disponible, donc l'ennemi avance */
                                flag = 0;
                                prec = ordrePassage[parcours].positionX;
                                ordrePassage[parcours].positionX++;
                                ordrePassage[parcours].pm--;
                                SDL_Delay(1000);                                   
                            }
                        }
                        else{ /* Cas où la ligne du personnage est inférieur à la ligne de l'ennemi (donc l'ennemi se déplace en haut) */
                            if(plateau[ordrePassage[parcours].positionX - 1][ordrePassage[parcours].positionY].solide){ /* Cas où la case de la prochaine ligne est solide (donc ERREUR l'ennemi fait demi tour) */
                                flag = 1;                                
                                ordrePassage[parcours].positionY = prec;
                                ordrePassage[parcours].pm--;
                                SDL_Delay(1000);                                              
                            }
                            else{ /* Cas où la case de la prochaine ligne est disponible, donc l'ennemi avance */
                                flag = 0;
                                prec = ordrePassage[parcours].positionX;
                                ordrePassage[parcours].positionX--;
                                ordrePassage[parcours].pm--;
                                SDL_Delay(1000);                                   
                            }
                        }
                    }
                    else{ /* Cas où la case de la prochaine colonne est disponible, donc l'ennemi avance */
                        prec = ordrePassage[parcours].positionY;
                        ordrePassage[parcours].positionY--;
                        ordrePassage[parcours].pm--;
                        SDL_Delay(1000);                        
                    }
                }
            }
            else{
                /* A faire pour les boss */
            }              
        }
    }
}

void deroulementCombat(){
    
    for(parcours = 0; parcours <= nbEntite; parcours++){
        if(ordrePassage[parcours].id == 1){
            printf("\n\nahahhahahaha1\n\n");
            /* tourPersonnage(); */
            printf("\n\nahahhahahaha2\n\n");
        }  
        else{
            tourP = 0;
            printf("\n\nAVANT TOUR ENNEMI\n\n");
            tourEnnemi();
            printf("\n\n APRES TOUR ENNEMI\n\n");
            SDL_Delay(5000);
        }
    }
}