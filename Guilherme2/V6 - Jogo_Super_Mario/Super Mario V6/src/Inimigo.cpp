#include "Inimigo.h"

Inimigo::Inimigo()
{
    //ctor
}

Inimigo::~Inimigo()
{
    //dtor
}

//--------SETS/GETS------------------------------------//

void Inimigo::setJogador(Jogador* _jogador)
{
    jogador = _jogador;
}

Jogador* Inimigo::getJogador()
{
    return jogador;
}

//---------MOVIMENTO-----------------------//

void Inimigo::Movimento()
{

        if(y <= 20)
        {
            vy = -vy;
            x = 31;
        }
        if(y >= 470)
        {
            vy = -vy;
            x = 0;
        }
        y = y + vy;
}
