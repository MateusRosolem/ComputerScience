Projeto: Integração Numérica com Regra do Trapézio em CUDA
==========================================================

* * *

🖋️ Sobre
---------

Este projeto implementa a **Regra do Trapézio** para calcular numericamente uma integral dupla usando a **CUDA**, explorando o paralelismo em GPUs. O objetivo é demonstrar a eficiência da paralelização em comparação com abordagens sequenciais, distribuindo o trabalho entre milhares de threads.

A função integrada é:

O domínio de integração é dividido em subintervalos, e cada thread calcula sua contribuição local, somando-as ao final.

* * *

📖 Introdução
-------------

### O Método do Trapézio

A Regra do Trapézio é um método de integração numérica que aproxima o valor da integral somando áreas de pequenos trapézios formados pela curva da função. Para uma função , a integral é aproximada como:

Pontos nas bordas recebem peso reduzido, conforme o método.

### Por que CUDA?

A **CUDA** permite realizar cálculos paralelos em GPUs, que possuem milhares de núcleos. Neste projeto:

* Cada thread processa uma parte do domínio de integração.
* Resultados parciais são acumulados utilizando operações atômicas.

* * *

🚀 Execução
-----------

### Compilação

Certifique-se de ter o **NVIDIA CUDA Toolkit** instalado e use o seguinte comando para compilar o código:
    nvcc -o trapezoidal_cuda trapezoidal_cuda.cu

### Execução

Para executar o programa:
    ./trapezoidal_cuda

O programa executa várias combinações de:

* **Número de blocos** de threads.
* **Subdivisões** nos eixos e .

Para cada combinação, calcula:

1. O **tempo médio de execução** após 10 rodadas.
2. O **resultado médio da integral**.

* * *

📊 Saída
--------

O programa exibe os seguintes valores para cada combinação de parâmetros:

* **Blocos de threads.**
* **Subdivisões no eixo .**
* **Subdivisões no eixo .**
* **Tempo médio de execução** (em milissegundos).
* **Valor médio da integral**.

### Exemplo de Saída:

    10, 1000, 1000, 0.123456789012345, 1.234567890123456
    100, 10000, 10000, 0.345678901234567, 1.567890123456789

* * *

🛠️ Funcionamento
-----------------

1. **Kernel CUDA (`trapezoidalIntegration`)**  
   Cada thread calcula a contribuição da integral para uma fração do domínio.
   
   * Usa operações atômicas (`atomicAdd`) para somar as contribuições ao resultado global.
   * Ajusta os pesos para pontos nas bordas, conforme a Regra do Trapézio.

2. **Execução Iterativa**  
   Para cada combinação de parâmetros, o programa:
   
   * Mede o tempo de execução do kernel usando **eventos CUDA**.
   * Calcula o valor médio da integral após 10 execuções.

* * *

🔧 Ajustes e Melhorias
----------------------

* **Explorar mais funções**: Permitir integração de diferentes funções com base em entrada do usuário.
* **Adaptação de subintervalos**: Ajustar dinamicamente os subintervalos para alcançar maior precisão com menor custo computacional.
* **Redução em Memória Compartilhada**: Usar memória compartilhada para reduzir acessos à memória global e melhorar a eficiência.

* * *

🚨 Observações
--------------

* Certifique-se de ter uma GPU com suporte à arquitetura CUDA.
* Resultados podem variar dependendo da precisão de ponto flutuante e do hardware utilizado.

Aproveite para explorar o poder da computação paralela! 🚀
