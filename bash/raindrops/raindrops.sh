#!/usr/bin/env bash

n="${1}"
output=

if [ $((n % 3)) -eq 0 ]; then
  output="${output}$(printf "Pling")"
fi

if [ $((n % 5)) -eq 0 ]; then
  output="${output}$(printf "Plang")"
fi

if [ $((n % 7)) -eq 0 ]; then
  output="${output}$(printf "Plong")"
fi

output=${output:-$n}

echo "$output"
