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
#include "saveok.h"

/**
 * \fn void showmenu
 * \brief fonction qui permet de créer le menu
 * \return la fenetre avec le menu et ces boutons
 */

void showmenu()
{
    Mix_Music *myMus;

    /* On initialise le son */
    SDL_Init(SDL_INIT_AUDIO);

    /* On ouvre un device audio */
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);
    Mix_VolumeMusic(MIX_MAX_VOLUME / 40);
    /* On charge un fichier musical */
    myMus = Mix_LoadMUS("../data/music/menumusic.mp3");

    /* On lance la musique */
    Mix_PlayMusic(myMus, 1);

    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024) == -1) //Initialisation de l'API Mixer
    {
        printf("%s", Mix_GetError());
    }

    SDL_Surface *icon = IMG_Load("../data/icon.png");
    SDL_SetWindowIcon(win, icon);

    SDL_Surface *surface_menu = IMG_Load("../data/menu/menu.png");
    SDL_Texture *texture_menu = SDL_CreateTextureFromSurface(ren, surface_menu);

    SDL_Surface *imageBoutonquitter = NULL;
    SDL_Texture *textureBoutonquitter = NULL;

    SDL_Surface *imageBoutonjouer = NULL;
    SDL_Texture *textureBoutonjouer = NULL;

    SDL_Surface *imagetitre = NULL;
    SDL_Texture *texturetitre = NULL;

    SDL_Surface *imageBoutontuto = NULL;
    SDL_Texture *textureBoutontuto = NULL;

    SDL_Surface *imageBoutoncharger = NULL;
    SDL_Texture *textureBoutoncharger = NULL;

    SDL_Surface *imageBoutonsave = NULL;
    SDL_Texture *textureBoutonsave = NULL;

    SDL_Surface *imageBoutonshop = NULL;
    SDL_Texture *textureBoutonshop = NULL;
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    //image de fond
    surface_menu = IMG_Load("../data/menu/im.jpeg");
    if (surface_menu == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    texture_menu = SDL_CreateTextureFromSurface(ren, surface_menu);

    //libération de la surface car plus besoin
    SDL_FreeSurface(surface_menu);

    if (texture_menu == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire

    //chargement de la texture
    SDL_Rect rectanglemenu;
    if (SDL_QueryTexture(texture_menu, NULL, NULL, &rectanglemenu.w, &rectanglemenu.h) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectanglemenu.x = 0;
    rectanglemenu.y = 0;
    rectanglemenu.w = surface_menu->w / 1.2;
    rectanglemenu.h = surface_menu->h / 1.2;
    //
    //affichage de l'image
    if (SDL_RenderCopy(ren, texture_menu, NULL, &rectanglemenu) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);

    imageBoutonshop = IMG_Load("../data/menu/shop.png");
    if (imageBoutonshop == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    textureBoutonshop = SDL_CreateTextureFromSurface(ren, imageBoutonshop);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imageBoutonshop);

    if (textureBoutonshop == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire

    //chargement de la texture
    SDL_Rect rectangleBoutonshop;
    if (SDL_QueryTexture(textureBoutonshop, NULL, NULL, &rectangleBoutonshop.w, &rectangleBoutonshop.h) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectangleBoutonshop.x = 1250;
    rectangleBoutonshop.y = 375;
    //
    //affichage de l'image
    if (SDL_RenderCopy(ren, textureBoutonshop, NULL, &rectangleBoutonshop) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);

    imageBoutonsave = IMG_Load("../data/menu/save.png");
    if (imageBoutonsave == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    textureBoutonsave = SDL_CreateTextureFromSurface(ren, imageBoutonsave);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imageBoutonsave);

    if (textureBoutonsave == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire

    //chargement de la texture
    SDL_Rect rectangleBoutonsave;
    if (SDL_QueryTexture(textureBoutonsave, NULL, NULL, &rectangleBoutonsave.w, &rectangleBoutonsave.h) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectangleBoutonsave.x = 1250;
    rectangleBoutonsave.y = 250;
    //
    //affichage de l'image
    if (SDL_RenderCopy(ren, textureBoutonsave, NULL, &rectangleBoutonsave) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);
    //Mise en place des boutons
    /*    Bouton quitter      */
    imageBoutonquitter = IMG_Load("../data/menu/bouton_quitter.png");
    if (imageBoutonquitter == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    textureBoutonquitter = SDL_CreateTextureFromSurface(ren, imageBoutonquitter);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imageBoutonquitter);

    if (textureBoutonquitter == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire

    //chargement de la texture
    SDL_Rect rectangleBoutonquitter;
    if (SDL_QueryTexture(textureBoutonquitter, NULL, NULL, &rectangleBoutonquitter.w, &rectangleBoutonquitter.h) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectangleBoutonquitter.x = 20;
    rectangleBoutonquitter.y = 500;
    //
    //affichage de l'image
    if (SDL_RenderCopy(ren, textureBoutonquitter, NULL, &rectangleBoutonquitter) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);
    /*    *****************Bouton titre pour les règles   */
    imagetitre = IMG_Load("../data/menu/titre.png");
    if (imagetitre == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    texturetitre = SDL_CreateTextureFromSurface(ren, imagetitre);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imagetitre);

    if (texturetitre == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire

    //chargement de la texture
    SDL_Rect rectangletitre;
    if (SDL_QueryTexture(texturetitre, NULL, NULL, &rectangletitre.w, &rectangletitre.h) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectangletitre.x = 0;
    rectangletitre.y = 0;
    //
    //affichage de l'image
    if (SDL_RenderCopy(ren, texturetitre, NULL, &rectangletitre) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);
    /*    Bouton a charger  */
    imageBoutoncharger = IMG_Load("../data/menu/Bouton_charger.png");
    if (imageBoutoncharger == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    textureBoutoncharger = SDL_CreateTextureFromSurface(ren, imageBoutoncharger);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imageBoutoncharger);

    if (textureBoutoncharger == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire

    //chargement de la texture
    SDL_Rect rectangleBoutoncharger;
    if (SDL_QueryTexture(textureBoutoncharger, NULL, NULL, &rectangleBoutoncharger.w, &rectangleBoutoncharger.h) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectangleBoutoncharger.x = 0;
    rectangleBoutoncharger.y = 375;
    //
    //affichage de l'image
    if (SDL_RenderCopy(ren, textureBoutoncharger, NULL, &rectangleBoutoncharger) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);

    /*    Bouton jouer  */
    imageBoutonjouer = IMG_Load("../data/menu/bouton_play.png");
    if (imageBoutonjouer == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    textureBoutonjouer = SDL_CreateTextureFromSurface(ren, imageBoutonjouer);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imageBoutonjouer);

    if (textureBoutonjouer == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire

    //chargement de la texture
    SDL_Rect rectangleBoutonjouer;
    if (SDL_QueryTexture(textureBoutonjouer, NULL, NULL, &rectangleBoutonjouer.w, &rectangleBoutonjouer.h) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectangleBoutonjouer.x = 0;
    rectangleBoutonjouer.y = 250;
    //
    //affichage de l'image
    if (SDL_RenderCopy(ren, textureBoutonjouer, NULL, &rectangleBoutonjouer) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    SDL_RenderPresent(ren);

    /*    Bouton a tuto      */
    imageBoutontuto = IMG_Load("../data/menu/tuto.png");
    if (imageBoutontuto == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors du chargement de l'image");
    }
    textureBoutontuto = SDL_CreateTextureFromSurface(ren, imageBoutontuto);

    //libération de la surface car plus besoin
    SDL_FreeSurface(imageBoutontuto);

    if (textureBoutontuto == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de la création de la texture bouton abandon");
    }
    //l'image est chargé en mémoire

    //chargement de la texture
    SDL_Rect rectangleBoutontuto;
    if (SDL_QueryTexture(textureBoutontuto, NULL, NULL, &rectangleBoutontuto.w, &rectangleBoutontuto.h) != 0)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDLError("Erreur lors de l'affichage de l'image");
    }

    //positionnement du bouton
    rectangleBoutontuto.x = 20;
    rectangleBoutontuto.y = 600;
    //
    //affichage de l'image
    if (SDL_RenderCopy(ren, textureBoutontuto, NULL, &rectangleBoutontuto) != 0)
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
                if (event.button.x >= 0 && event.button.x <= 380 && event.button.y >= 250 && event.button.y <= 322)
                {
                    Mix_FreeMusic(myMus);
                    Mix_CloseAudio();
                    Mix_Quit();
                    SDL_RenderClear(ren);
                    showtest();
                }
                if (event.button.x >= 1250 && event.button.x <= 1378 && event.button.y >= 375 && event.button.y <= 426)
                {
                    SDL_RenderClear(ren);
                    showshop();
                }
                if (event.button.x >= 1250 && event.button.x <= 1577 && event.button.y >= 250 && event.button.y <= 307)
                {
                    sauvegarderPartie();
                    SDL_RenderClear(ren);
                    saveok();
                }
                if (event.button.x >= 0 && event.button.x <= 375 && event.button.y >= 375 && event.button.y <= 451)
                {
                    SDL_RenderClear(ren);
                    choix_zone_carte();
                }
                break;
            }
        }
    }

    SDL_DestroyTexture(textureBoutonjouer);
    SDL_DestroyTexture(textureBoutonquitter);
    SDL_DestroyTexture(textureBoutoncharger);
    SDL_DestroyTexture(textureBoutontuto);
    SDL_DestroyTexture(texture_menu);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);

    /* La musique est terminée, on la libère */
    Mix_FreeMusic(myMus);
    /* On libère le matériel */
    Mix_CloseAudio();
    Mix_Quit();

    SDL_Quit();

    return EXIT_SUCCESS;
}

void SDLError(const char *message)
{
    SDL_Log("Erreur : %s > %s ! \n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}
