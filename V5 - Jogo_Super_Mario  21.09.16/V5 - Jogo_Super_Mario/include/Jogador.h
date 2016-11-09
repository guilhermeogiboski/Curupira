#ifndef JOGADOR_H
#define JOGADOR_H

#include "Personagem.h"


class Jogador: public Personagem
{
    private:

        const short int num;


    public:
        Jogador();
        Jogador(const short int N); // Recebe numero do Jogador (exemplo Jogador1 ou Jogador2).
        virtual ~Jogador();

        const short int getnum(); // Informa numero do Jogador (exemplo Jogador1 ou Jogador2).

        void Movimento();

        void MovMorte();       // Movimento de morte do Inimigo (vida = 0).

        void PosNovoAtaque(); // O jogador ser� reposicionado ap�s atacar ou ser atacado pelo Inimigo
                              // O ataque est� relacionado com a colis�o.


};

#endif // JOGADOR_H
