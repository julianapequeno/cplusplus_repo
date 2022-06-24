#include <iostream>
#include <time.h>
#include <vector>
#include <chrono>
#include <numeric>
#include <iomanip>

#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define RESET "\u001b[0m"
volatile int sink;

int main(){
    /*
    time_t start_t, end_t;
    double diff_t;*/
    /*Inicializando a matriz 1000x1000 com valores 10*/
    std::vector<std::vector<int>> my_matrix;
    std::vector<int> linha;
    linha.resize(1000,10);
    my_matrix.resize(1000,linha);

    auto start = std::chrono::steady_clock::now();

    int soma = 0;
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++){
            soma += my_matrix.at(i).at(j);
        }
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "O tempo para o processador compilar um algoritmo de somatório de todos os elementos de uma matrix " << std::setw(9)
                  << "1000x1000" << ", na ordem linha-coluna. Ou seja, na ordem natural de armazenamento, é : " << ANSI_COLOR_MAGENTA <<  diff.count() << RESET << " s\n";
    /*
    time(&end_t);
    diff_t = difftime(end_t,start_t);
    std::cout << "Tempo de execução na ordem i,j (linhas e colunas) = " << diff_t << std::endl;
*/

    auto inicio =  std::chrono::steady_clock::now();

    for(int j = 0; j < 1000; j++){
        for(int i = 0; i < 1000; i++){
            soma += my_matrix.at(i).at(j);
        }
    }
    auto fim = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff_2 = fim - inicio;
    std::cout << "O tempo para que o processador compile o mesmo algoritmo, de um somatório de matriz " << std::setw(9)
                  << "1000x1000" << ", porém na ordem inversa - coluna e linha - é : " << ANSI_COLOR_MAGENTA << diff_2.count() << RESET<< " s\n";

    std::cout << "Assim, está constado que inverter exige um custo maior, já que os vizinhos já não são os mesmos (pois a ordem não é natural). Está é a diferença entre eles dois: " << std::setw(9) << ANSI_COLOR_YELLOW << diff_2.count() - diff.count() << RESET << " s\n";
    std::cout << "Este é um exemplo de baixa localidade temporal e baixa localidade espacial. Pois a memória cache não guarda os dados na mesma forma em que foram guardados na memória";
}