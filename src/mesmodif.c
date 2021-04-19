#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "header.h"
#include "render.h"
#include "entite.h"
#include "sorts.h"
#include "initialisation.h"
#include "combat.h"


/**
  *\file mesmodif.c
 * \author lucas allan leo enzo
 * \version 1.0
 * \brief programme contenant le menu du choix de jeu
 * \date 19 avril 2021
  */

 ///Initialisation des images avec une texture\n
 ///positionnement des images\n
 ///check d'evènement avec les clics de la souris pour le choix du niveau\n


/**
  *\fn void showjeu(void)
  *\brief fonction qui creer une fenetre avec un choix de jeu où l'on peut jouer pour gagner des nitroDollars
  *\param aucun parametre
*/

void showjeu()
{

    SDL_Surface * icon = IMG_Load("../data/icon.png");
    SDL_SetWindowIcon(win, icon);

    SDL_SetRenderDrawColor(ren, 255, 0, 255, 255);

    SDL_Surface *imagepierre = NULL;
    SDL_Texture *texturepierre = NULL;

    SDL_Surface *imagepileouface = NULL;
    SDL_Texture *texturepileouface = NULL;

    SDL_Surface *imageprix = NULL;
    SDL_Texture *textureprix = NULL;

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    SDL_Surface *imageBoutonretour = NULL;
   	SDL_Texture *textureBoutonretour = NULL;

   	/*    Bouton a retour      */
   		imageBoutonretour=IMG_Load("../data/menu/bouton_retour.png");
   		if(imageBoutonretour==NULL)
   		{
   				SDL_DestroyRenderer(ren);
   				SDL_DestroyWindow(win);
   				SDLError("Erreur lors du chargement de l'image");
   		}
   		textureBoutonretour=SDL_CreateTextureFromSurface(ren,imageBoutonretour);

   		//libération de la surface car plus besoin
   		SDL_FreeSurface(imageBoutonretour);

   		if(textureBoutonretour==NULL)
   		{
   				SDL_DestroyRenderer(ren);
   				SDL_DestroyWindow(win);
   				SDLError("Erreur lors de la création de la texture bouton retour");
   		}
   		//l'image est chargé en mémoire


   		//chargement de la texture
   		SDL_Rect rectangleBoutonretour;
   		if(SDL_QueryTexture(textureBoutonretour,NULL,NULL,&rectangleBoutonretour.w,&rectangleBoutonretour.h)!=0)
   		{
   				SDL_DestroyRenderer(ren);
   				SDL_DestroyWindow(win);
   				SDLError("Erreur lors de l'affichage de l'image");
   		}

   		//positionnement du bouton
   		rectangleBoutonretour.x=0;
   		rectangleBoutonretour.y=750;
   		//
   		//affichage de l'image
   		if(SDL_RenderCopy(ren,textureBoutonretour,NULL, &rectangleBoutonretour)!=0)
   		{
   				SDL_DestroyRenderer(ren);
   				SDL_DestroyWindow(win);
   				SDLError("Erreur lors de l'affichage de l'image");
   		}
   SDL_RenderPresent(ren);

    //Mise en place des boutons
/*    Bouton quitter      */
    imagepierre=IMG_Load("../data/menu/pierr.png");
    if(imagepierre==NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    texturepierre=SDL_CreateTextureFromSurface(ren,imagepierre);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imagepierre);

    if(texturepierre==NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire


    //chargement de la texture
    SDL_Rect rectanglepierre;
    if(SDL_QueryTexture(texturepierre,NULL,NULL,&rectanglepierre.w,&rectanglepierre.h)!=0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectanglepierre.x=0;
    rectanglepierre.y=200;
    rectanglepierre.w = imagepierre->w *2;
    rectanglepierre.h =imagepierre->h *2;
    //
    //affichage de l'image
    if(SDL_RenderCopy(ren,texturepierre,NULL, &rectanglepierre)!=0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

 SDL_RenderPresent(ren);

 /*    Bouton pile ou face  */
     imagepileouface=IMG_Load("../data/menu/pileouface.png");
     if(imagepileouface==NULL)
     {
         SDL_DestroyRenderer(ren);
         SDL_DestroyWindow(win);
         SDLError("Erreur lors du chargement de l'image");
     }
     texturepileouface=SDL_CreateTextureFromSurface(ren,imagepileouface);

     //libération de la surface car plus besoin
     SDL_FreeSurface(imagepileouface);

     if(texturepileouface==NULL)
     {
         SDL_DestroyRenderer(ren);
         SDL_DestroyWindow(win);
         SDLError("Erreur lors de la création de la texture bouton abandon");
     }
     //l'image est chargé en mémoire


     //chargement de la texture
     SDL_Rect rectanglepileouface;
     if(SDL_QueryTexture(texturepileouface,NULL,NULL,&rectanglepileouface.w,&rectanglepileouface.h)!=0)
     {
         SDL_DestroyRenderer(ren);
         SDL_DestroyWindow(win);
         SDLError("Erreur lors de l'affichage de l'image");
     }

     //positionnement du bouton
     rectanglepileouface.x=500;
     rectanglepileouface.y=200;
     rectanglepileouface.w = imagepileouface->w * 2;
     rectanglepileouface.h = imagepileouface->h * 2;
     //
     //affichage de l'image
     if(SDL_RenderCopy(ren,texturepileouface,NULL, &rectanglepileouface)!=0)
     {
         SDL_DestroyRenderer(ren);
         SDL_DestroyWindow(win);
         SDLError("Erreur lors de l'affichage de l'image");
     }

     SDL_RenderPresent(ren);


/*    Bouton a prix  */
    imageprix=IMG_Load("../data/menu/prix.png");
    if(imageprix==NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    textureprix=SDL_CreateTextureFromSurface(ren,imageprix);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imageprix);

    if(textureprix==NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire


    //chargement de la texture
    SDL_Rect rectangleprix;
    if(SDL_QueryTexture(textureprix,NULL,NULL,&rectangleprix.w,&rectangleprix.h)!=0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectangleprix.x=1100;
    rectangleprix.y=200;
    rectangleprix.w = imageprix->w *2;
    rectangleprix.h = imageprix->h *2;
    //
    //affichage de l'image
    if(SDL_RenderCopy(ren,textureprix,NULL, &rectangleprix)!=0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);


    SDL_bool mouse_hover = SDL_FALSE;
    int continuer=3;
    SDL_Event event;
    int clicx;
    int clicy;
//debut des evenements pour saisi a la souris
    while (continuer)
    {
        while (SDL_PollEvent(&event))
        {

            switch (event.type)
            {
            case SDL_QUIT:
            SDL_DestroyRenderer(ren);
            SDL_DestroyWindow(win);
            break;
            //gestion clavier
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                    SDL_DestroyRenderer(ren);
                    SDL_DestroyWindow(win);
                        break;

                    default:
                        break;
                }
             case SDL_MOUSEBUTTONDOWN:
             	if(event.button.x >=0 && event.button.x<=350 && event.button.y>=200 && event.button.y<=696){
                SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
                SDL_RenderClear(ren);
                SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
                pierre();
              }

    		if(event.button.x >=1100 && event.button.x<=1452 && event.button.y>=200 && event.button.y<=698){
          printf("prix");

   		}
    		if(event.button.x >=500 && event.button.x<=916 && event.button.y>=200 && event.button.y<=786){
          SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
          SDL_RenderClear(ren);
          SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
          pile();

    		}
        if(event.button.x >=0 && event.button.x<=142 && event.button.y>=750 && event.button.y<=841){
          SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
          SDL_RenderClear(ren);
          SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
          showshop();
        }
             	break;
            }
        }

    }


    SDL_DestroyTexture(texturepileouface);
    SDL_DestroyTexture(texturepierre);
    SDL_DestroyTexture(textureprix);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);




    SDL_Quit();

    return EXIT_SUCCESS;
}























/*shop
continuer
sauvegarder et quitter*/
