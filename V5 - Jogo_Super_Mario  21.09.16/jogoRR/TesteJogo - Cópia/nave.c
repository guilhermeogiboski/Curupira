#include "objetos.h"


void iniciaPersonagem(struct Personagem *inimigo, int x0, int y0, char *diretorio, int id)
{
         BITMAP* auxImagem = load_bitmap(diretorio,NULL);                                
         inimigo->ID = id;
         inimigo->x = x0;
         inimigo->y = (float)y0;
         inimigo->velocidade =5;
         inimigo->ativo = TRUE;
         inimigo->tx = auxImagem->w;
         inimigo->ty = auxImagem->h;
         inimigo->imagem = auxImagem;

    
}

void iniciaNave( struct NaveEspacial *nv , int x0, int y0, char *diretorio, int id)
{
               
          BITMAP* auxImagem = load_bitmap(diretorio,NULL);                                
          nv->x = x0;
          nv->y = (float)y0;
          nv->velocidade =5;
          nv->tx = auxImagem->w;
          nv->ty = auxImagem->h;
          nv->imagem = auxImagem;
          nv->combustivel = 600;
          nv->vidas = 3;
          nv->pontos = 0;  
     
     
}

 
