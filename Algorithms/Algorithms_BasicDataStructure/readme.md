# TAD SEQUÊNCIA #

*TAD -> Construção matemática que define a natureza do dado criado.*

*ED -> Implementação da TAD, como a TAD é mapeada na memória e como ela é implementada*

**_Agora, qual a melhor ED para elaborar uma sequência em um computador?_**
- Vamos discutir entre dois tipos diferentes de ED da TAD SEQUÊNCIA: Vetores e Lista Ligadas

*Operações que trabalharemos a seguir em cada uma das ED: Inserção, Remoção e Acesso*

**REMOÇÃO, INSERÇÃO E ACESSO**
- Posso fazer de forma _ARBITRÁRIA_
- Posso fazer no _INÍCIO_
- Posso fazer no _FIM_

Assim, iremos preencher a seguinte tabela com o custo computacional dos algoritmos ao longo deste aprendizado:

|     | _INICÍO_ | _ARBITRÁRIA_ | _FIM_ |
| ----| ---------|------------|-----|
| *REMOÇÃO* | ------|-----------|-----|
| *INSERÇÃO*|-------|-----------|-----|
| *ACESSO*|--------|------------|-----|


**Simbora?!?**
- _TAD SEQUÊNCIA PILHA_ : Como no gerenciamento de memória. Só consigo inserir/remover o elemento de fila. Ou seja, a única posição que consigo inserir/remover um elemento é pelo final.
     - Assim, percebe-se que, na TAD PILHA, só posso inserir no fim ou remover no fim. Então, inserção/remoção arbitrária se torna irrelevante. Neste caso, há uma economia computacional.

- _TAD SEQUÊNCIA FILA_ : A do buffer!! Por exemplo, a barra de rolagem do youtube. O BUFFER permite que vc armazene os quadros que ainda faltam para evitar que vc perca a sua conexão de forma brusca, como um jogo da cobrinha, vc consome frames de um lado, e eles são retirados do outro. 
    - Assim, você faz a inserção no início e remoção no fim, OU, a remoção no início e a inserção no fim. Mais uma vez, a inserção/remoção arbitrária se torna irrelevante.


Agora vamos ver se as implementações de tais algoritmos são boas e úteis para as TADs apresentadas acima (focaremos nelas duas).

Como implementar? ED (Estrutura de Dados)!!

- A ED VETOR possui uma homogeneidade de tipos, todos os elementos possuem o mesmo tipo, e assim, o mesmo tamanho. 
    - Posso ter acesso a qualquer elemento. Acesso aleatório
    - Não preciso dos apontadores, gasta menos memória nesse quesito.

- A ED LISTA LIGADA possui uma heterogeinidade de tipos, os elementos podem ter tipos diferentes, e assim tamanhos diferentes. Porém, cada elemento possui um ponteiro diferente.
    - Não tenho acesso a qualquer elemento, apenas ao primeiro. Acesso sequencial.
    - Preciso de apontadores para os elementos.

## DISCUTINDO A IMPLEMENTAÇÃO DA TAD SEQUÊNCIA ##

Como representar a sequência?
    
- Um apontador para a sequência
- Um N que consta a quantidade de elementos presentes na sequência.
- Um Nmax que consta a quantidade máxima de elementos que PODEM ESTAR na sequência

### COM ED VETOR ###

```c++
    std::cout << "Implementando a TAD SEQUÊNCIA" << std::endl;
    char v[10]; //! Implementando na forma estática
    int N = 0;
    int Nmax = 10;
```

- ALGORITMO DE ACESSO

```c++
    char acesso(char *v, int N, int pos){
        return v[pos]; //!Pode ser também *(v+pos), ou seja, o acesso é O(1), chama-se de ACESSO RANDÔMICO.
    }
```
- Acesso Randômico significa dizer que não importa qual elemento você queria acessar, o custo computacional sempre será o mesmo.

Agora temos a nossa primeira informação!! Perceba, abaixo:

|  VETOR | _INICÍO_ | _ARBITRÁRIA_ | _FIM_ |
| ----| ---------|------------|-----|
| *REMOÇÃO* | ------|-----------|-----|
| *INSERÇÃO*|-------|-----------|-----|
| *ACESSO*|Constante|Constante|Constante|

- ALGORITMO DE INSERÇÃO 
    - pos e el são elementos de inserção.
```c++
    void inserir(char *v, int *N, int Nmax, int pos, char el){
        if(*N == Nmax){
            //return -1; //! Não dá para inserir mais ninguém no vetor
        }else{
            for(int ii = N-1; ii >= pos;ii--)
                v[ii+1] = v[ii]; //!Está deslocando todos os números para inserir o el em uma posição
            v[pos] = el; //!Finalmente, insira o el dentro do vetor, na posição pos
            *N = *N+1; //!Atualizando o valor de N, já que agora há mais um elemento no vetor
        }
        //Nestre caso, a inserção no início é O(n), inserção aleatória é O(n) e a inserção no último elemento é O(1)
    } 

```
Certo! ^^ Então agora temos que:

|  VETOR | _INICÍO_ | _ARBITRÁRIA_ | _FIM_ |
| ----| ---------|------------|-----|
| *REMOÇÃO* | ------|-----------|-----|
| *INSERÇÃO*|Linear|Linear|Constante|
| *ACESSO*|Constante|Constante|Constante|

Seguindo para as finais do jogo de basquete!! Segue que:

- ALGORTIMO DE REMOÇÃO

```c++
    void remover(char *v, int *N, int pos){
        if(*N==0){
            //return -1, o vetor é vazio e não tem quem remover
        }else{
            for(int ii = pos; ii <= N-2; ii++)
                v[ii] = v[ii+1];
            *N = *N+1;
        }
        //Minha remoção no início é O(n), remoção na posição aleatória é O(n) e remoção no fim é O(1)
    }

```
Agora sim já temos as informações necessárias para completar a tabelinha!

|  ED VETOR | _INICÍO_ | _ARBITRÁRIA_ | _FIM_ |
| ----| ---------|------------|-----|
| *REMOÇÃO* | Linear|Linear|Constante|
| *INSERÇÃO*|Linear|Linear|Constante|
| *ACESSO*|Constante|Constante|Constante|

- Com isso, eu consigo implementar um TAD PILHA de forma eficiente? SIM! Pois os fatores correspondem ao que a TAD PILHA necessita. No fim, a inserção e a remoção são constantes.

- E a TAD FILA? Aí complica. Pois o fator linear se mantém na inserção no início e na remoção no início, aí não é tão eficiente. Vamos ver a seguir uma diferente implementação do ED VETOR que permite um melhor desenvolvimento para a TAD FILHA (buffers por exemplo), a qual possui um melhor custo computacional.