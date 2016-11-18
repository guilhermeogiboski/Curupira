#ifndef INIMIGO_H
#define INIMIGO_H

#include "Personagem.h"
class Jogador;


class Inimigo: public Personagem
{
    public:
        Inimigo();
        virtual ~Inimigo();

        void setJogador(Jogador* _jogador);
        Jogador* getJogador();

   // protected:
      virtual void  Movimento();

    private:
        Jogador * jogador; // para perseguir

};

#endif // INIMIGO_H
