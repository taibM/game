#include<stdio.h>
#include<stdlib.h>

#include"SDL/SDL.h"
#include"SDL/SDL_image.h"

typedef struct joueur
{
SDL_Surface *personnage;
SDL_Rect pospersonnage ;
int vie ;
int score ;
SDL_Rect  spriteSrc; 

}joueur;

void init_deux(joueur * j2);
void affichage_inter( joueur j2,SDL_Surface* screen);
void liberation_inter(joueur* j2,SDL_Surface* screen );
