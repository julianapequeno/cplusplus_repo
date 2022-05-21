
#include "Matriz.hpp"


/*TODO implementação da classe*/

void Matriz::set_nome(std::string m){
    this->m_nome = m;
}
std::string Matriz::get_nome(){
    return this->m_nome;
}

void Matriz::set_linhas_e_colunas(int L, int M){
    this->m_linhas_e_colunas.first = L;
    this->m_linhas_e_colunas.second = M;
}

void Matriz::set_vetor_matriz(int i, int n){
    this->m_vetor_matriz[i].resize(1);
    this->m_vetor_matriz[i].push_back(n); 
}   
