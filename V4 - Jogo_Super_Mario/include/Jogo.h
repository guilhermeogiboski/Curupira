#ifndef JOGO_H
#define JOGO_H

#include <allegro.h>
#include "Jogador.h"
#include "Inimigo.h"



class Jogo
{
    private:

        BITMAP* buffer;
        // Bitmap de buffer para desenhar todas as imagens nele
        // e logo em seguida jogá-lo inteiro na tela, isso evita
        // que a tela ou as imagens fiquem piscando.
        BITMAP* Cenario1;
        BITMAP* Cen;
        Jogador* Jog;
        Inimigo* Inim;
        float posicao1;
        float posicao2;
        float posicao3;
        float vx;



    public:
        Jogo();
        virtual ~Jogo();

        void setCenario( BITMAP* CENARIO );
        void Iniciar();
        void Tela1();
        void DesenhaTela1();


        void setPersonagem(Jogador* P, Inimigo* I);


};

#endif // JOGO_H
