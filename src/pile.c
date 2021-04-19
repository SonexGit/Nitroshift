#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "header.h"
#include "render.h"
#include "entite.h"
#include "sorts.h"
#include "initialisation.h"
#include "combat.h"

/**
  *\file pile.c
 * \author lucas allan leo enzo
 * \version 1.0
 * \brief programme contenant la fonction d'un mini-jeu
 * \date 19 avril 2021
  */

 ///Initialisation des images avec une texture\n
 ///positionnement des images\n
 ///ordinateur choisit en random un chiffre entre 1 et 3 et celui ci sera transformé en un charactère\n
 ///différents check pour la fonctionnalité du jeu\n
 ///check d'evènement avec les clics de la souris\n
 ///lancer une partie de pile ou face\n

 /**
  * \fn void pile(void)
  * \brief fonction qui permet de créer le mini-jeu pile ou face
  * \param aucun parametre
  * \return la fenetre avec le mini-jeu pile ou face
  */


void pile()
{
  SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
    SDL_Surface * icon = IMG_Load("../data/icon.png");
    SDL_SetWindowIcon(win, icon);

    SDL_Surface *imagewin = NULL;
    SDL_Texture *texturewin = NULL;

    SDL_Surface *imageregle = NULL;
    SDL_Texture *textureregle = NULL;

    SDL_Surface *imageloose = NULL;
    SDL_Texture *textureloose = NULL;

    SDL_Surface *imagepile = NULL;
    SDL_Texture *texturepile = NULL;

    SDL_Surface *imageface = NULL;
    SDL_Texture *textureface = NULL;

    SDL_Surface *imageBoutonshop = NULL;
   	SDL_Texture *textureBoutonshop = NULL;

      /*    Bouton a regle */
      imageregle=IMG_Load("../data/menu/reglepile.png");
      if(imageregle==NULL)
      {
          SDL_DestroyRenderer(ren);
          SDL_DestroyWindow(win);
          SDLError("Erreur lors du chargement de l'image");
      }
      textureregle=SDL_CreateTextureFromSurface(ren,imageregle);

      //libération de la surface car plus besoin
      SDL_FreeSurface(imageregle);

      if(textureregle==NULL)
      {
          SDL_DestroyRenderer(ren);
          SDL_DestroyWindow(win);
          SDLError("Erreur lors de la création de la texture bouton retour");
      }
      //l'image est chargé en mémoire


      //chargement de la texture
      SDL_Rect rectangleregle;
      if(SDL_QueryTexture(textureregle,NULL,NULL,&rectangleregle.w,&rectangleregle.h)!=0)
      {
          SDL_DestroyRenderer(ren);
          SDL_DestroyWindow(win);
          SDLError("Erreur lors de l'affichage de l'image");
      }

      //positionnement du bouton
      rectangleregle.x=1000;
      rectangleregle.y=350;
      //
      //affichage de l'image
      if(SDL_RenderCopy(ren,textureregle,NULL, &rectangleregle)!=0)
      {
          SDL_DestroyRenderer(ren);
          SDL_DestroyWindow(win);
          SDLError("Erreur lors de l'affichage de l'image");
      }



   	/*    Bouton a retour      */
   		imageBoutonshop=IMG_Load("../data/menu/bouton_retour.png");
   		if(imageBoutonshop==NULL)
   		{
   				SDL_DestroyRenderer(ren);
   				SDL_DestroyWindow(win);
   				SDLError("Erreur lors du chargement de l'image");
   		}
   		textureBoutonshop=SDL_CreateTextureFromSurface(ren,imageBoutonshop);

   		//libération de la surface car plus besoin
   		SDL_FreeSurface(imageBoutonshop);

   		if(textureBoutonshop==NULL)
   		{
   				SDL_DestroyRenderer(ren);
   				SDL_DestroyWindow(win);
   				SDLError("Erreur lors de la création de la texture bouton retour");
   		}
   		//l'image est chargé en mémoire


   		//chargement de la texture
   		SDL_Rect rectangleBoutonshop;
   		if(SDL_QueryTexture(textureBoutonshop,NULL,NULL,&rectangleBoutonshop.w,&rectangleBoutonshop.h)!=0)
   		{
   				SDL_DestroyRenderer(ren);
   				SDL_DestroyWindow(win);
   				SDLError("Erreur lors de l'affichage de l'image");
   		}

   		//positionnement du bouton
   		rectangleBoutonshop.x=0;
   		rectangleBoutonshop.y=750;
   		//
   		//affichage de l'image
   		if(SDL_RenderCopy(ren,textureBoutonshop,NULL, &rectangleBoutonshop)!=0)
   		{
   				SDL_DestroyRenderer(ren);
   				SDL_DestroyWindow(win);
   				SDLError("Erreur lors de l'affichage de l'image");
   		}

    imagepile=IMG_Load("../data/menu/pile.png");
    if(imagepile==NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    texturepile=SDL_CreateTextureFromSurface(ren,imagepile);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imagepile);

    if(texturepile==NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire


    //chargement de la texture
    SDL_Rect rectanglepile;
    if(SDL_QueryTexture(texturepile,NULL,NULL,&rectanglepile.w,&rectanglepile.h)!=0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectanglepile.x=0;
    rectanglepile.y=250;

    //
    //affichage de l'image
    if(SDL_RenderCopy(ren,texturepile,NULL, &rectanglepile)!=0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

 SDL_RenderPresent(ren);


 imageface=IMG_Load("../data/menu/face.png");
 if(imageface==NULL)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors du chargement de l'image");
 }
 textureface=SDL_CreateTextureFromSurface(ren,imageface);

 //libération de la surface car plus besoin
 SDL_FreeSurface(imageface);

 if(textureface==NULL)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors de la création de la texture bouton abandon");
 }
 //l'image est chargé en mémoire


 //chargement de la texture
 SDL_Rect rectangleface;
 if(SDL_QueryTexture(textureface,NULL,NULL,&rectangleface.w,&rectangleface.h)!=0)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors de l'affichage de l'image");
 }

 //positionnement du bouton
 rectangleface.x=500;
 rectangleface.y=200;

 //
 //affichage de l'image
 if(SDL_RenderCopy(ren,textureface,NULL, &rectangleface)!=0)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors de l'affichage de l'image");
 }

 SDL_RenderPresent(ren);
 int choix;
 int aleatoire;
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
           if(event.button.x >=0 && event.button.x<=175 && event.button.y>=250 && event.button.y<=425){

             choix = 1;
             srand(time(NULL));
            	aleatoire = rand() % 2 +1;
            	if(choix != aleatoire){
                imageloose=IMG_Load("../data/menu/lose.png");
                if(imageloose==NULL)
                {
                    SDL_DestroyRenderer(ren);
                    SDL_DestroyWindow(win);
                    SDLError("Erreur lors du chargement de l'image");
                }
                textureloose=SDL_CreateTextureFromSurface(ren,imageloose);

                //libération de la surloose car plus besoin
                SDL_FreeSurface(imageloose);

                if(textureloose==NULL)
                {
                    SDL_DestroyRenderer(ren);
                    SDL_DestroyWindow(win);
                    SDLError("Erreur lors de la création de la texture bouton abandon");
                }
                //l'image est chargé en mémoire


                //chargement de la texture
                SDL_Rect rectangleloose;
                if(SDL_QueryTexture(textureloose,NULL,NULL,&rectangleloose.w,&rectangleloose.h)!=0)
                {
                    SDL_DestroyRenderer(ren);
                    SDL_DestroyWindow(win);
                    SDLError("Erreur lors de l'affichage de l'image");
                }

                //positionnement du bouton
                rectangleloose.x=500;
                rectangleloose.y=500;

                //
                //affichage de l'image
                if(SDL_RenderCopy(ren,textureloose,NULL, &rectangleloose)!=0)
                {
                    SDL_DestroyRenderer(ren);
                    SDL_DestroyWindow(win);
                    SDLError("Erreur lors de l'affichage de l'image");
                }

                SDL_RenderPresent(ren);
                 SDL_DestroyTexture(textureloose);
            	}
            	else{
                imagewin=IMG_Load("../data/menu/win.jfif");
                if(imagewin==NULL)
                {
                    SDL_DestroyRenderer(ren);
                    SDL_DestroyWindow(win);
                    SDLError("Erreur lors du chargement de l'image");
                }
                texturewin=SDL_CreateTextureFromSurface(ren,imagewin);

                //libération de la surwin car plus besoin
                SDL_FreeSurface(imagewin);

                if(texturewin==NULL)
                {
                    SDL_DestroyRenderer(ren);
                    SDL_DestroyWindow(win);
                    SDLError("Erreur lors de la création de la texture bouton abandon");
                }
                //l'image est chargé en mémoire


                //chargement de la texture
                SDL_Rect rectanglewin;
                if(SDL_QueryTexture(texturewin,NULL,NULL,&rectanglewin.w,&rectanglewin.h)!=0)
                {
                    SDL_DestroyRenderer(ren);
                    SDL_DestroyWindow(win);
                    SDLError("Erreur lors de l'affichage de l'image");
                }

                //positionnement du bouton
                rectanglewin.x=500;
                rectanglewin.y=500;

                //
                //affichage de l'image
                if(SDL_RenderCopy(ren,texturewin,NULL, &rectanglewin)!=0)
                {
                    SDL_DestroyRenderer(ren);
                    SDL_DestroyWindow(win);
                    SDLError("Erreur lors de l'affichage de l'image");
                }

                SDL_RenderPresent(ren);
                SDL_DestroyTexture(texturewin);
            	}

           }

           if(event.button.x >=500 && event.button.x<=770 && event.button.y>=200 && event.button.y<=470){
            printf("face");
            choix = 2;
            srand(time(NULL));
           	aleatoire = rand() % 2 +1;
           	if(choix != aleatoire){
              imageloose=IMG_Load("../data/menu/lose.png");
              if(imageloose==NULL)
              {
                  SDL_DestroyRenderer(ren);
                  SDL_DestroyWindow(win);
                  SDLError("Erreur lors du chargement de l'image");
              }
              textureloose=SDL_CreateTextureFromSurface(ren,imageloose);

              //libération de la surloose car plus besoin
              SDL_FreeSurface(imageloose);

              if(textureloose==NULL)
              {
                  SDL_DestroyRenderer(ren);
                  SDL_DestroyWindow(win);
                  SDLError("Erreur lors de la création de la texture bouton abandon");
              }
              //l'image est chargé en mémoire


              //chargement de la texture
              SDL_Rect rectangleloose;
              if(SDL_QueryTexture(textureloose,NULL,NULL,&rectangleloose.w,&rectangleloose.h)!=0)
              {
                  SDL_DestroyRenderer(ren);
                  SDL_DestroyWindow(win);
                  SDLError("Erreur lors de l'affichage de l'image");
              }

              //positionnement du bouton
              rectangleloose.x=500;
              rectangleloose.y=500;

              //
              //affichage de l'image
              if(SDL_RenderCopy(ren,textureloose,NULL, &rectangleloose)!=0)
              {
                  SDL_DestroyRenderer(ren);
                  SDL_DestroyWindow(win);
                  SDLError("Erreur lors de l'affichage de l'image");
              }

              SDL_RenderPresent(ren);
              SDL_DestroyTexture(textureloose);
            }
           	else{
              imagewin=IMG_Load("../data/menu/win.jfif");
              if(imagewin==NULL)
              {
                  SDL_DestroyRenderer(ren);
                  SDL_DestroyWindow(win);
                  SDLError("Erreur lors du chargement de l'image");
              }
              texturewin=SDL_CreateTextureFromSurface(ren,imagewin);

              //libération de la surwin car plus besoin
              SDL_FreeSurface(imagewin);

              if(texturewin==NULL)
              {
                  SDL_DestroyRenderer(ren);
                  SDL_DestroyWindow(win);
                  SDLError("Erreur lors de la création de la texture bouton abandon");
              }
              //l'image est chargé en mémoire


              //chargement de la texture
              SDL_Rect rectanglewin;
              if(SDL_QueryTexture(texturewin,NULL,NULL,&rectanglewin.w,&rectanglewin.h)!=0)
              {
                  SDL_DestroyRenderer(ren);
                  SDL_DestroyWindow(win);
                  SDLError("Erreur lors de l'affichage de l'image");
              }

              //positionnement du bouton
              rectanglewin.x=500;
              rectanglewin.y=500;

              //
              //affichage de l'image
              if(SDL_RenderCopy(ren,texturewin,NULL, &rectanglewin)!=0)
              {
                  SDL_DestroyRenderer(ren);
                  SDL_DestroyWindow(win);
                  SDLError("Erreur lors de l'affichage de l'image");
              }

              SDL_RenderPresent(ren);
               SDL_DestroyTexture(texturewin);

            }

           	}
            if(event.button.x >=0 && event.button.x<=142 && event.button.y>=750 && event.button.y<=841){
              SDL_RenderClear(ren);
              showshop();
              SDL_DestroyTexture(textureBoutonshop);
            }
          }

           break;
         }


 }



 SDL_DestroyTexture(texturepile);
 SDL_DestroyTexture(textureface);
 SDL_DestroyRenderer(ren);
 SDL_DestroyWindow(win);




 SDL_Quit();

 return EXIT_SUCCESS;
 }
