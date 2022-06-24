# Notes about Hierarquia de Memória :)
##### 📌Terceira Unidade da disciplina "Arquitetura de Computadores" do curso de BTI na UFRN

Mémoria é um lugar para o armazenamento de informações, e suas únicas ações são: leitura e escrita.

- Memória endereçável - Pois via um endereço, você pode ter acesso a um determinado dado.

Qual é o tamanho ideal? O maior tamanho possível e a localização mais perto do processador.

O que temos? Tecnologias de memória velozes, mas são muito caros. Por outro lado, temos algumas baratas, mas são muito lentas.

#### Memory Wall
- Realizar o processamento é muito mais rápido hoje em dia, do que busca o/a dado/instrução na memória. No gráfico temos o "PERFORMANCE GAP", da evolução da memória e do 
processador ao passar dos anos.
- Quando eu tenho os dados se torna mais fácil fazer a conta!!
- Como posso melhorar isso??

### Hierarquia de Memória
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

