# Entrada e Saída 📸

Comunicação do computador com o mundo externo! 

Visão de arquitetura: 
- O computador deve ter algo que permita essa conexão. Por exemplo, hoje em dia há uma universalização das portas USB. Para que a interface física de conexão seja mais simplificada nessa porta. (USB - Universal Serial Bus).

Mas e quanto a interface lógica? Como esse dado é traduzido entre o computador e o dispositivo? __CONTROLADORES DE E/S__!!

> Porque o periférico não pode ser conectado diretamente no barramento??
Há uma grande variedade de periféricos! São lógicas diferentes, por isso cada um deles possui um controlador. Também há a diferença nas taxas de transferência.

_chipset_: formatação para controlar de E/S. 

Não alteração na arquitetura. Ou seja, é um modelo com interfaces diferentes que consegue falar múltiplas línguas.   

__Projeto de arquitetura de E/S ✨__

As portas de E/S podem ser:
- Dedicadas: possuem um espaço de endereço único. Ou seja, existe um espaço FÍSICO onde são colocadas as informações do dispositivo. Comandos especiais são usados para ele.
- Mapeadas em memória: Possuo um mesmo espaço de endereçamento, e cada vez que plugo um dispositivo vou abrindo espaços de memória. Não preciso desses comandos especiais, ele é mais compatível com todo e qualquer dispositivo.

Transmissão dos dados pode ser:
- Paralela🎈: Existem vários caminhos que enviam os _bits_ da informação ao mesmo tempo.
    - Mais custoso, mais vias
- Serial🎳: Existe apenas uma linha de transmissão, cada _bit_ é transmitido, um por vez.
    - Como o ciclo é menor, a frequência é MAIOR

Tranferência de dados, técnicas padrão:
<br> Elas tendem a diminuir o grau de envolvimento do processador.

- E/S Programada (Polling): O processador sempre faz testes para ver se alguma coisa está pronta.
```python
    while(True):
        Está pronto para receber/enviar dados?
        if not ready:
            continue
        elif ready:
            break
```
É muito custoso para o processador! Pois ele para e pergunta se existe alguma coisa e fica num loop() até terminar de ler/enviar, enquanto poderia fazer outras coisas.

- Interrupções: O processador pode ser interrompido para atender atividades mais importantes. O processador possui pinos de interrupção, são requisições de interrupção. Aqui o processador NÃO PRECISA FICAR PERGUNTANDO se o disco já leu/enviou os dados. Quando o disco tiver acabado, ELE VAI INTERROMPER O PROCESSADOR. Assim, é como se o processador fala-se: _"Faça isso, e quando estiver pronto você me chama e eu continuo o processo"_, e ele vai fazer as outras atividades dele 😁😎

    Atendimento às interrupções:🧐
    1. Desabilita as novas interrupções
    2. Salva o estado atual do processador (todos os registradores)
    3. Habilita novas interrupções. (Se tiver uma nova de prioridade mais alta? Esse é um exemplo)
    4. Determina a causa da interrupção. _"Quem me interrompeu??"_
    5. Atende a interrupção.
    6. Desabilita novamente as novas interrupções.
    7. Restaura o estado anterior do processador
    8. Habilita novas interrupções
    9. Retorna da interrupção. _"Ufa! Finalmente, consegui terminar!"_

    - Perceba que mesmo assim, o processador prossegue fazendo a transferência das informações, como no primeiro modelo. Apenas gerencia melhor o seu tempo, ficando mais dinâmico e trabalhando mais eficientemente.

- Acesso Direto à Memória (DMA): um mecanismo que faz a transferência de dados para o processador! _"Hey DMA, faça essa transferência daqui para lá e depois me interrompa avisando que acabou!"_
    - Ele usa interrupções para avisar se deu certo/se deu erro para o processador.
    - Salva ainda mais tempo para o processador!😁😁😁
    - Mais custoso(caro), mas tem um desempenho melhor por terceirizar o trabalho da transferência do processador para o DMA.  Assim, dando mais tempo para o processador.
    - Preciso ter um módulo de DMA
<br>

### Diferenças entre os três :)

| Polling | _"Sério que tenho que ficar esperando?🙄"_ |
| ------ | ------- |
| __Interrupção__ | _"Okay, vou fazendo outras coisas ao mesmo tempo"_ |
| __DMA__ | _"DMA, faz isso para mim, quando você terminar, me interrompa avisando que terminou!"_ |