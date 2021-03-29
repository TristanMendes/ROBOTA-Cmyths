#include "perso.h"
void initPerso(Personne * p)
{



    //CHARGEMENT DES IMAGES DE L'HERO
    p->imagePerso[0][0]=IMG_Load("right1.png");
    p->imagePerso[0][1]=IMG_Load("right2.png");
    p->imagePerso[0][2]=IMG_Load("right4.png");
    p->imagePerso[0][3]=IMG_Load("right3.png");
    p->imagePerso[1][0]=IMG_Load("left1.png");
    p->imagePerso[1][1]=IMG_Load("left2.png");
    p->imagePerso[1][2]=IMG_Load("left3.png");
    p->imagePerso[1][3]=IMG_Load("left4.png");
    p->imagePerso[2][0]=IMG_Load("down1.png");
    p->imagePerso[2][1]=IMG_Load("down2.png");
    p->imagePerso[2][2]=IMG_Load("down3.png");
    p->imagePerso[2][3]=IMG_Load("down4.png");
    p->imagePerso[3][0]=IMG_Load("up1.png");
    p->imagePerso[3][1]=IMG_Load("up2.png");
    p->imagePerso[3][2]=IMG_Load("up3.png");
    p->imagePerso[3][3]=IMG_Load("up4.png");

    //CHARGEMENT DES IMAGE DE VIE
    p->V[0].image=IMG_Load("v4.png");
    p->V[1].image=IMG_Load("v3.png");
    p->V[2].image=IMG_Load("v2.png");
    p->V[3].image=IMG_Load("v1.png");
    p->etat_vie=3;
    p->V[4].image=IMG_Load("coeur.jpg");

  //INITIALISATIONS DES POSITIONS  
    p->TEXTE[0].position.x=5;
    p->TEXTE[0].position.y=5;
    p->TEXTE[1].position.x=5;
    p->TEXTE[1].position.y=25;
    p->TEXTE[2].position.x=700;
    p->TEXTE[2].position.y=5;
    p->postion.x=0;
    p->postion.y=345;
    p->V[0].position.x=5;
    p->V[0].position.y=50;    
 
  //AUTRES INITIALISATIONS
    p->vitesse=0.2;
    p->acceleration=0;
    p->etat=0;
    p->etape[0]=0;
    p->etape[1]=0;
    p->key=-1; 
    p->score=0;
    p->vie=0;
    p->temps=0;
    p->j=1;

}


void afficherPerso(Personne *p, SDL_Surface * screen)
{
char score[20],vie[20],temps[20];

TTF_Font *police=NULL;
SDL_Color couleur  = {0, 25, 255};
police =TTF_OpenFont("p1.otf",20);

sprintf(score, "SCORE:%d",p->score);
sprintf(vie, "VIE:%d",p->vie);
sprintf(temps, "TEMPS:%d",p->temps);
p->TEXTE[0].texte=TTF_RenderText_Blended(police,score, couleur);
p->TEXTE[1].texte=TTF_RenderText_Blended(police,vie, couleur);
p->TEXTE[2].texte=TTF_RenderText_Blended(police,temps, couleur);

if(p->key==2)
{
p->postion.y-=70;
SDL_BlitSurface(p->TEXTE[0].texte,NULL,screen,&p->TEXTE[0].position);
SDL_BlitSurface(p->TEXTE[1].texte,NULL,screen,&p->TEXTE[1].position);
SDL_BlitSurface(p->TEXTE[2].texte,NULL,screen,&p->TEXTE[2].position);
SDL_BlitSurface(p->V[p->etat_vie].image,NULL,screen,&p->V[0].position);
SDL_BlitSurface(p->imagePerso[p->etat][p->etape[1]],NULL,screen,&p->postion);
SDL_Flip(screen);
SDL_Delay(15);
p->postion.y=345;
}
   else  if(p->key==1||p->j==1)
    {SDL_BlitSurface(p->TEXTE[0].texte,NULL,screen,&p->TEXTE[0].position);
SDL_BlitSurface(p->TEXTE[1].texte,NULL,screen,&p->TEXTE[1].position);
SDL_BlitSurface(p->TEXTE[2].texte,NULL,screen,&p->TEXTE[2].position);
SDL_BlitSurface(p->V[p->etat_vie].image,NULL,screen,&p->V[0].position);
SDL_BlitSurface(p->imagePerso[p->etat][p->etape[0]],NULL,screen,&p->postion);
SDL_Flip(screen);       
    }

    else if(p->key==0||p->j==0)
    {SDL_BlitSurface(p->TEXTE[0].texte,NULL,screen,&p->TEXTE[0].position);
SDL_BlitSurface(p->TEXTE[1].texte,NULL,screen,&p->TEXTE[1].position);
SDL_BlitSurface(p->TEXTE[2].texte,NULL,screen,&p->TEXTE[2].position);
SDL_BlitSurface(p->V[p->etat_vie].image,NULL,screen,&p->V[0].position);
SDL_BlitSurface(p->imagePerso[p->etat][p->etape[1]],NULL,screen,&p->postion);
SDL_Flip(screen);
    }

 TTF_CloseFont(police);  
}


void deplacerPerso (Personne *p,Uint32 dt)
{
p->dx=(0.5*p->acceleration*dt*dt)+(p->vitesse*dt);

if(p->key==1&&p->postion.x<660)
{
p->postion.x+=p->dx;
}

else if(p->key==0)
{
p->postion.x-=p->dx;
}

}

void animerPerso (Personne* p)
{

//
if(p->key==1)
{

if(p->etape[0]<3)
{
	(p->etape[0])++;
}
else
{
	p->etape[0]=0;
}

}
//

else if(p->key==0)
{
if(p->etape[1]<3)
{
	(p->etape[1])++;
}
else
{
	p->etape[1]=0;
}

}
//
}

void updatePerso(Personne *p)
{
if(p->key==1&&p->postion.x<660)
{
p->score++;
if(p->score==50)
{
p->score=0;
p->vie++;
}
p->temps++;
p->j=1;
}


if(p->vie==5)
{
if(p->etat_vie<3)
{
p->etat_vie++;
}

p->vie=0;
}

if(p->etat_vie==4)
{
p->etat_vie=3;
SDL_Delay(5000);
}

if(p->postion.x>655&&p->postion.x<660&&p->key==1)
{
p->score=0;
p->vie=0;
if(p->etat_vie>0)
{p->etat_vie--;
SDL_Delay(50);
}
else 
{
p->etat_vie=4;
SDL_Delay(50);
p->score=0;
p->vie=0;
p->temps=0;
p->postion.x=0;
}
}


}


void liberer(Personne *p)
{
SDL_FreeSurface(p->imagePerso[0][0]);
SDL_FreeSurface(p->imagePerso[0][1]);
SDL_FreeSurface(p->imagePerso[0][2]);
SDL_FreeSurface(p->imagePerso[0][3]);

SDL_FreeSurface(p->imagePerso[1][0]);
SDL_FreeSurface(p->imagePerso[1][1]);
SDL_FreeSurface(p->imagePerso[1][2]);
SDL_FreeSurface(p->imagePerso[1][3]);

SDL_FreeSurface(p->imagePerso[2][0]);
SDL_FreeSurface(p->imagePerso[2][1]);
//SDL_FreeSurface(p.imagePerso[2][2]);
SDL_FreeSurface(p->imagePerso[2][3]);

SDL_FreeSurface(p->imagePerso[3][0]);
SDL_FreeSurface(p->imagePerso[3][1]);
SDL_FreeSurface(p->imagePerso[3][2]);
SDL_FreeSurface(p->imagePerso[3][3]);

SDL_FreeSurface(p->V[0].image);
SDL_FreeSurface(p->V[1].image);
SDL_FreeSurface(p->V[2].image);
SDL_FreeSurface(p->V[3].image);
SDL_FreeSurface(p->V[4].image);

SDL_FreeSurface(p->TEXTE[0].texte);
SDL_FreeSurface(p->TEXTE[1].texte);
SDL_FreeSurface(p->TEXTE[2].texte);
}


/*void saut (Personne* p,SDL_Surface *screen)
{

if(p->key==2)
{

p->postion.y-=50;
SDL_Delay(1000);
p->postion.y=345;
}
}*/
