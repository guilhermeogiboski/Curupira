#ifndef RECURSOS_H_INCLUDED
#define RECURSOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <stdio.h>
#include <conio.h>
COORD coord={0,0};

static const int preto=0;
static const int azulescuro=1;
static const int verde=2;
static const int ciano=3;
static const int vermelho=4;
static const int magenta=5;
static const int amarelo=6;
static const int branco=7;
static const int cinza=8;
static const int azulclaro=9;
static const int verdeclaro=10;
static const int cianoclaro=11;
static const int vermelhoclaro=12;
static const int magentaclaro=13;
static const int amareloclaro=14;
static const int brancoclaro=15;

 void gotoxy(int x,int y)
 {
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void setcolor(int ForgC)
{
// As cores sao:
// 0=preto 1=azul 2=verde ate 15=branco
// atributodecor = cordaletra + cordofundo * 16
// para escrever com texto vermelho no fundo amarelo 4 + 14*16 = 228
// vemelho claro no fundo amarelo  12 + 14*16 = 236
// alguns compiladores nao aceitam o fundo

     WORD wColor;
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}


#endif // RECURSOS_H_INCLUDED
