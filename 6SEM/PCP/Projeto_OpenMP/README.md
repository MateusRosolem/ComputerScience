Projeto: Regra do Trapézio com Paralelismo usando OpenMP
========================================================

Membros
-------

* Mateus Rosolem Baroni   
* Leandro Aguiar Mota

* * *

🖋️ Sobre
---------

Este projeto implementa a **Regra do Trapézio** para calcular numericamente uma integral dupla em um intervalo específico. O programa utiliza a biblioteca **OpenMP** para paralelizar o cálculo, dividindo o trabalho entre múltiplos threads.

### Contexto

A Regra do Trapézio é um método de integração numérica usado para aproximar o valor de uma integral. No caso deste projeto, é aplicada para uma função bidimensional definida como:

O cálculo da integral é feito subdividindo os intervalos em pequenas seções e calculando a soma ponderada dos valores da função nesses subintervalos.

* * *

📖 Introdução
-------------

O projeto utiliza **OpenMP** para melhorar a performance em sistemas com múltiplos núcleos. O cálculo da integral é distribuído entre threads, usando a diretiva `#pragma omp` para paralelizar os loops de integração.

O programa permite especificar:

* O número de threads a ser usado.
* O número de subdivisões nos eixos e .

### Fluxo do Programa:

1. **Entrada**: O programa recebe o número de threads e o número de subdivisões para e como argumentos.
2. **Paralelismo**: A soma das áreas dos sub-retângulos é distribuída entre threads.
3. **Resultado**: O tempo de execução e o resultado da integral aproximada são exibidos ao final.

* * *

🛠️ Compilação
--------------

Certifique-se de ter o **gcc** instalado e suporte à biblioteca **OpenMP**.

Para compilar o programa, use o seguinte comando:
    gcc -o trapezoidal trapezoidal.c -fopenmp -lm

* * *

🚀 Execução
-----------

Para executar o programa, use o comando:
    ./trapezoidal <num_threads> <intervals_x> <intervals_y>

### Parâmetros:

* `<num_threads>`: Número de threads para paralelização.
* `<intervals_x>`: Número de subdivisões no eixo .
* `<intervals_y>`: Número de subdivisões no eixo .

### Exemplo de Execução:

    ./trapezoidal 4 1000 1000

* * *

📊 Saída
--------

O programa exibe os seguintes resultados:

* **Número de threads** usados.
* **Subdivisões** no eixo e .
* **Tempo de execução** (em segundos).
* **Valor aproximado da integral**.

Exemplo de saída:
    4, 1000, 1000, 0.123456789012345, 1.234567890123456

* * *

🔧 Ajustes e Melhorias
----------------------

O programa pode ser modificado para:

1. Suportar diferentes funções de integração.
2. Permitir leitura de limites de integração pela entrada do usuário.
3. Melhorar a precisão ajustando dinamicamente os intervalos baseados em um erro tolerado.

Explore o código e otimize ainda mais o desempenho!
