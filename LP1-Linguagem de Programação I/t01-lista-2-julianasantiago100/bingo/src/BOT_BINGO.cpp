#include "Jogador.hpp"
#include "BingoRand.hpp"
#include "BOT_BINGO.hpp"
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

void BINGO::set_jogador(Jogador * j1){
    this->m_jogadores.push_back(j1);
}

void BINGO::imprime_jogadores(){
    for(auto a: this->m_jogadores){
        std::cout << "Jogador ";
        std::cout << a->get_nome() << std::endl;
        std::cout << "Cartela: [";
        for(long unsigned int i = 0; i < 24;i++){ /*Imprime os valores da cartela*/
            std::cout << a->get_numero_da_cartela(i);
            if(i+1 != 24){ //!Se for diferente de ser a última precisão
                std::cout << ", ";
            }
        }
        std::cout <<"]" << std::endl;
    }
}

int BINGO::get_quant_numeros_sorteados(){
    return this->m_quant_numeros_sorteados;
}

int BINGO::sorteio_bingo(){
    int num = this->m_bRand.rand();
    if(this->m_numeros_sorteados.size() > 0){
        for(auto a: this->m_numeros_sorteados){ /*Confere se o número já foi sorteado*/
            while(num == a){
                num = this->m_bRand.rand();
                auto result = std::find(begin(m_numeros_sorteados),end(m_numeros_sorteados),num);
                if(result != m_numeros_sorteados.end()){
                    //Ainda contém o número. Igualo a 'a' para que ele faço tudo novamente,
                    // até encontrar um diferente de todos os que estão no vetor
                    num = a;
                }
            }
        }
    }
    this->m_numeros_sorteados.push_back(num);
    this->m_quant_numeros_sorteados = this->m_quant_numeros_sorteados + 1;
    return num;
}

Jogador* BINGO::retorna_jogador(int i){
    return this->m_jogadores.at(i);
}

int BINGO::get_numeros_sorteados(int i){
    return this->m_numeros_sorteados.at(i);
}

void BINGO::deleta_jogadores(){
    for(auto a : this->m_jogadores){
        delete a;
    }
    this->m_jogadores.clear();
}

void BINGO::adiciona_vencedor(Jogador * vencedor){
    this->vencedores.push_back(vencedor);
}

int BINGO::get_quantos_vencedores(){
    return this->vencedores.size();
}

Jogador* BINGO::get_vencedor(int i){
    return this->vencedores.at(i);
}