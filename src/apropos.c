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
  *\file perdu.c
 * \author lucas allan leo enzo
 * \version 1.0
 * \brief programme contenant la fonction qui génère le choix de la classe
 * \date 19 avril 2021
  */

 ///Initialisation des images avec une texture\n
 ///positionnement des images et de la musique\n
 ///annonce de fin combat avec comme choix un retour au menu principal\n


 /**
  * \fn void showtest(void)
  * \brief fonction qui permet de créer la fenetre où l'on choisit sa classe avec un choix a 4 solutions
  * \param aucun parametre
  * \return la fenetre avec le choix de la classe
  */

void showtest()
{

    SDL_RenderClear(ren);
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);

    SDL_Surface *imageTank = NULL;
    SDL_Texture *textureTank = NULL;

    SDL_Surface *imagesniper = NULL;
    SDL_Texture *texturesniper = NULL;

    SDL_Surface *imagehealer = NULL;
    SDL_Texture *texturehealer = NULL;

    SDL_Surface *imageDPS = NULL;
    SDL_Texture *textureDPS = NULL;

    SDL_Surface *imageretour = NULL;
    SDL_Texture *textureretour = NULL;

    SDL_Surface *imagetankeur = NULL;
    SDL_Texture *texturetankeur = NULL;

    SDL_Surface *imagesnip = NULL;
    SDL_Texture *texturesnip = NULL;

    SDL_Surface *imageheal = NULL;
    SDL_Texture *textureheal = NULL;

    SDL_Surface *imagedp = NULL;
    SDL_Texture *texturedp = NULL;

    SDL_Surface *imageselect4 = NULL;
    SDL_Texture *textureselect4 = NULL;

    SDL_Surface *imageselect3 = NULL;
    SDL_Texture *textureselect3 = NULL;

    SDL_Surface *imageselect2 = NULL;
    SDL_Texture *textureselect2 = NULL;

    SDL_Surface *imageselect1 = NULL;
    SDL_Texture *textureselect1 = NULL;

    SDL_Surface *imagechoix = NULL;
    SDL_Texture *texturechoix = NULL;

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    imagechoix = IMG_Load("../data/menu/choix.png");
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
    rectanglechoix.h = imagechoix->h / 1.2;
    rectanglechoix.w = imagechoix->w / 1.2;
    //
    //affichage de l'image
    if (SDL_RenderCopy(ren, texturechoix, NULL, &rectanglechoix) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);

    imageselect4 = IMG_Load("../data/menu/select.png");
    if (imageselect4 == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    textureselect4 = SDL_CreateTextureFromSurface(ren, imageselect4);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imageselect4);

    if (textureselect4 == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire

    //chargement de la texture
    SDL_Rect rectangleselect4;
    if (SDL_QueryTexture(textureselect4, NULL, NULL, &rectangleselect4.w, &rectangleselect4.h) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectangleselect4.x = 1100;
    rectangleselect4.y = 680;
    //
    //affichage de l'image
    if (SDL_RenderCopy(ren, textureselect4, NULL, &rectangleselect4) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);

    imageselect3 = IMG_Load("../data/menu/select.png");
    if (imageselect3 == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    textureselect3 = SDL_CreateTextureFromSurface(ren, imageselect3);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imageselect3);

    if (textureselect3 == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire

    //chargement de la texture
    SDL_Rect rectangleselect3;
    if (SDL_QueryTexture(textureselect3, NULL, NULL, &rectangleselect3.w, &rectangleselect3.h) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectangleselect3.x = 440;
    rectangleselect3.y = 680;
    //
    //affichage de l'image
    if (SDL_RenderCopy(ren, textureselect3, NULL, &rectangleselect3) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);

    imageselect2 = IMG_Load("../data/menu/select.png");
    if (imageselect2 == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    textureselect2 = SDL_CreateTextureFromSurface(ren, imageselect2);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imageselect2);

    if (textureselect2 == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire

    //chargement de la texture
    SDL_Rect rectangleselect2;
    if (SDL_QueryTexture(textureselect2, NULL, NULL, &rectangleselect2.w, &rectangleselect2.h) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectangleselect2.x = 70;
    rectangleselect2.y = 680;
    //
    //affichage de l'image
    if (SDL_RenderCopy(ren, textureselect2, NULL, &rectangleselect2) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);

    imageselect1 = IMG_Load("../data/menu/select.png");
    if (imageselect1 == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    textureselect1 = SDL_CreateTextureFromSurface(ren, imageselect1);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imageselect1);

    if (textureselect1 == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire

    //chargement de la texture
    SDL_Rect rectangleselect1;
    if (SDL_QueryTexture(textureselect1, NULL, NULL, &rectangleselect1.w, &rectangleselect1.h) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectangleselect1.x = 800;
    rectangleselect1.y = 680;
    //
    //affichage de l'image
    if (SDL_RenderCopy(ren, textureselect1, NULL, &rectangleselect1) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);

    imagesnip = IMG_Load("../data/menu/perso1fini.png");
    if (imagesnip == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    texturesnip = SDL_CreateTextureFromSurface(ren, imagesnip);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imagesnip);

    if (texturesnip == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire

    //chargement de la texture
    SDL_Rect rectanglesnip;
    if (SDL_QueryTexture(texturesnip, NULL, NULL, &rectanglesnip.w, &rectanglesnip.h) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectanglesnip.x = 1100;
    rectanglesnip.y = 200;
    rectanglesnip.h = imagesnip->h * 2;
    rectanglesnip.w = imagesnip->w * 2;
    //
    //affichage de l'image
    if (SDL_RenderCopy(ren, texturesnip, NULL, &rectanglesnip) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);

    imagetankeur = IMG_Load("../data/menu/perso2fini.png");
    if (imagetankeur == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    texturetankeur = SDL_CreateTextureFromSurface(ren, imagetankeur);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imagetankeur);

    if (texturetankeur == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire

    //chargement de la texture
    SDL_Rect rectangletankeur;
    if (SDL_QueryTexture(texturetankeur, NULL, NULL, &rectangletankeur.w, &rectangletankeur.h) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectangletankeur.x = 50;
    rectangletankeur.y = 200;
    rectangletankeur.h = imagetankeur->h * 2;
    rectangletankeur.w = imagetankeur->w * 2;
    //
    //affichage de l'image
    if (SDL_RenderCopy(ren, texturetankeur, NULL, &rectangletankeur) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);

    imageheal = IMG_Load("../data/menu/perso3fini.png");
    if (imageheal == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    textureheal = SDL_CreateTextureFromSurface(ren, imageheal);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imageheal);

    if (textureheal == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire

    //chargement de la texture
    SDL_Rect rectangleheal;
    if (SDL_QueryTexture(textureheal, NULL, NULL, &rectangleheal.w, &rectangleheal.h) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectangleheal.x = 400;
    rectangleheal.y = 200;
    rectangleheal.h = imageheal->h * 2;
    rectangleheal.w = imageheal->w * 2;
    //
    //affichage de l'image
    if (SDL_RenderCopy(ren, textureheal, NULL, &rectangleheal) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);

    imagedp = IMG_Load("../data/menu/perso4fini.png");
    if (imagedp == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    texturedp = SDL_CreateTextureFromSurface(ren, imagedp);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imagedp);

    if (texturedp == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire

    //chargement de la texture
    SDL_Rect rectangledp;
    if (SDL_QueryTexture(texturedp, NULL, NULL, &rectangledp.w, &rectangledp.h) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectangledp.x = 750;
    rectangledp.y = 200;
    rectangledp.h = imagedp->h * 2;
    rectangledp.w = imagedp->w * 2;
    //
    //affichage de l'image
    if (SDL_RenderCopy(ren, texturedp, NULL, &rectangledp) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);

    //Mise en place des boutons
    /*    Bouton quitter      */
    imageTank = IMG_Load("../data/menu/tank.png");
    if (imageTank == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    textureTank = SDL_CreateTextureFromSurface(ren, imageTank);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imageTank);

    if (textureTank == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire

    //chargement de la texture
    SDL_Rect rectangleTank;
    if (SDL_QueryTexture(textureTank, NULL, NULL, &rectangleTank.w, &rectangleTank.h) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectangleTank.x = 1100;
    rectangleTank.y = 580;
    //
    //affichage de l'image
    if (SDL_RenderCopy(ren, textureTank, NULL, &rectangleTank) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);
    /*    *****************Bouton healer pour les règles   */
    imagehealer = IMG_Load("../data/menu/assassin.png");
    if (imagehealer == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    texturehealer = SDL_CreateTextureFromSurface(ren, imagehealer);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imagehealer);

    if (texturehealer == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire

    //chargement de la texture
    SDL_Rect rectanglehealer;
    if (SDL_QueryTexture(texturehealer, NULL, NULL, &rectanglehealer.w, &rectanglehealer.h) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectanglehealer.x = 440;
    rectanglehealer.y = 580;
    //
    //affichage de l'image
    if (SDL_RenderCopy(ren, texturehealer, NULL, &rectanglehealer) != 0)
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
    imagesniper = IMG_Load("../data/menu/sniper.png");
    if (imagesniper == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    texturesniper = SDL_CreateTextureFromSurface(ren, imagesniper);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imagesniper);

    if (texturesniper == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire

    //chargement de la texture
    SDL_Rect rectanglesniper;
    if (SDL_QueryTexture(texturesniper, NULL, NULL, &rectanglesniper.w, &rectanglesniper.h) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectanglesniper.x = 830;
    rectanglesniper.y = 580;
    //
    //affichage de l'image
    if (SDL_RenderCopy(ren, texturesniper, NULL, &rectanglesniper) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);

    /*    Bouton a DPS      */
    imageDPS = IMG_Load("../data/menu/soldat.png");
    if (imageDPS == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    textureDPS = SDL_CreateTextureFromSurface(ren, imageDPS);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imageDPS);

    if (textureDPS == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire

    //chargement de la texture
    SDL_Rect rectangleDPS;
    if (SDL_QueryTexture(textureDPS, NULL, NULL, &rectangleDPS.w, &rectangleDPS.h) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectangleDPS.x = 70;
    rectangleDPS.y = 580;
    //
    //affichage de l'image
    if (SDL_RenderCopy(ren, textureDPS, NULL, &rectangleDPS) != 0)
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
                if (event.button.x >= 20 && event.button.x <= 221 && event.button.y >= 600 && event.button.y <= 639)
                {
                    /*texte = TTf_RenderText_Blended(police,"Bienvenue a vous joueur de Nitroshift");

                  positionTxt.x=500;
                  positionTxt.y=600;
                  SDL_BlitSurface(texte,NULL,ren,&positionTxt);
                  SDL_Flip(ren);
*/

                    printf("Bienvenue a vous joueur de Nitroshift,\n");
                    printf("Ce jeu a ete cree par Leo Trottier, Allan Vannier, Enzo Rault et Lucas Renard.\n");
                    printf("Voici les regles du jeu:\n");
                    printf("Vous allez choisir un niveau allant de 1 a 4 avec comme niveau 1 la difficulte sera plus faible que celle du niveau 4.\n");
                    printf("Pour chaque niveau, vous allez avoir 3 combat avec des monstres et un 4eme combat sera le boss du niveau.\n");
                    printf("L'equipe de Nitroshift\n");
                }

                if (event.button.x >= 20 && event.button.x <= 162 && event.button.y >= 10 && event.button.y <= 101)
                {
                    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
                    SDL_RenderClear(ren);
                    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
                    showmenu();
                }
                if (event.button.x >= 1100 && event.button.x <= 1310 && event.button.y >= 680 && event.button.y <= 766)
                {
                    v1.etiquetteClasse = 10;
                    creationPersonnage();
                    SDL_RenderClear(ren);
                    SDL_SetRenderDrawColor(ren, 255, 255, 0, 255);
                    showmenu();
                }
                if (event.button.x >= 440 && event.button.x <= 650 && event.button.y >= 680 && event.button.y <= 766)
                {
                    v1.etiquetteClasse = 30;
                    creationPersonnage();
                    SDL_RenderClear(ren);
                    SDL_SetRenderDrawColor(ren, 255, 255, 0, 255);
                    showmenu();
                }
                if (event.button.x >= 70 && event.button.x <= 280 && event.button.y >= 680 && event.button.y <= 766)
                {
                    v1.etiquetteClasse = 20;
                    creationPersonnage();
                    SDL_RenderClear(ren);
                    SDL_SetRenderDrawColor(ren, 255, 255, 0, 255);
                    showmenu();
                }
                if (event.button.x >= 800 && event.button.x <= 1010 && event.button.y >= 680 && event.button.y <= 766)
                {
                    v1.etiquetteClasse = 40;
                    creationPersonnage();
                    SDL_RenderClear(ren);
                    SDL_SetRenderDrawColor(ren, 255, 255, 0, 255);
                    showmenu();
                }
                break;
            }
        }
    }

    SDL_DestroyTexture(texturesniper);
    SDL_DestroyTexture(textureTank);
    SDL_DestroyTexture(textureretour);
    SDL_DestroyTexture(textureDPS);
    SDL_DestroyTexture(texture_menu);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);

    SDL_Quit();

    return EXIT_SUCCESS;
}
