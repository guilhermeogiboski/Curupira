#ifndef MENU_H
#define MENU_H

#include "Jogo.h"

class Menu
{
    private:
        BITMAP* buffer;
        // Bitmap de buffer para desenhar todas as imagens nele
        // e logo em seguida jog�-lo inteiro na tela, isso evita
        // que a tela ou as imagens fiquem piscando.
        BITMAP* fundoR; // Fundo do menu de raiz.
        BITMAP* fundoC; // Fundo do menu de cr�ditos.
        BITMAP* fundoS; // Fundo da tela Score..
        Jogo* j;
        bool sair;      // Vari�vel para indicar o processo de sa�da
        // e evitar que o menu seja aberto novamente quando
        // o bot�o sair for pressionado.

    public:
        Menu();
        virtual ~Menu();

        void Inicializar();
        void Iniciar();
        void Raiz();       // Menu principal.
        void Creditos();   // Tela de cr�ditos.
        void Score(); //Tela score
        bool Sair();       // Menu de pergunta para confirma��o de sa�da.

        /* Sets */
        void setBuffer( BITMAP* B);
        void setFundoRaiz( BITMAP* R);
        void setFundoCreditos( BITMAP* C);
        void setFundoScore( BITMAP* S);
        void setJogo( Jogo* Jo);
};

#endif // MENU_H
