#include <vector>
#include "Pessoa.hpp"
#include "Cadastro.hpp"

#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RED "\u001b[31m"
#define ANSI_COLOR_BLUE "\u001b[34m"
#define ANSI_COLOR_CYANO "\u001b[36m"
#define ANSI_COLOR_WHITE "\u001b[37m"
#define ANSI_COLOR_GREEN "\u001b[32m"
#define RESET "\u001b[0m"
#define BACKGROUND_WHITE "\u001b[47;1m"

void inicializar_cadastro_unico(Cadastro *cadastro_unico){
    std::ifstream arquivo("../data/CadastroUnico.txt");
    std::string linha;
    Pessoa *p;
    std::pair<std::string, std::string> nome_e_cpf;
    int i  = 0;
    while(std::getline(arquivo,linha)){
        if(i%3==0){ // 3q
            nome_e_cpf.first = linha;
        }else if(i%3==1){ //3*q+1
            nome_e_cpf.second = linha;
            nome_e_cpf.second = linha.substr(0,linha.size()-1); //para apagar o \n do final
        }else if(i%3==2){ //3*q +2
            p = new Pessoa(nome_e_cpf.first,nome_e_cpf.second);
            p->setEndereco(linha);
            cadastro_unico->adicionaPessoa(p);
        }else{
            break;
        }
        i++;
    }
    arquivo.close();
    p = new Pessoa("",""); //apenas para apagar a variável p, se eu deletasse sem isso, a variável iria apagar a última pessoa adicionada no vector. Pois essa variável é um ponteiro.
    delete p;
}   

int main(){
    //std::cout << "Bem vindo ao programa de cadastros!! Cadastre abaixe os CPF´s desejados!" << std::endl;
    Cadastro *cadastro_unico = new Cadastro("Cadastro Único");
    inicializar_cadastro_unico(cadastro_unico); //iniciliza o cadastro e adiciona as informações na classe

    Cadastro *SUS = new Cadastro("Sistema Único de Saúde");

    Cadastro *CE = new Cadastro("Cadastro Estadual");

    Cadastro *CM = new Cadastro("Cadastro Municipal");

    //Recebe dados do terminal
    std::string cpfs;
    std::vector<std::string> cpfs_cadastro;
    while(std::getline(std::cin,cpfs)){
        if(cpfs.compare("")==0){
            break;
        }else{
           // std::cout << "OK, inserindo linha no banco de dados..." << std::endl;
            cpfs_cadastro.push_back(cpfs);
        }
    }
   // std::cout << "Acabou? Tá bom! Aqui vem os resultados!";
    //std::cout << "Loading..." << std::endl;

    //Separação dos dados em cada cadastro
    std::string cadastro;
    std::size_t found;
    std::string cpf;

    Pessoa *p1;
    std::vector<Pessoa *> vector_SUS;
    std::vector<Pessoa *> vector_CE;
    std::vector<Pessoa *> vector_CM;
    Pessoa *defaultPessoa = new Pessoa("Sistema único de Saúde","XXX.XXX.XXX-XX");
    vector_SUS.push_back(defaultPessoa);
    defaultPessoa = new Pessoa("Cadastro Estadual","XXX.XXX.XXX-XX");
    vector_CE.push_back(defaultPessoa);
    defaultPessoa = new Pessoa("Cadastro Municipal","XXX.XXX.XXX-XX");
    vector_CM.push_back(defaultPessoa);

    for(long unsigned int i = 0; i < cpfs_cadastro.size();i++){
        found = cpfs_cadastro[i].find(" ");
        if(found != std::string::npos){
            cadastro = cpfs_cadastro[i].substr(found+1);
            if(cadastro[0]=='C' && cadastro.size()==3){
                cadastro.erase(cadastro.size()-1);
            }
            cpf = cpfs_cadastro[i].substr(0,14); //exatamente o CPF: XXX.XXX.XXX
            p1 = cadastro_unico->encontraPessoa(cpf); //1- Eu busco o NOME da pessoa no cadastro único, isso por meio do seu cpf
            if(p1!= nullptr){
                if(cadastro.compare("CM")==0){ //é o cadastro municipal
                    CM->adicionaPessoa(p1);
                  //std::cout <<ANSI_COLOR_GREEN << "Adicionando pessoa!!😄" << RESET << std::endl;
                    vector_CM.push_back(p1);
                }else if(cadastro.compare("SUS")==0){//é o cadastro no Sistema Único de Saúde
                    SUS->adicionaPessoa(p1);
                  //  std::cout << ANSI_COLOR_GREEN << "Adicionando pessoa!!😄" << RESET << std::endl;
                    vector_SUS.push_back(p1);
                }else if(cadastro.compare("CE")==0){
                    CE->adicionaPessoa(p1);
                  //  std::cout << ANSI_COLOR_GREEN << "Adicionando pessoa!!😄" << RESET << std::endl;
                    vector_CE.push_back(p1);
                }else{
                    std::cout << ANSI_COLOR_RED << "Esse cadastro não existe em nossos sistemas..." << RESET << std::endl;
                }
            }else{
                std::cout << BACKGROUND_WHITE << ANSI_COLOR_MAGENTA << "Ninguém cadastrado!" << RESET << std::endl;
            }
            
        }
    }
    
    //Mostra na tela o resultado
    if(vector_SUS.size()>1){
        for(long unsigned int  i = 0; i < vector_SUS.size(); i++){
            std::cout << vector_SUS[i]->getNome() << std::endl;
        }
        std::cout << std::endl;
    }
    if(vector_CE.size()>1){
        for(long unsigned int i  = 0; i < vector_CE.size(); i++){
            std::cout << vector_CE[i]->getNome() << std::endl;
        }
        std::cout << std::endl;
    }
    if(vector_CM.size()>1){
        for(long unsigned int i = 0; i < vector_CM.size(); i++){
            std::cout << vector_CM[i]->getNome() << std::endl;
        }
        std::cout << std::endl;
    }

    
    //limpo os meus members vetores-variáveis de cadastro, e depois  deleto todos os objetos através de apenas uma gama de referências, a que tem todas, no cadastro_unico 
    //depois, eu deleto as variáveis de acesso, os ponteiros da classe Cadastro;]
    CM->limpaCadastro();
    CE->limpaCadastro();
    SUS->limpaCadastro();
    delete CM;
    delete CE;
    delete SUS;
    //primeiro ele limpa os vetores e depois apaga as referencias CM,CE e SUS
    //depois ele apaga todas as instancias TODAS DE UMA VEZ pelo cadastro_unico. 
    //por último, apaga a referencia caadastro_unico
    cadastro_unico->apaga_cadastrados();
    delete cadastro_unico;
    return EXIT_SUCCESS;
}   