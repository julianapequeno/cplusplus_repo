#include "OperaMatrizes.hpp"

void OperaMatrizes::function_mue(int n,Matriz *m){
     //std::cout << "Esse é o meu matrix: " << m->get_nome() << std::endl;
    for(int i = 0; i < m->get_linhas_e_colunas().first; i++){ //linha
        for(int y = 0; y < m->get_linhas_e_colunas().second; y++){ //coluna
            m->set_vetor_matriz_lugar_especificado(i,y,(m->get_valor_matriz(i,y) * n));
        }
    }
}

void OperaMatrizes::set_resultado_conta(Matriz *m){
    this->m_resultado_conta.push_back(m);
}

void OperaMatrizes::set_adicao(Matriz *m, bool primeira_ou_segunda){ //* Conto de dois em dois
    if(primeira_ou_segunda){ //<! É o início de uma conta
        this->m_add.first = m;
    }else{
        this->m_add.second = m;
    }
}

void OperaMatrizes::function_add(){
    for(int i = 0; i < this->m_add.first->get_linhas_e_colunas().first; i++){ //*Até a quantidade de linhas da primeira matriz
        for(int y = 0; y < this->m_add.second->get_linhas_e_colunas().second;y++){ //*Até a quantidade de colunas da primeira matriz
            this->m_add.second->set_vetor_matriz_lugar_especificado(i,y,this->m_add.first->get_valor_matriz(i,y) + this->m_add.second->get_valor_matriz(i,y)); //*Seta na posição da segunda matriz, a soma entre os valores que estão nessa posição na matriz 1 e na matriz 2
        }
    }
    this->set_resultado_conta(m_add.second); //<! Puxa o resultado para a soma final no resultado_conta
}