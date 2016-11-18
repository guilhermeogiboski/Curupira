#ifndef JOGADOR_H
#define JOGADOR_H
#include "Personagem.h"


class Jogador: public Personagem
{
    public:
        Jogador();
        virtual ~Jogador();

        void Movimento();

    protected:

    private:
};

#endif // JOGADOR_H
