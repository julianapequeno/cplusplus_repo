#include "Jogador.hpp"
#include "BingoRand.hpp"
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

Jogador::Jogador(std::string nome){
    this->m_cartela.resize(24);
    this->m_cartela = this->m_bRand.getNDifferent(1,99,24);
    this->set_nome(nome);
    this->m_acertados = 0;
}

std::string Jogador::get_nome(){
    return this->m_nome;
}

void Jogador::set_nome(std::string nome){
    this->m_nome = nome;
}

void Jogador::set_acertados(){
    this->m_acertados = this->m_acertados + 1;
}

int Jogador::get_numero_da_cartela(int i){ /*Para a padrão de entrada de 24 números, isso não pode dar exceção*/
    return this->m_cartela.at(i);
}

int Jogador::get_acertados(){
    return this->m_acertados;
}