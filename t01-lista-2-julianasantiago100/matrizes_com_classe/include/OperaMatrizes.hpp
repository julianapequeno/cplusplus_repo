#ifndef OperaMatrizes_hpp
#define OperaMatrizes_hpp

#include "Matriz.hpp"
#include <tuple>
#include <vector>

class OperaMatrizes{
    private:
        std::tuple<std::string,std::pair<int,int>,std::vector<int>> m_matrizes; //<!tuple para armazenar o nome, o tamanho da linha e da coluna e os números da matriz
        std::string m_operacao; //<!string com o nome da operação a ser realizada
    public:
        /// DETROI COMMENT operações a serem construídas: add,moe,mod...
        auto* function_mue(int n,Matriz * m);
        std::string metodo_teste(Matriz *);
};

#endif