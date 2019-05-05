#include<string.h>
#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include"2eme.h"
#define LARGEUR_SPRITE 32    
#define HAUTEUR_SPRITE 3


void init_deux( joueur* j2)
{
	j2->personnage = IMG_Load("sprite3.png");;
	//i->radar=IMG_Load("pos.png");
    	
    
    	j2->pospersonnage.x=720;
    	j2->pospersonnage.y=300;
    	j2->pospersonnage.h=40;
    	j2->pospersonnage.w=110;


    	j2->spriteSrc.x =0;// Coordonnée x du sprite que l'on veut sur l'image
        j2->spriteSrc.y =0; // Coordonnée y du sprite que l'on veut sur l'image
        j2->spriteSrc.w = 60;
        j2->spriteSrc.h = 120;

}
void affichage_inter( joueur j2,SDL_Surface* screen)
{
SDL_Event event;
int continuer=1;

while(continuer)
{
int x=300;
SDL_Delay(x);
	if (1)
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
            case SDLK_z:    
                j2.pospersonnage.y=j2.pospersonnage.y-50;
                x = 100;
                break; 
            case SDLK_s:
                
                j2.pospersonnage.y=j2.pospersonnage.y+50;
                 x = 100;
                break;
            case SDLK_d:
                x = 100;
                 j2.pospersonnage.x=j2.pospersonnage.x+50;
                

                if(j2.spriteSrc.x!=240)
                {
                    j2.spriteSrc.x=j2.spriteSrc.x+60;
                }
                else
                   {j2.spriteSrc.x=0;}
               

             
                break;
            case SDLK_q:
                j2.pospersonnage.x=j2.pospersonnage.x-50;; 
                j2.spriteSrc.x=j2.spriteSrc.x-0;
                x = 100;
                    
                       
                break;

        		break;
			}
	}


  
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format,255,255,255)); 
    SDL_BlitSurface(j2.personnage,&j2.spriteSrc,screen,&j2.pospersonnage);
    SDL_Flip(screen); 
    }

 
   }
}

void liberation_inter(joueur * j2,SDL_Surface* screen )
{
	  SDL_FreeSurface(j2->personnage);
  	  SDL_FreeSurface(screen);
  	 
}




int main(int argc, char *argv[])
{
    joueur j2;
    SDL_Surface *screen = NULL;
    init_deux(&j2);
     
    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE);
    
affichage_inter(j2,screen);
liberation_inter(&j2,screen);


    

    return EXIT_SUCCESS;
}








