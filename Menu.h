#ifndef MENU_H
#define MENU_H

#include "Jogo.h"

class Menu
{
    private:
        BITMAP* buffer;
        // Bitmap de buffer para desenhar todas as imagens nele
        // e logo em seguida jogá-lo inteiro na tela, isso evita
        // que a tela ou as imagens fiquem piscando.
        BITMAP* fundoR; // Fundo do menu de raiz.
        BITMAP* fundoC; // Fundo do menu de créditos.
        BITMAP* fundoS; // Fundo da tela Score..
        Jogo* j;
        bool sair;      // Variável para indicar o processo de saída
        // e evitar que o menu seja aberto novamente quando
        // o botão sair for pressionado.

    public:
        Menu();
        virtual ~Menu();

        void Inicializar();
        void Iniciar();
        void Raiz();       // Menu principal.
        void Creditos();   // Tela de créditos.
        void Score(); //Tela score
        bool Sair();       // Menu de pergunta para confirmação de saída.

        /* Sets */
        void setBuffer( BITMAP* B);
        void setFundoRaiz( BITMAP* R);
        void setFundoCreditos( BITMAP* C);
        void setFundoScore( BITMAP* S);
        void setJogo( Jogo* Jo);
};

#endif // MENU_H
