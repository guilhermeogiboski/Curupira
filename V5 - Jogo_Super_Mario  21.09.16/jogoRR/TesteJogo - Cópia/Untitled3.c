#include "teclado.h"

void keyboard_input()
{
   int i;

   for(i = 0; i < KEY_MAX; i++)
     teclas_anteriores[i] = key[i];

   poll_keyboard(); // atualizar estado do teclado
}

int apertou(int TECLA)
{
    
    printf("\nApertou");
    return(key[TECLA] == TRUE && teclas_anteriores[TECLA] == FALSE);
}

int segurou(int TECLA)
{
        printf("\nSegurou");
    return(key[TECLA] == FALSE && teclas_anteriores[TECLA] == FALSE);
}

int soltou(int TECLA)
{
        printf("\nSoltou");
    return(key[TECLA] == FALSE && teclas_anteriores[TECLA] == TRUE);
}
