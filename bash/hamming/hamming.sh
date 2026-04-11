#!/usr/bin/env bash

if [ $# -ne 2 ]; then
	echo "Usage: hamming.sh <string1> <string2>"
	exit 1
fi

a=$1
b=$2
length=${#a}

if [ "${#b}" -ne "$length" ]; then
	echo "strands must be of equal length"
	exit 1
fi

count=0
for ((i = 0; i < length; i++)); do
	if [ "${a:$i:1}" != "${b:$i:1}" ]; then
		count=$((count + 1))
	fi
done

echo $count
