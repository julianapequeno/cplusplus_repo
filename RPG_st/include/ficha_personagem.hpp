#ifndef FICHA_PERSONAGEM_HPP
#define FICHA_PERSONAGEM_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <chrono>

class Ficha_Personagem{
    private:   
        std::string m_nome;//!Nome do personagem
        std::string m_povo;//enum povo (HAWKINGS, LB_HAWKINGS, MUNDO_INVERTIDO,UTAH,CALIFORNIA,RUSSIA);
        std::pair<int,int> m_lealdadade_e_devocao; 
        int m_idade;
        std::pair<double,double> m_altura_e_peso;
        std::map<std::string,int> m_atributos_especializacoes;
    public: 
        /**
         * @brief Construct a new Ficha_Personagem object
         *  BOT
         */
        Ficha_Personagem(std::string);
        /**
         * Método para setar os atributos do personagem criado pelo usuário
         * 
         */
        void new_personagem_set_atributos();
        /**
         * @brief 
         * Método que imprime os dados do personagem
         */
        void imprimir_minha_ficha();

};

#endif