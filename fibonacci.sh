#!/bin/bash
echo -e "Enter Number of Series"
read n
n1=0
n2=1
next=0
prev=0
echo -n "series of fibonacci is: $n1 $n2 "
for (( i=1; i<n-1; i++))
do
next=$((n1+n2))
prev=$((n2))
n1=$((prev))
n2=$((next))
echo -n "$next "
done

