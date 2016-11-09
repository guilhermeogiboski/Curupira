#ifndef JOGADOR_H
#define JOGADOR_H
#include <allegro.h>

class Inimigo;

class Jogador
{
    private:
        BITMAP* img; // Imagem Jogador
        BITMAP* buffer;
        float x;       // Posição em x.
        float y;       // Posição em y.
        float h;       // Altura da imagem.
        float l;       // Largura da imagem.
        float vx;      // Velocidade em Y.
        float vy;      // Velocidade em X.
        BITMAP* P_AndaDireita;
        BITMAP* P_AndaEsquerda;
        Inimigo* PosInimigo;
        int pula;



    public:
        Jogador();
        virtual ~Jogador();

        /* Sets */
        void setimg( BITMAP* I);
        void setbuffer( BITMAP* BUF);
        void setx( float X );
        void sety( float Y );
        void seth( float H );
        void setl( float L );
        void setvx( float VX );
        void setvy( float VY );
        void setInimigo(Inimigo* PI);


        /* Gets */
        BITMAP* getimg();
        float getx();
        float gety();
        float geth();
        float getl();
        float getvx();
        float getvy();

        /* Movimentação */
        void Movimento();

        void MovMorte();

        void Desenha();

};

#endif // JOGADOR_H
