#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"



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
#include "apropos.h"
#include "menujeu.h"
#include "mesmodif.h"
#include "pile.h"
#include "amelioration.h"

/**
  *\file shifumi.c
 * \author lucas allan leo enzo
 * \version 1.0
 * \brief programme contenant la fonction d'un mini-jeu
 * \date 19 avril 2021
  */

 ///Initialisation des images avec une texture\n
 ///positionnement des images\n
 ///check d'evènement avec les clics de la souris\n
 ///lancer une partie de pierre-feuille-ciseaux\n

 /**
  * \fn void pierre(void)
  * \brief fonction qui permet de créer le mini-jeu pierre-feuille-ciseaux
  * \param aucun parametre
  * \return la fenetre avec le mini-jeu pierre-feuille-ciseaux
  */

void pierre()
{
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
    SDL_Surface * icon = IMG_Load("../data/icon.png");
    SDL_SetWindowIcon(win, icon);

    SDL_Surface *imagewin = NULL;
    SDL_Texture *texturewin = NULL;

    SDL_Surface *imageegal = NULL;
    SDL_Texture *textureegal = NULL;

    SDL_Surface *imageciseaux = NULL;
    SDL_Texture *textureciseaux = NULL;

    SDL_Surface *imageloose = NULL;
    SDL_Texture *textureloose = NULL;

    SDL_Surface *imagepierre = NULL;
    SDL_Texture *texturepierre = NULL;

    SDL_Surface *imagefeuille = NULL;
   	SDL_Texture *texturefeuille = NULL;

    SDL_Surface *imageBoutonshop = NULL;
   	SDL_Texture *textureBoutonshop = NULL;
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
       SDL_RenderPresent(ren);
      /*    Bouton a ciseaux */
      imageciseaux=IMG_Load("../data/menu/ciseaux.jfif");
      if(imageciseaux==NULL)
      {
          SDL_DestroyRenderer(ren);
          SDL_DestroyWindow(win);
          SDLError("Erreur lors du chargement de l'image");
      }
      textureciseaux=SDL_CreateTextureFromSurface(ren,imageciseaux);

      //libération de la surface car plus besoin
      SDL_FreeSurface(imageciseaux);

      if(textureciseaux==NULL)
      {
          SDL_DestroyRenderer(ren);
          SDL_DestroyWindow(win);
          SDLError("Erreur lors de la création de la texture bouton retour");
      }
      //l'image est chargé en mémoire


      //chargement de la texture
      SDL_Rect rectangleciseaux;
      if(SDL_QueryTexture(textureciseaux,NULL,NULL,&rectangleciseaux.w,&rectangleciseaux.h)!=0)
      {
          SDL_DestroyRenderer(ren);
          SDL_DestroyWindow(win);
          SDLError("Erreur lors de l'affichage de l'image");
      }

      //positionnement du bouton
      rectangleciseaux.x=500;
      rectangleciseaux.y=250;
      //
      //affichage de l'image
      if(SDL_RenderCopy(ren,textureciseaux,NULL, &rectangleciseaux)!=0)
      {
          SDL_DestroyRenderer(ren);
          SDL_DestroyWindow(win);
          SDLError("Erreur lors de l'affichage de l'image");
      }

 SDL_RenderPresent(ren);

   	/*    Bouton a retour      */
   		imagefeuille=IMG_Load("../data/menu/feuille.jfif");
   		if(imagefeuille==NULL)
   		{
   				SDL_DestroyRenderer(ren);
   				SDL_DestroyWindow(win);
   				SDLError("Erreur lors du chargement de l'image");
   		}
   		texturefeuille=SDL_CreateTextureFromSurface(ren,imagefeuille);

   		//libération de la surface car plus besoin
   		SDL_FreeSurface(imagefeuille);

   		if(texturefeuille==NULL)
   		{
   				SDL_DestroyRenderer(ren);
   				SDL_DestroyWindow(win);
   				SDLError("Erreur lors de la création de la texture bouton retour");
   		}
   		//l'image est chargé en mémoire


   		//chargement de la texture
   		SDL_Rect rectanglefeuille;
   		if(SDL_QueryTexture(texturefeuille,NULL,NULL,&rectanglefeuille.w,&rectanglefeuille.h)!=0)
   		{
   				SDL_DestroyRenderer(ren);
   				SDL_DestroyWindow(win);
   				SDLError("Erreur lors de l'affichage de l'image");
   		}

   		//positionnement du bouton
   		rectanglefeuille.x=200;
   		rectanglefeuille.y=250;
   		//
   		//affichage de l'image
   		if(SDL_RenderCopy(ren,texturefeuille,NULL, &rectanglefeuille)!=0)
   		{
   				SDL_DestroyRenderer(ren);
   				SDL_DestroyWindow(win);
   				SDLError("Erreur lors de l'affichage de l'image");
   		}
 SDL_RenderPresent(ren);
    imagepierre=IMG_Load("../data/menu/pierre.jfif");
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
    rectanglepierre.y=250;

    //
    //affichage de l'image
    if(SDL_RenderCopy(ren,texturepierre,NULL, &rectanglepierre)!=0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }



 SDL_RenderPresent(ren);
 char choixDuJoueur;
 char choixDuRobot;
 int score =0, nombreAuHasard = 0, quitter = 1, robot = 0;
 srand(time(NULL));
 nombreAuHasard = (rand() % (3 - 1 + 1)) + 1;
 if (nombreAuHasard == 1)
 {
     choixDuRobot = 'P';
 }
 else if (nombreAuHasard == 2)
 {
     choixDuRobot = 'F';
 }
 else if (nombreAuHasard == 3)
 {
     choixDuRobot = 'C';
 }
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
           if(event.button.x >=0 && event.button.x<=225 && event.button.y>=250 && event.button.y<=475){
             //if(v1.nitroDollars >= 500){
             //v1.nitroDollars = v1.nitroDollars-500;
/*pierre*/       choixDuJoueur == 'P';
              if (choixDuRobot == 'F')
                {
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


                else if (choixDuRobot == 'C')
                {
                  //v1.nitroDollars = v1.nitroDollars+1000;
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
                else{
                //  v1.nitroDollars = v1.nitroDollars+500;
                  imageegal=IMG_Load("../data/menu/egal.png");
                  if(imageegal==NULL)
                  {
                      SDL_DestroyRenderer(ren);
                      SDL_DestroyWindow(win);
                      SDLError("Erreur lors du chargement de l'image");
                  }
                  textureegal=SDL_CreateTextureFromSurface(ren,imageegal);

                  //libération de la suregal car plus besoin
                  SDL_FreeSurface(imageegal);

                  if(textureegal==NULL)
                  {
                      SDL_DestroyRenderer(ren);
                      SDL_DestroyWindow(win);
                      SDLError("Erreur lors de la création de la texture bouton abandon");
                  }
                  //l'image est chargé en mémoire


                  //chargement de la texture
                  SDL_Rect rectangleegal;
                  if(SDL_QueryTexture(textureegal,NULL,NULL,&rectangleegal.w,&rectangleegal.h)!=0)
                  {
                      SDL_DestroyRenderer(ren);
                      SDL_DestroyWindow(win);
                      SDLError("Erreur lors de l'affichage de l'image");
                  }

                  //positionnement du bouton
                  rectangleegal.x=500;
                  rectangleegal.y=500;
                  rectangleegal.h = imageegal->h /2;
                  rectangleegal.w = imageegal->w /2;
                  //
                  //affichage de l'image
                  if(SDL_RenderCopy(ren,textureegal,NULL, &rectangleegal)!=0)
                  {
                      SDL_DestroyRenderer(ren);
                      SDL_DestroyWindow(win);
                      SDLError("Erreur lors de l'affichage de l'image");
                  }

                  SDL_RenderPresent(ren);
                   SDL_DestroyTexture(textureegal);
                }


              }

                //-------------------------------------------------------------------------------------------------
           if(event.button.x >=200 && event.button.x<=425 && event.button.y>=250 && event.button.y<=475){
             //if (v1.nitroDollars >= 500){
          //   v1.nitroDollars = v1.nitroDollars-500;
             choixDuJoueur == 'F';
             if (choixDuRobot == 'P')
                 {
                //   v1.nitroDollars = v1.nitroDollars+1000;
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
                 else if (choixDuRobot == 'C'){
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
                 //v1.nitroDollars = v1.nitroDollars+500;
                 imageegal=IMG_Load("../data/menu/egal.png");
                 if(imageegal==NULL)
                 {
                     SDL_DestroyRenderer(ren);
                     SDL_DestroyWindow(win);
                     SDLError("Erreur lors du chargement de l'image");
                 }
                 textureegal=SDL_CreateTextureFromSurface(ren,imageegal);

                 //libération de la suregal car plus besoin
                 SDL_FreeSurface(imageegal);

                 if(textureegal==NULL)
                 {
                     SDL_DestroyRenderer(ren);
                     SDL_DestroyWindow(win);
                     SDLError("Erreur lors de la création de la texture bouton abandon");
                 }
                 //l'image est chargé en mémoire


                 //chargement de la texture
                 SDL_Rect rectangleegal;
                 if(SDL_QueryTexture(textureegal,NULL,NULL,&rectangleegal.w,&rectangleegal.h)!=0)
                 {
                     SDL_DestroyRenderer(ren);
                     SDL_DestroyWindow(win);
                     SDLError("Erreur lors de l'affichage de l'image");
                 }

                 //positionnement du bouton
                 rectangleegal.x=500;
                 rectangleegal.y=500;
                 rectangleegal.h = imageegal->h /2;
                 rectangleegal.w = imageegal->w /2;
                 //
                 //affichage de l'image
                 if(SDL_RenderCopy(ren,textureegal,NULL, &rectangleegal)!=0)
                 {
                     SDL_DestroyRenderer(ren);
                     SDL_DestroyWindow(win);
                     SDLError("Erreur lors de l'affichage de l'image");
                 }

                 SDL_RenderPresent(ren);
                  SDL_DestroyTexture(textureegal);
               }
             }

            if(event.button.x >=500 && event.button.x<=725 && event.button.y>=250 && event.button.y<=475){
              //if (v1.nitroDollars >= 500){
            //  v1.nitroDollars = v1.nitroDollars-500;
/*ciseaux*/choixDuJoueur == 'C';
  if (choixDuRobot == 'F'){
  //  v1.nitroDollars = v1.nitroDollars+1000;
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
    else if (choixDuRobot == 'P')
    {imageloose=IMG_Load("../data/menu/lose.png");
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
    //v1.nitroDollars = v1.nitroDollars+500;
    imageegal=IMG_Load("../data/menu/egal.png");
    if(imageegal==NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    textureegal=SDL_CreateTextureFromSurface(ren,imageegal);

    //libération de la suregal car plus besoin
    SDL_FreeSurface(imageegal);

    if(textureegal==NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire


    //chargement de la texture
    SDL_Rect rectangleegal;
    if(SDL_QueryTexture(textureegal,NULL,NULL,&rectangleegal.w,&rectangleegal.h)!=0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectangleegal.x=500;
    rectangleegal.y=500;
    rectangleegal.h = imageegal->h /2;
    rectangleegal.w = imageegal->w /2;
    //
    //affichage de l'image
    if(SDL_RenderCopy(ren,textureegal,NULL, &rectangleegal)!=0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);
     SDL_DestroyTexture(textureegal);
  }
             }

            if(event.button.x >=0 && event.button.x<=142 && event.button.y>=750 && event.button.y<=841){
              SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
              SDL_RenderClear(ren);
              SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
              showshop();
              SDL_DestroyTexture(textureBoutonshop);
            }
          }

           break;
         }


 }



 SDL_DestroyTexture(texturepierre);
 SDL_DestroyTexture(texturefeuille);
  SDL_DestroyTexture(textureciseaux);
 SDL_DestroyRenderer(ren);
 SDL_DestroyWindow(win);




 SDL_Quit();

 return EXIT_SUCCESS;
 }
