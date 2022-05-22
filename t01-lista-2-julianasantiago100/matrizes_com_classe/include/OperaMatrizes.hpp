#ifndef OperaMatrizes_hpp
#define OperaMatrizes_hpp

#include "Matriz.hpp"
#include <tuple>
#include <vector>

class OperaMatrizes{
    private:
        std::tuple<std::string,std::pair<int,int>,std::vector<int>> m_matrizes; //<!tuple para armazenar o nome, o tamanho da linha e da coluna e os números da matriz
        std::string m_operacao; //<!string com o nome da operação a ser realizada
        std::vector<Matriz *> m_resultado_conta; //<! Guarda todos os resultados das contas com as matrizes separados
        std::pair<Matriz *, Matriz *> m_add;
    public:
        /// DETROI COMMENT operações a serem construídas: add,moe,mod...
        void function_mue(int n,Matriz * m);
        std::string metodo_teste(Matriz *);

        void set_resultado_conta(Matriz *m); /* LEMBRAR:: Some todas no final!! O vector guarda todos os resultados separados!*/
        void set_adicao(Matriz *m,bool); 
        void function_add();

        void deleta_referencias_m_add();
};  

#endif