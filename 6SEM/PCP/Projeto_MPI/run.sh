#!/bin/bash
process_num=( 1 2 4 8 )
intervals=( 1000 10000 100000 )
output="results.csv"
header="Threads,Intervals_x_axis,Intervals_y_axis,Time Taken,Result"

> $output
echo $header > $output

mpicc code.c -lm -o code
if [ $? -ne 0 ]
then
  echo "Erro ao compilar code.c"
  exit 1
fi



for proc in ${process_num[@]}; do
    for interval_x in ${intervals[@]}; do
        for interval_y in ${intervals[@]}; do
            total=0
            ITERACOES=10
            
            # Executa 10 vezes para cada combinação
            for i in $(seq 1 $ITERACOES); do
                    resultado=$(mpirun -np $proc ./code $interval_x $interval_y)
                
                # Extrai o tempo e adiciona ao total
                tempo=$(echo $resultado | awk -F',' '{print $4}')
                result=$(echo $resultado | awk -F',' '{print $5}')
                total=$(echo "$total + $tempo" | bc)
                
                # Append no CSV
                echo "$proc,$interval_x,$interval_y,$tempo,$result" >> $output
            done
            
            # Calcula e exibe a média
            media=$(echo "scale=15; $total / $ITERACOES" | bc)
            echo "Processos: $proc, Intervalo X: $interval_x, Intervalo Y: $interval_y"
            printf "Média dos tempos: %15.15f\n" $media >> $output
            echo "----------------------------------------"
            
        done
    done
done 

