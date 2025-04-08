#!/bin/bash

# Read a number from user
read -p "Enter a number: " num

# 1. Check Odd or Even
if (( num % 2 == 0 )); then
    echo "$num is even"
else
    echo "$num is odd"
fi

# 2. Factorial Calculation
fact=1
for (( i=1; i<=num; i++ )); do
    fact=$((fact * i))
done
echo "Factorial: $fact"

# 3. Fibonacci Series
a=0
b=1
echo "Fibonacci:"
for (( i=0; i<num; i++ )); do
    echo -n "$a "
    fn=$((a + b))
    a=$b
    b=$fn
done
echo

# 4. Switch Case (using case statement)
echo "Switch case"
read -p "Enter 1 for date, 2 for cal: " ch
case $ch in
    1) date ;;
    2) cal ;;
    *) echo "Invalid" ;;
esac

# 5. Loop demo
echo "Loop demo"
for i in {1..5}; do
    echo "Loop $i"
done

# 6. Logical Operator Demo
echo "Logical operator demo"
if [[ $num -lt 100 && $num -gt 0 ]]; then
    echo "Number is between 0 and 100"
else
    echo "Number is not in the range"
fi
//after install required
//sudo apt update
//sudo apt install bsdmainutils
