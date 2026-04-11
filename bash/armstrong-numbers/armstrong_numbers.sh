#!/usr/bin/env bash

len=${#1}

n=0
for ((i = 0; i < len; i++)); do
	n=$((n + ${1:i:1} ** len))
done

if ((n == $1)); then
	printf "true"
else
	printf "false"
fi
