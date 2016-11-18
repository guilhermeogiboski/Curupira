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
