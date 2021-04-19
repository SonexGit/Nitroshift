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
#include "zone.h"
#include "apropos.h"

void niveau()
{

    SDL_SetRenderDrawColor(ren, 249, 228, 183, 255);
    SDL_RenderClear(ren);
    SDL_SetRenderDrawColor(ren, 249, 228, 183, 255);
    SDL_Surface *imagenb1 = NULL;
    SDL_Texture *texturenb1 = NULL;

    SDL_Surface *imagenb2 = NULL;
    SDL_Texture *texturenb2 = NULL;

    SDL_Surface *imagenb3 = NULL;
    SDL_Texture *texturenb3 = NULL;

    SDL_Surface *imageretour = NULL;
    SDL_Texture *textureretour = NULL;

    SDL_Surface *imagechoix = NULL;
    SDL_Texture *texturechoix = NULL;

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    imagechoix = IMG_Load("../data/menu/niveau.png");
    if (imagechoix == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        //SDLError("Erreur lors du chargement de l'image");
    }
    texturechoix = SDL_CreateTextureFromSurface(ren, imagechoix);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imagechoix);

    if (texturechoix == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        //SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire

    //chargement de la texture
    SDL_Rect rectanglechoix;
    if (SDL_QueryTexture(texturechoix, NULL, NULL, &rectanglechoix.w, &rectanglechoix.h) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        //SDLError("Erreur lors de l'affichage de l'image");
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
        //SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);

    imagenb1 = IMG_Load("../data/menu/nb1.png");
    if (imagenb1 == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        //SDLError("Erreur lors du chargement de l'image");
    }
    texturenb1 = SDL_CreateTextureFromSurface(ren, imagenb1);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imagenb1);

    if (texturenb1 == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        //SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire

    //chargement de la texture
    SDL_Rect rectanglenb1;
    if (SDL_QueryTexture(texturenb1, NULL, NULL, &rectanglenb1.w, &rectanglenb1.h) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        //SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectanglenb1.x = 70;
    rectanglenb1.y = 480;
    rectanglenb1.w = imagenb1->w * 2;
    rectanglenb1.h = imagenb1->h * 2;
    //
    //affichage de l'image
    if (SDL_RenderCopy(ren, texturenb1, NULL, &rectanglenb1) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        //SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);
    /*    *****************Bouton nb3 pour les règles   */
    imagenb3 = IMG_Load("../data/menu/nb3.png");
    if (imagenb3 == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        //SDLError("Erreur lors du chargement de l'image");
    }
    texturenb3 = SDL_CreateTextureFromSurface(ren, imagenb3);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imagenb3);

    if (texturenb3 == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        //SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire

    //chargement de la texture
    SDL_Rect rectanglenb3;
    if (SDL_QueryTexture(texturenb3, NULL, NULL, &rectanglenb3.w, &rectanglenb3.h) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        //SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectanglenb3.x = 1300;
    rectanglenb3.y = 480;
    rectanglenb3.w = imagenb3->w * 2;
    rectanglenb3.h = imagenb3->h * 2;
    //
    //affichage de l'image
    if (SDL_RenderCopy(ren, texturenb3, NULL, &rectanglenb3) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        //SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);
    /*    Bouton a charger  */
    imageretour = IMG_Load("../data/menu/bouton_retour.png");
    if (imageretour == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        //SDLError("Erreur lors du chargement de l'image");
    }
    textureretour = SDL_CreateTextureFromSurface(ren, imageretour);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imageretour);

    if (textureretour == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        //SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire

    //chargement de la texture
    SDL_Rect rectangleretour;
    if (SDL_QueryTexture(textureretour, NULL, NULL, &rectangleretour.w, &rectangleretour.h) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        //SDLError("Erreur lors de l'affichage de l'image");
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
        //SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);

    /*    Bouton jouer  */
    imagenb2 = IMG_Load("../data/menu/nb2.png");
    if (imagenb2 == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        //SDLError("Erreur lors du chargement de l'image");
    }
    texturenb2 = SDL_CreateTextureFromSurface(ren, imagenb2);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imagenb2);

    if (texturenb2 == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        //SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire

    //chargement de la texture
    SDL_Rect rectanglenb2;
    if (SDL_QueryTexture(texturenb2, NULL, NULL, &rectanglenb2.w, &rectanglenb2.h) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        //SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectanglenb2.x = 650;
    rectanglenb2.y = 480;
    rectanglenb2.w = imagenb2->w * 2;
    rectanglenb2.h = imagenb2->h * 2;
    //
    //affichage de l'image
    if (SDL_RenderCopy(ren, texturenb2, NULL, &rectanglenb2) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        //SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);

    int continuer = 3;
    SDL_Event event;


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
                if (numeroZone == 1)
                {
                    if (event.button.x >= 70 && event.button.x <= 354 && event.button.y >= 480 && event.button.y <= 662)
                    {
                        if (a1.z1.niveau1 == 1)
                        {
                            levelCombat = 1;
                            SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
                            SDL_RenderClear(ren);
                            SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
                            affichagePlateau();
                        }
                    }
                    if (event.button.x >= 650 && event.button.x <= 934 && event.button.y >= 480 && event.button.y <= 662)
                    {
                        if (a1.z1.niveau2 == 1)
                        {
                            levelCombat = 2;
                            SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
                            SDL_RenderClear(ren);
                            SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
                            affichagePlateau();
                        }
                    }
                    if (event.button.x >= 1300 && event.button.x <= 1584 && event.button.y >= 480 && event.button.y <= 662)
                    {
                        if (a1.z1.niveau3 == 1)
                        {
                            levelCombat = 3;
                            SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
                            SDL_RenderClear(ren);
                            SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
                            affichagePlateau();
                        }
                    }
                }
                if (numeroZone == 2)
                {
                    if (event.button.x >= 70 && event.button.x <= 354 && event.button.y >= 480 && event.button.y <= 662)
                    {
                        if (a1.z2.niveau1 == 1)
                        {
                            levelCombat = 4;
                            SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
                            SDL_RenderClear(ren);
                            SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
                            affichagePlateau();
                        }
                    }
                    if (event.button.x >= 650 && event.button.x <= 934 && event.button.y >= 480 && event.button.y <= 662)
                    {
                        if (a1.z2.niveau2 == 1)
                        {
                            levelCombat = 5;
                            SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
                            SDL_RenderClear(ren);
                            SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
                            affichagePlateau();
                        }
                    }
                    if (event.button.x >= 1300 && event.button.x <= 1584 && event.button.y >= 480 && event.button.y <= 662)
                    {
                        if (a1.z2.niveau3 == 1)
                        {
                            levelCombat = 6;
                            SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
                            SDL_RenderClear(ren);
                            SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
                            affichagePlateau();
                        }
                    }
                }
                if (numeroZone == 3)
                {
                    if (event.button.x >= 70 && event.button.x <= 354 && event.button.y >= 480 && event.button.y <= 662)
                    {
                        if (a1.z3.niveau1 == 1)
                        {
                            levelCombat = 7;
                            SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
                            SDL_RenderClear(ren);
                            SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
                            affichagePlateau();
                        }
                    }
                    if (event.button.x >= 650 && event.button.x <= 934 && event.button.y >= 480 && event.button.y <= 662)
                    {
                        if (a1.z3.niveau2 == 1)
                        {
                            levelCombat = 8;
                            SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
                            SDL_RenderClear(ren);
                            SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
                            affichagePlateau();
                        }
                    }
                    if (event.button.x >= 1300 && event.button.x <= 1584 && event.button.y >= 480 && event.button.y <= 662)
                    {
                        if (a1.z3.niveau3 == 1)
                        {
                            levelCombat = 9;
                            SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
                            SDL_RenderClear(ren);
                            SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
                            affichagePlateau();
                        }
                    }
                }
                if (event.button.x >= 20 && event.button.x <= 162 && event.button.y >= 10 && event.button.y <= 101)
                {
                    SDL_SetRenderDrawColor(ren, 249, 228, 183, 255);
                    SDL_RenderClear(ren);
                    SDL_SetRenderDrawColor(ren, 249, 228, 183, 255);
                    choix_zone_carte();
                }
                break;
            }
        }
    }

    SDL_DestroyTexture(texturenb1);
    SDL_DestroyTexture(texturenb2);
    SDL_DestroyTexture(texturenb3);
    SDL_DestroyTexture(texture_menu);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);

    SDL_Quit();

    return EXIT_SUCCESS;
}
