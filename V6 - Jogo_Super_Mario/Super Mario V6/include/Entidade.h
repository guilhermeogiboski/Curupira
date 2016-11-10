#ifndef ENTIDADE_H
#define ENTIDADE_H
#include <allegro.h>


class Entidade
{
protected:             // Protected para que as classes derivadas possuam esses atributos.
    BITMAP* img;
    BITMAP* buffer; // buffer para que a entidade possa se desenhar na tela.
    float x;        // Posi��o em x.
    float y;        // Posi��o em y.
    float h;        // Altura da imagem.
    float l;        // Largura da imagem.
    float vx;       // Velocidade em Y.
    float vy;       // Velocidade em X.

public:
    Entidade();
    virtual~Entidade();

    /* Sets */
    void setImg( BITMAP* IMG);
    void setBuffer( BITMAP* BUF);
    void setx( const float X );
    void sety( const float Y );
    void seth( const float H );
    void setl( const float L );
    void setvx( const float VX );
    void setvy( const float VY );




    /* Gets */
    BITMAP* getimg();
    const float getx();
    const float gety();
    const float geth();
    const float getl();
    const float getvx();
    const float getvy();


    /* Movimenta��o */
    virtual void Movimento() = 0;
    // virtual para que o m�todo possa ser redefinido nas subclasses
    // = 0 para tornar a classe 'abstrata', ou  "virtual puro", j� que n�o ser� criado
    // nenhum objeto Entidade.
    //� interessante que esta fun��o seja abstrata pois na classes filhas os objetos ter�o
    //cada um um movimento espec�fico e por n�o existir um objeto Entidade.


    /*Desenha*/
    virtual void Desenha(); //Desenha imagem

};

#endif // ENTIDADE_H
