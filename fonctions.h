#ifndef FONCTIONS_H_IMCLUDED
#define FONCTIONS_H_IMCLUDED
#endif
#include "gameloop.c"
#include "projet1.h"

#include "enigme.h"
void  gameloop1(SDL_Surface *screen,SDL_Surface*background,char ch1[],char ch2[],SDL_Rect position_newgame, SDL_Rect position_curseur);
void  gameloop2(SDL_Surface *screen,SDL_Surface*background,char ch1[],char ch2[],SDL_Rect position_newgame, SDL_Rect position_curseur);
void  startgame(SDL_Surface *screen,SDL_Surface*background,SDL_Rect *position_background);
int collusion_trigonometrique_inscrit(SDL_Surface *image1, SDL_Surface *image2,SDL_Rect position_image1,SDL_Rect position_image2);
