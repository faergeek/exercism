#!/usr/bin/env bash

input=$1
uppercased_input=$(echo "$input" | tr '[:lower:]' '[:upper:]' | tr -d "'" | tr -s '[:punct:]' ' ')

for word in $uppercased_input; do
	printf "%c" "${word:0:1}"
done
