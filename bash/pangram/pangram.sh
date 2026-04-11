#!/usr/bin/env bash

input=${1,,}
input_len=${#input}

alphabet=abcdefghijklmnopqrstuvwxyz
declare -A letters
for ((i = 0; i < ${#alphabet}; i++)); do
	letters[${alphabet:i:1}]=""
done

for ((i = 0; i < input_len; i++)); do
	unset "letters[${input:i:1}]"
done

[[ ${#letters[@]} -eq 0 ]] && echo "true" || echo "false"
