#include "Jogador.h"

Jogador::Jogador()
{
    //ctor
}

Jogador::~Jogador()
{
    //dtor
}

void Jogador::Movimento()
{
                                  //  |o personagem tem sua posi��o em Y
        // if (key[KEY_UP]) y = y - vy; // -|reduzida (no Allegro o eixo Y � oposto)
                                      //  |e se desloca para cima tantos pixels
                                      //  |quanto for o valor da velocidade do personagem em Y.
         if (key[KEY_DOWN]) y = y + vy;  // An�logo ao anterior, por�m, para baixo.
         if (key[KEY_RIGHT]) x = x + vx; // Em x o eixo � padr�o, portanto para a direita � positivo.
         if (key[KEY_LEFT]) x = x - vx;  //



         if( y>=400)
        {
            y=400;// mudar para colisao
            vy=0;
            if(key[KEY_UP]){
                vy=-5;
            }


        }else{
            vy= vy+0.1; // gravidade cte

        }
        y= y+vy;










}

void Jogador::setPontos(int _pontos)
{
    pontos = _pontos;
}

int Jogador::getPontos()
{
    return pontos;
}

