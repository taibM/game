#include<string.h>
#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
int main(void)
{
SDL_Surface *screen;
SDL_Surface *map;
SDL_Rect posmap ;
SDL_Event event;
  
Mix_Music* myMus;
   
int continuee =1;
screen=SDL_SetVideoMode(1280,720,0,SDL_HWSURFACE|SDL_DOUBLEBUF);
map=IMG_Load("back1.jpg");
SDL_Init(SDL_INIT_AUDIO);
                      /* code à exécuter en cas de pression sur une touche du clavier */
 if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS, 1024)==-1);
printf("%s",Mix_GetError());    
 
   
          
 
                      myMus = Mix_LoadMUS ("Once Upon A Time.wav");
                    
                      Mix_PlayMusic(myMus, -1);
while (continuee)
{
                      
posmap.x=0;            
posmap.y=0;
SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 255, 0));
SDL_BlitSurface(map,NULL,screen,&posmap);
SDL_Flip(screen);
SDL_PollEvent(&event);

switch(event.type)
{
case SDL_QUIT:
continuee=0;
break;
}
}
SDL_FreeSurface(screen);
SDL_FreeSurface(map);
Mix_FreeMusic (myMus);
Mix_CloseAudio();

return EXIT_SUCCESS;
}

