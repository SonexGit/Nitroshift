void positionnerboutonretour(){
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
		//SDL_DestroyTexture(textureBoutonretour);
}
showmenu();

positionnerboutonretour();

case SDL_MOUSEBUTTONDOWN:
     if(event.button.x >=0 && event.button.x<=142 && event.button.y>=750 && event.button.y<=841){
       SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
       SDL_RenderClear(ren);
       showmenu();

     }
    break;
