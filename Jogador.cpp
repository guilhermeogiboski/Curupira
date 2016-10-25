#include "Jogador.h"

Jogador::Jogador(): num(1), Personagem()
{
    //ctor
}

Jogador::Jogador(const short int N) : num(N), Personagem()
{

}

Jogador::~Jogador()
{
    destroy_bitmap(img);  // Destrói a imagem;
}

const short int Jogador::getnum()
{

}

void Jogador::Movimento()
{
    if (key[SPACE])
    {
        y = y - vy; //
    }

    if (y<470)
    {
        y = y + vy;
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

}

void Jogador::PosNovoAtaque()
{

}
