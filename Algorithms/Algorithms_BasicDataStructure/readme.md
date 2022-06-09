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

<p align='center'>
    <strong>COM ED VETOR</strong>
</p>

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
            *N = *N-1;
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

- Com isso, eu consigo implementar um TAD PILHA de forma eficiente? SIM! Pois os fatores correspondem ao que a TAD PILHA necessita. No fim, a inserção e a remoção no FIM são constantes.

- E a TAD FILA? Aí complica. Pois o fator linear se mantém na inserção no início e na remoção no início, aí não é tão eficiente. Vamos ver a seguir uma diferente implementação do ED VETOR que permite um melhor desenvolvimento para a TAD FILA (buffers por exemplo), a qual possui um melhor custo computacional.

Como resolver este problema?....Vejamos outro conceito de vetores que podemos implementar.

Imagine um vetor de 4 elementos, em uma implementação como as que fizemos anteriormente, para o TAD SEQUÊNCIA FILA, teríamos que a inserção/remoção no início é linear, ou seja, O(N). Pois, todos os elementos devem ser deslocados para que a(s) operações ocorram. Só que, e se eu conseguisse inserir antes do indíce 0? E se eu conseguir deixar arbitrária a minha posição de início do vetor? Isso implicaria que a minha remoção também seria mais simples. Vejamos a serguinte estrutura de dados salvadora da implementação mais fácil do TAD FILA....(>tambores por favor<)

<br>
<p align='center'>
<strong>ED VETOR CIRCULAR</strong>
</p>
E se fosse como o jogo da cobrinha? Se eu tivesse um espaço infinito!! Posso adicionar de um lado, remover do outro...E quando a cobrinha bate na parede? Ela aparece do outro lado, como um PORTAL (quase stranger things isso aqui). Assim, podemos usar esse conceito para montar nosso ED VETOR CIRCULAR.

   -   Como se o fim do vetor fosse mapeado para o seu início!! Assim posso inserir/remover elementos no início e/ou no fim SEM DESLOCAR NADA!! Massa não é? Acredito que acabamos de economizar muitos espaços de memória, e seu processador deve estar te agradecendo...:)

Agora, como podemos programar o nosso PORTAL PARA O MUNDO INVERTIDO no nosso vetor?

Existe um operador chamado mod(%), que serve exatamente para cortar as nossas sequências em ordens de multíplos do número pós %. Ou seja, se fosse N%4, o N seria dividido em grupos de 4 elementos. O mod é um operador matemático de resto, então seus índices são: {0,1,2,3}.

Segue o código de INSERÇÃO:
```c++
    void inserir_inicio(char *v, int *N, int *B, int el){
        if(*N==Nmax){
            //return -1, pois não sabe mais nada, é maior do que o tamanho do vetor
        }else{
            *B = (*B-1)%Nmax; //!Representa o PORTAL
            v[*B] = el;
            *N++; //!Aumenta mais um no número de elementos que estão contidos no vetor
        } //O(1)
    }
```

```c++
    void inserir_fim(char *v, int *N, int *B, int Nmax, char el){
        if(*N==Nmax){
            //return -1, pois não sabe mais nada, é maior do que o tamanho do vetor
        }else{
            *V[(*N+*B)%Nmax] = el; //! Meu portal para inserção no fim
            v[*B] = el;
            *N++; //!Aumenta mais um no número de elementos que estão contidos no vetor
        } //O(1)
    }
```
- ALGORITMO DE ACESSO

```c++
    char acesso(char *v,int Nmax, int B, int pos){
        return V[(pos+B)%Nmax]; //O(1)
    }
```

- ALGORITMO DE REMOÇÃO

```c++
    void remocao_inicio(char *v, int *N, int *B, int Nmax){
        if(*N==0){
            //return -1, não tem ninguém no vetor
        }else{
            *B = (*B+1)%Nmax;
            *N--; //!Neste caso, na teoria se desconsidera a posição ali do lado, mas na prática o lixo e restos ainda estão lá. Se fosse em uma área de segurança, seria mais sugerido tratar esse campo com mais sutileza e cuidado.
        }//Custo Computacional: O(1)
    }
```

```c++
    void remocao_fim(char *v, int *N, int *N, int Nmax){
        if(*N==0){
            //return -1, não tem ninguém no vetor
        }else{
            *N--; //Apenas dá um pop_back na última posição o vetor
        }
    }
```

Agora, após essa explanação, perceba que:

|  ED VETOR CIRCULAR | _INICÍO_ | _ARBITRÁRIA_ | _FIM_ |
| ----| ---------|------------|-----|
| *REMOÇÃO* | Constante|Linear|Constante|
| *INSERÇÃO*|Constante|Linear|Constante|
| *ACESSO*|Constante|Constante|Constante|

Então, com a TAD SEQUÊNCIA PILHA agora tenho mais uma opção!! Posso implementar a remoção e inserção no INÍCIO TAMBÉM!! ^^ E com a TAD SEQUÊNCIA FILA, consigo implementar a inserção e remoção no início e no fim de forma constante!! Facilita nossas contas e o custo computacional.
