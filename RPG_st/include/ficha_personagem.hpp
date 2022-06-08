#ifndef FICHA_PERSONAGEM_HPP
#define FICHA_PERSONAGEM_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>

class Ficha_Personagem{
    private:   
        std::string povo;//enum povo (HAWKINGS, LB_HAWKINGS, MUNDO_INVERTIDO,UTAH,CALIFORNIA,RUSSIA);
        std::pair<int,int> lealdadade_e_devocao; 
        int idade;
        std::pair<int,int> altura_e_peso;
        std::map<std::string,int> atributos_especializacoes;
    public: 
        /**
         * @brief 
         * 
         */
        void set_atributos();
};

#endif