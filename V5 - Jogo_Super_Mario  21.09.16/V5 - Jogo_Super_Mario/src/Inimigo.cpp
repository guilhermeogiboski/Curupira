#include "Inimigo.h"

Inimigo::Inimigo():Personagem()
{
    x0=0;
}

Inimigo::~Inimigo()
{
    destroy_bitmap(img);  // Destr�i a imagem;
}

void Inimigo::setPosReferencia (short int X0)
{
    x0 = X0;
}


/* Movimenta��o */

void Inimigo::Movimento()
{
    // INSERIR IMAGEM QUANDO INIMIGO ANDA PRA FRENTE E QUANDO ANDA PRA TRAS
    if(x <= (x0-100))
    {
        vx = vx;
        img = imgDireita;//

    }
    if(x >= (x0+100))
    {
        vx = -vx;
        img = imgEsquerda;
    }
    x = x + vx;
}


void Inimigo::MovMorte()
{

}

/* Colis�o */
void Inimigo::testeColisao()
{

}
