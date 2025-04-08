#!/bin/bash
# Multiple shell programs (odd/even, factorial, Fibonacci, switch, loop, logical)

read -p "Enter a number: " num
if (( num % 2 == 0 )); then echo "$num is even"; else echo "$num is odd"; fi

fact=1
for (( i=1; i<=num; i++ )); do fact=$((fact * i)); done
echo "Factorial: $fact"

a=0; b=1
echo "Fibonacci:"
for (( i=0; i<num; i++ )); do echo -n "$a "; fn=$((a + b)); a=$b; b=$fn; done
echo

echo "Switch case"
read -p "Enter 1 for date, 2 for cal: " ch
case $ch in 1) date ;; 2) cal ;; *) echo "Invalid" ;; esac

echo "Loop demo"
for i in {1..5}; do echo "Loop $i"; done

echo "Logical operator demo"
if [[ $num -lt 100 && $num -gt 0 ]]; then echo "Number is between 0 and 100"; fi
