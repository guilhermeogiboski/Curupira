#include "Personagem.h"

Personagem::Personagem()
{
    //ctor
}

Personagem::~Personagem()
{
    //dtor
}
void Personagem::setImgDireita(BITMAP* _imgDireita)
{
    this->imgDireita = _imgDireita;
}

void Personagem::setImgEsquerda(BITMAP* _imgEsquerda)
{
    this->imgEsquerda = _imgEsquerda;
}

BITMAP* Personagem::getImgDireita()
{
    return imgDireita;
}

BITMAP* Personagem::getImgEsquerda()
{
    return imgEsquerda;
}

void Personagem::setVida(int _vida)
{
    this->vida = _vida;
}

int Personagem::getVida()
{
        return vida;
}
void Personagem::Movimento()
{
                                //  |o personagem tem sua posi��o em Y
         if (key[KEY_UP]){y = y-vy;};  // -|reduzida (no Allegro o eixo Y � oposto)
                                      //  |e se desloca para cima tantos pixels
                                      //  |quanto for o valor da velocidade do personagem em Y.
         if (key[KEY_DOWN]){y = y+vy;};  // An�logo ao anterior, por�m, para baixo.
         if (key[KEY_RIGHT]) {x = x+vx;}; // Em x o eixo � padr�o, portanto para a direita � positivo.
         if (key[KEY_LEFT]) {x =x-vx;};  //

// TESTE PARA INIMIGO
      /*       if(y <= 20)
        {
            vy = -vy;
            x = 31;
        }
        if(y >= 470)
        {
            vy = -vy;
            x = 0;
        }
        y = y + vy;*/
}
