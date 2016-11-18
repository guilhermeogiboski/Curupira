#ifndef JOGADOR_H
#define JOGADOR_H
#include "Personagem.h"


class Jogador: public Personagem
{
    public:
        Jogador();
        virtual ~Jogador();

        virtual void  Movimento(); // colocar como virtual

        void setPontos(int _pontos);
        int getPontos();

    protected:

    private:
        int pontos;
};

#endif // JOGADOR_H
