#include "../include/ficha_personagem.hpp"

void Ficha_Personagem::set_atributos(){
    //Agilidade, Blefe, Conhecimento
    //Cura, Força, Furtividade
    //Inteligencia,Lábia,Ladinagem
    //Liderança,Manejo,Percepção
    //Performance,Pontaria,Resistência
    //Sobrevivência, Trato c/Animais, Vontade
    std::cout << "Agilidade: ";
    int x;
    std::cin >> x;
    atributos_especializacoes.insert(std::map<std::string,int>::value_type("Agilidade",x));
}