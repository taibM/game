#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "enigme.h"
#include <SDL/SDL_ttf.h>
#include <time.h>

int main()
{
int d=1;

srand(time(NULL));   // should only be called once
d=rand()%13; 
TTF_Init();
if(TTF_Init()==-1)
{fprintf(stderr,"ERREUR INIT: %s \n",TTF_GetError());
exit(EXIT_FAILURE);}
SDL_Color couleurnoir={0,0,0};
SDL_Surface *texte = NULL, *backg=NULL ; //declaration des variables globales 
SDL_Rect positiontexte,positiond;
positiontexte.x=640;
positiontexte.y=360;
TTF_Font *police;//(pointeur contient parametre de la police) 
SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL
SDL_Surface *ecran =NULL;
police=TTF_OpenFont("Raleway-ThinItalic.ttf",130);
ecran=SDL_SetVideoMode(1280, 720, 32,SDL_ANYFORMAT); // Ouverture de la fenêtre
backg = IMG_Load("quiz.png");
positiond.x=0 ; 
positiond.y=0 ; 
SDL_BlitSurface(backg,NULL, ecran, &positiond);
SDL_Flip(ecran);
texte=TTF_RenderText_Blended(police,"Enigme!",couleurnoir);
SDL_BlitSurface(texte,NULL,ecran,&positiontexte);
SDL_Flip(ecran);
SDL_Delay(2000);
quiz(ecran,d);
SDL_BlitSurface(backg,NULL, ecran, &positiond);
SDL_Flip(ecran);
reponse(ecran,d);
SDL_FreeSurface(backg);
TTF_CloseFont(police);
TTF_Quit();
SDL_Quit(); // Arrêt de la SDL 

    return EXIT_SUCCESS; // Fermeture du programme
}
