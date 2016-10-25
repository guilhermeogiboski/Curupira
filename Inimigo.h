#ifndef INIMIGO_H
#define INIMIGO_H

#include "Personagem.h"
#include "Jogador.h"

#include <stdio.h>
#include <iostream>

class Inimigo : public Personagem
{
    private:

        short int x0; // Ponto de refer�ncia onde o objeto Inimigo � criado.
                      // O movimento simples de um inimigo ser�: ir de um lado para outro partindo
                      // ponto de refer�ncia.

    protected:

        Jogador* j; // conhece Jogador para fazer colis�es. Informa��es de Jogador ser�o utilizadas pelo Chef�o.


    public:
        Inimigo();
        virtual ~Inimigo();

        /*sets*/
        void setJogador(Jogador* J);
        void setPosReferencia (short int X0);

/*
*******************************************************************************************************************
*       //ACHO QUE N�O � NECESS�RIO FAZER GETjOGADOR PORQUE O CHEF�O � CLASSE FILHA E N�O PRECISA DE GET          *
*        //POIS JOGADOR � UM ATRIBUTO PROTECTED DE INIMIGO                                                        *
*                                                                                                                 *
*                                                                                                                 *
*        Jogador* getJogador(); // Chef�o tamb�m conhecer� Jogador atra�s da classe Inimigo                       *
********************************************************************************************************************
*/

        /* Movimenta��o */
        virtual void Movimento(); // � virtual porque a classe filha Chefao utiliza essa fun��o atrav�s do polimorfismo
        virtual void MovMorte(); // Movimento de morte do Inimigo (vida = 0)

         /* Colis�o */
         virtual void testeColisao(); // Para colis�o s�o utilizados as informa��es de Lagura e Altura de cada personagem


};

#endif // INIMIGO_H
