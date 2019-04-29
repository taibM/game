#include<string.h>
#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#define LARGEUR_SPRITE 32    
#define HAUTEUR_SPRITE 32
#include "fonction.h"


int main (void)
{
SDL_Surface *screen;
joueur j;
SDL_Rect pospersonnage2 ;
SDL_Surface *personnage2;
personnage2=IMG_Load("p.png");
SDL_SetColorKey (personnage2,SDL_SRCCOLORKEY,SDL_MapRGB(personnage2->format,255,255,255));

j.spriteSrc.x =0;// Coordonnée x du sprite que l'on veut sur l'image
j.spriteSrc.y =0; // Coordonnée y du sprite que l'on veut sur l'image
j.spriteSrc.w = 60;
j.spriteSrc.h = 120;
pospersonnage2.x=580;
pospersonnage2.y=580;
pospersonnage2.h=105;
pospersonnage2.w=50;

SDL_Event event;
int continuer=1;
int i=1;

screen=SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
j.personnage=IMG_Load("sprite3.png");

SDL_SetColorKey (j.personnage,SDL_SRCCOLORKEY,SDL_MapRGB(j.personnage->format,255,255,255));
j.pospersonnage.x=0;
j.pospersonnage.y=0;
j.pospersonnage.w=60;
j.pospersonnage.h=200;

while(continuer)
{
int x=100;
SDL_Delay(x);
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
                j.pospersonnage.y=j.pospersonnage.y-50;
                x = 50;
                break; 
            case SDLK_DOWN:
                
                j.pospersonnage.y=j.pospersonnage.y+50;
                 x = 50;
                break;
            case SDLK_RIGHT:
                x = 50;
                 j.pospersonnage.x=j.pospersonnage.x+50;
                

                if(j.spriteSrc.x!=240)
                {
                    j.spriteSrc.x=j.spriteSrc.x+60;
                }
                else
                   {j.spriteSrc.x=0;}
               

             
                break;
            case SDLK_LEFT:
                j.pospersonnage.x=j.pospersonnage.x-50;; 
                j.spriteSrc.x=j.spriteSrc.x-0;
                x = 50;
                    
                       
                break;

        break;
}
}
SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 255, 0));
SDL_BlitSurface(j.personnage,&j.spriteSrc,screen,&j.pospersonnage);
SDL_BlitSurface(personnage2,NULL,screen,&pospersonnage2);
SDL_UpdateRect(screen, 0, 0, 0, 0);
SDL_Flip(screen);

}

else
 continuer=0;
}
SDL_FreeSurface(j.personnage);
SDL_FreeSurface(screen);



return 0;}












