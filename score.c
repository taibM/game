#define WIDTH 1000
#define HEIGHT 560
#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
void score(joueur j,TTF_Font font)
{
 
 joueur->score +=100;
 SDL_Color black={0,0,0};
sprintf( joueur->scoreImage, "score :%d", joueur->score );
  joueur->scoreSurface = TTF_RenderText_Solid( font, joueur->scoreImage , black );
}
