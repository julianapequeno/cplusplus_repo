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
        std::string povo;//enum povo (HAWKINGS, LB_HAWKINGS, MUNDO_INVERTIDO,UTAH,CALIFORNIA,RUSSIA);
        std::pair<int,int> lealdadade_e_devocao; 
        int idade;
        std::pair<double,double> altura_e_peso;
        std::map<std::string,int> atributos_especializacoes;
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

};

#endif