#include "Curupira.h"

Curupira::Curupira()
{
    //ctor
}

Curupira::~Curupira()
{
    //dtor
}
void Curupira::Movimento()
{

        if(x <= 20)
        {
            vx = -vx;
            //y = 31;
        }
        if(x >= 100)
        {
            vx = -vx;
            //y = 0;
        }
        x = x + vx;
}

void Curupira::setVida(int _vida)
{
    vida = _vida;
}

int Curupira::getVida()
{
    return vida;
}
