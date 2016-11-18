#include "Saci.h"

Saci::Saci()
{
    //ctor
}

Saci::~Saci()
{
    //dtor
}

void Saci::Movimento()
{

        if(x <= 20)
        {
            vx = -vx;
            //x = 31; voltinha
        }
        if(x >= 500)
        {
            vx = -vx;
           // x = 0;  voltinha
        }
        x = x + vx;
}

//--------SETS/GETS-----------//


void Saci::setVida(int _vida)
{
    vida = _vida;
}

int Saci::getVida()
{
    return vida;
}
