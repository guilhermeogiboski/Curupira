#include "Inimigo.h"

Inimigo::Inimigo()
{
   img = load_bitmap("Arquivos//Imagens//Inimigo.bmp", NULL);  //carrega a imagem a partir da pasta onde ela está.
   h = 100.0; // inicializa a altura da imagem/Inimigo.
   l = 100.0; // inicializa a largura da imagem/Inimigo.
   x = 900.0; // Posição inicial em x.
   y = 510.0; // Posição icial em y.
   vx = 1;  // Velocidade icial do objeto em x.
   vy = 1;  // Velocidade icial do objeto em y.

   Jog_Perseguido = NULL;
}

Inimigo::~Inimigo()
{
    destroy_bitmap(img);  // Destrói a imagem;
}


/* Sets */
void Inimigo::setimg( BITMAP* I )
{
    img = I;
}

void Inimigo::setbuffer( BITMAP* B )
{
    buffer = B;
}


 void Inimigo::setx( float X )
    {
        x = X;
    }

void Inimigo::sety( float Y )
{
        y = Y;
}

void Inimigo::seth( float H )
{
        h = H;
}

    void Inimigo::setl( float L )
    {
        l = L;
    }

    void Inimigo::setvx( float VX )
    {
        vx = VX;
    }

    void Inimigo::setvy( float VY )
    {
        vy = VY;
    }

/* Gets */
BITMAP* Inimigo::getimg()
{
    return img;
}


 float Inimigo::getx()
 {
    return x;
 }

 float Inimigo::gety()
 {
    return y;
 }

 float Inimigo::geth()
 {
    return h;
 }

 float Inimigo::getl()
{
    return l;
}

float Inimigo::getvx()
{
    return vx;
}

float Inimigo::getvy()
{
   return vy;
}

/* Movimentação */
void Inimigo::Perseguir()
{
    if (Jog_Perseguido != NULL)
    {
       if(x > Jog_Perseguido->getx())
       {
           x = x - vx;
       }
       if(x < Jog_Perseguido->getx())
       {
           x = x + vx;
       }

       if(y > Jog_Perseguido->gety())
       {
            y = y - vy;
       }
       if(y < Jog_Perseguido->gety())
       {
            y = y + vy;
       }

       }
       else
      {
         // msg erro
      }
 }


void Inimigo::Desenha()
{
    draw_sprite(buffer, img, x, y);  // Desenha no buffer
}
