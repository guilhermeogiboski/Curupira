//#pragma once
#include <allegro.h>
#include <stdlib.h> 
//#include "objetos.h"


 struct Personagem
 {
        int ID;
        int x;
        float y;
        int velocidade;
        int tx;
        int ty;
        int ativo;
        BITMAP* imagem;
 } ;
  
   struct NaveEspacial
 {
       int ID;
        int x;
        float y;
        int velocidade;
         int tx;
         int ty;
        int vidas;
        int pontos;
        float combustivel;
        BITMAP* imagem;
 };
 

