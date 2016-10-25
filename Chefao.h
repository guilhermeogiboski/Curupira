#ifndef CHEFAO_H
#define CHEFAO_H

#include "Jogador.h"
#include "Inimigo.h"

class Chefao : public Inimigo
{
    private:

        Jogador* Jog_Perseguido; // Posição do jogador.


    public:
        Chefao();
        virtual ~Chefao();

        void setJogador(Jogador* J);
        void Movimento();
        virtual void MovMorte(); // Movimento de morte do Chefao (vida = 0)




};

#endif // CHEFAO_H
