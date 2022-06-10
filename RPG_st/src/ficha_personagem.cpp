#include "../include/ficha_personagem.hpp"
#include "../include/ansicolors.hpp"
#include <cstring>
#include <string>

void Ficha_Personagem::new_personagem_set_atributos(){
    //std::cout << "Atributos do personagem: " << std::endl;
    int x = 0;
    std::ifstream dados;
    dados.open("../data/atributos_personagem.txt");
    std::string leitura_linha;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed);
    while(getline(dados, leitura_linha)){
        x = rand()%100; /*Aqui a pontuação do personagem em determinada habilidade vai até 100*/
        //std::cout << leitura_linha << ": " << x << std::endl;
        m_atributos_especializacoes.insert(std::map<std::string,int>::value_type("Agilidade",x));   
    }
}
Ficha_Personagem::Ficha_Personagem(std::string nome){
    this->m_nome = nome;
    std::cout << "Inicializando a ficha do personagem, aguarde um momento..." << std::endl;
    
    /*Inicializando localização da(o) personagem*/
    std::ifstream dados,dado2;
    dados.open("../data/fichas_personagens/localidades.txt",std::ios::out |std::ios::in);
    dado2.open("../include/personagens.txt",std::ios::out |std::ios::in);
    std::string leitura_linha,personagem;
    while(getline(dados,leitura_linha) && getline(dado2,personagem)){
        personagem = personagem.substr(0,nome.size());
        if(personagem.compare(nome)==0){
            auto found = leitura_linha.find_first_of('-');
            if(found != std::string::npos){
                leitura_linha = leitura_linha.substr(found+2,leitura_linha.size()-1);
                this->m_povo = leitura_linha;
                break;
            }
        }
    }
    dados.close();
    dado2.close();

    /*Recebendo altura e peso dos personagens*/
    std::ifstream abrir_arquivo,personagens_nomes;
    abrir_arquivo.open("../data/fichas_personagens/alturapeso.txt",std::ios::out |std::ios::in);
    personagens_nomes.open("../data/atributos_personagens.txt",std::ios::out |std::ios::in);
    std::string leitura_alturapeso,leitura_personagens;
    while(getline(abrir_arquivo,leitura_alturapeso) && getline(personagens_nomes,leitura_personagens)){
        if(leitura_personagens.compare(nome)==0){
            auto found = leitura_personagens.find_first_of('-');
            if(found != std::string::npos){
                leitura_personagens = leitura_personagens.substr(found+2,leitura_personagens.size()-1);
                /*Agora a string apenas possui a altura e o peso*/
                auto found_espaco = leitura_personagens.find_first_of(" ");
                double altura = stod(leitura_personagens.substr(found+2,found_espaco-1));
                double peso = stod(leitura_personagens.substr(found_espaco+1,leitura_personagens.size()-1));
                this->m_altura_e_peso.first = altura;
                this->m_altura_e_peso.second = peso;
                break;
            }
        }
    }
    abrir_arquivo.close();
    personagens_nomes.close();

    /*Setando habilidades*/
    this->new_personagem_set_atributos();
    std::cout << "Ficha inicilizada com sucesso!" << std::endl;
}

void Ficha_Personagem::imprimir_minha_ficha(){
    std::cout << "                    ▇ M I N H A  F I C H A ▇"<< std::endl;
    std::cout << "                #Nome: "<< ANSI_COLOR_MAGENTA << this->m_nome << ANSI_COLOR_RESET <<std::endl;
    std::cout << "                #Idade: "<< ANSI_COLOR_MAGENTA << this->m_nome << ANSI_COLOR_RESET <<std::endl;
    std::cout << "                #Povo: "<< ANSI_COLOR_MAGENTA << this->m_povo << ANSI_COLOR_RESET <<std::endl;
    std::cout << "                #Altura: "<< ANSI_COLOR_MAGENTA << this->m_altura_e_peso.first << ANSI_COLOR_RESET <<std::endl;
    std::cout << "                #Peso: "<< ANSI_COLOR_MAGENTA << this->m_altura_e_peso.second << ANSI_COLOR_RESET <<std::endl;    
    std::cout << "___________________________________________________________________\n" << std::endl;
    std::cout << "____________________▇ A T R I B U T O S ▇________________________"<< std::endl;
    std::cout << "                #Agilidade:"<< ANSI_COLOR_MAGENTA << this->m_atributos_especializacoes["Agilidade"] << ANSI_COLOR_RESET <<std::endl;    

}