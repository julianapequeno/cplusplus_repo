#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <chrono>
#include <thread>
#include "../include/BOT_mestre_de_mesa.hpp"
#include "../include/personagem.hpp"
#include "../include/ansicolors.hpp"

/*
#include <QtGui/QApplication> 
#include <QApplication>

#include <QLabel>
#include <QPixmap> 
*/

void clear(){
  std::cout<< "\033[2J\033[1;1H";
}

int main(){
    /*TODO código here*/
    int op = 0;
    do{
        //clear();
        std::cout<<"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"<<std::endl;
        std::cout<<"▇▇▇▇▇▇▇▇▇▓▒░"<<ANSI_COLOR_CYAN<< "ＢＥＭ" <<ANSI_COLOR_GRAY<< " ＶＩＮＤＯ（Ａ）" <<ANSI_COLOR_GREEN<< " ＡＯ" <<ANSI_COLOR_MAGENTA<< " R P G _ s t"<<ANSI_COLOR_RESET<< "░▒▓▇▇▇▇▇▇▇▇▇ "<< std::endl;
        std::cout<<"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"<<std::endl;
        std::cout << ANSI_COLOR_BLUE "                        1 - INICIAR JOGO " ANSI_COLOR_RESET << std::endl;
        std::cout << ANSI_COLOR_BLUE "                        2 - SCORES ANTERIORES" ANSI_COLOR_RESET << std::endl;
        std::cout << ANSI_COLOR_BLUE "                        3 - SAIR " ANSI_COLOR_RESET << std::endl;
        std::cout << "Sua escolha: ";

        std::cin >> op;
        switch (op)
        {
        case 1:
            std::cout <<  "⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯"  << std::endl;
            std::cout << std::endl;
            BOT_mestre_de_mesa *bot = new BOT_mestre_de_mesa();
            Personagem *p = new Personagem();
            std::cout << "Quantas pessoas irão jogar? " << std::endl;
            int jogadores_quant = 0;
            std::cin >> jogadores_quant;
            std::cout <<  "⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯"  << std::endl;
            std::cout << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            bot->set_quant_jogadores(jogadores_quant);
            bot->escolha_personagem_jogador(p);
            bot->setter_jogadores_and_BOT(p);
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
           // clear();
            std::cout <<  "⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯"  << std::endl;
            std::cout << ">> Okay! Seja bem vindo(a) " << ANSI_COLOR_MAGENTA << p->get_nome() << ANSI_COLOR_RESET << " ao jogo de RPG_st!" << std::endl;
            std::cout << "Estes são os jogadores que irão jogar essa partida com você: " << std::endl;
            for(int i = 1; i < bot->quant_jogadores();i++){ /*Desconsidera a primeira posição, pois é onde o jogador usuário está*/
                std::cout << ANSI_COLOR_MAGENTA << bot->get_jogador(i)->get_nome() << ANSI_COLOR_RESET << std::endl;
            }
            std::cout << ANSI_COLOR_GREEN">>> Jogadores OK ✅ \n Iniciando o jogo..." ANSI_COLOR_RESET << std::endl;
            std::cout <<  "⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯"  << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            std::cout <<  ANSI_COLOR_GRAY << "Prontos para a partida?? xxxD" << ANSI_COLOR_RESET << std::endl;
            
            /*Início do JOGO*/
            //clear();
            std::cout<<"▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇ "<<ANSI_COLOR_CYAN<< "A M B I E N T E  D E J O G O " <<ANSI_COLOR_RESET<< "▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇ " << std::endl;
            std::cout << "                      ________________________"<< std::endl;
            std::cout << ANSI_COLOR_GRAY "                      | 1 - MINHA FICHA      |" ANSI_COLOR_RESET << std::endl;
            std::cout << ANSI_COLOR_GRAY "                      | 2 - MEUS PONTOS      |" ANSI_COLOR_RESET << std::endl;
            std::cout << ANSI_COLOR_GRAY "                      | 3 - ATAQUES E DEFESA |" ANSI_COLOR_RESET << std::endl;
            std::cout << ANSI_COLOR_GRAY "                      |______________________|"<< std::endl;
            std::cout << std::endl;
            std::cout << "Jogadores que estão ONLINE nesta partida: ";
            for(int i = 1; i < bot->quant_jogadores();i++){ /*Desconsidera a primeira posição, pois é onde o jogador usuário está*/
                if(i+1 == bot->quant_jogadores()){
                    std::cout << ANSI_COLOR_MAGENTA << bot->get_jogador(i)->get_nome() << ANSI_COLOR_RESET << "";
                }else{
                    std::cout << ANSI_COLOR_MAGENTA << bot->get_jogador(i)->get_nome() << ANSI_COLOR_RESET << ", ";
                }
            }
            std::cout << "\n> Sua escolha: ";
            int x = 0;
            std::cin >> x;
            if(op==1){
                p->get_ficha_personagem()->imprimir_minha_ficha();
            }
            /*Deletando os ponteiros*/
            delete bot;
            delete p;
            break;
        }

    }while(op!=2);
}