#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include <iostream>
#include <string>
#include "../include/ficha_personagem.hpp"

class Personagem{
    private:
        std::string m_nome; //!Nome do seu personagem na partida
        int m_pontos; //!Pontuação do jogador
        Ficha_Personagem *ficha_dados_personagem; //LEMBRE DE DELETAR DEPOIS
    public:
        Personagem();
        /**
         * @brief Método que iniciliza a ficha do personagem.
         */
        void inicializa_ficha();
        /**
         * @brief Setter que recebe o nome do personagem que está jogando
         * @param, o nome do personagem
         */
        void set_nome(std::string);
        /**
         * @brief Getter que retorna o nome do personagem
         * 
         * @return , uma string com o valor de m_nome 
         */
        std::string get_nome();
        /**
         * @brief Método para deletar variáveis dinâmicas
         * 
         */
        void deletar_ficha();
        /**
         * @brief Método que retorna o atributo ficha_dados_personagem
         */
        Ficha_Personagem* get_ficha_personagem();
};

#endif