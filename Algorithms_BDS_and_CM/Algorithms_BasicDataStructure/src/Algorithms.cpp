#include "../include/Algorithms.hpp"

bool Algorithms::search(int *v,int N, int x){
    //std::cout << "Estou aqui:  " << v << std::endl; //cada inteiro possui 4 bits aqui, perceba!
    if(N==0){ 
        return false;
    }else if(v[0] == x){
        return true;
    }
    return search(v+1,N-1,x);
}

bool Algorithms::sortON2(char *v, int N){ //computacional complexity = O(N^2)
    for(int ii = 0; ii < N; ii++){
        for(int jj=0; jj < N; jj++){
            if(ii >= jj && (v[ii]<v[jj])){ 
                return false;
            }
        }
    }
    return true;
}

bool Algorithms::sortON(char *v, int N){ //Computacional complexity = O(N)
    for(int ii = 0; ii < (N-1);ii++){ //O(N)
        if(v[ii+1] < v[ii]){ //it means it is not ordery //O(1)
            return false;
        }
    }
    return true;
}

bool Algorithms::sortRecursivyForm(int *v, int N){
    if(sortRecursivyForm(v+1,N-1)){ //T(N) =  T(N-1) + 1 == O(N) #### T(N-1) é a chamada recursiva
        if(v[0] <= v[1]){
            return true;
        }
    }
    return false;
}

void Algorithms::swap(int *v, int ii, int jj){
    int varAux;
    varAux = v[ii];
    v[ii] = v[jj];
    v[jj] = varAux;
}

bool Algorithms::bubbleSortAscendingOrder(int *v, int N){ 
    bool isWrong;
    do{
        isWrong =  false;
        for(int ii =0; ii < (N-1);ii++){
            if(v[ii]> v[ii+1]){
                swap(v,ii,ii+1); //if found something wrong, he actualizes and changes
                isWrong = true;
            }
        }
        if(isWrong == false){
            return true;
        }
    }while(isWrong);
    return false;
}

bool Algorithms::bubbleSortDescendingOrder(int *v, int N){
    bool isWrong = false;
    while(!isWrong){
        for(int ii = 0; ii < (N-1); ii++){
            if(v[ii] < v[ii+1]){
                swap(v,ii,ii+1);
                isWrong = true;
            }
        }

        if(isWrong == false){
            return true;
        }else{
            isWrong = false;
        }
    }
    return false;
}


bool Algorithms::insertionSort(int *v, int N){
    for(int ii = N-1; ii>=0;ii--){
         //ou seja, vc atribui ao jj o valor da última posição da parte NÃO ORDENADA
        //o que determina que a parte não está ordenada: v[jj] >v[jj+1] && jj<N-1 (ordenação ascendente)
        
        //a seleção está em: int jj=ii -> seleção -> O(1)
        for(int jj = ii; v[jj] >v[jj+1] && jj<N-1; jj++){
            swap(v,jj,jj+1);
        }
    }
    //melhor caso: O(N)*(O(1)+O(1)) = O(N) - vetor ordenado
    //pior caso: O(N)*(O(1)+O(N)) = O(N^2) - roda todo o vetor

    //Não é interessante em situação de sequências ENORMES e não há uma garantia que está ordenada
    return true;
}

/*QUICKSORT and MERGESORT
    - separação //O(N)
    - ordenação primeira parte  //O(N/2)
    - ordenação segunda parte // O(N/2) (Posso fazer recursão por ter duas ordenações)
    - junção //O(1)
A única coisa que diferencia é o trabalho em cada etapa
*/

int Algorithms::break_apart(int *v, int N){ //Computer complexity -> O(N)
    int pivot  = 0;
    int pp = 1, qq = N-1;//pp no próximo logo após o pivot e qq no último
    while(qq > pp){
        while(v[pp] < v[pivot] && pp < N){ //pp < N, se chegar no fim ele para
            pp++;
        }
        while(v[qq] > v[pivot]){
            qq--; 
        }
        if(qq > pp){
            swap(v,pp,qq);
        }
    }
    swap(v,pivot,qq);
    return qq;
}
//For example, i can separate 7 in two vectores of 3 and a pivot
bool Algorithms::quicksort(int *v, int N){
    //returnes two pointers to groups of vector
    bool resul;
    int middle = break_apart(v,N); //O(N)
    if(N==0){ return middle;}
    resul = quicksort(v,middle);
    resul = quicksort(v+middle,N-middle-1); 
    return resul;
    //best case -> O(N*log N)
    //worst case -> O(N^2)
}
/*
mergeSort N
    if(N<=1){ vetor já ordenado}
    - separação - O(1)
    - ordenação 1 - O(N/2)
    - ordenação 2 - O(N/2)
    - junção - O(N)


*/
void Algorithms::mergeSort(int *v, int N, int M){ //computer complexity -> O(N*logN)
    int ii =0, pp = 0, qq = M; //M - middle for end - size
    int *tmp = (int *)malloc (N* sizeof(int));
    ///DAQUI, 3 WHILES -> O(N)
    while(pp < M && qq < N){
        //ainda tenho elemento na primeira metade
        if(v[pp] <= v[qq]){
            tmp[ii++] = v[pp++]; //ele realiza a operação em v, e depois incrementa na variável
        } else{
            tmp[ii++] = v[qq++];
        }
    }
    while(pp < M){
        tmp[ii++] = v[pp++];
    } 
    while(qq < N){
        tmp[ii++] = v[qq++];
    }
    ////
    //ESSE É O(N) por si só
    for(int ii = 0; ii < N; ii++){
        v[ii] = tmp[ii];
    }
    free(tmp);
}

int Algorithms::insertion_inicio_circular_vector(int *v,int *N,int *B, int Nmax, int el){
    if(*N == Nmax){
        return -1;
    }
    *B = (*B-1)%Nmax;
    v[*B] = el;
    *N++;
    //Computer Complexity -> Worst and Best case -> O(1)
}
int Algorithms::insertion_inicio_circular_vector2(int *v,int *N,int *B, int Nmax, int el){
    if(*N ==Nmax){
        return -1;
    }
    v[(*N+*B)%Nmax] = el;
    *N++;
    //Computer Complexity -> Worst and Best case -> O(1)
}
int Algorithms::acess_circular_vector(int *v, int N, int Nmax, int B, int pos){
    return v[pos+B]/Nmax; //COmputer Complexity -> Worst and Best case -> O(1)
}
int Algorithms::remocao_inicio(int *v, int *N, int *B, int Nmax){
    if(*N == 0){ //No one in vector
        return -1;
    }
    *N--;
    *B = *(B+1)%Nmax;
    //Computer complexity -> O(1)
}
int Algorithms::remocao_final(int *v,int *N, int *B, int Nmax){
    if(*N==0){
        return -1;
    }
    *N--;
    //Computer complexity -> O(1)
    //!Subtitles in PT-BR:: Perceba que aqui ele não apagou o elemento, ele apenas 
    //diminuiu o número de elementos que estão sendo acessados na jogada. Isso é um problema
    // na área de segurança. Stay tuned about it; 
}