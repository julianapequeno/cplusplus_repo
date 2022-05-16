
#include "Cadastro.hpp"

#include <algorithm>

Cadastro::Cadastro(std::string nome){
    m_nome = nome;
    /*nada a fazer*/
}

void Cadastro::adicionaPessoa(Pessoa *p){
    m_cadastrados.push_back(p);
}

Pessoa* Cadastro::removePessoa(std::string cpf){
    auto pessoa_iterator = std::find_if(m_cadastrados.begin(), m_cadastrados.end(),[cpf](Pessoa* p){ //função lambda para encontrar uma pessoa pelo cpf
        return p->getCPF() == cpf;
    });
    if(pessoa_iterator != m_cadastrados.end()){
        m_cadastrados.erase(pessoa_iterator); //remove do vetor
        return *pessoa_iterator; //retorna a referencia
    }
    else
        return nullptr; 
}

Pessoa* Cadastro::encontraPessoa(std::string cpf){
   // std::cout << "Searching..." << std::endl;
    auto pessoa_iterator = std::find_if(m_cadastrados.begin(), m_cadastrados.end(),
                            [cpf](Pessoa* p){ //função lambda para encontrar uma pessoa pelo cpf
                               // std::cout << "Este é o cpf dessa PESSOA P = " << p->getCPF() << " AND " << cpf << "\n";
                                return p->getCPF().compare(cpf)==0;
                            });
    if(pessoa_iterator != m_cadastrados.end()){
        return *pessoa_iterator; //retorna a referenci
    }else{
        return nullptr;
    }
}

/**
 * Remove todas as pessoas cadastradas
 * Esse método chama diretamente o método clear do container vector, logo os dados não são deletados.
 */
void Cadastro::limpaCadastro(){
    m_cadastrados.clear();
}

void Cadastro::apaga_cpfs(std::vector<Pessoa *> nomes){
    Pessoa *p;
    for(long unsigned int i = 1; i < nomes.size();i++){ //sem o default
        Pessoa *p = removePessoa(nomes[i]->getCPF());
        if(p != nullptr){
            delete p;
        }else{} //condicional de erro, caso queira desenvolver
    }
    p = new Pessoa("","");
    delete p;
   // return true;
}