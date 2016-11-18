#ifndef CENARIO_H
#define CENARIO_H
#include <allegro.h>
#include "Entidade.h"


class Cenario: public Entidade // Cenario � filha de Entidade
{
private:
    BITMAP* imgEsquerda; //Cen�rio posicionado a esquerda do cen�rio central
    BITMAP* imgCentro;   //Cen�rio posicionado no centro
    BITMAP* imgDireita;  //Cen�rio posicionado a direita do cen�rio central
    BITMAP* buffer;

public:
    Cenario();
    virtual ~Cenario();

    /*SETS*/
    void setImgEsq(BITMAP* imgEsq);
    void setImgCen(BITMAP* imgCen);
    void setImgDir(BITMAP* imgDir);
    void setBuffer( BITMAP* BUF);

    /*GETS*/
    BITMAP* getImgEsq();
    BITMAP* getImgCen();
    BITMAP* getImgDir();

    /*MOVIMENTO DO CEN�RIO*/
    void Movimento();


};

#endif // CENARIO_H
