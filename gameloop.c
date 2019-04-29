#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include<string.h>
#include<math.h>
#include "projet1.h"
#include "projet1.c"
#include "trigo.c"
#include "enigme.c"
#include <time.h>

//------------------------------------
//----------------------------------------
//------------------------------------------
typedef struct joueur joueur;
struct joueur
{
SDL_Surface *personnage;
SDL_Rect pospersonnage ;
int vie ;
int score ;
SDL_Rect  spriteSrc; 
};
//-------------------------------------
typedef struct score 
{
SDL_Rect position ;  
} score ; 
//------------------------------------
typedef enum bool
{false ,true}bool;

void  startgame(SDL_Surface *screen,SDL_Surface*background,SDL_Rect* position_background)
{

    double v_x = 1.5;
    double v_grav = 0.08;
    double v_saut = -3.9;
    double v_y = v_saut;
	int x2=0;


//----------------------------------------------
SDL_Rect camera;
const int speed=20;
Uint32 start;
const int FPS=30;
int x,y;
camera.x=0;
camera.y=0;
camera.w=2267;
camera.h=720;
bool b[2]={0,0};
//----------------------------------------------
 int distance;
 //SDL_Rect position_background;
 position_background->x=0;
 position_background->y=0;
 position_background->w=background->w;
 position_background->h=background->h;
 joueur j;
 score s;
//---------------------------------
 SDL_Color noir = {0,0,0}, rouge = {100,0,0};
 TTF_Init();
TTF_Font *police ;
 police = TTF_OpenFont("Capture_it.ttf", 50);
 Uint32 t1 ,t2;
 t1 = SDL_GetTicks();
char chrono[16] ;
SDL_Surface*texte=NULL;
//-----------------------------
//---------------------------------
 j.spriteSrc.x =0;// Coordonnée x du sprite que l'on veut sur l'image
 j.spriteSrc.y =0; // Coordonnée y du sprite que l'on veut sur l'image
 j.spriteSrc.w = 60;
 j.spriteSrc.h = 120;
 j.personnage=IMG_Load("ghada.png");

 SDL_SetColorKey (j.personnage,SDL_SRCCOLORKEY,SDL_MapRGB(j.personnage->format,255,255,255));
j.pospersonnage.x=0;
j.pospersonnage.y=410; 
j.pospersonnage.w=60;
j.pospersonnage.h=200;
//---------------------------------
 object o;
 Sentity c,c1,c2;
 int count=1;
Init_Sentity(&c1,"jack",1000,600);
Init_Sentity(&c2,"jack",500,600);

   int continuer=1;
  SDL_Event event;
  background=IMG_Load("adam.png"); 

int save=0;
int etat=0;
int k=0;
int x1=0;
//---------------------------------------------
//---------------------------------------------
 while(continuer)
 { 
//----------------------------------------
  SDL_PollEvent (&event);
  SDL_EnableKeyRepeat(10,10);
   switch(event.type)
   {
     case SDL_QUIT:
      continuer=0;
     break;
     case SDL_KEYDOWN:
      switch(event.key.keysym.sym)
      {
		
		 
	       case SDLK_UP:
		if(j.pospersonnage.x<640)
		{
		 k=1;
		 x1=j.pospersonnage.x;
		}	
		break;
               case SDLK_LEFT:
if(k!=1){
                if(j.pospersonnage.x>20) 
                {
		 j.pospersonnage.x=j.pospersonnage.x-20;
 
		 //b[1]=1;
		}
}
               break;
               case SDLK_RIGHT:
if(k!=1){
                 if(j.pospersonnage.x<640)
      	          j.pospersonnage.x=j.pospersonnage.x+20;		
                 else 
                  b[0]=1;
//----------------------------------------------------
                 if(j.spriteSrc.x!=240)
                    j.spriteSrc.x=j.spriteSrc.x+60;
                 else
                  j.spriteSrc.x=0;
}
                 break;
      
//----------------------------------------------------
     case SDL_KEYUP:
      switch(event.key.keysym.sym)
      {
        case SDLK_RIGHT:
         b[0]=0;
        break;
//------------------------------
	case SDLK_LEFT:
	 b[1]=0;
        break; 
      }
     break;
     }
   }
//--------------------------------------------------------------------------
if(b[0])
{
 x+=speed;
 camera.x+=speed;
  if(camera.x>=8000-600)
    camera.x=0;
}
else if(b[1])
{
 x-=speed;
 camera.x-=speed;
  if(camera.x<=0)
    camera.x=2267-266;
}
//--------------------------------------------------------------------------
 if(k==1 && ((x2-x1)<111))
   {
	j.pospersonnage.x+=v_x;
	j.pospersonnage.y+=v_y;
	v_y+=v_grav;
   }
 else k=0;
	x2=j.pospersonnage.x;


  SDL_BlitSurface(background,&camera,screen,NULL);
  SDL_BlitSurface(j.personnage,&j.spriteSrc,screen,&j.pospersonnage);
  b[0]=0;
  b[1]=0;
 Afficher_Sentity(c1,background);
Afficher_Sentity(c2,background);
 
//--------------------------------------------------
    t2 = SDL_GetTicks() - t1;   //Minute       //Seconde 
    sprintf(chrono, "%u:%u", t2/1000/60%60, t2/1000%60);
    texte = TTF_RenderText_Shaded(police, chrono, rouge,noir);
 
    SDL_BlitSurface(texte, NULL, screen, 0);
    SDL_Flip(screen);
//---------------------------------------------------
//-------------------------------------------------
  distance= collusion_trigonometrique_inscrit(j.personnage,c.surface,j.pospersonnage,c.pos);
  if(distance)
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
SDL_Delay(1000);
quiz(ecran,d);
SDL_BlitSurface(backg,NULL, ecran, &positiond);
SDL_Flip(ecran);
reponse(ecran,d);
SDL_FreeSurface(backg);
TTF_CloseFont(police);
TTF_Quit();
continuer=0;

   }
 }
TTF_CloseFont (police);
      //SDL_FreeSurface(texte) ;
      //SDL_Quit();
}
//------------------------------------------------

//-------------------------------------------------
void  gameloop1(SDL_Surface *screen,SDL_Surface*background,char ch1[],char ch2[],SDL_Rect position_newgame, SDL_Rect position_curseur)
{
 SDL_Surface *newgame=NULL;
 SDL_Surface *curseur=NULL;

 SDL_Rect position_background;

 position_background.x=0;
 position_background.y=0;

 int i=1,continuer=1;
 SDL_Event event;
 int choix=0;
 char path[10];
 newgame=IMG_Load(ch1);
 curseur=IMG_Load(ch2);
 while(continuer)
 {
  SDL_PollEvent (&event);
   switch(event.type)
   {
     case SDL_QUIT:
      continuer=0;
     break;
     case SDL_KEYDOWN:
      switch(event.key.keysym.sym)
      {
       case SDLK_LEFT:
        if(position_curseur.x==1027)
         {
          position_curseur.x=722;
          position_curseur.y=490;
         }
        else if(position_curseur.x==722)
          position_curseur.x=367;
       break;
       case SDLK_RIGHT:
        if(position_curseur.x==367)
         position_curseur.x=722;
        else if(position_curseur.x==722)
         {
          position_curseur.x=1027;
          position_curseur.y=570;
         }
       break;
       case SDLK_SPACE: 
        if (position_curseur.x==1027)
         continuer=0;
        else if(position_curseur.x==722)
            choix=1;
        else if(position_curseur.x==367)
          choix=2;
        if(choix==1 || choix ==2)
         {
	   SDL_Rect position_background;//il faut ajouter choix au start game et 
           startgame(screen,background,&position_background);
           event.key.keysym.sym=SDLK_ESCAPE;
         }
         
       break;
      }
     break;
   }
  sprintf(path,"menuu/a (%d).jpg",i);
  i++;
  background=IMG_Load(path);
  SDL_BlitSurface(background,NULL,screen,&position_background);
  SDL_BlitSurface(newgame,NULL,screen,&position_newgame);
  SDL_BlitSurface(curseur,NULL,screen,&position_curseur);
  SDL_Flip(screen);
  SDL_Delay(1000/15);
  SDL_FreeSurface(background);
  if(i==60)
   i=1;
 }

 SDL_FreeSurface(curseur);
 SDL_FreeSurface(newgame);

}
//----------------------------------------------
//----------------------------------------------
void  gameloop2(SDL_Surface *screen,SDL_Surface*background,char ch1[],char ch2[],SDL_Rect position_newgame, SDL_Rect position_curseur)
{
 SDL_Surface *newgame=NULL;
 SDL_Surface *curseur=NULL;

 SDL_Rect position_background;

 position_background.x=0;
 position_background.y=0;

 int i=1,continuer=1;
 SDL_Event event;

 char path[10];
 newgame=IMG_Load(ch1);
 curseur=IMG_Load(ch2);
 while(continuer)
 {
  SDL_PollEvent (&event);
   switch(event.type)
   {
     case SDL_QUIT:
      continuer=0;
     break;
     case SDL_KEYDOWN:
      switch(event.key.keysym.sym)
      {
       case SDLK_LEFT:
        if(position_curseur.x==960)
         {
          position_curseur.x=692;
          position_curseur.y=344;
         }
        else if(position_curseur.x==692)
          position_curseur.x=340;
       break;
       case SDLK_RIGHT:
        if(position_curseur.x==340)
         position_curseur.x=692;
        else if(position_curseur.x==692)
         {
          position_curseur.x=960;
          position_curseur.y=520;
         }
       break;
       case SDLK_SPACE:
        if(position_curseur.x==960)
         continuer=0;
        else if(position_curseur.x==692)
         Mix_PauseMusic(); 
        else if(position_curseur.x==340)
         Mix_ResumeMusic();
       break;
      }
     break;
   }
  sprintf(path,"menuu/a (%d).jpg",i);
  i++;
  background=IMG_Load(path);
  SDL_BlitSurface(background,NULL,screen,&position_background);
  SDL_BlitSurface(newgame,NULL,screen,&position_newgame);
  SDL_BlitSurface(curseur,NULL,screen,&position_curseur);
  SDL_Flip(screen);
  SDL_Delay(1000/15);
  SDL_FreeSurface(background);
  if(i==60)
   i=1;
 }

 SDL_FreeSurface(curseur);
 SDL_FreeSurface(newgame);

}

//--------------------------------------------------------------------
//--------------------------------------------------------------------






















