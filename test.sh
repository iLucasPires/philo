#!/bin/bash

max_iterations=$1
must_eat=$2

/philo $max_iterations 300 300 300 $must_eat > teste

for (( i=1; i<=$max_iterations; i++ ))
do
	num_lines=$(grep -c " $i is eat" teste)
	if [[ "$num_lines" -ne must_eat ]]; then
		echo "Erro na iteração $i"
		exit 1
	fi
done
echo "OK"

