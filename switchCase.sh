#!/bin/bash

arithmatic_operation() {
echo -n "Enter two numbers: "
read a b
echo "Select operation (+, -, *, /):"
read op
case $op in
+) echo "Result is: $((a+b))" ;;
-) echo "Result is: $((a-b))" ;;
\*) echo "Result is: $((a*b))" ;;
*) echo "Invalid operation" ;;
esac
}

check_vowel() {
echo "Enter a character: "
read char
case $char in
[aeiouAEIOU]) echo "$char is a vowel" ;;
*) echo "$char is not a vowel" ;;
esac
}

grade_calculation() {
echo -e "Enter marks for Math, Biology, Physics, chemistry and Computer"
read m b p c cmp
avg=$(((m+b+p+c+cmp)/5))
echo "Percentage is : $avg%"
case $avg in
9[0-9]|100) grade="A" ;;
8[0-9]) grade="B" ;;
7[0-9]) grade="C" ;;
6[0-9]) grade="D" ;;
4[0-9]|5[0-9]) grade="E" ;;
*) grade="F" ;;
esac
echo "Grade is: $grade"

}

time_conversion() {
echo "Enter hour (0-23):"
read hour
echo "Enter minute (0-59):"
read minute

case $hour in
[0-9]|1[01]) period="AM" ;;
*) period="PM" ;;
esac

if [ $hour -gt 12 ]; then
	hour=$((hour - 12))
elif [ $hour -eq 0 ]; then
	hour=12
fi

echo "Time: $hour:$minute $period"

}


echo "Select An Option:"
echo "1. Arithmatic Operation"
echo "2. Check Vowel"
echo "3. Grade of Math, Biology, Physics, Chemistry and Computer"
echo "4. Enter hour and minute and print time with AM Or PM"

read choice

case $choice in
	1) arithmatic_operation ;;
	2) check_vowel ;;
	3) grade_calculation ;;
	4) time_conversion ;;
	*) echo "Invalid selection" ;;
esac
