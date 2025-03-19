# Super Trunfo de Países

Este programa é uma implementação simples de um jogo de Super Trunfo usando países e alguns de seus atributos. Dois países são comparados com base em atributos como população, área, PIB, pontos turísticos e densidade demográfica, e o jogador escolhe qual atributo deseja usar para a comparação.

## Compilação e Execução

### Pré-requisitos

Você precisará de um compilador C para rodar o programa. No Linux, por exemplo, você pode usar o `gcc`. Se você estiver usando Windows, pode utilizar o `MinGW` ou qualquer outro compilador compatível com C.

### Compilar

Para compilar o programa, execute o seguinte comando no terminal:

```bash
gcc super_trunfo.c -o super_trunfo


Executar
Após compilar, execute o programa com o seguinte comando:

bash
Copiar
Editar
./super_trunfo

Atributos disponíveis para comparação
População - O país com a maior população vence.
Área - O país com a maior área vence.
PIB - O país com o maior Produto Interno Bruto vence.
Pontos Turísticos - O país com mais pontos turísticos vence.
Densidade Demográfica - O país com a menor densidade demográfica vence (este é o único atributo em que o menor valor é o vencedor).
Exemplo de uso
Ao executar o programa, você verá o seguinte menu:

yaml
Copiar
Editar
Escolha o atributo para comparar:
1 - População
2 - Área
3 - PIB
4 - Pontos Turísticos
5 - Densidade Demográfica
Digite sua escolha:
Suponha que você escolha "1" para comparar a população. O programa irá mostrar a população dos dois países e determinar quem vence nesse atributo.

Você repetirá o processo para um segundo atributo, e no final o programa determinará qual país venceu a comparação geral com base nos atributos escolhidos.

Exemplo de saída
yaml
Copiar
Editar
Escolha o atributo para comparar:
1 - População
2 - Área
3 - PIB
4 - Pontos Turísticos
5 - Densidade Demográfica
Digite sua escolha: 1
Atributo: População
Brasil: 213000000.00
Argentina: 45000000.00
Resultado: Brasil venceu!

Escolha o atributo para comparar:
1 - População
2 - Área
3 - PIB
4 - Pontos Turísticos
5 - Densidade Demográfica
Digite sua escolha: 2
Atributo: Área
Brasil: 8515767.00
Argentina: 2780400.00
Resultado: Brasil venceu!

Soma dos pontos:
Brasil: 2
Argentina: 0
Resultado: Brasil venceu!
