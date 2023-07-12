#!/bin/bash

print_menu() {
	clear
	echo "---- Evaluación Test ----"
	echo "1. Comprobación para 3 números"
	echo "2. Comprobación para 5 números"
	echo "3. Comprobación para 100 números (visualizador)"
	echo "4. Comprobación para 100 números (negativos incluidos)"
	echo "5. Comprobación para 500 números (visualizador)"
	echo "6. Comprobación para 500 números (negativos incluidos)"
	echo "7. Comprobación para intervalos personalizados (solo positivos)"
	echo "8. Comprobación para valores personalizados"
	echo "9. Salir"
	echo "------ By paescano ------"
}

run_test() {
	local test_name=$1
	local test_command=$2
	local test_description=$3
	local test_link=$4

	clear
	echo "$test_name"
	echo "$test_description"

	if [[ -n "$test_command" ]]; then
		NBR=$(eval $test_command)
		NBR_COUNT=$(echo $NBR | wc -w)
		CMD=$(./push_swap $NBR)
		CMD_LINK=$( echo "$CMD" | sed -e"s/rra/g/g" -e"s/rrb/h/g" \
		-e"s/rrr/i/g" -e"s/sa/a/g" -e"s/sb/b/g" -e"s/ss/c/g" \
		-e"s/ra/d/g" -e"s/rb/e/g" -e"s/rr/f/g"  -e"s/pa/j/g" -e"s/pb/k/g" | tr -d '\n')
		CMD_COUNT=${#CMD_LINK}
		RESULT=$(./push_swap $NBR | ./checker_Mac $NBR)

		echo "Secuencia de números empleados: $NBR"
		echo "Cantidad de números empleados: $NBR_COUNT"
		echo "Operaciones: $CMD_COUNT"
		echo "Secuencia de operaciones: $CMD"
		echo "Resultado del checker: $RESULT"

		if [[ -n "$test_link" ]]; then
			NBR_LINK=$( echo "$NBR" | tr ' ' ',' )
			echo "Link para visualizar el resultado: https://bluegales.github.io/push-swap-pain/?&nbr=$NBR_LINK&cmd=$CMD_LINK"
		fi
	fi

	read -n1 -rsp $'Presione cualquier tecla para volver al menú...\n'
}

while true; do
	print_menu
	read -p "Ingrese una opción: " opcion

	case $opcion in
		1)
			run_test "1. Comprobación para 3 números" "seq 1 3 | sort -R | tr '\n' ' ' | rev | cut -c 2- | rev" "Comprobación para 3 números"
			;;
		2)
			run_test "2. Comprobación para 5 números" "seq 1 5 | sort -R | tr '\n' ' ' | rev | cut -c 2- | rev" "Comprobación para 5 números"
			;;
		3)
			run_test "3. Comprobación para 100 números (visualizador)" "seq 1 100 | sort -R | tr '\n' ' ' | rev | cut -c 2- | rev" "Comprobación para 100 números (visualizador)" "true"
			;;
		4)
			run_test "4. Comprobación para 100 números (negativos incluidos)" "seq -49 50 | sort -R | tr '\n' ' ' | rev | cut -c 2- | rev" "Comprobación para 100 números (negativos incluidos)"
			;;
		5)
			run_test "5. Comprobación para 500 números (visualizador)" "seq 1 500 | sort -R | tr '\n' ' ' | rev | cut -c 2- | rev" "Comprobación para 500 números (visualizador)" "true"
			;;
		6)
			run_test "6. Comprobación para 500 números (negativos incluidos)" "seq -249 250 | sort -R | tr '\n' ' ' | rev | cut -c 2- | rev" "Comprobación para 500 números (negativos incluidos)"
			;;
		7)
			while true; do
				read -p "Introduce el principio del intervalo: " start
				read -p "Introduce el final del intervalo: " finish
				if ! [[ "$start" =~ ^[0-9]+$ ]]; then
					echo "El principio del intervalo debe ser un número"
				elif ! [[ "$finish" =~ ^[0-9]+$ ]]; then
					echo "El final del intervalo debe ser un número"
				elif [ $start -gt $finish ]; then
					echo "El principio del intervalo debe ser menor que el final"
				else
					break
				fi
			done

			run_test "7. Comprobación para intervalos personalizados" "seq $start $finish | sort -R | tr '\n' ' ' | rev | cut -c 2- | rev" "Comprobación para intervalos personalizados"			
			;;
		8)
			clear
			read -p "Introduce la entrada que desees para push swap: " NBR
			NBR_COUNT=$(echo $NBR | wc -w)
			CMD=$(./push_swap $NBR)
			CMD_LINK=$(echo "$CMD" | tr -d '\n' | tr ' ' '')
			CMD_COUNT=${#CMD_LINK}
			RESULT=$(./push_swap $NBR | ./checker_Mac $NBR)
			echo "8. Comprobación para entrada personalizada"
			echo "Entrada empleada: $NBR"
			echo "Operaciones: $CMD_COUNT"
			echo "Secuencia de operaciones: $CMD"
			echo "Resultado del checker: $RESULT"
			read -n1 -rsp $'Presione cualquier tecla para volver al menú...\n'
			;;
		9)
			echo "Saliendo..."
			exit 0
			;;
		*)
			echo "Opción inválida. Inténtelo nuevamente."
			read -n1 -rsp $'Presione cualquier tecla para continuar...\n'
			;;
	esac
done