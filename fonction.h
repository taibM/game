typedef struct joueur joueur;
struct joueur
{
SDL_Surface *personnage;
SDL_Rect pospersonnage ;
int vie ;
int score ;
SDL_Rect  spriteSrc; 

};
void  animationn(joueur *j);


