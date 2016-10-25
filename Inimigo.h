#ifndef INIMIGO_H
#define INIMIGO_H

#include "Personagem.h"
#include "Jogador.h"

#include <stdio.h>
#include <iostream>

class Inimigo : public Personagem
{
    private:

        short int x0; // Ponto de referência onde o objeto Inimigo é criado.
                      // O movimento simples de um inimigo será: ir de um lado para outro partindo
                      // ponto de referência.

    protected:

        Jogador* j; // conhece Jogador para fazer colisões. Informações de Jogador serão utilizadas pelo Chefão.


    public:
        Inimigo();
        virtual ~Inimigo();

        /*sets*/
        void setJogador(Jogador* J);
        void setPosReferencia (short int X0);

/*
*******************************************************************************************************************
*       //ACHO QUE NÃO É NECESSÁRIO FAZER GETjOGADOR PORQUE O CHEFÃO É CLASSE FILHA E NÃO PRECISA DE GET          *
*        //POIS JOGADOR É UM ATRIBUTO PROTECTED DE INIMIGO                                                        *
*                                                                                                                 *
*                                                                                                                 *
*        Jogador* getJogador(); // Chefão também conhecerá Jogador atraés da classe Inimigo                       *
********************************************************************************************************************
*/

        /* Movimentação */
        virtual void Movimento(); // É virtual porque a classe filha Chefao utiliza essa função através do polimorfismo
        virtual void MovMorte(); // Movimento de morte do Inimigo (vida = 0)

         /* Colisão */
         virtual void testeColisao(); // Para colisão são utilizados as informações de Lagura e Altura de cada personagem


};

#endif // INIMIGO_H
