#include "perso.h"

int main(int argc, char *argv[])
{

Uint32 dt,t_prev;
Personne p;
int i,j=-1;
SDL_Surface *obstacle=NULL,*screen=NULL,*image=NULL;
SDL_Rect positionObstacle,positionImage;;
SDL_Event evenement;

Mix_Music *music=NULL;
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
Mix_VolumeMusic(MIX_MAX_VOLUME/5);
music = Mix_LoadMUS("s.mp3");
Mix_PlayMusic(music,-1);

SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO);
TTF_Init();
IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
screen=SDL_SetVideoMode(800,400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

obstacle=IMG_Load("sapin.png");
image=IMG_Load("b.png");

positionObstacle.x=400;
positionObstacle.y=285;
positionImage.x=0;
positionImage.y=0;

    p.posMarioRel.x =p.postion.x;
    p.posMarioRel.y =p.postion.y;


int continuer=1;

initPerso(&p);

while(continuer)
{

t_prev=SDL_GetTicks();

SDL_PollEvent(&evenement);

SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
SDL_BlitSurface(image,NULL,screen,&positionImage);
SDL_BlitSurface(obstacle,NULL,screen,&positionObstacle);
afficherPerso(&p,screen);
p.key=-1;


switch(evenement.type)
{
case SDL_QUIT:
continuer=0;
break;

case SDL_KEYDOWN:
if(evenement.key.keysym.sym==SDLK_RIGHT)
{
p.key=1;
p.etat=0;
}

else if(evenement.key.keysym.sym==SDLK_LEFT)
{
p.key=0;
p.etat=1;
p.j=0;
}
else if(evenement.key.keysym.sym==SDLK_UP)
{
//p.acceleration+=0.005;
p.key=2;
}
else if(evenement.key.keysym.sym==SDLK_a)//acceleration
{
p.acceleration+=0.005;
}
else if(evenement.key.keysym.sym==SDLK_d)//sauter 
{

p.sauter=1;
}

else if(evenement.key.keysym.sym==SDLK_r)//ralentir
{
if(p.dx>0)
{
p.acceleration-=0.01;
}
}
break;

}
deplacerPerso (&p,dt);
animerPerso (&p);
updatePerso(&p);

if(p.sauter==1)
{
sauter(&p,screen);
}

dt=SDL_GetTicks()-t_prev;
}


SDL_FreeSurface(image);
liberer(&p);
SDL_FreeSurface(obstacle);
Mix_FreeMusic(music);


TTF_Quit();
SDL_Quit();
 return 0;
}


