#ifndef JOGO_H
#define JOGO_H

#include "Fase1.h"
#include "Fase2.h"
#include "Fase3.h"


class Jogo
{
    private:

        Fase1* fase_1;
        Fase2* fase_2;
        Fase3* fase_3;

    public:
        Jogo();
        virtual ~Jogo();

        void executar();

};

#endif // JOGO_H
