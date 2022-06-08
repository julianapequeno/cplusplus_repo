#include "../include/BOT_mestre_de_mesa.hpp"

std::minstd_rand BOT_mestre_de_mesa::rnd = std::minstd_rand();

BOT_mestre_de_mesa::BOT_mestre_de_mesa(){
    std::cout << "Olá eu me chamo " << this->m_nome  <<". Sou um mestre de mesa (e sim, um BOT, mas porque isso sempre tem que ser mencionado? :|). E estou aqui para jogar com você! Vamos lá??" << std::endl;
}

void BOT_mestre_de_mesa::setter_jogadores_and_BOT(Personagem *p){
    if(this->m_jogadores_na_partida > 13){ /*Considera o jogador escolh*/
        std::cout << "Existem muitos jogadores. Lembre-se que atualmente só pode-se jogar no máximo 13, contando com o usuário" << std::endl;
    }else{
        int a = 0;
        std::vector<std::string> nomes_temp;
        this->m_personagens.push_back(p); /*Coloca o jogador da partida dentro do vetor de jogadores, na primeira posição*/
        nomes_temp = this->name_jogador_BOT(p);
        std::cout << "Escalando jogadores para esta partida..." << std::endl;
        while(a < this->m_jogadores_na_partida-1){ //! Conta o jogador interativo também
            Personagem *p1 = new Personagem();
            /*Escolha do nome dos personagens*/ /*Podem ser quaisquer dos outros no arquivo, menos o que o usuário escolheu*/
            p1->set_nome(nomes_temp.at(a)); /*Atribui os nomes dos BOTs que vão jogar junto ao jogador*/
            this->m_personagens.push_back(p1);
            a++;
        }
        std::cout << "--------------------------------------------" << std::endl;
        std::cout << "Jogadores escalados! Bom jogo :)" << std::endl;
    }
}

std::vector<std::string> BOT_mestre_de_mesa::name_jogador_BOT(Personagem *p){
    std::ifstream dados;
    dados.open("../include/personagens.txt",std::ios::out |std::ios::in);
    std::string leitura_linha;
    std::vector<std::string> nomes_personagem;
    while(getline(dados, leitura_linha)){
        if(leitura_linha.compare(p->get_nome())!=0 && leitura_linha.compare("Crie o seu próprio personagem...")!=0){
            /*Não é o nome do meu jogador*/
            nomes_personagem.push_back(leitura_linha);
        }
    }
    if(nomes_personagem.size()==12){
        /*Significa o jogador escolheu escrever o seu próprio nome*/
    }
    dados.close();
    /*Embaralha a ordem*/
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(nomes_personagem.begin(),
                 nomes_personagem.end(),
                 std::default_random_engine(seed));

    for(int i = nomes_personagem.size()-1;i >= this->m_jogadores_na_partida;i--){ //OU seja A QUANTIDADE DE JOGADORES NA PARTIDA DEVE SER MENOR QUE O BANCO DE PERSONAGENS!!
        nomes_personagem.pop_back();
    }
    return nomes_personagem;
}

void BOT_mestre_de_mesa::delete_jogadores(){
    for(auto a : this->m_personagens)
        delete a;
}

void BOT_mestre_de_mesa::escolha_personagem_jogador(Personagem *p){
    std::ifstream dados;
    dados.open("../include/personagens.txt",std::ios::out |std::ios::in);
    std::string leitura_linha;
    std::vector<std::string> nomes_personagem;
    int i = 1;
    while(getline(dados, leitura_linha)){
        std::cout << i << " | " << leitura_linha << std::endl;
        i++;
    }
    dados.close();

    /*Caso o usuário escolha criar o seu próprio personagem*/
    //! Ideia-> Redirecionar para outra classe que cuida da ficha dos personagens

    int escolha = 0;
    std::cout << "Digite o número correspondente a sua escolha: ";
    std::cin >> escolha;
    if(escolha == 13){ 
        std::string personagem_criado;
        std::cout << "Certo! Preparando o ambiente para que você crie o seu próprio personagem!" << std::endl;
        std::cout << "------------------------------------------------------------------------------" << std::endl;
        std::cout << "Vamos lá! Qual será nome do seu personagem? ";
        std::cin >> personagem_criado;
        p->set_nome(personagem_criado);
    }
}

void BOT_mestre_de_mesa::set_quant_jogadores(int i){
    this->m_jogadores_na_partida = i;
}

int BOT_mestre_de_mesa::quant_jogadores(){
    return this->m_personagens.size();
}

Personagem* BOT_mestre_de_mesa::get_jogador(int i){
    return this->m_personagens.at(i);
}