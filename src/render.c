#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"

#include <stdio.h>
#include <stdlib.h>

#include "render.h"

int rendering()
{

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}

	win = SDL_CreateWindow("Nitroshift", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1600, 900, SDL_WINDOW_SHOWN);
	if (win == NULL)
	{
		fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	if (ren == NULL)
	{
		fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
		if (win != NULL)
		{
			SDL_DestroyWindow(win);
		}
		SDL_Quit();
		return EXIT_FAILURE;
	}

	// Ajouté récemment, peut-être que ça ne sert à rien ?
	// C'est pour filtrer le rendu au pixel le plus proche (lorsqu'on zoom notamment)
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");

	return EXIT_SUCCESS;
}

int stopRendering() {

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();

	return EXIT_SUCCESS;
}