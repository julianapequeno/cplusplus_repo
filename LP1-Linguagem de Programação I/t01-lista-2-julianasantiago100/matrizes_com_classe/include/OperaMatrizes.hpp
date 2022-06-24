#ifndef OperaMatrizes_hpp
#define OperaMatrizes_hpp

#include "Matriz.hpp"
#include <tuple>
#include <vector>

class OperaMatrizes{
    private:
        std::pair<Matriz *, Matriz *> m_add; //<!Atributo que guarda as matrizes atuais que serão somadas
    public:
        /**
         * Função de Multiplicação por Escalar
         * @param n, o número que será o multiplicador de todos os elementos da matriz
         * @param m, a referência para a matriz a qual será aplicada a multiplicação por escalar
         */
        void function_mue(int n,Matriz * m);
        /**
         * Setter das matrizes para a adição (função auxiliar)
         * A operação de adição só realiza somas de duas em duas matrizes, por isso guarda-se por meio desta função referências a duas matrizes
         * @param m, a matriz que será adicionada a conta da adição
         * @param b, um valor booleano o qual, sendo true -> é a primeira matriz da soma, sendo false -> é a segunda matriz da soma
         */
        void set_par_matriz(Matriz *m,bool b); 
        /**
         * Função de Adição de Matrizes
         * Como a adição neste projeto apenas é realizada de duas em duas matrizes, guarda-
         * se o resultado da adição na segunda matriz. Para que assim, caso ocorra de serem
         * três matrizes para a soma, seja elaborada como um somatório, em que somará-se o re-
         * sultado da soma anterior com a próxima matriz.
         * Usar referências por todo o código facilita a lógica para isso ser feito (neste caso, no main e no OperaMatrizes).
         * @param n, o número que será o multiplicador de todos os elementos da matriz
         * @param m, a referência para a matriz a qual será aplicada a multiplicação por escalar
         */
        void function_add();
        /**
         * Função de Multiplicação Matricial
         * Essa função multiplica uma matriz por outra.
         * Segundo a definição deste tipo de multiplicação, cada linha da primeira matriz
         * é multiplicada por cada coluna da segunda matriz. Elemento a elemento. 
         * Essa função também faz uso do pair m_add. Onde estão guardadas as matrizes
         * envolvidas com essa multiplicação. De duas a duas.
         * @return um valor-lógico verdadeiro ou falso, para afirmar se é possível multiplicar e realizar a multiplicação OU afirmar que não é possível multiplicar.
         */
        bool function_dot();
        /**
         * Função de Multiplicação Elemento à Elemento.
         * Multiplica cada elemento da matriz A por seu respectivo elemento (em posição) na
         * matriz B. Para que isso ocorra, as matrizes devem possuir a mesma dimensão.
         * @return um valor-lógico verdadeiro ou falso, para afirmar se é possível multiplicar e realizar a multiplicação OU afirmar que não é possível multiplicar.
         */
        bool function_mul();
};  

#endif