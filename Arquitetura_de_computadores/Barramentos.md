# Barramentos

Uma estrutura que conecta todos os dispositivos da arquitetura de Von-Neumman (como vimos em estudos anteriores).

Possuem linhas de transmissão:
 - Transmitem em binário, 0´s e 1´s.
 - Elas podem ser classificadas em:
    - Dados
    - Endereços
    - Controle
 - Não possuem diferenciação, é preciso avisar que é dado, endereço ou controle.

Barramento de dados: Transporta informções (dados ou instruções). 
 - Birecional: Processador <-> Memória

Barramento de endereços: O processador o utiliza para enviar endereços da memória ou de dispositivos de E/S. Unidirecional.

Barramento de controle: Sinaliza solicitações e confirmações. Bidirecional.
 - Exemplo: Clock, que é distribuído para todos os componentes do computador, para que funcionem no mesmo ciclo.

Vantagens: 
    Versatilidade - podemos ligar, pendurar um dispositivo nele.  <br>
    Baixo custo - único conjunto que vários componentes utilizam.
Desvantagem:
    Disputa - Como vários dispositivos o utilizam, controlar quem vai utilizar em que momento é um desafio. <br>
    limitação de velocidade: Quanto mais dispositivos, maior deve ser o fio. Assim, quanto maior o fio, por mais tempo o dado deve trafegar para chegar em um determinado destino. Por isso, fica mais lento.

### __LARGURA__
Número de linhas que o compõe. E quanto mais hardware, mais custo.

### __TIPO__
- Barramento Dedicado: Um barramento para cada funcionalidade. Ex: Barramento de Dados, Barramento de Controle, Barramento de Endereços.
Alto desempenho, alto custo. Quem possui: Celular, notebooks...

- Barramento Multiplexado: Todos compartilham apenas um barramento. Reduz os custos, mas o sistema é mais lento.

### __TEMPORIZAÇÃO__
- Barramento síncrono: Está sincronizado com o clock, transmite com as subidas do clock. É simples, fácil de implementar. Problema: Caso o dispositivo funcione em uma velocidade muito maior do que a do barramento, ele vai ter que andar na onda do barramento, assim, perdendo sua eficácia.
    - Não podem ser muito longos, para evitar o atraso no clock.

- Barramento assíncrono: Há um controle dentro do barramento para a transmissão de dados. _Handshaking_.
    - Pode funcionar com velocidades diferentes (entre ele e o dispositivo).

### __ARBITRAGEM__
Componente que determina quem terá acesso ao barramento, a partir das solicitações. Utiliza de um arranjo chamado _master-slave_:
    - Apenas o _bus master_ diz quem vai para o barramento.
    - O _bus slave_ obedece.

Arbitragem estática: Cada dispositivo tem um tempo para transmitir. Dá oportunidade para todo mundo, mesmo se nem todo mundo quiser transmitir.

Arbitragem dinâmica: _bus request_ e _bus grant_. Ele responde a requisições. Se o dispositivo solicitou o acesso (_bus request_), ele recebe permissão por meio do _bus grant_.

__Políticas de alocação__

Prioridade: Ele dá para quem tem a prioridade

Justiça: O árbitro cede o barramento para todos que requisitarem, mas um tempo certo para todo mundo, sem prioridade.

Híbrida: Justiça + Prioridade. Os que tem prioridade ainda terão mais acesso ao barramento. Mas não ocorre de um nunca ter acesso.

_Daisy Chaining_: O árbitro não implementa a prioridade, a prioridade já vem na ordem que os dispositivos estão dispostos e o barramento ligado neles. (explicação breve)

__HIERARQUIA__

Como rodar dispositivos com velocidades diferentes?

Criando mais de um barramento, uma hierarquia de barramentos. Dessa forma, utilizo uma interface do barramento de _expansão_ (o novo) para me comunicar com o barramento _main_. Assim, posso ter dispositivos conversando em uma frequência mais rápido, e dispositivos conversando em uma frequência mais lenta. Agora, os dispositivo podem 'brigar' pelo acesso em locais mais isolados.