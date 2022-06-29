# Notes about Hierarquia de Memória :)
##### 📌Terceira Unidade da disciplina "Arquitetura de Computadores" do curso de BTI na UFRN


Sumário
1. [Definição de Memória](#mémoria-é-um-lugar-para-o-armazenamento-de-informações-e-suas-únicas-ações-são-leitura-e-escrita)
2. [Memory Wall](#memory-wall)
3. [Hierarquia de Memória](#hierarquia-de-memória)
4. [CACHE](#cache)
5. [CACHE - Decisões de Projeto](#decisões-de-projeto)


#### __Mémoria__  é um lugar para o armazenamento de informações, e suas únicas ações são: leitura e escrita.

- Memória endereçável - Pois via um endereço, você pode ter acesso a um determinado dado.

Qual é o tamanho ideal? O maior tamanho possível e a localização mais perto do processador.

O que temos? Tecnologias de memória velozes, mas são muito caros. Por outro lado, temos algumas baratas, mas são muito lentas.

#### Memory Wall
- Realizar o processamento é muito mais rápido hoje em dia, do que busca o/a dado/instrução na memória. No gráfico temos o "PERFORMANCE GAP", da evolução da memória e do 
processador ao passar dos anos.
- Quando eu tenho os dados se torna mais fácil fazer a conta!!
- Como posso melhorar isso??

# Hierarquia de Memória
- Registradores: Eles são muito caros de se fabricar 😫 Mas são memórias cada vez __mais rápidas__.
- Memória Cache: Cache L1,L2,L3...são os níveis, quanto menor o número mais próximo ao processador ela está
  - Os registradores e a cache L1 estão DENTRO DO PROCESSADOR, dependendo do processador, ele também pode ter a cache L2 e L3 dentro do processador
- Memória Principal: Memória RAM (Random Acess Memory), o custo por BIT é mais barato do que o da memória cache, mas ela fica FORA do processador.
- Memória Externa: (Ou memória secundária, memória de massa) HD´s, memória Flash. O custo por BIT é menor do que todos os custos por BIT de memória já citados anteriormente.

Mais acima da pirâmida: Maior o CUSTO (o preço baseado em custo por BIT, são mais caras) e maior a VELOCIDADE (a rapidez de resposta de busca na memória).
Mais abaixo na pirâmide: Maior o TEMPO DE ACESSO (ou seja, mais lento) e Maior a CAPACIDADE (pode armazenar mais)

 
 #### Como são formadas?
 
 - Memória Cache: Tecnologia é a SRAM (Static Random Acess Memory).
 - Memória Principal: Tecnologia é a DRAM (Dynamic Random Acess Memory)
 - Memória virtual (ou externa): Tecnologia é HDD, SSD.

<div align="center"> 
  <image src="images/disco_computador.png" width=350 height=200>
</div>

<div align="center">
  <image src="images/disco_celular.png" width=350 height=200>
</div>


- __Hierarquia Inclusiva__: Tudo o que está dentro do registrador está dentro da cache, tudo o que está dentro da cache, está na principal, e tudo o que está na principal está no disco. Ou seja, são sub-conjuntos uma da outra, baseado na ordem de hierarquia.

   - Os discos rígidos e as memórias principais são os únicos NÃO VOLÁTEIS. Assim, para acessar, os dados vão sendo copiados até chegar aos registrados e aos usuários.

  - A memória principal pode ser acessada pelo processador.
  - A memória secundária não pode ser acessada diretamente! O dado DEVE PASSAR PELA MEMÓRIA PRINCIPAL para poder ser lido/escrito na memória secundária.

<div align="center">
 
 # __CACHE__
 </div>

 Para melhorar o tempo de busca do dado dentro da memória, a cache foi criada. Assim, quando o processador busca alguma informação na memória, inicialmente ela:
  - Verifica se existe dentro da memória cache. Caso sim, há um _cache hit_. Caso não esteja lá, é um _cache miss_.

A ordem de comunicação ocorre nesta ordem:

CPU -> Cache L1 -> Cache L2 -> Cache L3 -> Memória Principal -> DISCO

- Se o dado estiver na Memória principal, o dado é devolvido para a memória cache, e de lá, devolve-se para a CPU por meio da repetição da busca da CPU na memória Cache.

- Da CPU a Memória Principal, tudo é feito pelo Hardware (existência do dado, transferência do dado).
- Já a partir do DISCO, e executado pelo Sistema Operacional (SO).

A CACHE guarda sempre as últimas informações solicitadas pelo computador.

> 📚 __PRINCÍPIO DA LOCALIDADE__ : É uma _guess_ de comportamento de usuário, e de pedidos do processador. Diz que, se um item (leitura/escrita) foi referenciado, há uma probabilidade de que ele seja acessado novamente (LOCALIDADE TEMPORAL) ou que um de seus vizinhos sejam acessados daqui há pouco (LOCALIDADE ESPACIAL).

- Exemplo de Localidade Temporal: LOOPS
- Exemplo de Localidade Espacial: ESTRUTURAS - VETORES, MATRIZES, STRUCTS...

Esses princípios são seguidos por serem nossa maneira de programar há muito tempo. E essa localidade faz com que a hierarquia de memória (guardando os sub-conjuntos) funcione de forma usual. -----

Implementei um exemplo de acesso por coluna/linha de uma matriz 1000x1000 e comparei os tempos para conferirmos como custa mais para a memória procurar, baseado neste princípio da localidade.
Esse é um exemplo de baixa localidade temporal e baixa localidade espacial. Pois a memória cache não guarda os dados na mesma forma em que foram guardados na memória

> [Exemplo de tempo de execução do programa com memória cache e uma matriz 1000x1000](main.cpp)

```c++ 
auto inicio =  std::chrono::steady_clock::now();

    for(int j = 0; j < 1000; j++){
        for(int i = 0; i < 1000; i++){
            soma += my_matrix.at(i).at(j);
        }
    }
    auto fim = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff_2 = fim - inicio;
```

Perceba que neste trecho do código, o iterador percorre o vetor de uma forma não convencional, e assim, não da forma em que está guardada na memória. Como o princípio da localidade considera essa forma de programação, ele sofre um pouco ao tentar ser aplicado neste caso, já que os 'vizinhos' são diferentes.


- É uma memória rápida, de pequena capacidade. Itens referenciados com frequência.

- Entre CPU e Cache, apenas o dado requerido é devolvido. Mas entre Cache e Memória Principal, por conta do PRINCÍPIO DA LOCALIDADE, há uma transferência de blocos, a cache também recebe os vizinhos dos dados.
<div align="center">

  #### T E R M I N O L O G I A S

</div>

  - Taxa de _hit_: Quantas vezes ocorreu um _cache hit_, em que o dado estava na cache.
  - Taxa de _miss_: Quantas vezes ocorreu um _cache miss_, em que o dado não estava na cache.
  - Tempo de hit: Tempo para definir se o dado está ou não na cache, e entregar o dado para a memória principal.
  - Penalidade de miss: Tempo para determinar se houve miss, para entregar para a memória principal e para que a memória principal retorne o dado para a memória cache. 
  - Palavra: unidade de sistema de memória.
  - Bloco: Coletivo de palavras dentro da memória.
  - Linha: Coletivo de palavras dentro da cache. (O bloco, porém dentro da cache)
  - Tag: o nome dos blocos, identificadores.

  A memória cache atua em solicitações entre o processador e a memória principal.
    - O resultado dessa solicitação é um _cache hit_ ou um _cache miss_. O que implicarão em tempo de miss, ou penalidade de hit.

  ## __DECISÕES DE PROJETO__
  1. Qual o tamanho da unidade mínima de transferência de dados na memória? 
  <br>_Está associado ao tamanho da palavra pelo processador. Perceba que se for de 64bits vai precisar de mais memória e mais energia_
      - Após o _hit_, a cache devolve um endereço, e cada endereço corresponde a uma palavra. Os possíveis endereços a serem referenciados estão no __espaço de endereçamento__, neste caso (32 bits), de 0 a 1023.

2. Agora, quantas palavras eu trago da memória principal (com o vizinhos), qual o tamanho do bloco?
    - O tamanho do bloco é o mesmo do que vem na memória principal e na memória cache. 
    - Essa decisão de projeto afeta diretamente a quantidade de blocos que existirão na memória cache.
    - Não pode ser muito grande, pois excederia a questão da localidade espacial. Seria fora do escopo, no caso, seria um vizinho muuuuuuito distante.
    - Exemplo: Tamanho da palavra - 32 bits. Cada bloco tem 8 palavras, como temos 1024 palavras..temos 128 blocos!

- Memória cache é bem menor do que a memória principal, mas __o tamanho dos blocos é IGUAL__.

Para descobrir qual bloco o endereço pertence:
```c++
  int B; //bloco
  int E; //endereço do que eu quero
  int N; //tamanho da palavra do processador/bloco
  B = E div N
```

- Tudo vai sendo COPIADO para a memória cache.

<div align="center">

__QUESTÕES DE HIERARQUIA DE MEMÓRIA__
</div>

1. _POSICIONAMENTO DO BLOCO_

  - Mapeamento direto (directed-mapped)<br>
    Cada bloco está em uma posição determinada na cache. Isso facilita MUITO a busca, pois o cache hit/miss é determinado pela verificação de uma localização já determinada. Desvantagem: Há um desperdício de espaço, pode ser que todas as solicitações precisem ocupar o MESMO espaço!
    - REGRA DE MAPEAMENTO:
    ```c++
       int pos_na_cache =   end_do_bloco % linhas_da_cache;
    ```
  - Totalmente associativa (fully associative)<br>
    Neste caso, o bloco pode ser colocado em _qualquer posição_. Não há desperdício de espaço :) Masss, a busca no pior caso é ENORME. Por isso, esse tipo de mapeamento só é usado em memórias muito pequenas, ou realiza buscas em paralelo.
  - Associativa por conjunto (n-way set-associative)<br>
    É um meio do caminho entre os dois anteriores, que são bem extremos. Separa a cache por conjuntos.
    _"way"_ (ou vias), 
    <br> Quão mais alto o números de vias, maior o desempenho da cache, mas o estudos mostram que o maior é de 16 bits.

    Cálculo:
    ```c++
      int map_conjunto = end_bloco % quant_conjuntos;
    ```
    Uma vez escolhido o conjunto, aí é só aplicar o TA, escolhe o que estiver disponível/busca em todos desse conjunto. <br> Este caso, é como se pegasse o melhor dos dois mundos (MD e TA)
2. _SUBSTITUIÇÃO DE BLOCO_
    Se o dado não estiver na cache, o processador congela o seu funcionamento (_stall_), e busca na memória principal o dado. <br>
    - Algoritmo aleatório: O bloco substituído é um bloco aleatório.
      - Gerador de números aleatórios
    - Menor Recentemente Usado (LRU): substitui-se o bloco que não é usado há mais tempo. Baseado no princípio da localidade temporal. Neste caso, tenho que ter um registrador que guarde há quanto tempo o dado foi solicitado pela ultima vez.
      - Referência temporal para cada um;
      - Alto custo de implementação, pois cada bloco precisa de um registrador.
      - Precisa ser sempre redimencionado para evitar colocar blocos que nunca serão usados.
    - Menos Frequentemente Usado (LFU) : substitui-se o bloco que foi menos utilizado. Neste caso, preciso de um contador que me diga que bloco é mais frequentemente acessado.
      - Registrador que conta quantas vezes foi utilizado
      - É redimensionado devido à saturação do contador. (Zerado)
    - Primeiro a entrar, primeiro a sair (FIFO): substitui-se o mais antigo, mesmo que tenha sido usado recentemente, o que entrou primeiro na cache.
      - Uma fila para falar "esse é o mais antigo aqui" <br> <br>
    > O algoritmo __ótimo__ para substituir na cache, o ÓTIMO, é um que não conseguimos implementar: "Retire da cache o dado meno provável de ser utilizado, o mais longe do dado".

3. _ESTRATÉGIA DE GRAVAÇÃO_
 <br> Dois modos de escrita:<br>
    - _Write-through_: A informação é escrita na cache e na memória principal ao mesmo tempo.
      - Dispositivos com m'ais de um processador, onde ambos compartilham uma única memória. [Pode ocorrer um problema, de disposição de corrida (disciplina de SO)]
    - _Write-back_: Escrita preguiçosa...Só escreve 
    de volta na memória quando a cache precisar se livrar dele, quando ele for substituído. Economizo em escritas (menos, pois só vai para a memória principal no final de tudo). Problema: Há uma inconsistência entre as duas memórias.
      - Servidores, sistemas embarcados
      - Consome menos largura de banda
