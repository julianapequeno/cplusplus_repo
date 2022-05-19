#include "rua.hpp"

/*
TODO: implementação dos métodos
*/
using namespace std;

rua::rua(std::string nome, std::string cep){
    this->m_nome = nome;
    this->m_CEP = cep;
}

void rua::adiciona_casa(Casa *c, lado_rua l){
   // int numero_casa = c->getNumero();
    int tamanho_vetor_lado;
    if(l == lado_rua::LADO_A){
            //setando o número da casa
        tamanho_vetor_lado = this->m_lado_a.size();
        tamanho_vetor_lado = tamanho_vetor_lado * 2;
        c->setNumero(tamanho_vetor_lado);
      //  std::cout << "NÚMERO DESTA CASA: " << tamanho_vetor_lado << std::endl;
        this->m_lado_a.push_back(c);
    }else if(l == lado_rua::LADO_B){

        tamanho_vetor_lado = this->m_lado_b.size();
        tamanho_vetor_lado = tamanho_vetor_lado * 2 + 1;
        c->setNumero(tamanho_vetor_lado);
      //  std::cout << "NÚMERO DESTA CASA: " << tamanho_vetor_lado << std::endl;
        this->m_lado_b.push_back(c);
    }
}

std::tuple<Casa*,Casa*,Casa*> rua::vizinhos(Casa *c){
    std::tuple<Casa*,Casa*,Casa*> tupla_vizinhos; //E,D e F
    int indice = -1;
    bool esta_no_lado_b = false;
    for(long unsigned int a = 0; a < this->m_lado_a.size(); a++){
        if(this->m_lado_a[a]->getNumero() == c->getNumero()){
            indice = a;
        }
    }
    if(indice != -1){
        //A CASA ESTÁ NO LADO A
        if((this->m_lado_a[indice-1] != nullptr)){
            //ESQUERDA
            std::get<0>(tupla_vizinhos) = this->m_lado_a[indice-1];
        }else{
            std::get<0>(tupla_vizinhos) = nullptr;
        }

        if(this->m_lado_a[indice+1] != nullptr){
            //DIREITA
            std::get<1>(tupla_vizinhos) = this->m_lado_b[indice+1];
        }else{
            std::get<1>(tupla_vizinhos) = nullptr;
        }

        int BB = 0;
        bool atribui = false;
        for(auto b : this->m_lado_b){
            if(BB == indice){ //na frente de a
                std::get<2>(tupla_vizinhos) = b;
                atribui = true;
            }
            BB++;
        }
        if(!atribui){
            std::get<2>(tupla_vizinhos) = nullptr;
        }
    }else{
        esta_no_lado_b = true;
    }


    if(esta_no_lado_b){
        for(long unsigned int b = 0; b < this->m_lado_b.size();b++){
            if(this->m_lado_b[b]->getNumero() == c->getNumero()){
                indice = b;
            }
        }
        if(indice != -1){
            //A CASA ESTÁ NO LADO B
            if((this->m_lado_b[indice-1]!= nullptr)){
                std::get<0>(tupla_vizinhos) = this->m_lado_b[indice-1];
            }else{
                std::get<0>(tupla_vizinhos) = nullptr;
            }

            if((this->m_lado_b[indice+1]!=nullptr)){
                std::get<1>(tupla_vizinhos) = this->m_lado_b[indice+1];
            }else{
                std::get<1>(tupla_vizinhos) = nullptr;
            }

            int AA = 0;
            bool atribui = false;
            for(auto a : this->m_lado_a){
                if(AA == indice){
                    std::get<2>(tupla_vizinhos) = a;
                    atribui = true;
                }
                AA++;
            }
            if(!atribui){
                std::get<2>(tupla_vizinhos) = nullptr;
            }
        }
    }

    return tupla_vizinhos;
}

std::tuple<Casa*,Casa*,Casa*> rua::vizinhos(int num){
    std::tuple<Casa*,Casa*,Casa*> tupla_vizinhos;
    long unsigned int indice;
    bool lateral_esquerda = false;
    bool lateral_direita = false;
    for(long unsigned int a  = 0; a < this->m_lado_a.size();a++){
        if(a == 0){ lateral_esquerda = true; }else{ lateral_esquerda = false;}
        if(a == this->m_lado_a.size()-1){ lateral_direita = true;}else{ lateral_direita = false;}
        if(this->m_lado_a[a]->getNumero() == num){
           // std::cout << "ENTRANDO NA FILEIRA A..." << std::endl;
            indice = a;
            if(this->m_lado_a[a-1] != nullptr && lateral_esquerda == false){
                //ESQUERDA
                std::get<0>(tupla_vizinhos) = this->m_lado_a[a-1];
            }else{
                std::get<0>(tupla_vizinhos) = nullptr;
            }

            if(this->m_lado_a[a+1] != nullptr && lateral_direita == false){
                //DIREITA
                std::get<1>(tupla_vizinhos) = this->m_lado_a[a+1];
            }else{
                std::get<1>(tupla_vizinhos) = nullptr;
            }

            //A FRENTE, NO M_LADO_B
            bool atribui = false;
            for(long unsigned int b = 0; b < this->m_lado_b.size();b++){
               //std::cout<< "TEM NA FRENTE!" << std::endl;
                if(indice == b){
                    //a casa a frente
                  //  std::cout << "NA FRENTE TEM ESSA CASA!! No." <<  this->m_lado_b[b]->getNumero() << std::endl;
                    std::get<2>(tupla_vizinhos) = this->m_lado_b[b];
                    atribui = true; 
                    break;
                }
            }
            if(!atribui){
                std::get<2>(tupla_vizinhos) = nullptr;
            }
            break;
            return tupla_vizinhos;
        }
    }

    for(long unsigned int b = 0; b < this->m_lado_b.size();b++){
        if(b == 0){ lateral_esquerda = true; }else{ lateral_esquerda = false;}
        if(b == this->m_lado_b.size()-1){ lateral_direita = true;}else{ lateral_direita = false;}
        if(this->m_lado_b[b]->getNumero() == num){
           // std::cout << "ENTRANDO NA FILEIRA B..." << std::endl;
            indice = b;
            if(this->m_lado_b[b-1] != nullptr && lateral_esquerda==false){
                std::get<0>(tupla_vizinhos) = this->m_lado_b[b-1];
            }else{
                std::get<0>(tupla_vizinhos) = nullptr;
            }

            if(this->m_lado_b[b+1] != nullptr && lateral_direita == false){
                std::get<1>(tupla_vizinhos) = this->m_lado_b[b+1];
            }else{
                std::get<1>(tupla_vizinhos) = nullptr;
            }

            bool atribui = false;
            for(long unsigned int a = 0; a < this->m_lado_a.size();a++){
                if(indice == a){
                   // std::cout << "TEM NA FRENTE!!" << std::endl;
                    std::get<2>(tupla_vizinhos) = this->m_lado_a[a];
                    atribui = true;
                    break;
                }
            }
            if(!atribui){
                std::get<2>(tupla_vizinhos) = nullptr;
            }
            break;
        }
    }

    return tupla_vizinhos;
}

std::string rua::endereco(int num){ //o endereço no formato:<nome_rua>, Cep: <cep>; Casa No. <numero>, Área: <const> / <tot> m2; Lado <lado>.
    bool esta_aqui = false;
    for(auto a: this->m_lado_a ){
     //   std::cout << "NÚMERO DAS CASAS NO A: " << a->getNumero() << std::endl;
        if(a->getNumero() == num){
          //  std::cout << "ENTREIIII NO A" << std::endl;
            esta_aqui = true;
            string lado_a = "A";
            string no = ", Casa no. ";
            string cep_r = ", "; //", Cep: "
            string area = ", ";
            string lado = ", lado ";
            string ponto = ".";
            //string occuped;
          /*
            if(a->isOcupada()==true){
                occuped = " (ocupada)";
            }else{
                occuped = " (desocupada)";
            } */
            //ESTÁ NO LADO A
            return  this->m_nome + cep_r + this->m_CEP + no + std::to_string(a->getNumero()) + area + a->toString() + lado + lado_a;
            break;
        }
    }
    if(!esta_aqui){
        for(auto bb : this->m_lado_b){
           // std::cout << "NÚMERO DA CASAS NO B: " << bb->getNumero() << std::endl;
            if(bb->getNumero() == num){
              //  std::cout << "ENTREIIII NO B" << std::endl;
                esta_aqui = true;
                string lado_b = "B";
                string numero = ", Casa no. ";
                string cep_b = ", "; //", Cep: "
                string virgula = ", ";
                string lado_escrito = ", lado ";
                //ESTÁ NO LADO A
                //string occuped;
              /*
                if(bb->isOcupada()==true){
                    occuped = " (ocupada)";
                }else{
                    occuped = " (desocupada)";
                }*/
                return  this->m_nome + cep_b += this->m_CEP + numero + std::to_string(bb->getNumero()) + virgula + bb->toString() + lado_escrito + lado_b;
                break;
            }
        }
    }
    return "";
}

std::vector<Casa*> rua::get_desocupadas(){
    std::vector<Casa*> vetor_desocupadas;
    for(auto a: this->m_lado_a){
        if(a->isOcupada() == false){
            vetor_desocupadas.push_back(a);
        }
    }
    for(auto b: this->m_lado_b){
        if(b->isOcupada() == false){
            vetor_desocupadas.push_back(b);
        }
    }
    return vetor_desocupadas;
} // NO MAIN -> SE NÃO TIVER NENHUMA, <NENHUMA>
