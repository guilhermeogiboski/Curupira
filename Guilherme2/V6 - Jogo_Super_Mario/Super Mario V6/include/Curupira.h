#ifndef CURUPIRA_H
#define CURUPIRA_H

#include "Inimigo.h"

//teste


class Curupira: public Inimigo
{
    public:
        Curupira();
        virtual ~Curupira();

        void Movimento();

        void setVida(int _vida);
        int getVida();


    protected:

    private:

        int vida;

};

#endif // CURUPIRA_H
