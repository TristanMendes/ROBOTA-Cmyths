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
    p->sauter=-1;

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
p->postion.y-=145;
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
else if(p->sauter)
{
SDL_BlitSurface(p->TEXTE[0].texte,NULL,screen,&p->TEXTE[0].position);
SDL_BlitSurface(p->TEXTE[1].texte,NULL,screen,&p->TEXTE[1].position);
SDL_BlitSurface(p->TEXTE[2].texte,NULL,screen,&p->TEXTE[2].position);
SDL_BlitSurface(p->V[p->etat_vie].image,NULL,screen,&p->V[0].position);
SDL_BlitSurface(p->imagePerso[0][0], 0, screen, &p->postion);
SDL_Flip(screen);
}

 TTF_CloseFont(police);  
}


void deplacerPerso (Personne *p,Uint32 dt)
{
//p->vitesse+=p->acceleration*dt;//MISE A JOUR DE LA NOUVELLE VITESSE;

p->dx=(0.5*p->acceleration*dt*dt)+(p->vitesse*dt);//CALCUL DE LA DISTANCE ENGENDREE;

if(p->key==1&&p->postion.x<660)
{
p->postion.x+=p->dx;//MISE A JOUR DE LA NOUVELLE DISTANCE;
}

else if(p->key==0)
{
p->postion.x-=p->dx;
}

}

void animerPerso (Personne* p)
{


if(p->key==1)
{

if(p->etape[0]<3)
{
	(p->etape[0])++;//PERMET DE SE DEPLACER DANS LE TABLEAU DES MATRICES(CAS DU DEPLACEMENT 'RIGHT')
}
else
{
	p->etape[0]=0;//REVIENT AU PREMIER AU ELEMENT APRES AVOIR PARCOURU LA MATRICE DES IMAGES
}

}

else if(p->key==0)
{
if(p->etape[1]<3)
{
	(p->etape[1])++;//PERMET DE SE DEPLACER DANS LE TABLEAU DES MATRICES(CAS DU DEPLACEMENT 'LEFT')
}
else
{
	p->etape[1]=0;//REVIENT AU PREMIER  ELEMENT APRES AVOIR PARCOURU LA MATRICE DES IMAGES
}

}
//
}

void updatePerso(Personne *p)
{
if(p->key==1&&p->postion.x<660)
{
p->score++;//LE SCORE AUGMENT A CHAQUE FOIS LE PP AVANCE VERS LA DROITE (RIGHT);
if(p->score==50)
{
p->score=0;
p->vie++; //SI SON SCORE ARRIVE A 50, ALORS ON LUI DONNE UNE VIE ET SON SCORE REVIENT A 0 (JUSTE UN ESSAI, PAS DEFINITIF);
}
p->temps++;//LE TEMPS EVOLUE EGALEMENT AU COURS DU JEU;
p->j=1;
}


if(p->vie==5)
{
if(p->etat_vie<3)
{
p->etat_vie++;//LORSQUE SON NOMBRE DE VIE ATTEINT 5, ALORS ON LUI OFFRE UN JOLI COEUR;
}

p->vie=0;//ET LE NOMBRE DE VIE REVIENT A SON TOUR A 0;
}

if(p->etat_vie==4) //SI etat_vie atteint 4,  CE QUI CORRESPOND A L'IMAGE DU GAME OVER, ALORS ON RECOMMENCE LE JEU A 0;
{
p->etat_vie=3;
SDL_Delay(1000);
}


//CETTE PARTIE EST FAITE JUSTE POUR VERIFIER SI LE NOMBRE DE COEUR DIMINUE LORS DUNE COLLISSION;
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

/*
void sauter(Personne* p,SDL_Surface* screen)
{
SDL_Surface *image=NULL,*obstacle=NULL;
SDL_Rect positionImage,positionObstacle;
image=IMG_Load("b.png");
obstacle=IMG_Load("sapin.png");
positionObstacle.x=400;
positionObstacle.y=285;

positionImage.x=0;
positionImage.y=0;

if(p->sauter==1)//S'IL APPUIE SUR LE BOUTON DU SAUT QUI EST S(POUR LE MOMENT);
{

while(p->postion.y>200) //200 REPRESENTE LE SOMMET DU SAUT;
{
p->postion.y-=20;//ON DIMINUE LE Y POUR Q'IL PUISSE MONTER
p->postion.x+=5;
SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));
SDL_BlitSurface(image,NULL,screen,&positionImage);
SDL_BlitSurface(obstacle,NULL,screen,&positionObstacle);
afficherPerso(p,screen); //ON AFFICHE LES RESSOURCES A CHAQUE ETAPE DU SAUT;
SDL_Delay(5);//TEMPS DE PAUSE POUR MIEUX VOIR LETAT DE SAUT ET DE LA COURBE;
}
while(p->postion.y<340) //TANT QU'IL N'EST PAS ARRIVÉ A LA POSITION INITIALE(LORS DE LA DESCENTE);
{p->postion.y+=35; //LE Y AUGMENTE POUR QU'IL PUISSE DESCENDRE, ON AUGMENTE LE Y RAPIDEMENT POURQU'IL DESCEND PLUS VITE QUIL NEST DESCENDU;
p->postion.x+=5;
SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));
SDL_BlitSurface(image,NULL,screen,&positionImage);
SDL_BlitSurface(obstacle,NULL,screen,&positionObstacle);
afficherPerso(p,screen);
SDL_Delay(5);
}

p->postion.y=345;
p->sauter=0;
}
}

*/

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


void sauter(Personne *p,SDL_Surface *screen)
{

#define SCREEN_W 800
#define SCREEN_H 400
#define POS_X 100
#define POS_Y 400

SDL_Surface *image=NULL,*obstacle=NULL;
SDL_Rect positionImage,positionObstacle;
image=IMG_Load("b.png");
obstacle=IMG_Load("sapin.png");
positionObstacle.x=400;
positionObstacle.y=285;

positionImage.x=0;
positionImage.y=0;

double v_x, v_y, v_grav, v_jump, v_air;
int done=1;
double b;
b=p->postion.y;
  p->postion.y=(-0.004*p->postion.x*p->postion.x)+1; ///lequation de la parabolle;
    /* initialisation des vitesses */
    v_grav =0.08;//va représenter l'attraction terrestre.
    v_jump =-4;//vitesse du saut

    v_air = 1.5;//pas trop compris se que signifiait cette variable
    v_x = v_air;//vitesse de déplacement dans les airs.
    v_y = v_jump;

  
p->postion.y=b;
    while(done)
{

if(p->etat==0)
{
     v_x=v_air;
        /* evolution de la position*/
	
	
	
        p->postion.x += v_x;
        p->postion.y += v_y;
 
        /* evolution de la vitesse*/
        v_y += v_grav;//vitesse à la quel le personnage va latéralement monter
 
        /* collisions */
        if (p->postion.y > POS_Y)//si le perso dépace une certaine hauteur alors on fait redescendre le perso
            v_y =-v_jump;
	
        if (p->postion.x < POS_X || p->postion.x > SCREEN_W - POS_X)
            v_x = -v_x;
 
 
        /* dessin*/ 
        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));
SDL_BlitSurface(image,NULL,screen,&positionImage);
SDL_BlitSurface(obstacle,NULL,screen,&positionObstacle);
        afficherPerso(p,screen);
        SDL_Flip(screen);

if(p->postion.y==b)
{
done=0;
}
}
else if(p->etat==1)
{

v_x=-v_air;
        /* evolution de la position*/
	
	
	
        p->postion.x += v_x;
        p->postion.y += v_y;
 
        /* evolution de la vitesse*/
        v_y += v_grav;//vitesse à la quel le personnage va latéralement monter
 
        /* collisions */
        if (p->postion.y > POS_Y)//si le perso dépace une certaine hauteur alors on fait redescendre le perso
            v_y =-v_jump;
	
        if (p->postion.x < POS_X || p->postion.x > SCREEN_W - POS_X)
            v_x = -v_x;
 
 
        /* dessin*/ 
        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));
SDL_BlitSurface(image,NULL,screen,&positionImage);
SDL_BlitSurface(obstacle,NULL,screen,&positionObstacle);
        afficherPerso(p,screen);
        SDL_Flip(screen);
   
if(p->postion.y==b)
{
done=0;
}
}

} 
p->sauter=0;
}

