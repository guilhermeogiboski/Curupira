#include<windows.h>
#include<stdio.h>
#include<conio.h>
//#include<iostream>
#include <stdlib.h>
#include <time.h>
#include "recursos.h"
#include "funções.h"


main()
{

    int p;

    tela(50,18);
    p=cobra();
    gameover();
    pontosfinais(p);
    getch();
}
