#ifndef BOT_BINGO_hpp
#define BOT_BINGO_hpp

/*
* Classe para realizar as simulações do jogo de Bingo!
* O programa entra com os jogadores e esta classe gerencia
* quem marcou os pontos, quem ganhou...É um BOT do jogo de BINGO
*/
#include "BingoRand.hpp"
#include <iostream>
#include <vector>
#include "Jogador.hpp"
using namespace std;

class BINGO{
    private:
        std::vector<Jogador *> m_jogadores; /*Vetor com todos os jogadores incritos na partida*/
        BingoRand m_bRand; /*Atributo de uso da classe BingoRand*/
        int m_quant_numeros_sorteados; /*Quantos números já foram sorteados*/
        std::vector<int> m_numeros_sorteados; /*Todos os números que já foram sorteados*/
        std::vector<Jogador *> vencedores; /*Atributo que guarda os vencedores da partida*/
    public:
        /**
        * @brief Setter no jogador no vetor m_jogadores
        * @brief O vetor m_jogadores guarda as referências a todos os jogadores criados
        * @param Jogador *, recebe uma referência de uma nova instância da classe jogador
        */
        void set_jogador(Jogador *);
        /**
        * @brief Imprime os jogadores inscritos na partida!
        */
        void imprime_jogadores();
        /**
        * @brief Retorna a quantidade de números que já foram sorteados no BINGO
        * @return, o valor do m_quant_numeros_sorteados
        */
        int get_quant_numeros_sorteados();
        /**
        * @brief Função que sorteia o próximo número!
        * @return próximo valor do sorteio
        */
        int sorteio_bingo();
        /**
        * @brief Método que retorna um jogador inscrito na partida;
        * @param i, o índice i que indica onde o jogador requisitado está no vetor m_jogadores
        * @return o Jogador atribuído ao índice i no vetor m_jogadores
        */
        Jogador* retorna_jogador(int i);
        /**
        * @brief Retorna todos os números que já foram sorteados pelo BOT BINGO.
        * @param i, o indice i que indica qual posição no vetor m_numeros_sorteados será retornada
        * @return o valor de m_numeros_sorteados no índice i, o qual é um número sorteado pelo BOT BINGO
        */
        int get_numeros_sorteados(int i);
        /**
         * @brief Método que deleta todas as referências aos jogadores inscritos na partida;
         * Criado para evitar vazão de memória. No final do programa, todas as referências são
         * destruídas. Deleta do atributo m_jogadores.
         */
        void deleta_jogadores();
        /**
         * @brief Oba! Mais um vencedor da partida! Este método adiciona ao vetor vencedores
         * todos os jogadores que venceram a partida de BINGO.
         * @param vencedor, uma referência a um objeto Jogador, tal qual este ganhou a partida. 
         */
        void adiciona_vencedor(Jogador * vencedor);
        /**
         * @brief Getter de quantos jogadores venceram a partida;
         * @return o tamanho do vetor vencedores
         */
        int get_quantos_vencedores();
        /**
         * @brief Getter de um vencedor da partida.
         * @param i, o indice do vetor vencedores
         * @return Jogador*, a referência ao objeto do jogador vencedor
         */
        Jogador* get_vencedor(int i);
};


#endif