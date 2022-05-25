
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
    this->m_vetor_matriz.resize(this->m_vetor_matriz.size()+1);
    this->m_vetor_matriz.at(i).push_back(n); 
}   

int Matriz::get_valor_matriz(int l, int c){
    return this->m_vetor_matriz.at(l).at(c);
}

void Matriz::set_vetor_matriz_lugar_especificado(int L, int C, int n){
    this->m_vetor_matriz.at(L).at(C) = n;
}

std::pair<int,int> Matriz::get_linhas_e_colunas(){
    return this->m_linhas_e_colunas;
}

void Matriz::clear_matriz(){
    for(auto a : this->m_vetor_matriz){
        a.clear();
    }
    this->m_vetor_matriz.clear();
}

void Matriz::reiniciar_vector_matriz(){
    this->m_vetor_matriz.resize(this->m_linhas_e_colunas.first);
    for(auto a : this->m_vetor_matriz){
        a.resize(this->m_linhas_e_colunas.second);
    }
}

void Matriz::push_vector_matriz(int L, int n){
    this->m_vetor_matriz.at(L).push_back(n);
}