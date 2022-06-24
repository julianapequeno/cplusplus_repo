#ifndef Jogador_hpp
#define Jogador_hpp

/*
* Classe para representar um jogador no jogo de Bingo!
* Cada instância define um novo jogador!
*/
#include <iostream>
#include <string>
#include <vector>
#include "BingoRand.hpp"
using namespace std;

class Jogador{
    private:    
        std::string m_nome; /*Nome do jogador*/
        std::vector<int> m_cartela; /*Cartela do jogador. Número fixo de 24*/
        BingoRand m_bRand; /*Atributo de uso da classe BingoRand, para instanciar a cartela*/
        int m_acertados; /*Quantidade de números que o jogador acertou*/
    public:
        /**
        * Construtor da classe Jogador
        * Inicializa o objeto Jogador com o tamanho da cartela igual a 24;
        * @param nome, o nome do jogador 
        */
        Jogador(std::string nome);
        /** 
        * Setter do atributo m_nome
        * @param nome, recebe o valor a ser atribuído ao atributo m_nome
        */
        void set_nome(std::string nome);
        /** 
        * Getter do atributo m_nome
        * @return, retorna o o valor de m_nome;
        */
        std::string get_nome();
        /**
        * Setter da quantidade de números que foram marcados na cartela do jogador.
        * Esse método acrescenta +1 ao atributo m_acertados; 
        */
        void set_acertados();
        /**
        * Getter de um número em um índice arbitrário na cartela. 
        * @param i, é o índice da posição que retornará um número da cartela do jogador;
        * @retun o valor presente no vetor m_cartela no índice i
        */
        int get_numero_da_cartela(int i);
        /**
        * Getter do atributo m_acertados; Retorna a quantidade de números que o jogador marcou
        * em sua cartela;
        * @return o valor do atributo m_acertados
        */
        int get_acertados();
};

#endif 