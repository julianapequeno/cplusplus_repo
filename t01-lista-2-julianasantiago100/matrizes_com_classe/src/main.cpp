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
    /*'Somador' de todas as operações realizadas */
    std::vector<Matriz *> vetor_matrizes;
    std::vector<string> somador; //<! variável criada para ter um controle visto de cima de todas as operações a serem realizadas no programa
    string minha_conta;
    //IDEIA: fazer um do_while e em cada início eu crio uma nova instância para matriz 

    /*Criação das variáveis locais que serão usadas para o controle e a manipulação do programa */
    Matriz * matrix; //<! uma referência a um objeto do tipo Matriz
    OperaMatrizes * operacao = new OperaMatrizes(); //<! uma instância (objeto) e sua referência do tipo OperaMatrizes
    string linha_leitura_matriz; //<! linha_leitura_matriz recebe a linha lida dinamicamente
    int linhas, colunas; //<! número de linhas e colunas da matriz
    std::vector<string> minha_linha; //<! vetor com a minha linha atual de forma segmentada
    string operacao_atual; //<! Para manter em aberto a operação sendo realizada entre duas matrizes

    int i_add = 0; //LEMBRAR, LEMBRAR -> NAS OUTRAS FUNÇÕES COLOQUE O FALTA_UM TAMBÉM!!
    bool acabou_dois=false,entre=false; //<! Variável de controle para o caso de ser a última matriz digitada. Ele precisa fazer os cálculos finais!
    getline(cin,linha_leitura_matriz); //getline inicial
    do{ 
        //std::cout << "Criei uma nova matriz!" << std::endl;
        /*Conferindo se o dado é uma matriz ou uma operaçãoS */
        string token;//
        std::vector<string> linha_dinamica;//
        istringstream tokenizer { linha_leitura_matriz };//
        while(tokenizer >> token){//
            linha_dinamica.push_back(token);//
        }//
        bool eh_operacao = is_in_function(linha_dinamica[0]);

                    /* std::string::iterator *it = std::find_if(linha_dinamica.begin(),linha_dinamica.end(), is_in_function());
                        if(it != linha_dinamica.end()){//
                        std::cout << "OPA! TEM!" << std::endl;//
                        }*/
        if(!eh_operacao){
            entre = false;
            matrix = new Matriz(); //<! crio uma nova instância (objeto) da classe Matriz
            /* Recebimento dos dados de informação geral (nome, linha e coluna) via terminal*/
            auto a = matriz_informacoes_iniciais(linha_leitura_matriz);
            matrix->set_nome(get<2>(a));
            matrix->set_linhas_e_colunas(get<0>(a),get<1>(a));
            linhas = get<0>(a);
            colunas = get<1>(a);
            minha_conta = minha_conta + get<2>(a) + " ";

            /* Recebimento dos números contidos na matriz tamanho: (linhas*colunas)*/
            int quantidade_espacos = colunas-1;
            int n,encontrei_numero;
            //string token;
            for(int i = 0; i < linhas;i++){
                getline(cin,linha_leitura_matriz);
                istringstream tokenizer2 { linha_leitura_matriz };

                /*Separação e atribuição dos números de cada linha */
                while(tokenizer2 >> token){
                    minha_linha.push_back(token);
                }
               // std::cout << "Adicionando na linha" << std::endl;
                //std::cout << "Esse é o tamanho das colunas: " << colunas << " e esse é o tamanho do vector minha linha: " << minha_linha.size() << std::endl;
                int meu_numero;
                /*Mudança de string para int e atribuição aos atributos do objeto da classe Matriz*/
                for(int y = 0; y < minha_linha.size(); y++){
                    //std::cout << i << " Entrando..." << std::endl;
                    meu_numero = stoi(minha_linha[y]);
                    matrix->set_vetor_matriz(i,meu_numero); //Segmentation Fault
                }
                //std::cout << "Coloquei no objeto!" << std::endl;
                minha_linha.clear(); //apago do meu vetor de linha dinâmico os dados da minha linha atual
                //std::cout << "Limpei para o próximo!!"<< std::endl;
            }
            vetor_matrizes.push_back(matrix); //<!Adiciono a referência da instância a classe Matriz ao vetor de referência das matrizes
        }else{
            entre = true; //Para entrar na leitura de operações
        }

        if(acabou_dois || entre){
            /*Recebimento de uma operação
            **  Isto é, Adição (add),
            **  Multiplicação matricial (dot),
            **  Multiplicação elemento à elemento (mul) ou
            **  Multiplicação por escalar (mue)
            */

            istringstream tokenizer { linha_leitura_matriz };
            while(tokenizer >> token){
                minha_linha.push_back(token);
            }
            if(minha_linha.size()==1){
                minha_conta = minha_conta + minha_linha[0] + " " ; //<! Adiciono mais uma operação a string
            }else{
                minha_conta = minha_conta + minha_linha[0] + " " + minha_linha[1]; //<! Adiciono na minha string da conta a operação mue (ela recebe um parâmetro númérico que também aparece na conta)
            }
            
            /*Início das operações*/
            if(minha_linha[0].compare("mue")==0){
                std::cout << "Aqui!!"<< std::endl;
                int valor_multiplicador = stoi(minha_linha[1]);
                operacao->function_mue(valor_multiplicador,matrix); /*Referencia a última matrix criada! Perfeito!*/
                operacao->set_resultado_conta(matrix); /* FEITO!! OKAY!! Multiplicar a matriz por valor_multiplicador -> Chamar a classe de OperaMatrizes*/
            } 
            if(minha_linha[0].compare("add")==0 || operacao_atual.compare("add")==0){
                if(i_add%2==0){ //2q + 0
                    //std::cout << "Meu vetor atual: " << matrix->get_nome() << std::endl;
                    operacao_atual = minha_linha[0];
                    operacao->set_adicao(matrix,true);
                    i_add++;
                    acabou_dois = true;
                }else if(i_add%2==1){ //2q + 1
                    acabou_dois = false;
                    std::cout << "Meu vetor atual: " << matrix->get_nome() << std::endl;
                    operacao->set_adicao(matrix,false);
                    operacao->function_add();
                    i_add++;
                   // i_add = 0; //*Reseta o quantificador de matrizes para a adição
                    operacao_atual = " "; //* Reseta a operação atual quando entra a segunda matriz
                }

                /*Preparar para receber outra matriz e seus dados*/
                /* Depois, enviar as duas para a operação de adição -> Chamar a classe de OperaMatrizes */
            } /* Deve existir uma espécie de somador para, para contabilizar essas contas e exibir um resultado final*/
            if(minha_linha[0].compare("dot")==0){   
                /*Preparar para receber outra matriz e seus dados*/
                /* Depois, enviar as duas para a operação de Multiplicação matricial -> Chamar a classe de OperaMatrizes */
            }
            if(minha_linha[0].compare("mul")==0){
                /*Preparar para receber outra matriz e seus dados*/
                /* Depois, enviar as duas para a operação de Multiplicação elemento à elemento -> Chamar a classe de OperaMatrizes */
            }
            minha_linha.clear();
        }
    }while(!getline(cin,linha_leitura_matriz).eof());
        std::cout << "Meu cálculo: " << minha_conta << std::endl;
        for(int i = 0; i < vetor_matrizes[vetor_matrizes.size()-1]->get_linhas_e_colunas().first; i++){
            for(int y = 0; y < vetor_matrizes[vetor_matrizes.size()-1]->get_linhas_e_colunas().second; y++){
                std::cout << vetor_matrizes[vetor_matrizes.size()-1]->get_valor_matriz(i,y) << std::endl;
            }
        }
    //getline(cin,linha_leitura_matriz);  depois do -> /*Conferindo se o dado é uma matriz ou uma operaçãoS */
    
        /*
        int found_espaco = 0,found_numero = 0;
        int n;
        for(int i = 0; i < linhas; i++){
            getline(cin, linha_leitura_matriz); //o número de espaços é sempre o número de colunas -1;
            for(int espaco = 0; espaco <= (colunas-1);espaco++){
                found_numero = linha_leitura_matriz.find("1234567890");
                linha_leitura_matriz[found_numero] = 'a';
                found_espaco = linha_leitura_matriz.find(" ");
                n = stoi(linha_leitura_matriz.substr(found_numero,found_espaco));
                //////AQUI ESTOU TENTANDO CAPTURAR OS DADOS DA MATRIZ
                std::cout << "Esse é o seu n: " << n << std::endl;
            }
        }
        getline(cin,leitura_dados);
        if(leitura_dados.substr(0,3).compare("mue")==0){
            //é um
        }
        */
    //IDEIA DE ESTRUTURA GERAL PARA O PROGRAMA do{}while(!getline(cin,leitura_dados).eof());

    /*Apagando qualquer possibilidade de vazamento de memória */
    // linha_dinamica.clear();
    //IDEIA_LEMBRAR! KILL TODOS OS Matriz* do vetor_matrizes!!! ELE POSSUI TODAS AS REFERENCIAS AOS OBJETOS CRIADOS, ENTÃO JÁ SERVE PARA EXCLUIR TODOS!
}
