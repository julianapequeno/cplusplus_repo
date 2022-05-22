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

void OperaMatrizes::set_par_matriz(Matriz *m, bool primeira_ou_segunda){ //* Conto de dois em dois
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

void OperaMatrizes::function_dot(){
    //Multiplica-se cada linha da primeira matriz por cada coluna da segunda matriz
   std::vector<std::vector<int>> resultado_dot;
    int i_final = 0, y_final = 0, soma_multiplicacao= 0,flag = 0, coluna;
    resultado_dot.resize(this->m_add.first->get_linhas_e_colunas().first); //<! Quantidade de linhas da matriz - Atribuindo a um vetor de vetores
    
    for(int i =  0; i < this->m_add.first->get_linhas_e_colunas().first ; i++){
        coluna = 0;
        resultado_dot[i].resize(this->m_add.first->get_linhas_e_colunas().second); //<! Quantidade de colunas da matriz - Atribuindo a um vetor de vetores
        while(flag < 2){
            for(int y = 0; y < this->m_add.first->get_linhas_e_colunas().second; y++){ //roda pelas minhas colunas da segunda matriz -> UMA DE CADA VEZ
                //std::cout << this->m_add.first->get_valor_matriz(i,y) << " * " << this->m_add.second->get_valor_matriz(y,coluna) << std::endl;
                soma_multiplicacao += (this->m_add.first->get_valor_matriz(i,y) * this->m_add.second->get_valor_matriz(y,coluna));
                //std::cout << soma_multiplicacao << std::endl;
            }
            resultado_dot[i_final][y_final] = soma_multiplicacao;
            y_final++;
            coluna++;
            flag++;
            soma_multiplicacao = 0;
        }
        flag = 0;
        i_final++;
        y_final = 0;
    }
    /* Adiciono na segunda matriz o resultado do cálculo (que está em resultado_dot), por conta das considerações
    * gerais do programa. Esta lógica sempre considera a última matriz inserida pelo usuário, como a ma-
    * triz que possui os resultados no final da compilação. Manteremos assim.
    */
   for(int i = 0; i < this->m_add.first->get_linhas_e_colunas().first; i++){
       for(int y = 0; y < this->m_add.first->get_linhas_e_colunas().second; y++){
           this->m_add.second->set_vetor_matriz_lugar_especificado(i,y, resultado_dot[i][y]); //this->m_add.first->get_valor_matriz(i,y)
       }
       resultado_dot[i].clear();
   }
   resultado_dot.clear();
}