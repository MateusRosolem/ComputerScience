Projeto: Integração Numérica com Regra do Trapézio em MPI
=========================================================

* * *

🖋️ Sobre
---------

Este projeto implementa a **Regra do Trapézio** para calcular uma integral dupla, utilizando a biblioteca **MPI** para paralelizar o cálculo em múltiplos processos. Cada processo MPI é responsável por calcular uma parte da integral e os resultados são combinados ao final.

A função integrada é:

O domínio de integração é , dividido em subintervalos.

* * *

📖 Introdução
-------------

### O Método do Trapézio

A Regra do Trapézio aproxima uma integral somando áreas de pequenos trapézios formados pela curva da função. Para a integral dupla:

Os pontos nas bordas têm peso reduzido.

### Por que MPI?

A **MPI** (**Message Passing Interface**) é uma biblioteca padrão para computação paralela distribuída, ideal para clusters.

* Cada processo calcula parte da integral.
* O processo root combina os resultados usando redução.

* * *

🚀 Execução
-----------

### Compilação

Certifique-se de ter o **MPI** instalado. Use o seguinte comando para compilar:
    mpicc -o trapezoidal_mpi trapezoidal_mpi.c

### Execução

Execute o programa com `mpirun` ou `mpiexec`, especificando o número de processos:
    mpirun -np <n_processes> ./trapezoidal_mpi <intervalos_x> <intervalos_y>

* `<n_processes>`: Número de processos MPI a serem usados.
* `<intervalos_x>` e `<intervalos_y>`: Número de subdivisões no domínio em e .

### Exemplo de execução:

    mpirun -np 4 ./trapezoidal_mpi 1000 1000

* * *

📊 Saída
--------

A saída exibe, para cada execução:

* **Rank do processo root (0).**
* **Subdivisões nos eixos e .**
* **Tempo total de execução** (em segundos).
* **Valor aproximado da integral**.

### Exemplo de Saída:

    0,1000,1000,0.023456789012345,1.234567890123456

* * *

🛠️ Funcionamento
-----------------

1. **Divisão do Domínio**  
   Cada processo calcula sua parte do domínio, dividindo as linhas em :
   
   * `start`: Índice inicial no para o processo atual.
   * `end`: Índice final no . O último processo pode pegar linhas extras.

2. **Cálculo Local**  
   O processo computa sua parte da integral com o Método do Trapézio, considerando os pesos nas bordas.

3. **Redução MPI**  
   O valor local de cada processo é somado no processo root usando `MPI_Reduce`.

4. **Resultados**  
   O processo root exibe o tempo de execução e o resultado da integral.

* * *

🔧 Ajustes e Melhorias
----------------------

* **Balanceamento Dinâmico**: Ajustar dinamicamente a distribuição de linhas para melhorar a eficiência em sistemas heterogêneos.
* **Maior Precisão**: Usar intervalos adaptativos para obter resultados mais precisos em funções com variação rápida.
* **Escalabilidade**: Testar em sistemas com maior número de processos para explorar a eficiência.

* * *

🚨 Observações
--------------

* Certifique-se de que todos os nós do cluster possuem o programa compilado.
* A precisão do resultado depende do número de subintervalos.

Experimente a paralelização distribuída com MPI para resolver problemas computacionalmente intensivos! 🚀
