#include<string.h>
#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include "fonction.h"

void  init(joueur j)
{
SDL_Surface *screen;
//SDL_Surface *personnage;
//SDL_Rect pospersonnage ;


int numstage =2,continuee =1;
screen=SDL_SetVideoMode(1020,724,0,SDL_HWSURFACE|SDL_DOUBLEBUF);
j.personnage=IMG_Load("1.png");
SDL_Delay(1000/24);
SDL_SetColorKey (j.personnage,SDL_SRCCOLORKEY,SDL_MapRGB(j.personnage->format,255,255,255));

while (continuee)
{
if (numstage ==1)
{
j.pospersonnage.x=10;
j.pospersonnage.y=10;
}
if (numstage ==2)
{
j.pospersonnage.x=0;
j.pospersonnage.y=0;
}
if (numstage ==3)
{
j.pospersonnage.x=15;
j.pospersonnage.y=15;
}
SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 255, 0));
SDL_BlitSurface(j.personnage,NULL,screen,&j.pospersonnage);
SDL_Flip(screen);
}

}
