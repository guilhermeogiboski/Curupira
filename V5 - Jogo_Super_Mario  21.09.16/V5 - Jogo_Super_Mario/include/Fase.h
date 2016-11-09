#ifndef FASE_H
#define FASE_H

#include "Jogador.h"
#include "Inimigo.h"
#include "Chefao.h"
//#include "Tela.h"

//class Menu;

class Fase
{
    protected:

        BITMAP* Buffer();
        //Menu* m;
        Jogador* P1;
        Jogador* P2;
        Inimigo* i1;
        Inimigo* i2;
        Inimigo* i3;
        Inimigo* i4;
        Inimigo* i5;
        Inimigo* i6;
        Chefao* c;

    public:
        Fase();
        virtual ~Fase();

        /*sets*/
        void setBuffer(BITMAP* B);
        //void setTela(Tela* T);
        //void setMenu(Menu* M);
        void setJogadores(Jogador* P, Jogador* PP);
        void setInimigo(Inimigo* I1, Inimigo* I2, Inimigo* I3, Inimigo* I4, Inimigo* I5, Inimigo* I6);
        void setChefao(Chefao* C);


        /*gets*/
        BITMAP* getBuffer();


        void Inicializar();
        void Entrar();






};

#endif // FASE_H
