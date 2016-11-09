#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_
#include <allegro.h>



class Personagem // CLASSE PAI
{
    protected:             // Protected para que as classes derivadas possuam esses atributos.
           BITMAP* img;
           BITMAP* imgDireita;  // Imagem andando para frente.
           BITMAP* imgEsquerda; // Imagem andando no sentido contr�rio.
           BITMAP* buffer; // buffer para que o jogador possa se desenhar na tela.
           float x;        // Posi��o em x.
           float y;        // Posi��o em y.
           float h;        // Altura da imagem.
           float l;        // Largura da imagem.
           float vx;       // Velocidade em Y.
           float vy;       // Velocidade em X.
           int vida;       // quantidade de vida.
           bool C,B,D,E;   // Vari�veis para detectar o sentido das colis�es.

    public:
           Personagem();
           virtual~Personagem();

           /* Sets */
           void setImg( BITMAP* I);
           void setImgDir( BITMAP* IMG_DIR); // Imagem do personagem quando "caminha" para a direita
           void setImgEsq( BITMAP* IMG_ESQ); // Imagem do personagem quando "caminha" para a esquerda
           void setBuffer( BITMAP* B);
           void setx( const float X );
           void sety( const float Y );
           void seth( const float H );
           void setl( const float L );
           void setvx( const float VX );
           void setvy( const float VY );
           void setVida( const short int V);



           /* Gets */
           BITMAP* getimg();
           const float getx();
           const float gety();
           const float geth();
           const float getl();
           const float getvx();
           const float getvy();
           const short int getVida();


           /* Movimenta��o */
           virtual void Movimento() = 0;
           // virtual para que o m�todo possa ser redefinido nas subclasses
           // = 0 para tornar a classe 'abstrata', ou  "virtual puro", j� que n�o ser� criado
           // nenhum objeto Personagem.
           //� interessante que esta fun��o seja abstrata pois na classes filhas os objetos ter�o
           //cada um um movimento espec�fico e por n�o existir um objeto Personagem.

           virtual void MovMorte() = 0; // M�todo virtual puro;
                                        // Movimento de morte do personagem (vida = 0)

            /*Desenha*/
           virtual void Desenha();
           //

};

#endif
