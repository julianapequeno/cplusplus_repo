#include <iostream>
#include "../include/Algorithms.hpp"

/*void merge(char *S, int x,int N){
    int pp=0, qq=N/2,tt=0;
    char * tmp = new char(N*sizeof(char));
    
}*/

#define BACKGROUND "\u001b[47;1m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RED "\u001b[31m"
#define ANSI_COLOR_BLUE "\u001b[34m"
#define ANSI_COLOR_CYANO "\u001b[36m"
#define ANSI_COLOR_WHITE "\u001b[37m"
#define ANSI_COLOR_GREEN "\u001b[32m"
#define RESET "\u001b[0m"

int main(){
    int number;
    std::cout << BACKGROUND << ANSI_COLOR_RED << "SEARCH ALGORITHM" << RESET << std::endl;
    std::cout << "💨Enter a number: ";
    std::cin >> number;
    Algorithms a;
    int v[10] = {2,3,4,5,1,10,2,3,7,8};
    bool result  = a.search(v,10,number);
    if(result){
        std::cout << ANSI_COLOR_GREEN << "Number " << number << " it exists in vector😊" << std::endl<<  RESET;
    }else{
        std::cout << ANSI_COLOR_RED << "This number does not exist in vector🙁" << std::endl;
    }

    std::cout << BACKGROUND << ANSI_COLOR_RED << "BUBBLE SORT" << RESET << std::endl;
    
    /*
    std::cout << "💨Enter a vector of numbers: ";
    std::vector<int> v_numbers;

    std::string tmp;
    int x;
    do{
        std::cin >> x;
        v_numbers.push_back(x);
        tmp = x+"\o";
        std::cout << tmp << std::endl;
    }while((char(x) >= 40 && char(x) <= 57));
    */
    std::cout << ANSI_COLOR_MAGENTA << "Original vector: " << RESET;
    for(int i  = 0; i < 10; i++){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    bool resultDescending = a.bubbleSortDescendingOrder(v,10);
    std::cout << ANSI_COLOR_MAGENTA << "Vector Descending: "<<  RESET;
    for(int i  = 0; i < 10; i++){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    bool resultAscending = a.bubbleSortAscendingOrder(v,10);
    std::cout << ANSI_COLOR_MAGENTA << "Vector Ascending: " << RESET;
    for(int i  = 0; i < 10; i++){
        std::cout << v[i] << " ";
    }  
    std::cout << std::endl;

    int  vv[10] = {2,3,4,5,1,10,2,3,7,8};
    std::cout << BACKGROUND << ANSI_COLOR_RED << "INSERTION SORT" << RESET << std::endl;
    bool resultInsertionSort = a.insertionSort(vv,10);
    if(resultInsertionSort){
        std::cout << ANSI_COLOR_CYANO << "Sort vector after insertion sort: " << RESET;
        for(auto i : v){
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;
    int  vvv[10] = {2,3,4,5,1,10,2,3,7,8};
    std::cout << BACKGROUND << ANSI_COLOR_RED << "QUICK SORT" << RESET << std::endl;
    std::cout << ANSI_COLOR_YELLOW << "Original vector: " << RESET;
    for(int i  = 0; i < 10; i++){
        std::cout << vvv[i] << " ";
    }
    bool resultQuickSort = a.quicksort(vvv,10);
    if(resultQuickSort){
        std::cout << ANSI_COLOR_YELLOW << "Sort vector after quick sort: " << RESET;
        for(auto i: vvv){
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    int vector[10] = {2,3,4,5,1,10,2,3,7,8}; //reinicializando
    std::cout<< BACKGROUND << ANSI_COLOR_RED << "MERGE SORT" << RESET << std::endl;
     std::cout << ANSI_COLOR_CYANO << "Original vector: " << RESET;
    for(int i  = 0; i < 10; i++){
        std::cout << vector[i] << " ";
    }
    std::cout << ANSI_COLOR_CYANO << "Sort vector after merge sort: " << RESET;
    a.mergeSort(vector,10,5);
    for(auto i: vector){
        std::cout << i << " ";
    }
    std::cout << std::endl;

}