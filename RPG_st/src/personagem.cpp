#include "../include/personagem.hpp"

Personagem::Personagem(){
    
}
void Personagem::set_nome(std::string nome){
    this->m_nome = nome; 
}

std::string Personagem::get_nome(){
    return this->m_nome;
}

void Personagem::inicializa_ficha(){
    this->ficha_dados_personagem = new Ficha_Personagem(this->m_nome);
}