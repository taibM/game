#include<string.h>
#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include "fonction.h"


int  main(void){
SDL_Surface *screen;
//SDL_Surface *personnage;
SDL_Surface *personnage2;
//SDL_Rect pospersonnage ;
SDL_Rect pospersonnage2 ;
joueur j ; 
SDL_Event event;
int continuer=1;
int i=1;

screen=SDL_SetVideoMode(1020,724,0,SDL_HWSURFACE|SDL_DOUBLEBUF);
j.personnage=IMG_Load("1.png");
personnage2=IMG_Load("2.png");
SDL_Delay(1000/24);
SDL_SetColorKey (j.personnage,SDL_SRCCOLORKEY,SDL_MapRGB(j.personnage->format,255,255,255));
SDL_SetColorKey (personnage2,SDL_SRCCOLORKEY,SDL_MapRGB(personnage2->format,255,255,255));
j.pospersonnage.x=0;
j.pospersonnage.y=0;
j.pospersonnage.w=50;
j.pospersonnage.h=180;
pospersonnage2.x=580;
pospersonnage2.y=580;
pospersonnage2.h=105;
pospersonnage2.w=50;
while(continuer)
{
if ((j.pospersonnage.x + j.pospersonnage.w< pospersonnage2.x) || (j.pospersonnage.x> pospersonnage2.x +pospersonnage2.w) || (j.pospersonnage.y + j.pospersonnage.h< pospersonnage2.y) || (j.pospersonnage.y>  pospersonnage2.y + pospersonnage2.h ))
 {
SDL_PollEvent(&event);
switch(event.type)
{
    case SDL_QUIT:
        continuer = 0;
        break;
    case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
            case SDLK_UP:
                
                j.pospersonnage.y--;
                break; 
            case SDLK_DOWN:
                
                j.pospersonnage.y++;
                break;
            case SDLK_RIGHT:
                j.pospersonnage.x++;
             
                
                break;
            case SDLK_LEFT:
                j.pospersonnage.x--;
                
                
                break;

        break;
}
}
SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 255, 0));
SDL_BlitSurface(j.personnage,NULL,screen,&j.pospersonnage);
SDL_BlitSurface(personnage2,NULL,screen,&pospersonnage2);
SDL_Flip(screen);
}
else 
    continuer =0;
}
return 0;
}

