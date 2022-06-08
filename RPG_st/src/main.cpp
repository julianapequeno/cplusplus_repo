#include <iostream>
#include "../include/BOT_mestre_de_mesa.hpp"
#include "../include/personagem.hpp"
/*
#include <QtGui/QApplication> 
#include <QApplication>

#include <QLabel>
#include <QPixmap> 
*/

int main(){
    /*TODO código here*/
    int op = 0;
    do{
        std::cout << "BEM VINDO AO RPG_ST" << std::endl;
        std::cout << "1 - Iniciar o jogo" << std::endl;
        std::cout << "2 - Sair do sistema" << std::endl;

        std::cin >> op;
        switch (op)
        {
        case 1:
            std::cout << "--------------------------------------------" << std::endl;
            BOT_mestre_de_mesa *bot = new BOT_mestre_de_mesa();
            Personagem *p = new Personagem();
            std::cout << "Quantas pessoas irão jogar? " << std::endl;
            int jogadores_quant = 0;
            std::cin >> jogadores_quant;
            bot->set_quant_jogadores(jogadores_quant);
            bot->setter_jogadores_and_BOT(p);

            bot->escolha_personagem_jogador(p);
            std::cout << "Okay! Seja bem vindo(a) " << p->get_nome() << " ao jogo de RPG_st!" << std::endl;
            std::cout << "Estes são os jogadores que irão jogar essa partida com você: " << std::endl;
            for(int i = 1; i < bot->quant_jogadores();i++){ /*Desconsidera a primeira posição, pois é onde o jogador usuário está*/
                std::cout << bot->get_jogador(i)->get_nome() << std::endl;
            }
            std::cout << "Prontos para a partida?? xxxD" << std::endl;
            /*Deletando os ponteiros*/
            delete bot;
            delete p;
            break;
        }

    }while(op!=2);
}