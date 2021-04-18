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
#include "mesmodif.h"
#include "pile.h"
#include "shifumi.h"
#include "menujeu.h"
#include "amelioration.h"
#include "shop.h"

/**
 * \fn void showsauver
 * \brief fonction qui permet de créer le sauver
 * \return la fenetre avec le sauver et ces boutons
 */

void saveok()
{
  SDL_Surface * icon = IMG_Load("../data/icon.png");
  SDL_SetWindowIcon(win, icon);

    SDL_Surface * surface_sauver = IMG_Load("../data/menu/sauver.png");
    SDL_Texture * texture_sauver=SDL_CreateTextureFromSurface(ren,surface_sauver);

    SDL_Surface *imageretour = NULL;
    SDL_Texture *textureretour = NULL;

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    if(surface_sauver==NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    texture_sauver=SDL_CreateTextureFromSurface(ren,surface_sauver);

    //libération de la surface car plus besoin
    SDL_FreeSurface(surface_sauver);

    if(texture_sauver==NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire


    //chargement de la texture
    SDL_Rect rectanglesauver;
    if(SDL_QueryTexture(texture_sauver,NULL,NULL,&rectanglesauver.w,&rectanglesauver.h)!=0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
      //positionnement du bouton
    rectanglesauver.x=450;
    rectanglesauver.y=350;
    rectanglesauver.w = surface_sauver->w *2;
    rectanglesauver.h = surface_sauver->h *2;
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    //affichage de l'image
    if(SDL_RenderCopy(ren,texture_sauver,NULL, &rectanglesauver)!=0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

 SDL_RenderPresent(ren);


 imageretour=IMG_Load("../data/menu/bouton_retour.png");
 if(imageretour==NULL)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors du chargement de l'image");
 }
 textureretour=SDL_CreateTextureFromSurface(ren,imageretour);

 //libération de la surface car plus besoin
 SDL_FreeSurface(imageretour);

 if(textureretour==NULL)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors de la création de la texture bouton abandon");
 }
 //l'image est chargé en mémoire


 //chargement de la texture
 SDL_Rect rectangleretour;
 if(SDL_QueryTexture(textureretour,NULL,NULL,&rectangleretour.w,&rectangleretour.h)!=0)
 {
     SDL_DestroyRenderer(ren);
     SDL_DestroyWindow(win);
     SDLError("Erreur lors de l'affichage de l'image");
 }

 //positionnement du bouton
 rectangleretour.x=20;
 rectangleretour.y=10;
 //
 //affichage de l'image
 if(SDL_RenderCopy(ren,textureretour,NULL, &rectangleretour)!=0)
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
             	  if(event.button.x >=20 && event.button.x<=162 && event.button.y>=10 && event.button.y<=101){
          SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
          SDL_RenderClear(ren);
          SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
          showmenu();
        }

             	break;
            }
        }

    }



    SDL_DestroyTexture(texture_sauver);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);




    SDL_Quit();

    return EXIT_SUCCESS;
}
