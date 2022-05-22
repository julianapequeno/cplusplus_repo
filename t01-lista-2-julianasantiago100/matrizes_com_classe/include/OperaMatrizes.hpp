#ifndef OperaMatrizes_hpp
#define OperaMatrizes_hpp

#include "Matriz.hpp"
#include <tuple>
#include <vector>

class OperaMatrizes{
    private:
        std::string m_operacao; //<!string com o nome da operação a ser realizada
        std::vector<Matriz *> m_resultado_conta; //<! Guarda todos os resultados das contas com as matrizes separados
        std::pair<Matriz *, Matriz *> m_add; //<!Atributo que guarda as matrizes atuais que serão somadas
    public:
        /**
         * Função de Multiplicação por Escalar
         * @param n, o número que será o multiplicador de todos os elementos da matriz
         * @param m, a referência para a matriz a qual será aplicada a multiplicação por escalar
         */
        void function_mue(int n,Matriz * m);
        /**
         * Guarda todas as matrizes com seus respectivos novos valores, pós passarem pelas funções matemáticas
         * @param m, a matriz já alterada que será adicionada ao vetor m_resultado_conta para a soma final
         */
        void set_resultado_conta(Matriz *m); /* LEMBRAR:: Some todas no final!! O vector guarda todos os resultados separados!*/
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
         */
        void function_dot();
};  

#endif