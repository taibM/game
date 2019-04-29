#include<string.h>
#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#define LARGEUR_SPRITE 32    
#define HAUTEUR_SPRITE 32
int main(int argc, char *argv[])
{
    SDL_Surface *screen = NULL, *rectangle = NULL;
    SDL_Rect position;

    SDL_Rect posradar;
    SDL_Surface *radar;
    radar=IMG_Load("h.png");
    
    posradar.x=0;
    posradar.y=580;
    posradar.h=5;
    posradar.w=5;


    position.x = 0; 
    position.y = 520;
     
    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE);
    rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 220, 300, 32, 0, 255, 255, 0);
    

SDL_Event event;
int continuer=1;

while(continuer)
{
int x=100;
SDL_Delay(x);
if (posradar.x<220||posradar.y<720)
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
                posradar.y=posradar.y-1;
                x = 50;
                break; 
            case SDLK_DOWN:
                
                posradar.y=posradar.y+1;
                 x = 50;
                break;
            case SDLK_RIGHT:
                x = 50;
                 posradar.x=posradar.x+1;             
                break;
            case SDLK_LEFT:
                posradar.x=posradar.x-1;
                x = 50;
                    
                       
                break;

        break;
}
}


  
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 17, 206, 112));
    SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 255, 255, 255)); 
    SDL_BlitSurface(rectangle, NULL, screen, &position); 
    SDL_BlitSurface(radar,NULL,screen,&posradar);
    SDL_Flip(screen); 
    }

   else
{
   posradar.x=0;
   posradar.y=580;
}
   }
  SDL_FreeSurface(radar);
  SDL_FreeSurface(screen);
  SDL_FreeSurface(rectangle); 
    

    return EXIT_SUCCESS;
}


