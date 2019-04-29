/**
*@file trigo.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <math.h>
//--------------------------------------------------------------------
//-----------------------------------------------------------------------
/**
*@brief detects if there is a collusion
*@param image1 the first image 
*@param image2 the second image 
*@param the position_image1 the position of the first image 
*@param the position of the second image 
*@return returns 1 if there is a collusion and 0 else
*/
int collusion_trigonometrique_inscrit(SDL_Surface *image1, SDL_Surface *image2,SDL_Rect position_image1,SDL_Rect position_image2)
{
 float centre1_x=position_image1.x+(position_image1.w/2);
 float centre1_y=position_image1.y+(position_image1.h/2);
 float r1,distance;
 if(position_image1.w<position_image1.h)
  r1=position_image1.w/2;
 else r1=position_image1.h/2;

 float centre2_x=position_image2.x+(position_image2.w/2);
 float centre2_y=position_image2.y+(position_image2.h/2);
 float r2;
 if(position_image2.w<position_image2.h)
  r2=position_image2.w/2;
 else r2=position_image2.h/2;

double a=(centre2_x-centre1_x)*(centre2_x-centre1_x)+(centre2_y-centre1_y)*(centre2_y-centre1_y);

 distance=sqrt(a)-(r1+r2);
 

 if(distance<=0)
  return 1;
 else return 0;
}
//----------------------------------------------------------------------
//----------------------------------------------------------------------
int collusion_trigonometrique_circonscrit(SDL_Surface *image1, SDL_Surface *image2,SDL_Rect position_image1,SDL_Rect position_image2)
{
 float centre1_x=position_image1.x+(position_image1.w/2);
 float centre1_y=position_image1.y+(position_image1.h/2);
 float r1,distance;
 double a=(position_image1.w/2)*(position_image1.w/2)+(position_image1.h/2)*(position_image1.h/2) ;

  r1=sqrt(a);

 float centre2_x=position_image2.x+(position_image2.w/2);
 float centre2_y=position_image2.y+(position_image2.h/2);
 float r2;
 a=(position_image2.w/2)*(position_image2.w/2)+(position_image2.h/2)*(position_image2.h/2) ;
 r2=sqrt(a);

 a=(centre2_x-centre1_x)*(centre2_x-centre1_x)+(centre2_y-centre1_y)*(centre2_y-centre1_y);
 distance=sqrt(a)-r1-r2 ;
  if(distance<=0)
  return 1;
 else
  return 0;
}
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
/*int main()
{
 SDL_Surface *screen=NULL,*perso1,*perso2;
 SDL_Rect position1,position2;
 int continuer=1;
 SDL_Event event;
 int collusion;
//-----------------------------------------------------
//-----------------------------------------
 SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
 screen=SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
 perso1=IMG_Load("cercle1.png");
 perso2=IMG_Load("cercle2.png");

 position1.x=600;
 position1.y=100;

 position2.x=100;
 position2.y=100;
//-----------------------------------------
 SDL_EnableKeyRepeat(10,10);
 while(continuer)
 {
  SDL_WaitEvent(&event);
  switch(event.type)
  {
   case SDL_QUIT:
    continuer=0;
    break;
   case SDL_KEYDOWN:
    switch(event.key.keysym.sym)
    {
     case SDLK_RIGHT:
      position2.x=position2.x+7;
      break;
     case SDLK_LEFT:
      position2.x=position2.x-7;
      break;
     case SDLK_DOWN:
      position2.y=position2.y+7;
      break;
     case SDLK_UP: 
      position2.y=position2.y-7;
      break;
    }

  }
  collusion=collusion_trigonometrique_inscrit(perso1,perso2,position1,position2);
 
  if(collusion)
   continuer=0;
  SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
  SDL_BlitSurface(perso1,NULL,screen,&position1);
  SDL_BlitSurface(perso2,NULL,screen,&position2);
  SDL_Flip(screen);
 }
//-----------------------------------------
 SDL_FreeSurface(perso1);
 SDL_FreeSurface(perso2);
 SDL_Quit();
}*/
