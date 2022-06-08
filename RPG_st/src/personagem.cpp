#include "../include/personagem.hpp"

void Personagem::set_nome(std::string nome){
    this->m_nome = nome; 
}

std::string Personagem::get_nome(){
    return this->m_nome;
}