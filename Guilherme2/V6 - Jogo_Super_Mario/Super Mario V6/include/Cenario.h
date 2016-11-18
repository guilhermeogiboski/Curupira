#ifndef CENARIO_H
#define CENARIO_H
#include <allegro.h>
#include "Entidade.h"


class Cenario: public Entidade // Cenario é filha de Entidade
{
private:
    BITMAP* imgEsquerda; //Cenário posicionado a esquerda do cenário central
    BITMAP* imgCentro;   //Cenário posicionado no centro
    BITMAP* imgDireita;  //Cenário posicionado a direita do cenário central
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

    /*MOVIMENTO DO CENÁRIO*/
    void Movimento();


};

#endif // CENARIO_H
