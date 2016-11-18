#ifndef PERSONAGEM_H
#define PERSONAGEM_H
#include <allegro.h>
#include "Entidade.h"



class Personagem: public Entidade
{
    public:
        Personagem();
        virtual ~Personagem();

        //--------SETS E GETS---------

        void setImgDireita(BITMAP*_imgDireita);
        void setImgEsquerda(BITMAP*_imgEsquerda);

        BITMAP* getImgDireita();
        BITMAP* getImgEsquerda();

        void setVida(int _vida);
        int getVida();


    protected:
        int vida;
        BITMAP* imgDireita;
        BITMAP* imgEsquerda;

    private:
};

#endif // PERSONAGEM_H
