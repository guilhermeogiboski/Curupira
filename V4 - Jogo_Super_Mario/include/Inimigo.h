#ifndef INIMIGO_H
#define INIMIGO_H
#include <allegro.h>

#include "Jogador.h"

class Inimigo
{
    private:
        BITMAP* img; // Imagem Inimigo
        BITMAP* buffer;
        float x;       // Posição em x.
        float y;       // Posição em y.
        float h;       // Altura da imagem.
        float l;       // Largura da imagem.
        float vx;      // Velocidade em Y.
        float vy;      // Velocidade em X.
        Jogador* Jog_Perseguido; // Posição do jogador.



    public:
        Inimigo();
        virtual ~Inimigo();

        void setJogador(Jogador* j) {  Jog_Perseguido = j; }

                /* Sets */
        void setimg( BITMAP* IMG );
        void setbuffer( BITMAP* BUF);
        void setx( float X );
        void sety( float Y );
        void seth( float H );
        void setl( float L );
        void setvx( float VX );
        void setvy( float VY );


        /* Gets */
        BITMAP* getimg();
        float getx();
        float gety();
        float geth();
        float getl();
        float getvx();
        float getvy();

        /* Movimentação */
        void Perseguir();

        void Desenha();

};

#endif // INIMIGO_H
