#ifndef SACI_H
#define SACI_H

#include "Inimigo.h"

class Saci: public Inimigo
{
    public:
        Saci();
        virtual ~Saci();

        void Movimento();

        void setVida(int _vida);
        int getVida();

    protected:

    private:
        int vida;
};

#endif // SACI_H
