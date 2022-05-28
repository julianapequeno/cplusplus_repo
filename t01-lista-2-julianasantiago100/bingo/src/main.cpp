#include "BingoRand.hpp"
#include "Jogador.hpp"
#include "BOT_BINGO.hpp"
#include <iostream>
using namespace std;

int main(){
    string leitura;
    BingoRand bRand;
    BINGO * bot_bingo = new BINGO(); /*Variável usada para manuseio do BINGO */
    Jogador *j1; /*Referência alpha para a criação dos jogadores de forma dinâmica*/
    int N_jogadores,i = 0,leitura_int;
    unsigned long int leitura_seed;

    /*Recebo do usuário um seed e atribuo no objeto bRand*/
    getline(cin,leitura);   
    leitura_seed = stoul(leitura);
    bRand.setSeed(leitura_seed);

    /*Recebo o número de jogadores da rodada*/
    getline(cin,leitura);
    leitura_int = stoi(leitura);
    N_jogadores = leitura_int;

    /*Recebo o nome dos jogadores da rodada e crio cada jogador*/
    while(i < N_jogadores){
        getline(cin,leitura);
        j1 = new Jogador(leitura);
        bot_bingo->set_jogador(j1); /*Adiciono o jogador no jogo de BINGO*/
        i++;
    }  
    /*Final da entrada de dados*/

    /*Início da saída*/
    bot_bingo->imprime_jogadores();
    bool ganhou = false;
    bool acabou_numeros_sorteados = bot_bingo->get_quant_numeros_sorteados();
    int numero_sorteado;
   // std::vector<Jogador *> vencedores; /*Variável que armazenará os vencedores*/
    /*Sorteio*/
    while(!ganhou && !acabou_numeros_sorteados){
        numero_sorteado = bot_bingo->sorteio_bingo();
        std::cout << "Bola sorteada foi: " << numero_sorteado << std::endl;
        for(int i = 0; i < N_jogadores; i++){
            for(int n_cartela = 0; n_cartela < 24; n_cartela++){
                if(bot_bingo->retorna_jogador(i)->get_numero_da_cartela(n_cartela) == numero_sorteado){
                        //O jogador marcou!!
                        bot_bingo->retorna_jogador(i)->set_acertados(); //!Incrementa um acerto
                        if(bot_bingo->retorna_jogador(i)->get_acertados() == 24){
                            std::cout << "Jogador: ";
                            std::cout << bot_bingo->retorna_jogador(i)->get_nome();
                            std::cout << " Bingo!!" << std::endl;
                            bot_bingo->adiciona_vencedor(bot_bingo->retorna_jogador(i));
                            ganhou = true;
                        }else{
                            std::cout << "Jogador: ";
                            std::cout << bot_bingo->retorna_jogador(i)->get_nome();
                            std::cout << " marcou!" << std::endl;
                        }
                        break; //!Pois como cada cartela possui números diferentes, não vai haver mais um numero_sorteado. Isso economizará o custo computacional do algoriitmo :)
                }
            }
        }
        if(bot_bingo->get_quant_numeros_sorteados() == 99){
            acabou_numeros_sorteados = true;
        }
    }
    std::cout << "Foram sorteados " << bot_bingo->get_quant_numeros_sorteados() << " números:"<< std::endl;
    for(int i = 0; i < bot_bingo->get_quant_numeros_sorteados();i++){
        if(i+1 == bot_bingo->get_quant_numeros_sorteados()){
            std::cout << bot_bingo->get_numeros_sorteados(i) << std::endl;
        }else{
            std::cout << bot_bingo->get_numeros_sorteados(i) << ", ";
        }
    }
    if(ganhou){
        std::cout << "Vencedores" << std::endl;
        if(bot_bingo->get_quantos_vencedores() > 0){
            for(int a= 0; a < bot_bingo->get_quantos_vencedores(); a++){
                std::cout << bot_bingo->get_vencedor(a)->get_nome() << std::endl;
            }
        }else{
            std::cout << "Não houveram vencedores";
        }

    }
    /*Deleta os ponteiros e variáveis alocadas dinamicamente do programa*/
    bot_bingo->deleta_jogadores();
    delete bot_bingo;
    j1 = NULL;
    delete j1;
    /*Fim do programa*/
    return 0;
}