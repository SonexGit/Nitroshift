#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "header.h"
#include "render.h"
#include "entite.h"
#include "sorts.h"
#include "initialisation.h"
#include "combat.h"
#include "mesmodif.h"
#include "pile.h"
#include "shifumi.h"
#include "menujeu.h"
#include "amelioration.h"


 /**
   *\file shop.c
  * \author lucas allan leo enzo
  * \version 1.0
  * \brief programme contenant la fonction qui génère le menu du shop
  * \date 19 avril 2021
   */

  ///Initialisation des images avec une texture\n
  ///positionnement des images\n
  ///check d'evènement avec les clics de la souris\n
  ///cas de if pour faire plusieurs actions(exemple: choisir les mini-jeux ou amélioration)\n

  /**
   * \fn void showshop
   * \brief fonction qui permet de créer le menu du shop avec soit les mini-jeux ou bien améliorer son équipement
   * \param aucun parametre
   * \return la fenetre avec le menu et ces boutons
   */



void showshop()
{

    SDL_Surface *imageminijeux = NULL;
    SDL_Texture *textureminijeux = NULL;

    SDL_Surface *imageamelioration = NULL;
    SDL_Texture *textureamelioration = NULL;

    SDL_Surface *imageshop = NULL;
    SDL_Texture *textureshop = NULL;

    SDL_Surface *imageselect1 = NULL;
    SDL_Texture *textureselect1 = NULL;

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    //Mise en place des boutons
    imageshop=IMG_Load("../data/menu/shop.png");
    if(imageshop==NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    textureshop=SDL_CreateTextureFromSurface(ren,imageshop);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imageshop);

    if(textureshop==NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire


    //chargement de la texture
    SDL_Rect rectangleshop;
    if(SDL_QueryTexture(textureshop,NULL,NULL,&rectangleshop.w,&rectangleshop.h)!=0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }
    //positionnement du bouton
    rectangleshop.x=650;
    rectangleshop.y=20;
    rectangleshop.h= imageshop->h  *3;
    rectangleshop.w= imageshop->w  *3;

    //
    //affichage de l'image
    if(SDL_RenderCopy(ren,textureshop,NULL, &rectangleshop)!=0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);


/*    Bouton quitter      */
    imageselect1=IMG_Load("../data/menu/select.png");
    if(imageselect1==NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    textureselect1=SDL_CreateTextureFromSurface(ren,imageselect1);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imageselect1);

    if(textureselect1==NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire


    //chargement de la texture
    SDL_Rect rectangleselect1;
    if(SDL_QueryTexture(textureselect1,NULL,NULL,&rectangleselect1.w,&rectangleselect1.h)!=0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }
    //positionnement du bouton
    rectangleselect1.x=20;
    rectangleselect1.y=400;

    //
    //affichage de l'image
    if(SDL_RenderCopy(ren,textureselect1,NULL, &rectangleselect1)!=0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

 SDL_RenderPresent(ren);

 SDL_Surface *imageselect2 = NULL;
 SDL_Texture *textureselect2 = NULL;


 SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

 //Mise en place des boutons
 /*    Bouton quitter      */
 imageselect2=IMG_Load("../data/menu/select.png");
 if(imageselect2==NULL)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors du chargement de l'image");
 }
 textureselect2=SDL_CreateTextureFromSurface(ren,imageselect2);

 //libération de la surface car plus besoin
 SDL_FreeSurface(imageselect2);

 if(textureselect2==NULL)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors de la création de la texture bouton abandon");
 }
 //l'image est chargé en mémoire


 //chargement de la texture
 SDL_Rect rectangleselect2;
 if(SDL_QueryTexture(textureselect2,NULL,NULL,&rectangleselect2.w,&rectangleselect2.h)!=0)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors de l'affichage de l'image");
 }
 //positionnement du bouton
 rectangleselect2.x=1220;
 rectangleselect2.y=400;

 //
 //affichage de l'image
 if(SDL_RenderCopy(ren,textureselect2,NULL, &rectangleselect2)!=0)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors de l'affichage de l'image");
 }

 SDL_RenderPresent(ren);

 imageminijeux=IMG_Load("../data/menu/minijeux.png");
 if(imageminijeux==NULL)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors du chargement de l'image");
 }
 textureminijeux=SDL_CreateTextureFromSurface(ren,imageminijeux);

 //libération de la surface car plus besoin
 SDL_FreeSurface(imageminijeux);

 if(textureminijeux==NULL)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors de la création de la texture bouton abandon");
 }
 //l'image est chargé en mémoire


 //chargement de la texture
 SDL_Rect rectangleminijeux;
 if(SDL_QueryTexture(textureminijeux,NULL,NULL,&rectangleminijeux.w,&rectangleminijeux.h)!=0)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors de l'affichage de l'image");
 }
 //positionnement du bouton
 rectangleminijeux.x=20;
 rectangleminijeux.y=300;
 //rectangleminijeux.w = imageminijeux->w *1.5;
 //rectangleminijeux.h = imageminijeux->w *1.5;
 //
 //affichage de l'image
 if(SDL_RenderCopy(ren,textureminijeux,NULL, &rectangleminijeux)!=0)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors de l'affichage de l'image");
 }

 SDL_RenderPresent(ren);


 imageamelioration=IMG_Load("../data/menu/amelio.png");
 if(imageamelioration==NULL)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors du chargement de l'image");
 }
 textureamelioration=SDL_CreateTextureFromSurface(ren,imageamelioration);

 //libération de la surface car plus besoin
 SDL_FreeSurface(imageamelioration);

 if(textureamelioration==NULL)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors de la création de la texture bouton abandon");
 }
 //l'image est chargé en mémoire


 //chargement de la texture
 SDL_Rect rectangleamelioration;
 if(SDL_QueryTexture(textureamelioration,NULL,NULL,&rectangleamelioration.w,&rectangleamelioration.h)!=0)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors de l'affichage de l'image");
 }
 //positionnement du bouton
 rectangleamelioration.x=1200;
 rectangleamelioration.y=250;
 //rectangleamelioration.w = imageamelioration->w *1;
 //rectangleamelioration.h = imageamelioration->w *1;
 //
 //affichage de l'image
 if(SDL_RenderCopy(ren,textureamelioration,NULL, &rectangleamelioration)!=0)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors de l'affichage de l'image");
 }

 SDL_RenderPresent(ren);


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
       //TTF_Font *police = NULL;
       //TTF_Init();
       //police = TTF_OpenFont("police.ttf",35);
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
             	if(event.button.x >=20 && event.button.x<=230 && event.button.y>=400 && event.button.y<=486){
                SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
                  SDL_RenderClear(ren);
                  showjeu();
    		      }
              if(event.button.x >=1220 && event.button.x<=1430 && event.button.y>=400 && event.button.y<=486){
                  SDL_RenderClear(ren);
                  showamelioration();
                }

              if(event.button.x >=0 && event.button.x<=142 && event.button.y>=750 && event.button.y<=841){
                SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
                SDL_RenderClear(ren);
                SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
                showmenu();
              }
             	break;
            }
        }

    }


    SDL_DestroyTexture(textureselect1);
    SDL_DestroyTexture(textureBoutonretour);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);




    SDL_Quit();

    return EXIT_SUCCESS;
}
