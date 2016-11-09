#ifndef _PRINCIPAL_H_
#define _PRINCIPAL_H

#include "Jogo.h"

class Principal
{
    private:
           Jogo J;       // O Jogo em si.
           Jogador P; // O Jogador.
           Inimigo I; // O Inimigo.
           BITMAP C;
    public:
           Principal();
           virtual ~Principal();
           void Executar();
};

#endif
 // PRINCIPAL_H
