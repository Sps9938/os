#!/bin/bash
echo -e "Enter 1st String\n"
read string1
echo -e "Enter 2nd String\n"
read string2

if [[ "$string1" == "$string2" ]]; then
	echo "$string1 is match with $string2"
else
	echo "$string1 is not match with $string2"

fi
