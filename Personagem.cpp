#include "Personagem.h"

/*Construtor*/
Personagem::Personagem()
{
    C = false;
    B = false;
    D = false;
    E = false;
    img = NULL;
    buffer = NULL;
}

/*Destrutor*/
Personagem::~Personagem() // Destrutor
{
    buffer = NULL;
    destroy_bitmap(img);  // Destrói a imagem;
}

/* Sets */
void Personagem::setImg( BITMAP* I)
{
    img = I;
}

void Personagem::setImgDir( BITMAP* IMG_DIR)
{
    imgDireita = IMG_DIR;
}

void Personagem::setImgEsq( BITMAP* IMG_ESQ)
{
    imgEsquerda = IMG_ESQ;
}

void Personagem::setBuffer(BITMAP* B)
{
    buffer = B;
}

void Personagem::setVida( const short int V)
{
    vida = V;
}

void Personagem::setx( const float X )
{
    x = X;
}

void Personagem::sety( const float Y )
{
    y = Y;
}

void Personagem::seth( const float H )
{
    h = H;
}

void Personagem::setl( const float L )
{
    l = L;
}

void Personagem::setvx( const float VX )
{
    vx = VX;
}

void Personagem::setvy( const float VY )
{
    vy = VY;
}



/* Gets */
BITMAP* Personagem::getimg()
{
    return img;
}

const short int Personagem::getVida()
{
    return vida;
}

const float Personagem::getx()
{
    return x;
}

const float Personagem::gety()
{
    return y;
}

const float Personagem::geth()
{
    return h;
}

const float Personagem::getl()
{
    return l;
}

const float Personagem::getvx()
{
    return vx;
}

const float Personagem::getvy()
{
    return vy;
}


void Personagem::Desenha()
{
    draw_sprite(buffer, img, x, y);
    // Desenha no buffer(Buffer, Imagem, posiçãoX, posiçãoY, Efeito na cor, Efeito na posição);
}
