#!/usr/bin/env bash

[ $(($1 % 3)) -eq 0 ] && result+="Pling"
[ $(($1 % 5)) -eq 0 ] && result+="Plang"
[ $(($1 % 7)) -eq 0 ] && result+="Plong"

echo "${result:-$1}"
