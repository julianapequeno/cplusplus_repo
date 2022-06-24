#include "Casa.hpp"

/*
TODO: Implementação dos métodos
*/

Casa::Casa(double area_construida, double area_total){
    this->m_areaConstruida = area_construida;
    this->m_areaTotal = area_total;
    this->m_numero = -1;
    this->m_ocupada = false;
}

int Casa::getNumero(){
    return this->m_numero;
}

void Casa::setNumero(int n){
    this->m_numero = n;
}

bool Casa::isOcupada(){
    return this->m_ocupada;
}

void Casa::setOcupada(bool ocupada){
    this->m_ocupada = ocupada;
}

std::string Casa::toString(){ //Área: area_ocupada / areaConstruida m2
    std::string barra = " / ";
    std::string metroquadrado = ""; //" m2"
    std::string areacontruida = std::to_string(this->m_areaTotal); //std::fixed << std::setprecision(2) <<
    std::size_t found = areacontruida.find(".");
    areacontruida = areacontruida.substr(0,found+3);
    std::string areatotal = std::to_string(this->m_areaConstruida);
    found = areatotal.find(".");
    areatotal = areatotal.substr(0,found+3);
    std::string name_area = "Área: ";
    return name_area += areatotal += barra += areacontruida += metroquadrado;
}