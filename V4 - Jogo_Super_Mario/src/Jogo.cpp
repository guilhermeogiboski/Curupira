#include "Jogo.h"

Jogo::Jogo()
{
    buffer = create_bitmap(800, 600);
    Cenario1 = load_bitmap("Arquivos//Imagens//Cenario1.bmp", NULL);  //carrega a imagem a partir da pasta onde ela está.
    posicao1 = 0;
    posicao2 = 910;
    posicao3 = -910;
    vx = 0.8;

    Jog = NULL;
    Inim = NULL;
}

Jogo::~Jogo()
{
    destroy_bitmap(buffer);
}

void Jogo::setPersonagem(Jogador* P, Inimigo* I)
{
    Jog = P;
    Inim = I;
    Inim->setJogador(Jog);
    Jog->setInimigo(Inim);
}

void Jogo::setCenario( BITMAP* CENARIO )
{
    Cen = CENARIO;
}

void Jogo::Iniciar()
{
    Jog->setbuffer(buffer); // Associa o buffer ao jogador
    Inim->setbuffer(buffer); // Associa o buffer ao Inimigo
    setCenario(buffer);
    Tela1();
}


void Jogo::DesenhaTela1()
{
    if (key[KEY_RIGHT])
    {

        if(posicao1 < -900)
        {
            posicao1 = 0;
            posicao2 = 910;
            posicao3 = -910;
        }
        posicao1 = posicao1 - vx;
        posicao2 = posicao2 - vx;
        posicao3 = posicao3 - vx;
    }

    if (key[KEY_LEFT])
    {
        if(posicao1 > 910)
        {
            posicao1 = 0;
            posicao2 = 910;
            posicao3 = -910;
        }
        posicao1 = posicao1 + vx;
        posicao2 = posicao2 + vx;
        posicao3 = posicao3 + vx;
    }

    draw_sprite(buffer, Cenario1, posicao1,0);
    draw_sprite(buffer, Cenario1, posicao2,0);
    draw_sprite(buffer, Cenario1, posicao3,0);


    if(posicao2 < 1)
    {
        posicao1 = 0;
        posicao2 = 990;
    }
}


void Jogo::Tela1()
{
    while (!key[KEY_ESC]) //loop principal.
    {
        DesenhaTela1();
        Jog->Desenha(); // Chama a função Desenha para desenhar o Jogador no buffer.
        Inim->Desenha(); // Chama a função Desenha para desenhar o Inimigo no buffer.

       blit(buffer, screen, 0, 0, 0, 0, 800, 600); // Desenha o buffer na tela.

        Jog->Movimento(); // Aciona o movimento do jogador.
        Jog->MovMorte();

        Inim->Perseguir(); // Aciona o movimento do Inimigo.

        clear( buffer ); // Limpa o buffer;
    }
}

