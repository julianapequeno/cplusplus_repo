#ifndef Matriz_hpp
#define Matriz_hpp

#include <iostream>
#include <vector>
#include <tuple>
/*TODO documentação estilo doxygen*/
class Matriz{
    //TODO métodos e atributos
    private:
        std::string m_nome; //<! Nome da matriz
        std::pair<int,int> m_linhas_e_colunas; //<! Pair de dois ints que armazem o valor da quantidade de linhas e colunas da matriz
        std::vector<std::vector<int>> m_vetor_matriz; //<! Vetor de vetores contém todos os números da matriz, sendo cada linha representada por um vetor
    public: 
        /**
         * Setter do nome da matriz
         * @param n o nome que deve ser atribuído à matriz atual
         */
        void set_nome(std::string m);
        /**
         * Getter do nome da matriz.
         * @return o nome da matriz.
         */
        std::string get_nome();
        /**
         * Setter das linhas e colunas da matriz 
         * @param L, o número de linhas da matriz
         * @param M, o número de colunas da matriz
         */
        void set_linhas_e_colunas(int L, int M);
        /**
         * Getter da quantidade de linhas e colunas da matriz.
         * @return um par com a quantidade de linhas e de colunas, a quantidade de valores dispostos dentro da matriz
         */
        std::pair<int,int> get_linhas_e_colunas();
        /**
         * Setter do vetor da matriz, número a número
         * @param i, a linha em que o número deve ser inserido, ou seja, o vetor em que será atribuído
         * @param n, o número que será inserido no vetor i
         */    
        void set_vetor_matriz(int i, int n);
        /**
         * Getter de um valor específico da matriz
         * @return um valor da matriz
         */
        int get_valor_matriz(int l, int c);
        /**
         * Setter modificado do vetor da matriz, em uma posição específica
         * @param L, a linha em que o número deve ser inserido, ou seja, o vetor em que será atribuído
         * @param C, a coluna em que o número deve ser inserido, ou seja, a coluna do vetor em que será atribuído
         * @param n, o número que será atribuído na posição especificada
         */  
        void set_vetor_matriz_lugar_especificado(int L, int C, int n);
        /**
         * Limpa toda o vector de vectors m_vetor_matriz.
         * Primeiro, clear() em todos os vetores internos.
         * Segundo e por último, clear() no vetor externo.
         */  
        void clear_matriz();
        /**
         * É um método parecido com set_vetor_matriz_lugar_especificado(). Entretanto,
         * este método atribui o elemento por meio do push_back(). Foi criado para
         * a atribuir os elementos a nova matriz após uma função dot, visto que toda a matriz
         * anterior é limpada antes de receber os novos parâmetros de linhas,colunas e elementos.
         * @param L, em qual linha - vetor - eu devo adicionar o n
         * @param n, o elemento a ser adicionado na matriz
         */
        void push_vector_matriz(int L, int n);
        /*
        * Método criado para reinicializar os dados da matriz;
        * Após o clear_matriz(), é necessário que a matriz seja reinicializada em seu
        * tamanho de vector das linhas e seus vectors de cada uma das linhas com a quantidade das colunas.
        */
        void reiniciar_vector_matriz();
};

#endif 