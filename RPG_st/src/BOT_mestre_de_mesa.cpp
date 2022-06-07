#include "BOT_mestre_de_mesa.hpp"

std::minstd_rand BOT_mestre_de_mesa::rnd = std::minstd_rand();

BOT_mestre_de_mesa::BOT_mestre_de_mesa(){
    std::cout << "Olá eu me chamo " << this->m_nome  <<". Sou um mestre de mesa (e sim, um BOT, mas porque isso sempre tem que ser mencionado? :|). E estou aqui para jogar com você! Vamos lá??" << std::endl;
}

void BOT_mestre_de_mesa::setter_jogadores_and_BOT(Personagem p){
    int a = 0;
    this->m_personagens.push_back(&p); /*Coloca o jogador da partida dentro do vetor de jogadores, na primeira posição*/
    while(a < this->m_jogadores_na_partida-1){ //! Conta o jogador interativo também
        Personagem *p1 = new Personagem();
        /*Escolha do nome dos personagens*/ /*Podem ser quaisquer dos outros no arquivo, menos o que o usuário escolheu*/
    //AQUI ELE RECEBE name_jogador_BOT(p) e ATRIBUI OS NOMES A CADA REFERENCIA
        this->m_personagens.push_back(p1);
    }
}

std::vector<std::string> BOT_mestre_de_mesa::name_jogador_BOT(Personagem p){
    std::ifstream dados;
    dados.open("../include/personagens.txt",std::ios::out |std::ios::in);
    std::string leitura_linha;
    std::vector<std::string> nomes_personagem;
    while(getline(dados, leitura_linha)){
        if(leitura_linha.compare(p.get_nome())!=0){
            /*Não é o nome do meu jogador*/
            nomes_personagem.push_back(leitura_linha);
        }
    }
    dados.close();
    /*Embaralha a ordem*/
    std::shuffle(nomes_personagem.begin(),
                 nomes_personagem.end(),
                 std::default_random_engine(seed));

    for(int i = nomes_personagem.size();i >= this->m_jogadores_na_partida;i--){ //OU seja A QUANTIDADE DE JOGADORES NA PARTIDA DEVE SER MENOR QUE O BANCO DE PERSONAGENS!!
        nomes_personagem.pop_back();
    }
    return nomes_personagem;
}