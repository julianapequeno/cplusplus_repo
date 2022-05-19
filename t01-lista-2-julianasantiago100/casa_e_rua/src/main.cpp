

#include "Casa.hpp"
#include "rua.hpp"

/*
TODO: implementar o main
*/
using namespace std;

int main(){
    string nome_rua;
    string CEP;
    std::vector<std::pair<std::pair<string,bool>,std::pair<double,double>>> casa_informacoes;
    //casa_informacoes = [{X,Y},{{string,bool},{double,double}} , , ,];
    string entrada_dinamica;
    //bool agora_casas = false;
    int i = 0;
    Casa *c;
    rua::lado_rua l;
    rua *Rua_dados;
    string entrada_lado,areas,ocupacao;

    getline(cin,nome_rua);
    getline(cin,CEP);
    Rua_dados = new rua(nome_rua,CEP);
    //std::cout << "Okay! Nome da rua e CEP cadastrados! Insira os dados das casas..." << std::endl;

    //getline(cin,entrada_lado) && getline(cin,areas) && getline(cin,ocupacao)

    while(getline(cin,entrada_dinamica)){
        if(entrada_dinamica.size() > 0){
            if(i%3==0){ //PRIMEIRA LINHA -> LADO DA RUA EM QUE A CASA ESTÁ
                entrada_lado = entrada_dinamica;
                if(entrada_lado.compare("A")==0){
                    l = rua::lado_rua::LADO_A;
                }else if(entrada_lado.compare("B")==0){
                    l = rua::lado_rua::LADO_B;
                }
            }else if(i%3==1){
                areas = entrada_dinamica;
                //segunda LINHA -> AREA OCUPADA e AREA TOTAL
                std::size_t found = areas.find(" ");
                if(found!= std::string::npos){
                    c = new Casa(stod(areas.substr(0,areas.size()-(found))), stod(areas.substr(found+1,areas.size()-(found+1))));
                }

            }else if(i%3==2){
                ocupacao = entrada_dinamica;
                //terceira linha -> OCUPAÇÃO DA CASA
                if(ocupacao.substr(0,10).compare("desocupada")==0){
                  //  std::cout << "Setando desocupação" << std::endl;
                    c->setOcupada(false);
                }else if(ocupacao.substr(0,7).compare("ocupada")==0){
                    c->setOcupada(true);
                }
                Rua_dados->adiciona_casa(c,l); //ADICIONA A CASA NA RUA E SEGUE EM FRENTE
            }   
            i++;
        }else{
            break;
        }
    }

    //Imprimindo o endereço e a área de todas as casa desocupadas
    std::cout << "Casas Desocupadas" << std::endl;
    std::vector<Casa*> vetor_desocupadas = Rua_dados->get_desocupadas();
   // std::cout << "Tamanho do vetor_desocupadas: " << vetor_desocupadas.size() << std::endl;
    if(vetor_desocupadas.size() == 0){
        std::cout << "<nenhuma>" << std::endl;
    }else{ // tem casas desocupadas
        for(long unsigned int i = 0; i < vetor_desocupadas.size(); i++){
            //rua e endereço de cada casa
          //  std::cout.fixed;
            std::cout.precision(2);
           std::cout << Rua_dados->endereco(vetor_desocupadas[i]->getNumero()) << std::endl;
            //vizinhos
            std::cout << "Vizinhos" << std::endl;
            std::tuple<Casa*, Casa*,Casa*> vizinhos_rua = Rua_dados->vizinhos(vetor_desocupadas[i]->getNumero());
            std::string endereco_dinamico;
            if(std::get<2>(vizinhos_rua) != nullptr){
               // std::cout << "NÚMERO DA CASA DA FRENTE: " << get<2>(vizinhos_rua)->getNumero() << std::endl;
                endereco_dinamico = Rua_dados->endereco(get<2>(vizinhos_rua)->getNumero());
                if(get<2>(vizinhos_rua)->isOcupada() == false){
                  endereco_dinamico = endereco_dinamico + " (desocupada)";
                }else{
                  endereco_dinamico = endereco_dinamico + " (ocupada)";
                }
                std::cout << "Frente: " << endereco_dinamico << std::endl;
            }else{
                std::cout << "Frente: <nenhum>" << std::endl;
            }
            if(std::get<0>(vizinhos_rua) != nullptr){
                endereco_dinamico = Rua_dados->endereco(std::get<0>(vizinhos_rua)->getNumero());
                if(get<0>(vizinhos_rua)->isOcupada() == false){
                  endereco_dinamico = endereco_dinamico + " (desocupada)";
                }else{
                 endereco_dinamico = endereco_dinamico + " (ocupada)";
                }
                std::cout << "Esquerda: " << endereco_dinamico << std::endl;
            }else{
                std::cout << "Esquerda: <nenhum>" << std::endl;
            }
            if(std::get<1>(vizinhos_rua) != nullptr){
              endereco_dinamico = Rua_dados->endereco(std::get<1>(vizinhos_rua)->getNumero());
                if(get<1>(vizinhos_rua)->isOcupada() == false){
                  endereco_dinamico = endereco_dinamico + " (desocupada)";
                }else{
                  endereco_dinamico = endereco_dinamico + " (ocupada)";
                }
                std::cout << "Direita: " << endereco_dinamico << std::endl;
            }else{
                std::cout << "Direita: <nenhum>" << std::endl;
            }
        }
    }

/*
    while(std::getline(cin,entrada_dinamica)){
        
        if(!agora_casas){
            if(entrada_dinamica[0]!= 'A' || entrada_dinamica[0]!= 'B'){ //CASO DE TESTE PARA QUEBRAR O CÓDIGO: E se for "Av..." ??
                //ainda é a rua e o CEP
                if(entrada_dinamica[0] >= 65 && entrada_dinamica[0] <= 122){
                    //NOME DA RUA
                    nome_rua = entrada_dinamica;
                }else{
                    //CEP
                    CEP = entrada_dinamica;
                }
            }else{ //se for igual a A ou a B, é porque começou o casas_informações
                Rua_dados = new rua(nome_rua,CEP);
                agora_casas = true;
            }
        }else{
            if(i%3==0){ //PRIMEIRA LINHA -> LADO DA RUA EM QUE A CASA ESTÁ
                if(entrada_dinamica.compare("A")==0){
                    l = rua::lado_rua::LADO_A;
                }else if(entrada_dinamica.compare("B")==0){
                    l = rua::lado_rua::LADO_B;
                }
            }else if(i%3==1){
                //segunda LINHA -> AREA OCUPADA e AREA TOTAL
                std::size_t found = entrada_dinamica.find(" ");
                if(found!= std::string::npos){
                    c = new Casa(stod(entrada_dinamica.substr(0,entrada_dinamica.size()-(found))), stod(entrada_dinamica.substr(found+1,entrada_dinamica.size()-(found+1))));
                }

            }else if(i%3==2){
                //terceira linha -> OCUPAÇÃO DA CASA
                if(entrada_dinamica.compare("desocupada")){
                    c->setOcupada(false);
                }else if(entrada_dinamica.compare("ocupada")){
                    c->setOcupada(true);
                }
                Rua_dados->adiciona_casa(c,l); //ADICIONA A CASA NA RUA E SEGUE EM FRENTE
            }   
        }
    }
    */
    return EXIT_SUCCESS;
}