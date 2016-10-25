#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include "Menu.h"

class Principal
{
        private:
           Menu M;       // Menu principal do jogo.
           Jogo J;       // O Jogo em si.
           Jogador  P1;  // O Jogador 1.
           Jogador  P2;  // O Jogador 2.


    public:
        Principal();
        virtual ~Principal();

        void Executar();
        void Inicializar();

};

#endif // PRINCIPAL_H
