#include <iostream>
#include <vector>

class Algorithms{
    private:
        int m_N;
        std::vector<int> m_vector_numbers;
    public:
        void setN(int N);
        int getN();
        void getNumbersVector();
        std::vector<int> setNumbersVector(std::vector<int> vectorNumber);

        //Search Algorithms - (Default). Determine if number x is in the sequence
        bool search(int *S,int N, int x);
        
        //Sort Algorithms. Determine if a sequence is sorted 
        bool sortON2(char *v, int N); // Computer complexity -> O(N^2)
        bool sortON(char *v, int N); //Computer complexity -> O(N)
        bool sortRecursivyForm(int *v, int N); //computer complexity -> O(N)

        //Sort Algorithms.
        //Bubble Sort
        bool bubbleSortAscendingOrder(int *v, int N);
        bool bubbleSortDescendingOrder(int *v, int N);
        //Insertion Sort
        bool insertionSort(int *v, int N);
        //quick sort //separação por pivoteamento
        bool quicksort(int *v, int N); 
        //merge sort
        void mergeSort(int *v, int N, int M);
        //Auxiliar functions
        void swap(int *v, int ii, int jj); //for bubble sort
        int break_apart(int *v, int N); //for Quick Sort

        //Circular Vector
        int insertion_inicio_circular_vector(int *v,int *N,int *B, int Nmax, int el);
        int insertion_inicio_circular_vector2(int *v,int *N,int *B, int Nmax, int el);
        int insertion_fim_circular_vector(int *v,int *N,int *B, int Nmax, int el);
        int acess_circular_vector(int *v, int N, int Nmax, int B, int pos);
        int remocao_inicio(int *v, int *N, int *B, int Nmax);
        int remocao_final(int *v,int *N, int *B, int Nmax);
};      