#include "Cenario.h"

Cenario::Cenario(): Entidade()
{
    imgEsquerda = NULL;
    imgCentro = NULL;
    imgDireita = NULL;
}

Cenario::~Cenario()
{
    destroy_bitmap(imgEsquerda);  // Destrói a imagem;
    destroy_bitmap(imgCentro);
    destroy_bitmap(imgDireita);
    buffer = NULL;
}

/*SETS*/
void Cenario::setImgEsq(BITMAP* imgEsq)
{
    imgEsquerda = imgEsq;
}

void Cenario::setImgCen(BITMAP* imgCen)
{
    imgCentro = imgCen;
}

void Cenario::setImgDir(BITMAP* imgDir)
{
    imgDireita = imgDir;
}

void Cenario::setBuffer( BITMAP* BUF)
{
    buffer = BUF;
}

/*GETS*/
BITMAP* Cenario::getImgEsq()
{
    return imgEsquerda;
}

BITMAP* Cenario::getImgCen()
{
    return imgCentro;
}

BITMAP* Cenario::getImgDir()
{
    return imgDireita;
}


/*MOVIMENTO DO CENÁRIO*/
void Cenario::Movimento()
{

}
