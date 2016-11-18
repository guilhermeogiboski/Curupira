#include "Entidade.h"

Entidade::Entidade()
{
    img = NULL;
   // h = 100; // inicializa a altura da imagem/personagem.
    //l = 100; // inicializa a largura da imagem/personagem.
    x = 350; // Posição inicial em x.
    y = 250; // Posição icial em y.
    vx = 1;  // Velocidade icial do objeto em x.
    vy = 1;  // Velocidade icial do objeto em y.




}

Entidade::~Entidade()
{
   // buffer = NULL;
   // destroy_bitmap(img);  // Destrói a imagem;
}


/* Sets */
void Entidade::setImg( BITMAP* IMG)
{
    img = IMG;
}

void Entidade::setBuffer( BITMAP* BUF)
{
    buffer = BUF;
}

void Entidade::setx( const float X )
{
    x = X;
}

void Entidade::sety( const float Y )
{
    y = Y;
}

//void Entidade::seth( const float H )
//{
    //h = H;
//}

/*void Entidade::setl( const float L )
{
    l = L;
} */

void Entidade::setvx( const float VX )
{
    vx = VX;
}

void Entidade::setvy( const float VY )
{
    vy = VY;
}



/* Gets */
BITMAP* Entidade:: getimg()
{
    return img;
}

const float Entidade::getx()
{
    return x;
}

const float Entidade::gety()
{
    return y;
}

/*const float Entidade::geth()
{
    return h;
}

const float Entidade::getl()
{
    return l;
}*/

const float Entidade::getvx()
{
    return vx;
}

const float Entidade::getvy()
{
    return vy;
}


void Entidade::Desenha()
{
    draw_sprite(buffer, img, this->getx(), this->gety());
    // Desenha no buffer(Buffer, Imagem, posiçãoX, posiçãoY, Efeito na cor, Efeito na posição);
}



