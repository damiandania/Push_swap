#!/bin/sh

GREEN=$(tput setaf 2)
RED=$(tput setaf 1)
YELLOW=$(tput setaf 3)
BOLD=$(tput bold)
RESET=$(tput sgr0)

if [ $# -eq 0 ]
then
	read -p "${YELLOW}Total tests to do: ${RESET}" total_num
	read -p "${YELLOW}Numbers per test: ${RESET}" len_num
elif [ $# -eq 1 ]
then
	total_num=$1
	len_num=$1
elif [ $# -eq 2 ]
then
	total_num=$1
	len_num=$2
else
	echo "${RED}Too many arguments${RESET}"
	exit
fi

var=0;
test_count=0;

echo "${RED}Performing tests...${RESET}"

for i in $(seq $total_num)
do
	ARG=$(seq -$len_num $len_num | sort -R | head -n $len_num | tr '\n' ' ')
	#echo $ARG
	ret=$(./push_swap $ARG | wc -l)
	ret2=$(./push_swap $ARG | ./checker_linux $ARG )
	var=$(($ret + $var))
	test_count=$(($test_count + 1))
	echo "$test_count. $ret moves → ${GREEN}[$ret2]${RESET}"
done

echo ${BOLD}Average: ${GREEN}$(($var / $total_num))${RESET}
