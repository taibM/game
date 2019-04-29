#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct 
{ 
  SDL_Surface background;
  SDL_Rect camera;
}background;

typedef struct 
{
  SDL_Surface *personnage;
  SDL_Rect pospersonnage;
}joueur;

void scroll (int direction,joueur *j,background *map);
void display_scroll (SDL_Surface *ecran,background map);
