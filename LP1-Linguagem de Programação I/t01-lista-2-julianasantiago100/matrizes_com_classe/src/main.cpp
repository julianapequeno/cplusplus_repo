#include <iostream>  
#include <sstream>
#include <algorithm>

#include "Matriz.hpp"
#include "OperaMatrizes.hpp"

using namespace std;

/**
 * Recebe a string que contém o nome, a linha e a coluna da matriz
 * Esse método atribui cada informação ao seu tipo e localização
 * @param leitura_dados, é a string de leitura do terminal que contém todas as informações juntas, por exemplo: "A 2 2"
 * @return um tuple contendo as informações (nome, linha e coluna) de forma separada e organizada
 */
std::tuple<int, int, string> matriz_informacoes_iniciais(string leitura_dados){
    std::string tamanho_linhas, tamanho_colunas, tamanho_matriz;
    int L, C;
    int found_primeiro_espaco, found_tamanho_size;
    //mexendo nas strings
    found_primeiro_espaco = leitura_dados.find(" ");
    tamanho_matriz = leitura_dados.substr(found_primeiro_espaco+1,leitura_dados.size()-1);
    leitura_dados = leitura_dados.substr(0,found_primeiro_espaco);
    //setar o tamanho de lilhas e colunas
    found_tamanho_size = tamanho_matriz.find(" ");
    tamanho_linhas = tamanho_matriz.substr(0,found_tamanho_size);
    tamanho_colunas = tamanho_matriz.substr(found_tamanho_size+1, tamanho_matriz.size()-(found_tamanho_size+1));
    //transforma para int
    L = stoi(tamanho_linhas);
    C = stoi(tamanho_colunas); 
    std::tuple<int, int, string> retorno;
    get<0>(retorno) = L;
    get<1>(retorno) = C;
    get<2>(retorno) = leitura_dados;
    return retorno;
}

/**
 * @brief Função feita para averiguar se o programa está recebendo uma nova matriz a 
 * ser inserida, ou uma funcionalidade a ser aplicada.
 * @param linha_leitura_matriz, a linha lida atualmente pelo programa
 * @return true, é uma linha de operação.
 * @return false, é uma linha de início de inserção de matriz
 */
bool is_in_function(string linha_leitura_matriz){
    if(linha_leitura_matriz.substr(0,3).compare("mue")==0){
        return true;
    }else if(linha_leitura_matriz.substr(0,3).compare("mul")==0){
        return true;
    }else if(linha_leitura_matriz.substr(0,3).compare("add")==0){
        return true;
    }else if(linha_leitura_matriz.substr(0,3).compare("dot")==0){
        return true;
    }else{
        return false;
    }
}

int main ( void ){
    std::vector<Matriz *> vetor_matrizes; /*'Somador' de todas as operações realizadas, possuo o resultado final de cada etapa, dentro de cada uma das matrizes */
    string minha_conta; //<! Minha string que captura a conta que está sendo realizada final

    /*Criação das variáveis locais que serão usadas para o controle e a manipulação do programa */
    Matriz * matrix; //<! uma referência a um objeto do tipo Matriz
    OperaMatrizes * operacao = new OperaMatrizes(); //<! uma instância (objeto) e sua referência do tipo OperaMatrizes
    string linha_leitura_matriz; //<! linha_leitura_matriz recebe a linha lida dinamicamente
    int linhas; //<! número de linhas e colunas da matriz
    std::vector<string> minha_linha, minha_operacao; //<! vetores com a minha linha atual de forma segmentada
    string operacao_atual; //<! Para manter em aberto a operação sendo realizada entre duas matrizes
    
    int i_add = 0; 
    bool acabou_dois=false,entre=false,deu_certo=true,resultado_apareceu=false; /*!< acabou_dois é uma variável de controle para o caso de ser a última matriz digitada. Ele precisa fazer os cálculos finais!*/
    
    getline(cin,linha_leitura_matriz); //!getline inicial
    do{ 
        /*Conferindo se o dado é uma matriz ou uma operação */
        //! Leitura e separação dos dados da linha linha_leitura_matriz
        string token;
        std::vector<string> linha_dinamica;
        istringstream tokenizer { linha_leitura_matriz };
        while(tokenizer >> token){
            linha_dinamica.push_back(token);
        }
        bool eh_operacao = is_in_function(linha_dinamica[0]); //! Verifica se é uma matriz ou uma operação

        if(!eh_operacao){
            entre = false;
            matrix = new Matriz(); //<! crio uma nova instância (objeto) da classe Matriz
            /* Recebimento dos dados de informação geral (nome, linha e coluna) via terminal*/
            auto a = matriz_informacoes_iniciais(linha_leitura_matriz);
            matrix->set_nome(get<2>(a));
            matrix->set_linhas_e_colunas(get<0>(a),get<1>(a));
            linhas = get<0>(a); 
            minha_conta = minha_conta + get<2>(a) + " ";

            /* Recebimento dos números contidos na matriz tamanho: (linhas*colunas)*/
            for(int i = 0; i < linhas;i++){
                getline(cin,linha_leitura_matriz);
                istringstream tokenizer2 { linha_leitura_matriz };

                /*Separação e atribuição dos números de cada linha */
                while(tokenizer2 >> token){
                    minha_linha.push_back(token);
                }
                int meu_numero;
                /*Mudança de string para int e atribuição aos atributos do objeto da classe Matriz*/
                for(long unsigned int y = 0; y < minha_linha.size(); y++){
                    meu_numero = stoi(minha_linha[y]);
                    matrix->set_vetor_matriz(i,meu_numero); 
                }
                minha_linha.clear(); //!Apago do meu vetor de linha dinâmico os dados da minha linha atual
            }
            vetor_matrizes.push_back(matrix); //!Adiciono a referência da instância a classe Matriz ao vetor de referência das matrizes
        }else{
            entre = true; //!Para entrar na leitura de operações
        }

        if(acabou_dois || entre){ //<! Se ainda estiver dentro de um cálculo ou se for uma linha de leitura de uma nova operação
            /*Recebimento de uma operação
            **  Isto é, Adição (add),
            **  Multiplicação matricial (dot),
            **  Multiplicação elemento à elemento (mul) ou
            **  Multiplicação por escalar (mue).
            */
            if(!acabou_dois){ //! Se não estiver dentro de um cálculo, leia a nova operação
                string token_operacao;
                istringstream tokenizer_operacoes { linha_leitura_matriz };
                while(tokenizer_operacoes >> token_operacao){
                    minha_operacao.push_back(token_operacao);
                }
                if(minha_operacao.size()==1){
                    minha_conta = minha_conta + minha_operacao[0] + " " ; //! Adiciono mais uma operação a string
                }else{
                    minha_conta = minha_conta + minha_operacao[0] + " " + minha_operacao[1] + " "; //! Adiciono na minha string da conta a operação mue (ela recebe um parâmetro númérico que também aparece na conta)
                }
            }
            
            /*Início das operações*/
            if(minha_operacao[0].compare("mue")==0){
                int valor_multiplicador = stoi(minha_operacao[1]);
                operacao->function_mue(valor_multiplicador,matrix); /*Referencia a última matrix criada! Perfeito! A última matrix inserida sempre conterá o resultado final*/
            } 
            if(minha_operacao[0].compare("add")==0 || operacao_atual.compare("add")==0){ /*Se for igual a add ou se estiver ocorrendo um cálculo*/
                if(i_add%2==0){ //2q + 0
                    operacao_atual = minha_operacao[0];
                    operacao->set_par_matriz(matrix,true);
                    i_add++;
                    acabou_dois = true;
                }else if(i_add%2==1){ //2q + 1
                    acabou_dois = false;
                    entre = false;
                    operacao->set_par_matriz(matrix,false);
                    operacao->function_add();
                    i_add++;
                    operacao_atual = " "; //* Reseta a operação atual quando entra a segunda matriz, aqui as contas são de dois em dois
                }
            } 
            if(minha_operacao[0].compare("dot")==0 || operacao_atual.compare("dot")==0){   
                if(i_add%2==0){
                    operacao_atual = minha_operacao[0];
                    operacao->set_par_matriz(matrix,true);
                    i_add++;
                    acabou_dois = true;
                }else if(i_add%2==1){
                    acabou_dois = false;
                    entre = false;
                    operacao->set_par_matriz(matrix,false);
                    deu_certo = operacao->function_dot();
                    if(!deu_certo){
                        std::cout <<"Resultado " << minha_conta << "não pôde ser calculado, resultado até aqui:" <<std::endl;
                        resultado_apareceu = true;
                        vetor_matrizes.pop_back(); //!Anula a última matrix do meu resultado. A anterior é o meu último resultado válido.
                        break; //!Saia do meu ambiente de cálculo matemático
                    }
                    i_add++;
                    operacao_atual = " "; //* Reseta a operação atual quando entra a segunda matriz
                }
            }
            if(minha_operacao[0].compare("mul")==0 || operacao_atual.compare("mul")==0){
                if(i_add%2==0){
                    operacao_atual = minha_operacao[0];
                    operacao->set_par_matriz(matrix,true);
                    i_add++;
                    acabou_dois = true;
                }else if(i_add%2==1){
                    acabou_dois = false;
                    entre = false;
                    operacao->set_par_matriz(matrix,false);
                    deu_certo = operacao->function_mul();
                    if(!deu_certo){
                        std::cout <<"Resultado " << minha_conta << "não pôde ser calculado, resultado até aqui:" ;
                        resultado_apareceu = true;
                        break;//!Saia do meu ambiente de cálculo matemático
                    }
                    i_add++;
                    operacao_atual = " ";
                }
            }
            minha_operacao.clear();
        }
    }while(!getline(cin,linha_leitura_matriz).eof());

        /*Resultados finais. Print da minha_conta e da matriz resultante! (presente na última matrix entrada pelo user) */
        minha_conta.erase(minha_conta.size()-1);
        if(!resultado_apareceu){
            std::cout << "Resultado " << minha_conta << std::endl;
        }
         for(int i = 0; i < vetor_matrizes[vetor_matrizes.size()-1]->get_linhas_e_colunas().first; i++){
                for(int y = 0; y < vetor_matrizes[vetor_matrizes.size()-1]->get_linhas_e_colunas().second; y++){
                    if(y+1==vetor_matrizes[vetor_matrizes.size()-1]->get_linhas_e_colunas().second){
                        std::cout << vetor_matrizes[vetor_matrizes.size()-1]->get_valor_matriz(i,y);
                    }else{
                        std::cout << vetor_matrizes[vetor_matrizes.size()-1]->get_valor_matriz(i,y)<< " ";
                    }
                }
                std::cout << std::endl;
            }
        
        /*Sobre o resultado estar na última matrix: PERCEBA QUE O RESULTADO FINAL DE CADA PASSO ESTÁ DENTRO DA ÚLTIMA MATRIZ USADA
        * NAQUELE PASSO. ASSIM, PROGRESSIVAMENTE...O RESULTADO FINAL ESTÁ DENTRO DA ÚLTIMA
        * MATRIZ INSERIDA. ASSIM, SE TORNA DESNECESSÁRIO O MÉTODO DE 'SOMAR_RESULTADO' NA CLAS-
        * SE OPERAMATRIZES.
        */

        /*Apagando qualquer possibilidade de vazamento de memória */
        for(auto a: vetor_matrizes){
            delete a;
        }
        matrix = NULL;
        operacao = NULL;
        delete matrix;
        delete operacao;
        
        /*Fim do programa! */
        return 0;
}
