#ifndef   TECLADO_H
#define TECLADO_H

#include <allegro.h>

int teclas_anteriores[KEY_MAX];

    void keyboard_imput();// atualizar estado do teclado
    int apertou(int TECLA);
    int segurou (int TECLA);
    int soltou (int TECLA);
    
#endif 
