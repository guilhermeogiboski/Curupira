#include "Principal.h"

Principal::Principal()
{
    Executar();
}

Principal::~Principal()
{

}

void Principal::Executar()
{
    J.setPersonagem(&P, &I);  // Associa o Jogador e Inimigo ao jogo.
    J.setCenario(&C);
    J.Iniciar();
    // cria o jogo e envia o personagem como parâmetro (por referência)

}
