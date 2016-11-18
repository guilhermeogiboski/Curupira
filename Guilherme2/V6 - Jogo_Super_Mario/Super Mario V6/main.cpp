#include <iostream>
#include <allegro.h>
#include "Jogador.h"
#include "Personagem.h"

#include "GerenciadorGrafico.h"


// teste
//class Curupira;
#include "Curupira.h"
#include "Saci.h"


using namespace std;

int main()
{
    allegro_init();
    install_timer();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0);


    BITMAP* buffer = create_bitmap(SCREEN_W,SCREEN_H);

    Jogador j;

    Curupira c;

    Curupira* c2 = new Curupira();


    Saci s,s2;
   /* for(int i = 0; i < 10; i++)
    {

        Curupira *novo = new Curupira();
        novo->setX(100+i*10);
        novo->setY(200);
        Lista.Adicionar(novo);

    }*/





    j.setImg(load_bitmap("Imagens//mario.bmp", NULL));
    j.setVida(3);
    j.setx(150); // Posição inicial em x.
    j.sety(40); // Posição icial em y.
    j.setvx(1);  // Velocidade icial do objeto em x.
    j.setvy(1);  // Velocidade icial do objeto em y.

    j.setBuffer(buffer);
    //p.Desenha();

    //draw_sprite(screen,buffer,0,0);
    // blit(buffer, screen, 0, 0, 0, 0, 800, 600); // Desenha o buffer na tela.

    //circlefill(screen, 100,110,50,makecol(255,0,0));

   // BITMAP* mario = load_bitmap("imagens//mario.bmp",NULL);

   c.setImg(load_bitmap("Imagens//mario.bmp", NULL));
   c.setVida(4);
   c.setx(50);
   c.sety(50);
   c.setvx(1);
   c.setvy(1);
   c.setBuffer(buffer);


    c2->setImg(load_bitmap("Imagens//mario.bmp", NULL));
   c2->setVida(4);
   c2->setx(25);
   c2->sety(25);
   c2->setvx(0.1);
   c2->setvy(1);
   c2->setBuffer(buffer);

    s.setImg(load_bitmap("Imagens//mario.bmp", NULL));
   s.setVida(4);
   s.setx(90);
   s.sety(200);
   s.setvx(2);
   s.setvy(2);
   s.setBuffer(buffer);

    s2.setImg(load_bitmap("Imagens//mario.bmp", NULL));
   s2.setVida(4);
   s2.setx(80);
   s2.sety(500);
   s2.setvx(1);
   s2.setvy(1);
   s2.setBuffer(buffer);




 while (!key[KEY_ESC]) //loop principal.
    {

//    Lista.Desenha()
    j.Desenha();
    c.Desenha();
    s.Desenha();
    s2.Desenha();
    c2->Desenha();
    blit(buffer, screen, 0, 0, 0, 0, 800, 600);
    j.Movimento();
    c.Movimento();
    s.Movimento();
    s2.Movimento();
    c2->Movimento();

    //draw_sprite(screen,buffer,p.getx(),p.gety());

    clear( buffer );



    }






//system("pause");
    return 0;
}
END_OF_MAIN()
