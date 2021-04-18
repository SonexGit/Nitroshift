#ifndef RENDER_H_
#define RENDER_H_

#define SCREEN_ORIGINAL_WIDTH 1600 // à ne pas changer pour l'instant
#define SCREEN_ORIGINAL_HEIGHT 900 // à ne pas changer pour l'instant

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900

SDL_Window *win;
SDL_Renderer *ren;

int rendering();
int stopRendering();

#endif // RENDER_H_
