#ifndef Matriz_hpp
#define Matriz_hpp

#include <iostream>
#include <vector>
#include <tuple>
/*TODO documentação estilo doxygen*/
class Matriz{
    //TODO métodos e atributos
    private:
        std::string m_nome; //<! nome da matriz
        std::pair<int,int> m_linhas_e_colunas; //<! pair de dois ints que armazem o valor da quantidade de linhas e colunas da matriz
        std::vector<std::vector<int>> m_vetor_matriz; //<! vetor de vetores contém todos os números da matriz, sendo cada linha representada por um vetor
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
         * @return linhas*colunas, a quantidade de valores dispostos dentro da matriz
         */
        int get_linhas_e_colunas();
        /**
         * Setter do vetor da matriz, número a número
         * @param i, a linha em que o número deve ser inserido, ou seja, o vetor em que será atribuído
         * @param n, o número que será inserido no vetor i
         */    
        void set_vetor_matriz(int i, int n);
};

#endif //FiguraGeometrica_hpp