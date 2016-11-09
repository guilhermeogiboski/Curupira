#include "Chefao.h"

Chefao::Chefao(): Inimigo()
{
    Jog_Perseguido = NULL;
}

Chefao::~Chefao()
{
    destroy_bitmap(img);  // Destrói a imagem;
}

void Chefao::setJogador(Jogador* J)
{
    Jog_Perseguido = J;
}

/* Movimentação */
void Chefao::Movimento()
{
    if (Jog_Perseguido != NULL)
    {
        if(x > Jog_Perseguido->getx())
        {
            x = x - vx;
        }
        if(x < Jog_Perseguido->getx())
        {
            x = x + vx;
        }

        if(y > Jog_Perseguido->gety())
        {
            y = y - vy;
        }
        if(y < Jog_Perseguido->gety())
        {
            y = y + vy;
        }

    }
    else
    {
        // msg erro
    }
}

void Chefao::MovMorte()
{

}
