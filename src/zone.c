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

void choix_zone_carte()
{

    SDL_SetRenderDrawColor(ren, 249, 228, 183, 255);
    SDL_RenderClear(ren);
    SDL_SetRenderDrawColor(ren, 249, 228, 183, 255);
    SDL_Surface *imagez1 = NULL;
    SDL_Texture *texturez1 = NULL;

    SDL_Surface *imagez2 = NULL;
    SDL_Texture *texturez2 = NULL;

    SDL_Surface *imagez3 = NULL;
    SDL_Texture *texturez3 = NULL;

    SDL_Surface *imageretour = NULL;
    SDL_Texture *textureretour = NULL;

    SDL_Surface *imagechoix = NULL;
    SDL_Texture *texturechoix = NULL;

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    imagechoix = IMG_Load("../data/menu/choix_zone.png");
    if (imagechoix == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    texturechoix = SDL_CreateTextureFromSurface(ren, imagechoix);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imagechoix);

    if (texturechoix == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire

    //chargement de la texture
    SDL_Rect rectanglechoix;
    if (SDL_QueryTexture(texturechoix, NULL, NULL, &rectanglechoix.w, &rectanglechoix.h) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectanglechoix.x = 720;
    rectanglechoix.y = 10;

    //
    //affichage de l'image
    if (SDL_RenderCopy(ren, texturechoix, NULL, &rectanglechoix) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);

    imagez1 = IMG_Load("../data/menu/z1.png");
    if (imagez1 == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    texturez1 = SDL_CreateTextureFromSurface(ren, imagez1);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imagez1);

    if (texturez1 == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire

    //chargement de la texture
    SDL_Rect rectanglez1;
    if (SDL_QueryTexture(texturez1, NULL, NULL, &rectanglez1.w, &rectanglez1.h) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectanglez1.x = 70;
    rectanglez1.y = 480;
    rectanglez1.w = imagez1->w * 2;
    rectanglez1.h = imagez1->h * 2;
    //
    //affichage de l'image
    if (SDL_RenderCopy(ren, texturez1, NULL, &rectanglez1) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);
    /*    *****************Bouton z3 pour les règles   */
    imagez3 = IMG_Load("../data/menu/z1.png");
    if (imagez3 == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    texturez3 = SDL_CreateTextureFromSurface(ren, imagez3);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imagez3);

    if (texturez3 == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire

    //chargement de la texture
    SDL_Rect rectanglez3;
    if (SDL_QueryTexture(texturez3, NULL, NULL, &rectanglez3.w, &rectanglez3.h) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectanglez3.x = 1340;
    rectanglez3.y = 480;
    rectanglez3.w = imagez3->w * 2;
    rectanglez3.h = imagez3->h * 2;
    //
    //affichage de l'image
    if (SDL_RenderCopy(ren, texturez3, NULL, &rectanglez3) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);
    /*    Bouton a charger  */
    imageretour = IMG_Load("../data/menu/bouton_retour.png");
    if (imageretour == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    textureretour = SDL_CreateTextureFromSurface(ren, imageretour);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imageretour);

    if (textureretour == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire

    //chargement de la texture
    SDL_Rect rectangleretour;
    if (SDL_QueryTexture(textureretour, NULL, NULL, &rectangleretour.w, &rectangleretour.h) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectangleretour.x = 20;
    rectangleretour.y = 10;
    //
    //affichage de l'image
    if (SDL_RenderCopy(ren, textureretour, NULL, &rectangleretour) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);

    /*    Bouton jouer  */
    imagez2 = IMG_Load("../data/menu/z1.png");
    if (imagez2 == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    texturez2 = SDL_CreateTextureFromSurface(ren, imagez2);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imagez2);

    if (texturez2 == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire

    //chargement de la texture
    SDL_Rect rectanglez2;
    if (SDL_QueryTexture(texturez2, NULL, NULL, &rectanglez2.w, &rectanglez2.h) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectanglez2.x = 720;
    rectanglez2.y = 480;
    rectanglez2.w = imagez2->w * 2;
    rectanglez2.h = imagez2->h * 2;
    //
    //affichage de l'image
    if (SDL_RenderCopy(ren, texturez2, NULL, &rectanglez2) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);
    a1.zone1 = 1;

    SDL_bool mouse_hover = SDL_FALSE;
    int continuer = 3;
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
                if (event.button.x >= 70 && event.button.x <= 326 && event.button.y >= 480 && event.button.y <= 736)
                {
                    creationAcces();
                    if (a1.zone1 == 1)
                    {
                        numeroZone =1;
                        SDL_RenderClear(ren);
                        niveau();
                    }
                }
                if (event.button.x >= 720 && event.button.x <= 976 && event.button.y >= 480 && event.button.y <= 736)
                {
                    creationAcces();
                    if (a1.zone2 == 1)
                    {
                        numeroZone = 2;
                        SDL_RenderClear(ren);
                        niveau();
                    }
                }
                if (event.button.x >= 1340 && event.button.x <= 1596 && event.button.y >= 480 && event.button.y <= 736)
                {
                    creationAcces();
                    if (a1.zone3 == 1)
                    {
                        numeroZone = 3;
                        SDL_RenderClear(ren);
                        niveau();
                    }
                }
                if (event.button.x >= 20 && event.button.x <= 162 && event.button.y >= 10 && event.button.y <= 101)
                {
                    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
                    SDL_RenderClear(ren);
                    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
                    showmenu();
                }

                break;
            }
        }
    }

    SDL_DestroyTexture(texturez1);
    SDL_DestroyTexture(texturez2);
    SDL_DestroyTexture(texturez3);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);

    return EXIT_SUCCESS;
}
