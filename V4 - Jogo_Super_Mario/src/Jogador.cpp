#include "Jogador.h"

#include "Inimigo.h"

#include <stdio.h>
#include <iostream>
#include <math.h>


Jogador::Jogador()
{
    img= load_bitmap("Arquivos//Imagens//mario.bmp", NULL);  //carrega a imagem a partir da pasta onde ela está.
    P_AndaDireita = load_bitmap("Arquivos//Imagens//mario.bmp", NULL);  //carrega a imagem a partir da pasta onde ela está.
    P_AndaEsquerda = load_bitmap("Arquivos//Imagens//marioEsquerda.bmp", NULL);  //carrega a imagem a partir da pasta onde ela está.
    h = 100; // inicializa a altura da imagem/Jogador.
    l = 100; // inicializa a largura da imagem/Jogador.
    x = 300; // Posição inicial em x.
    y = 510; // Posição icial em y.
    vx = 0.5;  // Velocidade icial do objeto em x.
    vy = 0.5;  // Velocidade icial do objeto em y.
    pula=NULL;
}

Jogador::~Jogador()
{
    destroy_bitmap(P_AndaDireita);  // Destrói a imagem;
    destroy_bitmap(P_AndaEsquerda);  // Destrói a imagem;
}


/* Sets */
void Jogador::setimg( BITMAP* I )
{
    img = I;
}

void Jogador::setbuffer( BITMAP* B )
{
    buffer = B;
}

void Jogador::setx( float X )
{
    x = X;
}

void Jogador::sety( float Y )
{
    y = Y;
}

void Jogador::seth( float H )
{
    h = H;
}

void Jogador::setl( float L )
{
    l = L;
}

void Jogador::setvx( float VX )
{
    vx = VX;
}

void Jogador::setvy( float VY )
{
    vy = VY;
}

void Jogador::setInimigo(Inimigo* PI )
{
    PosInimigo = PI;
}




/* Gets */
BITMAP* Jogador::getimg()
{
    return img;
}


float Jogador::getx()
{
    return x;
}

float Jogador::gety()
{
    return y;
}

float Jogador::geth()
{
    return h;
}

float Jogador::getl()
{
    return l;
}

float Jogador::getvx()
{
    return vx;
}

float Jogador::getvy()
{
    return vy;
}

/* Movimentação */
void Jogador::Movimento()
{

    if (key[KEY_SPACE])
    {
        pula=0;
    }

    if (pula==0)
    {
        y = y - vy; //
    }
    if(pula==1)
    {
        y = y + vy;
    }

    if (y==300)
    {
        pula=1;
    }

    if (y>510)
    {
        y = 510;
    }


    if (key[KEY_RIGHT])
    {
        x = x + vx;// Em x o eixo é padrão, portanto para a direita é positivo.
        img = P_AndaDireita;
    }

    if (key[KEY_LEFT])
    {
        x = x - vx;  // E para a esquerda negativo.
        img = P_AndaEsquerda;
    }

}


void Jogador::MovMorte()
{


    if(PosInimigo->getx()==x)
    {

    }


}


void Jogador::Desenha()
{
    draw_sprite(buffer, img, x, y);
    // Desenha no buffer(Buffer, Imagem, posiçãoX, posiçãoY, Efeito na cor, Efeito na posição);
}
