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
#include "shop.h"
#include "zone.h"
#include "apropos.h"
/**
 * \fn void showmenu
 * \brief fonction qui permet de créer le menu
 * \return la fenetre avec le menu et ces boutons
 */

void showamelioration()
{

    SDL_Surface *imagevie = NULL;
    SDL_Texture *texturevie = NULL;

    SDL_Surface *imageattaque = NULL;
    SDL_Texture *textureattaque = NULL;

    SDL_Surface *imagedefense = NULL;
    SDL_Texture *texturedefense = NULL;

    SDL_Surface *imageselct1 = NULL;
    SDL_Texture *textureselct1 = NULL;

    SDL_Surface *imageselct2 = NULL;
    SDL_Texture *textureselct2 = NULL;

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

  /*    Bouton quitter      */
    imageselct1=IMG_Load("../data/menu/update.png");
    if(imageselct1==NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    textureselct1=SDL_CreateTextureFromSurface(ren,imageselct1);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imageselct1);

    if(textureselct1==NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire


    //chargement de la texture
    SDL_Rect rectangleselct1;
    if(SDL_QueryTexture(textureselct1,NULL,NULL,&rectangleselct1.w,&rectangleselct1.h)!=0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }
    //positionnement du bouton
    rectangleselct1.x=20;
    rectangleselct1.y=500;

    //
    //affichage de l'image
    if(SDL_RenderCopy(ren,textureselct1,NULL, &rectangleselct1)!=0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

 SDL_RenderPresent(ren);

 imageselct2=IMG_Load("../data/menu/update.png");
 if(imageselct2==NULL)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors du chargement de l'image");
 }
 textureselct2=SDL_CreateTextureFromSurface(ren,imageselct2);

 //libération de la surface car plus besoin
 SDL_FreeSurface(imageselct2);

 if(textureselct2==NULL)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors de la création de la texture bouton abandon");
 }
 //l'image est chargé en mémoire


 //chargement de la texture
 SDL_Rect rectangleselct2;
 if(SDL_QueryTexture(textureselct2,NULL,NULL,&rectangleselct2.w,&rectangleselct2.h)!=0)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors de l'affichage de l'image");
 }
 //positionnement du bouton
 rectangleselct2.x=600;
 rectangleselct2.y=500;

 //
 //affichage de l'image
 if(SDL_RenderCopy(ren,textureselct2,NULL, &rectangleselct2)!=0)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors de l'affichage de l'image");
 }

 SDL_RenderPresent(ren);


 SDL_Surface *imageselct3 = NULL;
 SDL_Texture *textureselct3 = NULL;


 SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

 //Mise en place des boutons
 /*    Bouton quitter      */
 imageselct3=IMG_Load("../data/menu/update.png");
 if(imageselct3==NULL)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors du chargement de l'image");
 }
 textureselct3=SDL_CreateTextureFromSurface(ren,imageselct3);

 //libération de la surface car plus besoin
 SDL_FreeSurface(imageselct3);

 if(textureselct3==NULL)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors de la création de la texture bouton abandon");
 }
 //l'image est chargé en mémoire


 //chargement de la texture
 SDL_Rect rectangleselct3;
 if(SDL_QueryTexture(textureselct3,NULL,NULL,&rectangleselct3.w,&rectangleselct3.h)!=0)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors de l'affichage de l'image");
 }
 //positionnement du bouton
 rectangleselct3.x=1220;
 rectangleselct3.y=500;

 //
 //affichage de l'image
 if(SDL_RenderCopy(ren,textureselct3,NULL, &rectangleselct3)!=0)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors de l'affichage de l'image");
 }

 SDL_RenderPresent(ren);

 imagevie=IMG_Load("../data/menu/vie.png");
 if(imagevie==NULL)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors du chargement de l'image");
 }
 texturevie=SDL_CreateTextureFromSurface(ren,imagevie);

 //libération de la surface car plus besoin
 SDL_FreeSurface(imagevie);

 if(texturevie==NULL)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors de la création de la texture bouton abandon");
 }
 //l'image est chargé en mémoire


 //chargement de la texture
 SDL_Rect rectanglevie;
 if(SDL_QueryTexture(texturevie,NULL,NULL,&rectanglevie.w,&rectanglevie.h)!=0)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors de l'affichage de l'image");
 }
 //positionnement du bouton
 rectanglevie.x=40;
 rectanglevie.y=250;
 //rectanglevie.w = imagevie->w *1.5;
 //rectanglevie.h = imagevie->w *1.5;
 //
 //affichage de l'image
 if(SDL_RenderCopy(ren,texturevie,NULL, &rectanglevie)!=0)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors de l'affichage de l'image");
 }

 SDL_RenderPresent(ren);

 imageattaque=IMG_Load("../data/menu/attaque.png");
 if(imageattaque==NULL)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors du chargement de l'image");
 }
 textureattaque=SDL_CreateTextureFromSurface(ren,imageattaque);

 //libération de la surface car plus besoin
 SDL_FreeSurface(imageattaque);

 if(textureattaque==NULL)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors de la création de la texture bouton abandon");
 }
 //l'image est chargé en mémoire


 //chargement de la texture
 SDL_Rect rectangleattaque;
 if(SDL_QueryTexture(textureattaque,NULL,NULL,&rectangleattaque.w,&rectangleattaque.h)!=0)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors de l'affichage de l'image");
 }
 //positionnement du bouton
 rectangleattaque.x=620;
 rectangleattaque.y=300;

 //
 //affichage de l'image
 if(SDL_RenderCopy(ren,textureattaque,NULL, &rectangleattaque)!=0)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors de l'affichage de l'image");
 }

 SDL_RenderPresent(ren);


 imagedefense=IMG_Load("../data/menu/defense.png");
 if(imagedefense==NULL)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors du chargement de l'image");
 }
 texturedefense=SDL_CreateTextureFromSurface(ren,imagedefense);

 //libération de la surface car plus besoin
 SDL_FreeSurface(imagedefense);

 if(texturedefense==NULL)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors de la création de la texture bouton abandon");
 }
 //l'image est chargé en mémoire


 //chargement de la texture
 SDL_Rect rectangledefense;
 if(SDL_QueryTexture(texturedefense,NULL,NULL,&rectangledefense.w,&rectangledefense.h)!=0)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors de l'affichage de l'image");
 }
 //positionnement du bouton
 rectangledefense.x=1240;
 rectangledefense.y=280;

 //
 //affichage de l'image
 if(SDL_RenderCopy(ren,texturedefense,NULL, &rectangledefense)!=0)
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
             	if(event.button.x >=20 && event.button.x<=236 && event.button.y>=500 && event.button.y<=591){
                //if(v1.nitroDollars >=500){
                v1.hpMax = v1.hpMax +20;
            	//}
            }
              if(event.button.x >=600 && event.button.x<=816 && event.button.y>=500 && event.button.y<=591){
              //  if(v1.nitroDollars >=500){
                v1.attaque = v1.attaque +5;
            	//}
            }
              if(event.button.x >=1220 && event.button.x<=1436 && event.button.y>=500 && event.button.y<=591){
              //  if(v1.nitroDollars >=500){
                v1.defense = v1.defense +5;
              //}
            	}

        if(event.button.x >=0 && event.button.x<=142 && event.button.y>=750 && event.button.y<=841){
          SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
          SDL_RenderClear(ren);
          showshop();
        }


             	break;
            }
        }

    }


    SDL_DestroyTexture(textureselct1);

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);




    SDL_Quit();

    return EXIT_SUCCESS;
}
