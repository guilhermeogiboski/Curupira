#include "Jogador.h"

#include "Inimigo.h"

#include <stdio.h>
#include <iostream>
#include <math.h>


Jogador::Jogador()
{
    img= load_bitmap("Arquivos//Imagens//mario.bmp", NULL);  //carrega a imagem a partir da pasta onde ela est�.
    P_AndaDireita = load_bitmap("Arquivos//Imagens//mario.bmp", NULL);  //carrega a imagem a partir da pasta onde ela est�.
    P_AndaEsquerda = load_bitmap("Arquivos//Imagens//marioEsquerda.bmp", NULL);  //carrega a imagem a partir da pasta onde ela est�.
    h = 100; // inicializa a altura da imagem/Jogador.
    l = 100; // inicializa a largura da imagem/Jogador.
    x = 300; // Posi��o inicial em x.
    y = 510; // Posi��o icial em y.
    vx = 0.5;  // Velocidade icial do objeto em x.
    vy = 0.5;  // Velocidade icial do objeto em y.
    pula=NULL;
}

Jogador::~Jogador()
{
    destroy_bitmap(P_AndaDireita);  // Destr�i a imagem;
    destroy_bitmap(P_AndaEsquerda);  // Destr�i a imagem;
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

/* Movimenta��o */
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
        x = x + vx;// Em x o eixo � padr�o, portanto para a direita � positivo.
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
    // Desenha no buffer(Buffer, Imagem, posi��oX, posi��oY, Efeito na cor, Efeito na posi��o);
}
