# TAD SEQU�NCIA #

*TAD -> Constru��o matem�tica que define a natureza do dado criado.*

*ED -> Implementa��o da TAD, como a TAD � mapeada na mem�ria e como ela � implementada*

**_Agora, qual a melhor ED para elaborar uma sequ�ncia em um computador?_**
- Vamos discutir entre dois tipos diferentes de ED da TAD SEQU�NCIA: Vetores e Lista Ligadas

*Opera��es que trabalharemos a seguir em cada uma das ED: Inser��o, Remo��o e Acesso*

**REMO��O, INSER��O E ACESSO**
- Posso fazer de forma _ARBITR�RIA_
- Posso fazer no _IN�CIO_
- Posso fazer no _FIM_

Assim, iremos preencher a seguinte tabela com o custo computacional dos algoritmos ao longo deste aprendizado:

|     | _INIC�O_ | _ARBITR�RIA_ | _FIM_ |
| ----| ---------|------------|-----|
| *REMO��O* | ------|-----------|-----|
| *INSER��O*|-------|-----------|-----|
| *ACESSO*|--------|------------|-----|


**Simbora?!?**
- _TAD SEQU�NCIA PILHA_ : Como no gerenciamento de mem�ria. S� consigo inserir/remover o elemento de fila. Ou seja, a �nica posi��o que consigo inserir/remover um elemento � pelo final.
     - Assim, percebe-se que, na TAD PILHA, s� posso inserir no fim ou remover no fim. Ent�o, inser��o/remo��o arbitr�ria se torna irrelevante. Neste caso, h� uma economia computacional.

- _TAD SEQU�NCIA FILA_ : A do buffer!! Por exemplo, a barra de rolagem do youtube. O BUFFER permite que vc armazene os quadros que ainda faltam para evitar que vc perca a sua conex�o de forma brusca, como um jogo da cobrinha, vc consome frames de um lado, e eles s�o retirados do outro. 
    - Assim, voc� faz a inser��o no in�cio e remo��o no fim, OU, a remo��o no in�cio e a inser��o no fim. Mais uma vez, a inser��o/remo��o arbitr�ria se torna irrelevante.


Agora vamos ver se as implementa��es de tais algoritmos s�o boas e �teis para as TADs apresentadas acima (focaremos nelas duas).

Como implementar? ED (Estrutura de Dados)!!

- A ED VETOR possui uma homogeneidade de tipos, todos os elementos possuem o mesmo tipo, e assim, o mesmo tamanho. 
    - Posso ter acesso a qualquer elemento. Acesso aleat�rio
    - N�o preciso dos apontadores, gasta menos mem�ria nesse quesito.

- A ED LISTA LIGADA possui uma heterogeinidade de tipos, os elementos podem ter tipos diferentes, e assim tamanhos diferentes. Por�m, cada elemento possui um ponteiro diferente.
    - N�o tenho acesso a qualquer elemento, apenas ao primeiro. Acesso sequencial.
    - Preciso de apontadores para os elementos.

## DISCUTINDO A IMPLEMENTA��O DA TAD SEQU�NCIA ##

Como representar a sequ�ncia?
    
- Um apontador para a sequ�ncia
- Um N que consta a quantidade de elementos presentes na sequ�ncia.
- Um Nmax que consta a quantidade m�xima de elementos que PODEM ESTAR na sequ�ncia

<p align='center'>
    <strong>COM ED VETOR</strong>
</p>

```c++
    std::cout << "Implementando a TAD SEQU�NCIA" << std::endl;
    char v[10]; //! Implementando na forma est�tica
    int N = 0;
    int Nmax = 10;
```

- ALGORITMO DE ACESSO

```c++
    char acesso(char *v, int N, int pos){
        return v[pos]; //!Pode ser tamb�m *(v+pos), ou seja, o acesso � O(1), chama-se de ACESSO RAND�MICO.
    }
```
- Acesso Rand�mico significa dizer que n�o importa qual elemento voc� queria acessar, o custo computacional sempre ser� o mesmo.

Agora temos a nossa primeira informa��o!! Perceba, abaixo:

|  VETOR | _INIC�O_ | _ARBITR�RIA_ | _FIM_ |
| ----| ---------|------------|-----|
| *REMO��O* | ------|-----------|-----|
| *INSER��O*|-------|-----------|-----|
| *ACESSO*|Constante|Constante|Constante|

- ALGORITMO DE INSER��O 
    - pos e el s�o elementos de inser��o.
```c++
    void inserir(char *v, int *N, int Nmax, int pos, char el){
        if(*N == Nmax){
            //return -1; //! N�o d� para inserir mais ningu�m no vetor
        }else{
            for(int ii = N-1; ii >= pos;ii--)
                v[ii+1] = v[ii]; //!Est� deslocando todos os n�meros para inserir o el em uma posi��o
            v[pos] = el; //!Finalmente, insira o el dentro do vetor, na posi��o pos
            *N = *N+1; //!Atualizando o valor de N, j� que agora h� mais um elemento no vetor
        }
        //Nestre caso, a inser��o no in�cio � O(n), inser��o aleat�ria � O(n) e a inser��o no �ltimo elemento � O(1)
    } 

```
Certo! ^^ Ent�o agora temos que:

|  VETOR | _INIC�O_ | _ARBITR�RIA_ | _FIM_ |
| ----| ---------|------------|-----|
| *REMO��O* | ------|-----------|-----|
| *INSER��O*|Linear|Linear|Constante|
| *ACESSO*|Constante|Constante|Constante|

Seguindo para as finais do jogo de basquete!! Segue que:

- ALGORTIMO DE REMO��O

```c++
    void remover(char *v, int *N, int pos){
        if(*N==0){
            //return -1, o vetor � vazio e n�o tem quem remover
        }else{
            for(int ii = pos; ii <= N-2; ii++)
                v[ii] = v[ii+1];
            *N = *N+1;
        }
        //Minha remo��o no in�cio � O(n), remo��o na posi��o aleat�ria � O(n) e remo��o no fim � O(1)
    }

```
Agora sim j� temos as informa��es necess�rias para completar a tabelinha!


|  ED VETOR | _INIC�O_ | _ARBITR�RIA_ | _FIM_ |
| ----| ---------|------------|-----|
| *REMO��O* | Linear|Linear|Constante|
| *INSER��O*|Linear|Linear|Constante|
| *ACESSO*|Constante|Constante|Constante|

- Com isso, eu consigo implementar um TAD PILHA de forma eficiente? SIM! Pois os fatores correspondem ao que a TAD PILHA necessita. No fim, a inser��o e a remo��o no FIM s�o constantes.

- E a TAD FILA? A� complica. Pois o fator linear se mant�m na inser��o no in�cio e na remo��o no in�cio, a� n�o � t�o eficiente. Vamos ver a seguir uma diferente implementa��o do ED VETOR que permite um melhor desenvolvimento para a TAD FILA (buffers por exemplo), a qual possui um melhor custo computacional.

Como resolver este problema?....Vejamos outro conceito de vetores que podemos implementar.

Imagine um vetor de 4 elementos, em uma implementa��o como as que fizemos anteriormente, para o TAD SEQU�NCIA FILA, ter�amos que a inser��o/remo��o no in�cio � linear, ou seja, O(N). Pois, todos os elementos devem ser deslocados para que a(s) opera��es ocorram. S� que, e se eu conseguisse inserir antes do ind�ce 0? E se eu conseguir deixar arbitr�ria a minha posi��o de in�cio do vetor? Isso implicaria que a minha remo��o tamb�m seria mais simples. Vejamos a serguinte estrutura de dados salvadora da implementa��o mais f�cil do TAD FILA....(>tambores por favor<)

<br>
<p align='center'>
<strong>ED VETOR CIRCULAR</strong>
</p>
E se fosse como o jogo da cobrinha? Se eu tivesse um espa�o infinito!! Posso adicionar de um lado, remover do outro...E quando a cobrinha bate na parede? Ela aparece do outro lado, como um PORTAL (quase stranger things isso aqui). Assim, podemos usar esse conceito para montar nosso ED VETOR CIRCULAR.

   -   Como se o fim do vetor fosse mapeado para o seu in�cio!! Assim posso inserir/remover elementos no in�cio e/ou no fim SEM DESLOCAR NADA!! Massa n�o �? Acredito que acabamos de economizar muitos espa�os de mem�ria, e seu processador deve estar te agradecendo...:)

Agora, como podemos programar o nosso PORTAL PARA O MUNDO INVERTIDO no nosso vetor?

Existe um operador chamado mod(%), que serve exatamente para cortar as nossas sequ�ncias em ordens de mult�plos do n�mero p�s %. Ou seja, se fosse N%4, o N seria dividido em grupos de 4 elementos. O mod � um operador matem�tico de resto, ent�o seus �ndices s�o: {0,1,2,3}.

Segue o c�digo de INSER��O:
```c++
    void inserir_inicio(char *v, int *N, int *B, int el){
        if(*N==Nmax){
            //return -1, pois n�o sabe mais nada, � maior do que o tamanho do vetor
        }else{
            *B = (*B-1)%Nmax; //!Representa o PORTAL
            v[*B] = el;
            *N++; //!Aumenta mais um no n�mero de elementos que est�o contidos no vetor
        } //O(1)
    }
```

```c++
    void inserir_fim(char *v, int *N, int *B, int Nmax, char el){
        if(*N==Nmax){
            //return -1, pois n�o sabe mais nada, � maior do que o tamanho do vetor
        }else{
            *V[(*N+*B)%Nmax] = el; //! Meu portal para inser��o no fim
            v[*B] = el;
            *N++; //!Aumenta mais um no n�mero de elementos que est�o contidos no vetor
        } //O(1)
    }
```
- ALGORITMO DE ACESSO

```c++
    char acesso(char *v,int Nmax, int B, int pos){
        return V[(pos+B)%Nmax]; //O(1)
    }
```

- ALGORITMO DE REMO��O

```c++
    void remocao_inicio(char *v, int *N, int *B, int Nmax){
        if(*N==0){
            //return -1, n�o tem ningu�m no vetor
        }else{
            *B = (*B+1)%Nmax;
            *N--; //!Neste caso, na teoria se desconsidera a posi��o ali do lado, mas na pr�tica o lixo e restos ainda est�o l�. Se fosse em uma �rea de seguran�a, seria mais sugerido tratar esse campo com mais sutileza e cuidado.
        }//Custo Computacional: O(1)
    }
```

```c++
    void remocao_fim(char *v, int *N, int *N, int Nmax){
        if(*N==0){
            //return -1, n�o tem ningu�m no vetor
        }else{
            *N--; //Apenas d� um pop_back na �ltima posi��o o vetor
        }
    }
```

Agora, ap�s essa explana��o, perceba que:

|  ED VETOR CIRCULAR | _INIC�O_ | _ARBITR�RIA_ | _FIM_ |
| ----| ---------|------------|-----|
| *REMO��O* | Constante|Linear|Constante|
| *INSER��O*|Constante|Linear|Constante|
| *ACESSO*|Constante|Constante|Constante|

Ent�o, com a TAD SEQU�NCIA PILHA agora tenho mais uma op��o!! Posso implementar a remo��o e inser��o no IN�CIO TAMB�M!! ^^ E com a TAD SEQU�NCIA FILA, consigo implementar a inser��o e remo��o no in�cio e no fim de forma constante!! Facilita nossas contas e o custo computacional.